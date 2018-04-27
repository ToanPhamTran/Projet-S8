/*
 * @Name : SPI.c
 * @Created on: 17 avr. 2018
 * @Author : PHAM TRAN Toan
 * @Description : Program which regroup the function for the SPI mode of MSP
 * @Project : HARSH WORK MULTI SENSOR - ESIGELEC PROJECT S8
 * @Environment : Code composer studio
 * @GitHub : https://github.com/ToanPhamTran/Projet-S8
 */

#include <msp430.h>
#include "constante.h"

/*...................................................................................*/
/* void InitSPI_Port(void)                                           	             */
/*...................................................................................*/
/* Description : Initialize the pin use for the SPI mode                             */
/* Inputs :                                                                          */
/*          void                                                                     */
/* Output : void		                                                             */
/*...................................................................................*/

void InitSPI_Port(void)
{

	P1SEL |= (SIMO + SOMI + CLK);
	P1SEL2 |= (SIMO + SOMI + CLK);
}

/*...................................................................................*/
/* void InitSPI_modet(void)                                           	             */
/*...................................................................................*/
/* Description : Initialize the register use for the SPI mode                        */
/* Inputs :                                                                          */
/*         void                                                                      */
/* Output : void			                                                         */
/*...................................................................................*/

void InitSPI_mode(void)
{
	/*
	 * La polarité est configuré par le registre UCCKPL
	 * on configure le sens de direction de l'envoie du bit ici le bit de poid fort en premier
	 */

	UCA0CTL0 |= UCSYNC;
	UCA0CTL0 |= UCMSB;
	//UCA0CTL0 |= UCCKPL;
	UCA0CTL1 &=~ UCSWRST;

	/*
	 * enable USCIO RX interrupt
	 */
	IE2 |= UCA0RXIE;
}

/*...................................................................................*/
/* void TXSPI_data(uint_8 var)                                           	         */
/*...................................................................................*/
/* Description : Transmitter the data which is an unsigned 8 bit integer             */
/* Inputs :                                                                          */
/*          uint var : data to send to master via SPI                                */
/* Output : void			                                                         */
/*...................................................................................*/

void TXSPI_data(uint_8 var)
{
	while (!(IFG2 & UCA0TXIFG));
	UCA0TXBUF= 2*var;
}

/*...................................................................................*/
/* void RXSPI_data(void)                                           	                 */
/*...................................................................................*/
/* Description : Function which receive a data by the Master                         */
/* Inputs :                                                                          */
/*          void                                                                     */
/* Output : return the data receive by the master			                         */
/*...................................................................................*/

uint_8 RXSPI_data()
{
	//while (!(IFG2 & UCA0RXIFG));
	return UCA0RXBUF;
}
