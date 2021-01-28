/* 
 * File:   003UART_TxInterrupt_example.c
 * Author: Mario
 * Brief:  Rx Interrupt example, toggle PB7 pin when 
 *         receive the character 'a' 
 */

#include <stdint.h>
#include "ConfigBits.h"
#include "UART.h"

#define _XTAL_FREQ 32000000


int main() {
  
    OSCCONbits.IRCF = 0b1110;   //8MHZ internal clock
    OSCCONbits.SPLLEN = 1;      //PLL Enable for 32MHz
    TRISBbits.TRISB7 = 0; // PB7 as output
    
    
    UART_setup(BRGH16_DISABLE,HIGH_SPEED,34);   // 57600 baud @ 32MHz
    
    UART_InitPin_Rx(PORT_B,4);
    UART_EnableInterrupts(RX);
    
    while(1)
    {
        //Do something
    }
 
}

void __interrupt() my_interrupt(void)
{
    if (PIR1bits.RCIF){             //USART Receive Interrupt Flag bit      
        PIR1bits.RCIF = 0;          //Clear Flag   
        if (UART_Read() == 'a'){
            PORTB ^= ( 1 << 7 );    //toggle PB7
        }
    } 
}