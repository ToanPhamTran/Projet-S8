#include <msp430.h>
#include "SPI.h"
#include "conv.h"
#include "constante.h"
#include "ADC.h"
#include "capt.h"

void main ()
{
	WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer
	P1DIR |= LED;
	InitSPI_Port();
	InitPort_capt();
	InitSPI_mode();

	__enable_interrupt();
	while(1)
}
#pragma vector = USCIAB0RX_VECTOR
__interrupt void USCI0RX_ISR(void)
{

	uint_16 valeur_test;
	uint_8 tamp;
	uint_8 send_data1;
	uint_8 send_data2;
	valeur_test = Conv_SO();
	send_data1= control_so1(valeur_test);
	send_data2= control_so2(valeur_test);

	if (IFG2 & UCA0RXIFG)
	{
		tamp = UCA0RXBUF;
		if (tamp == 0X32)
		{
			TXSPI_data(send_data1);
		}

		if (tamp == 0x33)
		{
			TXSPI_data(send_data2)
		}
	}
}
