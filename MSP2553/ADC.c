/*
 * @Name : ADC.h
 * @Created on: 17 avr. 2018
 * @Author : ESIGELEC
 * @Description : Program which regroup the function to convert a data
 * @Project : HARSH WORK MULTI SENSOR - ESIGELEC PROJECT S8
 * @Environment : Code composer studio
 * @GitHub : https://github.com/ToanPhamTran/Projet-S8
 */

#include "msp430.h"
#include "constante.h"

/*...................................................................................*/
/* void ADC_init (void)                                                              */
/*...................................................................................*/
/* Description : Initialize the register use for the ADC                             */
/* Inputs :                                                                          */
/*        void                                                                       */
/* Output : void                							                         */
/*...................................................................................*/

void ADC_init(void)
{
	  ADC10CTL0 = ADC10CTL1 = 0;

// Choix de la référence de tension Vcc GND
// Référence interne active et générateur à 2,5 Volts  ADC10 actif
// Les autres bits sont supposés à 0 

	  ADC10CTL0 =  SREF_0 + ADC10SHT_0  + REF2_5V + REFON + ADC10ON;  ;  

// Choix du diviseur par 1 pour l'horloge, démarrage conversion logiciel
// Horloge de conversion 1MHz, conversion monovoie-monocoup	

	  ADC10CTL1 =  ADC10DIV_0 + ADC10SSEL_2 +  SHS_0 + CONSEQ_0 ;

}

/*...................................................................................*/
/* void ADC_Demarrer_conversion (void)                                               */
/*...................................................................................*/
/* Description : start the conversion of the ADC                                     */
/* Inputs :                                                                          */
/*        voie : unsigned 8 bit integer                                              */
/* Output : void                							                         */
/*...................................................................................*/

void ADC_Demarrer_conversion(uint_8 voie)
{
     ADC10CTL1 = (voie * 0x1000)+ ADC10DIV_0 + ADC10SSEL_2 +  SHS_0 + CONSEQ_0 ;
    ADC10CTL0 |= ENC + ADC10SC;     // Sampling and conversion start
 }  

/*...................................................................................*/
/* void ADC_Lire_resultat(void)                                                      */
/*...................................................................................*/
/* Description : Read the result                                                     */
/* Inputs :                                                                          */
/*        unsigned char voie                                                         */
/* Output : return the conversion value on 10 bit                	                 */
/*...................................................................................*/

uint_16 ADC_Lire_resultat ()
{
  	while (ADC10CTL1 & ADC10BUSY);	// Tant que ADC occupé on attend
	ADC10CTL0 &= ~ENC;		// Conversion finie alors Disable ADC conversion

    	return ADC10MEM;	        // Return Conversion value
}
