/*
 * @Name : SPI.h
 * @Created on: 17 avr. 2018
 * @Author : PHAM TRAN Toan
 * @Description : Program which regroup the function for the SPI mode of MSP
 * @Project : HARSH WORK MULTI SENSOR - ESIGELEC PROJECT S8
 * @Environment : Code composer studio
 * @GitHub : https://github.com/ToanPhamTran/Projet-S8
 */
#include <msp430.h>
#include "constante.h"

#ifndef SPI
#define SPI

/*...................................................................................*/
/* void InitSPI_Port(void)                                           	             */
/*...................................................................................*/
/* Description : Initialize the pin use for the SPI mode                             */
/* Inputs :                                                                          */
/*          void                                                                     */
/* Output : void		                                                             */
/*...................................................................................*/

void InitSPI_Port(void);

/*...................................................................................*/
/* void InitSPI_modet(void)                                           	             */
/*...................................................................................*/
/* Description : Initialize the register use for the SPI mode                        */
/* Inputs :                                                                          */
/*         void                                                                      */
/* Output : void			                                                         */
/*...................................................................................*/

void InitSPI_mode(void);

/*...................................................................................*/
/* void TXSPI_data(uint_8 var)                                           	         */
/*...................................................................................*/
/* Description : Transmitter the data which is an unsigned 8 bit integer             */
/* Inputs :                                                                          */
/*          uint var : data to send to master via SPI                                */
/* Output : void			                                                         */
/*...................................................................................*/

void TXSPI_data(uint_8 var);

/*...................................................................................*/
/* void RXSPI_data(void)                                           	                 */
/*...................................................................................*/
/* Description : Function which receive a data by the Master                         */
/* Inputs :                                                                          */
/*          void                                                                     */
/* Output : return the data receive by the master			                         */
/*...................................................................................*/

uint_8 RXSPI_data();

#endif
