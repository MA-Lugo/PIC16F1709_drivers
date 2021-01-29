/* 
 * File:   004ADC_example.c
 * Author: Mario
 * Brief:  ADC read example
 */

#include <stdint.h>
#include "ConfigBits.h"
#include "ADC.h"

#define _XTAL_FREQ 32000000

uint16_t value1,value2,value3;

int main() {
  
    OSCCONbits.IRCF = 0b1110;   //8MHZ internal clock
    OSCCONbits.SPLLEN = 1;      //PLL Enable for 32MHz
    
    ADC_setup(ADC_CLK_FOSCDIV32,ADC_PVREF_VDD,ADC_NVREF_VSS);
    ADC_Format(ADC_FORMAT_RIGHT);
    ADC_Init_CH(ADC_CH_AN3);
    ADC_Init_CH(ADC_CH_AN7);
    ADC_Init_CH(ADC_CH_AN11);
     
           
    while(1)
    {
        value1 = ADC_Read(ADC_CH_AN3);
        value2 = ADC_Read(ADC_CH_AN7);
        value3 = ADC_Read(ADC_CH_AN11);
    
        __delay_ms(1000);
    }
}

