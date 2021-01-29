/* 
 * File:   005TMR0_INT_example.c
 * Author: Mario
 * Brief:  Toggle PB7 every 500ms using TMR0 interrupt.
 *         Values can be calculate on: 
 *         https://www.sistemasorp.es/blog/temporizadores_pic.html
 *          
 */

#include <stdint.h>
#include "ConfigBits.h"
#include "TMR0.h"

#define _XTAL_FREQ 32000000

#define TMR0REG_VALUE       131         //1ms @ 32MHz 


uint16_t counter = 0;
int main() 
{
  
    OSCCONbits.IRCF = 0b1110;   //8MHZ internal clock
    OSCCONbits.SPLLEN = 1;      //PLL Enable for 32MHz
    
    TMR0_setup(TMR0_CLK_FOSCDIV4, TMR0_EDGE_FALL,TMR0_PRESC_64);
    TMR0_EnableInterrupts();
    TMR0_INT_Handle(TMR0REG_VALUE);
    
    TRISBbits.TRISB7 = 0;   // PB7 as output
    WPUBbits.WPUB7 = 0;     // PB7 pull-up disable
    
    while(1)
    {
        //do something
    }
}


void __interrupt() my_interrupt(void)
{
    if (INTCONbits.TMR0IF)                  //TMR0 Interrupt Flag bit 
    {               
        TMR0_INT_Handle(TMR0REG_VALUE);
        counter++;
        if (counter == 500)
        {
            PORTB ^= ( 1 << 7 );            //toggle PB7
            counter = 0;
        }
        
    } 
}