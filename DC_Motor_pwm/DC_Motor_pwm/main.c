/*
 * DC_Motor_pwm.c
 *
 * Created: 09-05-2026 22:57:55
 * Author : athul
 */ 

#define F_CPU 16000000UL

#include <avr/io.h>

void ADC_Init()
//ADMUX ADC multiplexer selection register 
//RFFS0 Bit inside the ADMUX register -- it control the adc reference voltage 
{
	ADMUX = (1 << REFS0); //AVcc reference, ADC0 selected

//ADCSRA ADC control and status Register A
//ADEN ADC Enable bit
//ADPS2,ADPS1,ADPS0 ADC Prescaler
	
	ADCSRA = (1 << ADEN)  | //Enable ADC
	         (1 << ADPS2) |
			 (1 << ADPS1) |
			 (1 << ADPS0);  //Prescaler  = 128
	
}

uint16_t ADC_Read()
//ADSC ADC Start conversion
{
	ADCSRA |= (1 << ADSC); // Start conversion
	while (ADCSRA & (1 << ADSC)); // Wait for conversion complete
	return ADC;
}

void PWM_Init()
//DDRD Data Direction Register for PORTD
//OC0A Output Compare Output A
//TCCR0A Timer/Counter countrol register0 A
//COM0A1 Compare Output Mode Bit 
//WGM00/01 Wavefom gneration mode bit
//CS01/00 Clock slect bit (64)

{
	DDRD |= (1 << PD6); //set OC0A (PD6) as output
	
	TCCR0A = (1 << COM0A1) | //Non-inverting PWM
	         (1 << WGM01)  |
			 (1 << WGM00);   //Fast PWM mode
			 
    TCCR0B = (1 << CS01) | (1 << CS00); // Prescaler = 64
	OCR0A = 0;
}

int main()
{
    uint16_t adc_value;
	uint8_t pwm_value;
	
	ADC_Init();
	PWM_Init();
	
    while (1) 
    { 
		adc_value = ADC_Read(); //Read 10bit ADC Value
		pwm_value = adc_value / 4; //Scale 10bit to 8bit
		OCR0A = pwm_value; //set PWM duty cycle
    }
}

