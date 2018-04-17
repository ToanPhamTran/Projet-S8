/*
 * @Name : conv.h
 * @Created on: 17 avr. 2018
 * @Author : PHAM TRAN Toan
 * @Description : Program which regroup the function to convert data in unsigned 8 bit integer
 * @Project : HARSH WORK MULTI SENSOR - ESIGELEC PROJECT S8
 * @Environment : Code composer studio
 * @GitHub : https://github.com/ToanPhamTran/Projet-S8
 */
#include "constante.h"
#include <msp430.h>

#ifndef CONVERSION
#define CONVERSION

/*...................................................................................*/
/* void convert_data1 (int data_hex)                                           	     */
/*...................................................................................*/
/* Description : convert the value on an unsigned 8 bit integer                      */
/*               this value has the 5 high bit of the data convert by the ADC        */
/* Inputs :                                                                          */
/*          data hex  : data hex that you want to convert                            */
/* Output : return data 1 value in unsigned 8 bit integer			                 */
/*...................................................................................*/

uint_8 convert_data1 (uint_16 data_hex);

/*...................................................................................*/
/* void convert_data2 (int data_hex)                                           	     */
/*...................................................................................*/
/* Description : convert the value on an unsigned 8 bit integer                      */
/*               this value has the 5 low bit of the data convert by the ADC         */
/* Inputs :                                                                          */
/*          data hex  : data hex that you want to convert                            */
/* Output : return data 2 value in unsigned 8 bit integer                            */
/*...................................................................................*/

uint_8 convert_data2 (uint_16 data_hex);

/*...................................................................................*/
/* uint_8 control_lum1(uint_16 data_hex)                                           	 */
/*...................................................................................*/
/* Description : add 3 bit of control 001 to the data send                           */
/* Inputs :                                                                          */
/*          data hex  : data hex that you want to convert                            */
/* Output : return send_data1, data to send by SPI                                   */
/*...................................................................................*/

uint_8 control_lum1(uint_16 data_hex);

/*...................................................................................*/
/* uint_8 control_lum2(uint_16 data_hex)                                           	 */
/*...................................................................................*/
/* Description : add 3 bit of control 000 to the data send                           */
/* Inputs :                                                                          */
/*          data hex  : data hex that you want to convert                            */
/* Output : return send_data1, data to send by SPI                                   */
/*...................................................................................*/

uint_8 control_lum2(uint_16 data_hex);

/*...................................................................................*/
/* uint_8 control_so1(uint_16 data_hex)                                           	 */
/*...................................................................................*/
/* Description : add 3 bit of control 011 to the data send                           */
/* Inputs :                                                                          */
/*          data hex  : data hex that you want to convert                            */
/* Output : return send_data1, data to send by SPI                                   */
/*...................................................................................*/

uint_8 control_so1(uint_16 data_hex);

/*...................................................................................*/
/* uint_8 control_so2(uint_16 data_hex)                                           	 */
/*...................................................................................*/
/* Description : add 3 bit of control 010 to the data send                           */
/* Inputs :                                                                          */
/*          data hex  : data hex that you want to convert                            */
/* Output : return send_data1, data to send by SPI                                   */
/*...................................................................................*/

uint_8 control_so2(uint_16 data_hex);

/*...................................................................................*/
/* uint_8 control_vbr1(uint_16 data_hex)                                           	 */
/*...................................................................................*/
/* Description : add 3 bit of control 101 to the data send                           */
/* Inputs :                                                                          */
/*          data hex  : data hex that you want to convert                            */
/* Output : return send_data1, data to send by SPI                                   */
/*...................................................................................*/

uint_8 control_vbr1(uint_16 data_hex);

/*...................................................................................*/
/* uint_8 control_vbr2(uint_16 data_hex)                                           	 */
/*...................................................................................*/
/* Description : add 3 bit of control 100 to the data send                           */
/* Inputs :                                                                          */
/*          data hex  : data hex that you want to convert                            */
/* Output : return send_data1, data to send by SPI                                   */
/*...................................................................................*/

uint_8 control_vbr2(uint_16 data_hex);

/*...................................................................................*/
/* uint_8 control_co1(uint_16 data_hex)                                           	 */
/*...................................................................................*/
/* Description : add 3 bit of control 111 to the data send                           */
/* Inputs :                                                                          */
/*          data hex  : data hex that you want to convert                            */
/* Output : return send_data1, data to send by SPI                                   */
/*...................................................................................*/

uint_8 control_co1(uint_16 data_hex);

/*...................................................................................*/
/* uint_8 control_co2(uint_16 data_hex)                                           	 */
/*...................................................................................*/
/* Description : add 3 bit of control 110 to the data send                           */
/* Inputs :                                                                          */
/*          data hex  : data hex that you want to convert                            */
/* Output : return send_data1, data to send by SPI                                   */
/*...................................................................................*/

uint_8 control_co2(uint_16 data_hex);

#endif



