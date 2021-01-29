/* 
 * File:   ADC.c
 * Author: Mario
 *
 */

#include "ADC.h"

/******************************************************************************
 * @fn				- ADC_setup
 * @brief			- This function configure the ADC peripheral
 *                    
 *
 * @param[in]		- ADC_CLK macros
 * @param[in]		- ADC_PVREF macros
 * @param[in]		- ADC_NVREF macros
 *
 * @return			- none
 *
 * @note			- check TAD parameter for don't viloate it with ADC_CLK
 *****************************************************************************/
void ADC_setup(uint8_t ADC_CLK,uint8_t ADC_PVREF,uint8_t ADC_NVREF)
{
    ADCON1bits.ADCS = ADC_CLK;
    ADCON1bits.ADPREF = ADC_PVREF;
    ADCON1bits.ADNREF = ADC_NVREF;
}



/******************************************************************************
 * @fn				- ADC_Format
 * @brief			- This function configure the fustified format of the 
 *                    result
 *                    
 *
 * @param[in]		- ADC_FORMAT_LEFT or ADC_FORMAT_RIGHT
 *
 * @return			- none
 *
 * @note			- none
 *****************************************************************************/
void ADC_Format(uint8_t ADC_FORMAT)
{
    ADCON1bits.ADFM = ADC_FORMAT;
}

void ADC_Init_CH(uint8_t ADC_CH)
{
    switch (ADC_CH)
    {
        case ADC_CH_AN0:
            WPUAbits.WPUA0 = 0;
            ANSELAbits.ANSA0 = 1;
            TRISAbits.TRISA0 = 1;
            break;
        case ADC_CH_AN1:
            WPUAbits.WPUA1 = 0;
            ANSELAbits.ANSA1 = 1;
            TRISAbits.TRISA1 = 1;
            break;
        case ADC_CH_AN2:
            WPUAbits.WPUA2 = 0;
            ANSELAbits.ANSA2 = 1;
            TRISAbits.TRISA2 = 1;
            break;
        case ADC_CH_AN3:
            WPUAbits.WPUA4 = 0;
            ANSELAbits.ANSA4 = 1;
            TRISAbits.TRISA4 = 1;
            break;
        case ADC_CH_AN4:
            WPUCbits.WPUC0 = 0;
            ANSELCbits.ANSC0 = 1;
            TRISCbits.TRISC0 = 1;
            break;
        case ADC_CH_AN5:
            WPUCbits.WPUC1 = 0;
            ANSELCbits.ANSC1 = 1;
            TRISCbits.TRISC1 = 1;
            break;
        case ADC_CH_AN6:
            WPUCbits.WPUC2 = 0;
            ANSELCbits.ANSC2 = 1;
            TRISCbits.TRISC2 = 1;
            break;
        case ADC_CH_AN7:
            WPUCbits.WPUC3 = 0;
            ANSELCbits.ANSC3 = 1;
            TRISCbits.TRISC3 = 1;
            break;
        case ADC_CH_AN8:
            WPUCbits.WPUC6 = 0;
            ANSELCbits.ANSC6 = 1;
            TRISCbits.TRISC6 = 1;
            break;
        case ADC_CH_AN9:
            WPUCbits.WPUC7 = 0;
            ANSELCbits.ANSC7 = 1;
            TRISCbits.TRISC7 = 1;
            break;
        case ADC_CH_AN10:
            WPUBbits.WPUB4 = 0;
            ANSELBbits.ANSB4 = 1;
            TRISBbits.TRISB4 = 1;
            break;
        default:
            WPUBbits.WPUB5 = 0;
            ANSELBbits.ANSB5 = 1;
            TRISBbits.TRISB5 = 1;
            break;
    }
}



/******************************************************************************
 * @fn				- ADC_Read
 * @brief			- This function read the given channel
 *                    
 *                    
 *
 * @param[in]		- ADC_CH macros
 *
 * @return			- reading value
 *
 * @note			- none
 *****************************************************************************/
uint16_t ADC_Read(uint8_t ADC_CH)
{
   
    ADCON0bits.CHS = ADC_CH;
    ADCON0bits.ADON = 1;
    ADCON0bits.GO_nDONE = 1;
    while(ADCON0bits.GO_nDONE);
    ADCON0bits.ADON = 0;
    
    
    return ADRES;
}
