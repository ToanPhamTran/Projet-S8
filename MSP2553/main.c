#include <msp430.h>
#include "SPI.h"
#include "conv.h"
#include "constante.h"
#include "ADC.h"
#include "capt.h"

void main ()
{
	uint_8 test, test1,test2;
	uint_16 valeur;
	WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer
	P1DIR |= LED;
	InitSPI_Port();
	InitPort_capt();
	InitSPI_mode();
	/*valeur = Conv_CO();
	test= convert_data1(valeur);
	test1=control_co1(valeur);
	test2=control_co2(valeur);*/

	__enable_interrupt();
	while(1);
}
#pragma vector = USCIAB0RX_VECTOR
__interrupt void USCI0RX_ISR(void)
{

	uint_16 valeur_so,valeur_co, valeur_lum, valeur_vbr;
	uint_8 tamp;
	uint_8 send_data1;
	uint_8 send_data2;
	valeur_lum=Conv_LUM();
	valeur_so = Conv_SO();
	valeur_co = Conv_CO();
	valeur_vbr=Conv_VBR();

	if (IFG2 & UCA0RXIFG)
	{
		tamp = UCA0RXBUF;
		if (tamp == 0X30)
		{
			send_data1=control_lum1(valeur_lum);
			TXSPI_data(send_data1);
		}
		if (tamp == 0X31)
		{
			send_data2=control_lum2(valeur_lum);
			TXSPI_data(send_data2);
		}
		if (tamp == 0X32)
		{
			send_data1=control_so1(valeur_so);
			TXSPI_data(send_data1);
		}
		if (tamp == 0X33)
		{
			send_data2=control_so2(valeur_so);
			TXSPI_data(send_data2);
		}
		if (tamp == 0X34)
		{
			send_data1=control_vbr1(valeur_vbr);
			TXSPI_data(send_data1);
		}
		if (tamp == 0X35)
		{
			send_data2=control_vbr2(valeur_vbr);
			TXSPI_data(send_data2);
		}
		if (tamp == 0X36)
		{
			send_data1=control_co1(valeur_co);
			//UCA0TXBUF = send_data1;
			TXSPI_data(send_data1);
		}
		if (tamp == 0X37)
		{
			send_data2=control_co2(valeur_co);
			//UCA0TXBUF = send_data2;
			TXSPI_data(send_data2);
		}
		//UCA0TXBUF=0;
		//send_data1=0;
		//send_data2=0;
	}
}
