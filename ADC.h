/* 
 * File:   ADC.h
 * Author: Mario
 *
 */

#ifndef ADC_H
#define	ADC_H

#include <stdint.h>
#include <pic16f1709.h>


#define ADC_CLK_FOSCDIV2        0b000
#define ADC_CLK_FOSCDIV4        0b100
#define ADC_CLK_FOSCDIV8        0b001
#define ADC_CLK_FOSCDIV16       0b101
#define ADC_CLK_FOSCDIV32       0b010
#define ADC_CLK_FOSCDIV64       0b110
#define ADC_CLK_FRC             0b111


#define ADC_NVREF_VSS           0
#define ADC_NVREF_EXTERNAL      1

#define ADC_PVREF_VDD           0
#define ADC_PVREF_EXTERNAL      2


#define ADC_FORMAT_LEFT         0
#define ADC_FORMAT_RIGHT        1

#define ADC_CH_AN0              0
#define ADC_CH_AN1              1
#define ADC_CH_AN2              2
#define ADC_CH_AN3              3
#define ADC_CH_AN4              4
#define ADC_CH_AN5              5
#define ADC_CH_AN6              6
#define ADC_CH_AN7              7
#define ADC_CH_AN8              8
#define ADC_CH_AN9              9
#define ADC_CH_AN10             10
#define ADC_CH_AN11             11


#endif	/* ADC_H */

void ADC_setup(uint8_t ADC_CLK,uint8_t ADC_PVREF,uint8_t ADC_NVREF);

void ADC_Format(uint8_t ADC_FORMAT);

void ADC_Init_CH(uint8_t ADC_CH);