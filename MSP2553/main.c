#include <msp430.h> 
#include <string.h>
#include <stdio.h>
#include "capt.h"

/*
 * Fonction qui permet d'initialiser les ports du SPI
 */
void InitSPI_Port(void)
{
	P1DIR |= BIT0 ;
	P1OUT &=~ BIT0;

	P1SEL |= (BIT1 + BIT2 +BIT4);
	P1SEL2 |= (BIT1 + BIT2 +BIT4);
}

/*
 * Fonctionn permettant d'initialiser les registres du SPI
 */
void InitSPI_mode(void)
{
	/*
	 * La polarité est configuré par le registre UCCKPL
	 * on configure le sens de direction de l'envoie du bit ici le bit de poid fort en premier
	 */

	UCA0CTL0 |=  UCMSB + UCSYNC;
	//UCA0CTL0 |= UCCKPL;
	UCA0CTL1 &=~ UCSWRST;

	/*
	 * enable USCIO RX interrupt
	 */
	IE2 |= UCA0RXIE;
}

/*
 * Fonction permettant de transmettre un caractère au maitre
 */
void TXSPI_data(unsigned char c)
{
	while (!(IFG2 & UCA0TXIFG));
	UCA0TXBUF=2*c;
}

void TXSPI_int(int c)
{
	while (!(IFG2 & UCA0TXIFG));
	UCA0TXBUF=2*c;
}

/*
 * Fonction permettant de recevoir un caractère du maitre
 */

unsigned char RXSPI_data()
{
	//while (!(IFG2 & UCA0RXIFG));
	return UCA0RXBUF;
}

void Send_data_test()
{
	//unsigned char send ;
	int tamp;
	int var;
	int data1;
	//int data2;
	var = Capt_detection(3);
	tamp = (uint8_t)(0xFF&var);
	data1= var <<8;
	//data1 = var >>8;
	//send =(data_test & ( 0x00F0))>>0x04;
	//send = (unsigned char)test << 8;
	TXSPI_data('e');
	TXSPI_int(var);
	//TXSPI_data('1');
	TXSPI_data('0');
	TXSPI_int(data1);
	//TXSPI_data('3');
}
int main(void)
{
    WDTCTL = WDTPW + WDTHOLD;	// Stop watchdog timer
    InitSPI_Port();
    InitPort_capt();
    InitSPI_mode();
    __enable_interrupt();
    while(1);
}

#pragma vector = USCIAB0RX_VECTOR
__interrupt void USCI0RX_ISR(void)
{
	unsigned char tamp;
	//var= Capt_detection(BIT3);
	//char send_data[100];
	//unsigned char test;
	if (IFG2 & UCA0RXIFG)
	{
		tamp=	UCA0RXBUF;
		if (tamp & 0x60)
		{
			P1OUT ^= BIT0;
			//test = '1023';
			//TXSPI_data(var);
			Send_data_test();
			//send_data[2]= 'le';
		}
		else
		{
			P1OUT &=~ BIT0;
		}

	}
}
