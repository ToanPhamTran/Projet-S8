#include <msp430.h> 
#include "ADC.h"

/*
 * main.c
 */

void InitPort_capt(void)
{
		P1SEL &=~ (BIT3 | BIT5 | BIT6 | BIT7);
		P1SEL2 &=~ (BIT3 | BIT5 | BIT6 | BIT7);
		P2SEL &=~ (BIT1 | BIT2);
		P2SEL2 &=~ (BIT1 | BIT2);
		/*
		 * Les ports definis en tant qu'entree
		 */
		P1DIR &=~ (BIT3 | BIT5 | BIT6 | BIT7);
		//P1DIR |= BIT0;
		ADC_init();

		/*
		 *  Les ports definis en tant que sortie
		 */

}
int Capt_detection(int pin)
{
	int tamp;
	ADC_Demarrer_conversion(pin);
	tamp=ADC_Lire_resultat();
	return tamp;
}

