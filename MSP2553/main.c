#include <msp430.h> 

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

	UCA0CTL1 = UCMSB + UCSYNC;
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
	UCA0TXBUF=c;
}

/*
 * Fonction permettant de recevoir un caractère du maitre
 */

unsigned char RXSPI_data()
{
	while (!(IFG2 & UCA0RXIFG));
	return UCA0RXBUF;
}

int main(void)
{
    WDTCTL = WDTPW + WDTHOLD;	// Stop watchdog timer
    InitSPI_Port();
    InitSPI_mode();
    __enable_interrupt();
    while(1);
}

#pragma vector = USCIAB0RX_VECTOR
__interrupt void USCI0RX_ISR(void)
{
	unsigned char tamp;
	tamp = RXSPI_data();
	if (0x60 & tamp)
	{
		P1OUT |= BIT0;
	}
	else
	{
		P1OUT &=~ BIT0;
	}
}
