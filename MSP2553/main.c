/*
 * @Name : main.c
 * @Created on: 17 avr. 2018
 * @Author : PHAM TRAN Toan
 * @Description : Main program
 * @Project : HARSH WORK MULTI SENSOR - ESIGELEC PROJECT S8
 * @Environment : Code composer studio
 * @GitHub : https://github.com/ToanPhamTran/Projet-S8
 */

#include <msp430.h> 
#include <string.h>
#include <stdio.h>
#include "capt.h"
#include "constante.h"
#include "SPI.h"
#include "conv.h"

void Send_data_test()
{
	//unsigned char send ;
	TXSPI_data('e');
	TXSPI_data('0');

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
			P1OUT ^= LED;
			//test = '1023';
			//TXSPI_data(var);
			Send_data_test();
			//send_data[2]= 'le';
		}
		else
		{
			P1OUT &=~ LED;
		}

	}
}
