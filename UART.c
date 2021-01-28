/* 
 * File:   UART.c
 * Author: Mario
 *
 */

#include "UART.h"


/******************************************************************************
 * @fn				- UART_setup
 * @brief			- This function initialize the UART Port as asynchronous 
 *                    mode and 8 bit transmition
 *
 * @param[in]		- ENABLE or DISABLE macros
 * @param[in]		- HIGH_SPEED or LOW_SPEED macros
 * @param[in]		- SPBRG value
 *
 * @return			- none
 *
 * @note			- none
 *****************************************************************************/
void UART_setup(uint8_t BRGH16_EnOrDis,uint8_t HighOrLow_Speed, uint16_t SPBRG_value)
{
    TX1STA = 0;
    TX1STAbits.TXEN = 1;                    //Transmit Enable bit
    TX1STAbits.BRGH = HighOrLow_Speed;      //High Baud Rate Select bit
    TX1STAbits.TRMT = 1;
    
    
    RC1STA = 0;
    RC1STAbits.SPEN = 1;                    //SPEN: Serial Port Enable bit
    RC1STAbits.CREN = 1;                    //CREN: Continuous Receive Enable bit 
    
    BAUDCON1bits.BRG16 = BRGH16_EnOrDis;
    
    SPBRGL = (uint8_t)SPBRG_value;
    SPBRGH = (SPBRG_value >> 8);
    
}

void UART_InitPin_Tx(uint8_t PORT_x, uint8_t PinNumber)
{
    
}

void UART_InitPin_Rx(uint8_t PORT_x, uint8_t PinNumber)
{
    
}

void UART_WriteChar(uint8_t data)
{     
   
}

void UART_WriteString(uint8_t *pText)
{
    
}

uint8_t UART_Read(void)
{
    
}

void UART_EnableInterrupts(uint8_t RxOrTx)
{

}

