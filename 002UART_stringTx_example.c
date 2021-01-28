/* 
 * File:   002UART_stringTx_example.c
 * Author: Mario
 * Brief : UART transmition @ 57660 Baudrate, sends "Hello World!" every 2
 *        seconds 
 */

#include <stdint.h>
#include "ConfigBits.h"
#include "UART.h"

#define _XTAL_FREQ 32000000


uint8_t MyString[] = "Hello World!\n";

int main() {
  
    OSCCONbits.IRCF = 0b1110;   //8MHZ internal clock
    OSCCONbits.SPLLEN = 1;      //PLL Enable for 32MHz
    
    UART_setup(BRGH16_DISABLE,HIGH_SPEED,34);   // 57600 baud @ 32MHz
    UART_InitPin_Tx(PORT_B,6);
    UART_InitPin_Rx(PORT_B,5);
    
    while(1)
    {
        UART_WriteString(&MyString[0]);
        __delay_ms(2000);
    }
 
}

