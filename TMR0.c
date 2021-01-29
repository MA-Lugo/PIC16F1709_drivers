/* 
 * File:   TMR0.c
 * Author: Mario
 *
 */

#include "TMR0.h"

void TMR0_setup (uint8_t TMR0_CLK, uint8_t TMR0_EDGE, uint8_t TMR0_PRESC)
{
    OPTION_REGbits.TMR0CS = TMR0_CLK;
    OPTION_REGbits.TMR0SE = TMR0_EDGE;
    
    if(TMR0_PRESC <= 7)
    {
        OPTION_REGbits.PSA = 0;
        OPTION_REGbits.PS = TMR0_PRESC;
    }
    else
    {
       OPTION_REGbits.PSA = 1; 
    }
}

void TMR0_INT_Handle(uint8_t TMR0REG_VALUE)
{
    INTCONbits.TMR0IF = 0;
    TMR0 = TMR0REG_VALUE;
}

void TMR0_EnableInterrupts(void)
{
    INTCONbits.GIE = 1;     
    INTCONbits.TMR0IE = 1;
    
}