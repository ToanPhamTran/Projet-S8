/*
 * @Name : capt.c
 * @Created on: 17 avr. 2018
 * @Author : PHAM TRAN Toan
 * @Description : Program which regroup the function to get the data by the sensor
 * @Project : HARSH WORK MULTI SENSOR - ESIGELEC PROJECT S8
 * @Environment : Code composer studio
 * @GitHub : https://github.com/ToanPhamTran/Projet-S8
 */

#include <msp430.h> 
#include "ADC.h"
#include "constante.h"

/*
 * main.c
 */
/*...................................................................................*/
/* void InitPort_capt (void)                                                         */
/*...................................................................................*/
/* Description : Initialize the pin use by the sensor                                */
/* Inputs :                                                                          */
/*        void                                                                       */
/* Output : void                							                         */
/*...................................................................................*/

void InitPort_capt(void)
{
		P1SEL &=~ (CAPT_LUM | CAPT_SO | CAPT_VBR | CAPT_CO);
		P1SEL2 &=~ (CAPT_LUM | CAPT_SO | CAPT_VBR | CAPT_CO);
		/*
		 * Les ports definis en tant qu'entree
		 */
		P1DIR &=~ (CAPT_LUM | CAPT_SO | CAPT_VBR | CAPT_CO);
		//P1DIR |= BIT0;
		ADC_init();

		/*
		 *  Les ports definis en tant que sortie
		 */

}

/*...................................................................................*/
/* void Conv_LUM (void)                                                              */
/*...................................................................................*/
/* Description : convert the data received by the sensor on 10 bits with the ADC     */
/* Inputs :                                                                          */
/*          void                                                                     */
/* Output : return tamp a value on 10 bits                							 */
/*...................................................................................*/

uint_16 Conv_LUM(void)
{
	uint_16 tamp;
	ADC_Demarrer_conversion(CAPT_LUM);
	tamp=ADC_Lire_resultat();
	return tamp;
}

/*...................................................................................*/
/* void Conv_SO (void)                                                               */
/*...................................................................................*/
/* Description : convert the data received by the sensor on 10 bits with the ADC     */
/* Inputs :                                                                          */
/*          void                                                                     */
/* Output : return tamp a value on 10 bits                					         */
/*...................................................................................*/

uint_16 Conv_S0(void)
{
	uint_16 tamp;
	ADC_Demarrer_conversion(CAPT_SO);
	tamp=ADC_Lire_resultat();
	return tamp;
}

/*...................................................................................*/
/* void Conv_VBR (void)                                                              */
/*...................................................................................*/
/* Description : convert the data received by the sensor on 10 bits with the ADC     */
/* Inputs :                                                                          */
/*          void                                                                     */
/* Output : return tamp a value on 10 bits                						     */
/*...................................................................................*/

uint_16 Conv_VBR(void)
{
	uint_16 tamp;
	ADC_Demarrer_conversion(CAPT_VBR);
	tamp=ADC_Lire_resultat();
	return tamp;
}

/*...................................................................................*/
/* void Conv_CO (void)                                                               */
/*...................................................................................*/
/* Description : convert the data received by the sensor on 10 bits with the ADC     */
/* Inputs :                                                                          */
/*          void                                                                     */
/* Output : return tamp a value on 10 bits                							 */
/*...................................................................................*/

uint_16 Conv_CO(void)
{
	uint_16 tamp;
	ADC_Demarrer_conversion(CAPT_CO);
	tamp=ADC_Lire_resultat();
	return tamp;
}



