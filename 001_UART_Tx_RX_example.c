/* 
 * File:   001_UART_Tx_RX_example.c
 * Author: Mario
 * Brief:  Echo program @ 57600 Baud
 */

#include <stdint.h>
#include "ConfigBits.h"
#include "UART.h"

#define _XTAL_FREQ 32000000


uint8_t data = 0;
int main() {
  
    OSCCONbits.IRCF = 0b1110;   //8MHZ internal clock
    OSCCONbits.SPLLEN = 1;      //PLL Enable for 32MHz
    
    UART_setup(BRGH16_DISABLE,HIGH_SPEED,34);   // 57600 baud @ 32MHz
    UART_InitPin_Tx(PORT_B,6);
    UART_InitPin_Rx(PORT_B,4);
   
    
    while(1)
    {
        if(data = UART_Read())
        {   
            UART_WriteChar(data);
        }
        
    }
}
