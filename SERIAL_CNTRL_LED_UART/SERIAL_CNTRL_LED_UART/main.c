/*
 * SERIAL_CNTRL_LED_UART.c
 *
 * Created: 10-05-2026
 * Author : Athul
 */

#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h>
#include <string.h>

#define BAUD 9600
#define UBRR_VALUE ((F_CPU/16/BAUD)-1)

/* ---------------- UART FUNCTIONS ---------------- */

void UART_Init(unsigned int ubrr) // Initialize UART
{
    UBRR0H = (unsigned char)(ubrr >> 8); // Load upper 8 bits of baud value

    UBRR0L = (unsigned char)ubrr; // Load lower 8 bits of baud value

    UCSR0B = (1 << RXEN0) | (1 << TXEN0); // Enable UART receiver and transmitter

    UCSR0C = (1 << UCSZ01) | (1 << UCSZ00); // Set UART frame format: 8 data bits, 1 stop bit
}

void UART_Transmit(char data) // Function to transmit one character
{
    while (!(UCSR0A & (1 << UDRE0))); // Wait until transmit buffer becomes empty

    UDR0 = data; // Load data into UART data register for transmission
}

void UART_SendString(char *str) // Function to send string through UART
{
    while (*str) // Continue until null character
    {
        UART_Transmit(*str++); // Send character and move to next
    }
}

char UART_Receive() // Function to receive one character
{
    while (!(UCSR0A & (1 << RXC0))); // Wait until data is received

    return UDR0; // Return received character
}

/* ---------------- PWM FUNCTIONS ---------------- */

void PWM_Init() // PWM initialization function
{
    DDRD |= (1 << PD6); // Configure PD6 (OC0A) as output pin

    TCCR0A |= (1 << WGM00) | (1 << WGM01); // Select Fast PWM mode

    TCCR0B |= (1 << CS01) | (1 << CS00); // Set prescaler to 64

    TCCR0A |= (1 << COM0A1); // Enable non-inverting PWM mode

    OCR0A = 0; // Initial PWM duty cycle = 0%
}

void PWM_SetBrightness(uint8_t duty) // Function to update PWM duty cycle
{
    if (duty == 0) // Check whether LED should turn OFF
    {
        TCCR0A &= ~(1 << COM0A1); // Disconnect PWM output

        PORTD &= ~(1 << PD6); // Force PD6 LOW
    }

    else // Execute if brightness greater than 0
    {
        TCCR0A |= (1 << COM0A1); // Enable PWM output

        OCR0A = duty; // Update PWM duty cycle
    }
}

/* ---------------- MAIN PROGRAM ---------------- */

int main(void)
{
    char command[10]; // Character array to store received command

    uint8_t index = 0; // Variable to track array index

    int brightness; // Variable to store brightness percentage

    UART_Init(UBRR_VALUE); // Initialize UART

    PWM_Init(); // Initialize PWM

    UART_SendString("UART LED Control Ready\r\n"); // Send startup message

    while (1) // Infinite loop
    {
        char received = UART_Receive(); // Receive one character from UART

        if (received == '\r' || received == '\n') // Check for Enter key
        {
            command[index] = '\0'; // Add null terminator to string

            if (strcmp(command, "ON") == 0) // Compare command with ON
            {
                PWM_SetBrightness(255); // Turn LED fully ON

                UART_SendString("LED is now ON\r\n"); // Send confirmation message
            }

            else if (strcmp(command, "OFF") == 0) // Compare command with OFF
            {
                PWM_SetBrightness(0); // Turn LED completely OFF

                UART_SendString("LED is now OFF\r\n"); // Send confirmation message
            }

            else if (strlen(command) > 0) // Check command is not empty
            {
                brightness = atoi(command); // Convert string into integer

                if (brightness >= 0 && brightness <= 100) // Check valid range
                {
                    uint8_t pwmValue; // Variable for PWM value

                    pwmValue = (brightness * 255) / 100; // Convert percentage into PWM range

                    PWM_SetBrightness(pwmValue); // Update LED brightness

                    UART_SendString("Brightness set to "); // Send message text

                    UART_SendString(command); // Send brightness value

                    UART_SendString("%\r\n"); // Send percentage symbol
                }

                else // Execute for invalid input
                {
                    UART_SendString("Invalid Command\r\n"); // Send error message
                }
            }

            index = 0; // Reset index for next command
        }

        else // Execute if received character is not Enter
        {
            if (index < sizeof(command) - 1) // Prevent buffer overflow
            {
                command[index++] = received; // Store character into array
            }
        }
    }
}