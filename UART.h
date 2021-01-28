/* 
 * File:   UART.h
 * Author: Mario
 *
 */

#ifndef UART_H
#define	UART_H

#include <stdint.h>
#include <pic16f1709.h>



#define BRGH16_ENABLE       1
#define BRGH16_DISABLE      0

#define HIGH_SPEED          1
#define LOW_SPEED           0

/******************************************************************************
 * 						APIs supported by this driver
 *****************************************************************************/

void UART_setup(uint8_t BRGH16_EnOrDis,uint8_t HighOrLow_Speed, uint16_t SPBRG_value);
void UART_InitPin_Tx(uint8_t PORT_x, uint8_t PinNumber);
void UART_InitPin_Rx(uint8_t PORT_x, uint8_t PinNumber);

void UART_WriteChar(uint8_t data);
void UART_WriteString(uint8_t *pText);

uint8_t UART_Read(void);


void UART_EnableInterrupts(uint8_t RxOrTx);



#endif	/* UART_H */

