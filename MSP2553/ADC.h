/*
 * @Name : ADC.h
 * @Created on: 17 avr. 2018
 * @Author : ESIGELEC
 * @Description : Program which regroup the function to convert a data
 * @Project : HARSH WORK MULTI SENSOR - ESIGELEC PROJECT S8
 * @Environment : Code composer studio
 * @GitHub : https://github.com/ToanPhamTran/Projet-S8
 */
#include "constante.h"
#ifndef ADC
#define ADC
/*...................................................................................*/
/* void ADC_init (void)                                                              */
/*...................................................................................*/
/* Description : Initialize the register use for the ADC                             */
/* Inputs :                                                                          */
/*        void                                                                       */
/* Output : void                							                         */
/*...................................................................................*/

void ADC_init(void);

/*...................................................................................*/
/* void ADC_Demarrer_conversion (void)                                               */
/*...................................................................................*/
/* Description : start the conversion of the ADC                                     */
/* Inputs :                                                                          */
/*        voie : unsigned 8 bit integer                                              */
/* Output : void                							                         */
/*...................................................................................*/

void ADC_Demarrer_conversion(uint_8 voie);
 
/*...................................................................................*/
/* void ADC_Lire_resultat(void)                                                      */
/*...................................................................................*/
/* Description : Read the result                                                     */
/* Inputs :                                                                          */
/*        unsigned char voie                                                         */
/* Output : return the conversion value on 10 bit                	                 */
/*...................................................................................*/

uint_16 ADC_Lire_resultat ();

#endif
