/* 
 * File:   006DATA_AQC_example.c
 * Author: Mario
 * Brief:  
 */

#include <stdint.h>
#include "ConfigBits.h"
#include "TMR0.h"
#include "UART.h"
#include "ADC.h"

#define _XTAL_FREQ 32000000

#define TMR0REG_VALUE       131         //1ms @ 32MHz 

#define ENABLE      1
#define DISABLE     0

uint16_t counter = 0;
uint8_t transmission = DISABLE;

uint8_t StartFrame[] = "$DAQ";
uint8_t EndFrame[]   = "\r\n";   

uint16_t data[3];

void DATA_ACQ (void);
void DATA_Transmission(void);

int main() 
{
  
    OSCCONbits.IRCF = 0b1110;   //8MHZ internal clock
    OSCCONbits.SPLLEN = 1;      //PLL Enable for 32MHz
    
    UART_setup(BRGH16_DISABLE,HIGH_SPEED,103);       //@ 19200 baud
    UART_InitPin_Tx(PORT_B,6);
    
    ADC_setup(ADC_CLK_FRC,ADC_PVREF_VDD,ADC_NVREF_VSS);
    ADC_Format(ADC_FORMAT_RIGHT);
    ADC_Init_CH(ADC_CH_AN3);
    ADC_Init_CH(ADC_CH_AN7);
    ADC_Init_CH(ADC_CH_AN11);
    
    
    TMR0_setup(TMR0_CLK_FOSCDIV4, TMR0_EDGE_FALL,TMR0_PRESC_64);
    TMR0_EnableInterrupts();
    TMR0_INT_Handle(TMR0REG_VALUE);
    
    
    while(1)
    {
        if(transmission == ENABLE)
        {
            DATA_Transmission();
            transmission = DISABLE;
        }
    }
}


void __interrupt() my_interrupt(void)
{
    if (INTCONbits.TMR0IF)                  //TMR0 Interrupt Flag bit 
    {               
        TMR0_INT_Handle(TMR0REG_VALUE);
        counter++;
        if (counter == 50)
        {
            transmission = ENABLE;
            counter = 0;
        }
        
    } 
}

void DATA_ACQ (void)
{
    data[0] = ADC_Read(ADC_CH_AN3);
    data[1] = ADC_Read(ADC_CH_AN7);
    data[2] = ADC_Read(ADC_CH_AN11);
    
}

void DATA_Transmission(void)
{
    DATA_ACQ();
    UART_WriteString(&StartFrame);
    
    for(uint8_t i=0; i<=2; i++)
    {
        UART_WriteChar((uint8_t)data[i]);                   //data LSB
        UART_WriteChar( (uint8_t)(data[i] >> 8) );          //data MSB
        
    }
    UART_WriteString(&EndFrame);
}