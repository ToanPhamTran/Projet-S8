/*
 * @Name : conv.c
 * @Created on: 17 avr. 2018
 * @Author : PHAM TRAN Toan
 * @Description : Program which regroup the function use to convert data
 * @Project : HARSH WORK MULTI SENSOR - ESIGELEC PROJECT S8
 * @Environment : Code composer studio
 * @GitHub : https://github.com/ToanPhamTran/Projet-S8
 */
#include "msp430.h"
#include "constante.h"

/*...................................................................................*/
/* void convert_data1 (int data_hex)                                           	     */
/*...................................................................................*/
/* Description : convert the value on an unsigned 8 bit integer                      */
/*               this value has the 5 high bit of the data convert by the ADC        */
/* Inputs :                                                                          */
/*          data hex  : data hex that you want to convert                            */
/* Output : return data 2 value in unsigned 8 bit integer                            */
/*...................................................................................*/

uint_8 convert_data1(uint_16 data_hex)
{
	uint_8 data1;
	data1 = (uint_8)(0xFF & (data_hex >>5));
	return data1;
}

/*...................................................................................*/
/* void convert_data2 (int data_hex)                                           	     */
/*...................................................................................*/
/* Description : convert the value on an unsigned 8 bit integer                      */
/*               this value has the 5 low bit of the data convert by the ADC         */
/* Inputs :                                                                          */
/*          data hex  : data hex that you want to convert                            */
/* Output : return data 2 value in unsigned 8 bit integer                            */
/*...................................................................................*/

uint_8 convert_data2 (uint_16 data_hex)
{
	uint_16 trans = 0xFFE0;
	uint_16 trans1= 0x001F;
	uint_16 tamp, tamp1;
	uint_8  data2;

	tamp= (data_hex | trans);
	tamp1 = (tamp & trans1);
	data2 = (uint_8)(0xFF & tamp1);

	return data2;
}

/*...................................................................................*/
/* uint_8 control_lum1(uint_16 data_hex)                                           	 */
/*...................................................................................*/
/* Description : add 3 bit of control 001 to the data send                           */
/* Inputs :                                                                          */
/*          data hex  : data hex that you want to convert                            */
/* Output : return send_data1, data to send by SPI                                   */
/*...................................................................................*/

uint_8 control_lum1(uint_16 data_hex)
{
	uint_8 send_data1, var;
	var = convert_data1(data_hex);

	send_data1= (uint_8)(0xDF & var);

	return send_data1;
}

/*...................................................................................*/
/* uint_8 control_lum2(uint_16 data_hex)                                           	 */
/*...................................................................................*/
/* Description : add 3 bit of control 000 to the data send                           */
/* Inputs :                                                                          */
/*          data hex  : data hex that you want to convert                            */
/* Output : return send_data1, data to send by SPI                                   */
/*...................................................................................*/

uint_8 control_lum2(uint_16 data_hex)
{
	uint_8 send_data2, var;
	var = convert_data2(data_hex);

	send_data2= (uint_8)(0xFF & var);

	return send_data2;
}

/*...................................................................................*/
/* uint_8 control_so1(uint_16 data_hex)                                           	 */
/*...................................................................................*/
/* Description : add 3 bit of control 011 to the data send                           */
/* Inputs :                                                                          */
/*          data hex  : data hex that you want to convert                            */
/* Output : return send_data1, data to send by SPI                                   */
/*...................................................................................*/

uint_8 control_so1(uint_16 data_hex)
{
	uint_8 send_data1, var;
	var = convert_data1(data_hex);

	send_data1= (uint_8)(0xAF & var);

	return send_data1;
}

/*...................................................................................*/
/* uint_8 control_so2(uint_16 data_hex)                                           	 */
/*...................................................................................*/
/* Description : add 3 bit of control 010 to the data send                           */
/* Inputs :                                                                          */
/*          data hex  : data hex that you want to convert                            */
/* Output : return send_data1, data to send by SPI                                   */
/*...................................................................................*/

uint_8 control_so2(uint_16 data_hex)
{
	uint_8 send_data2, var;
	var = convert_data2(data_hex);

	send_data2= (uint_8)(0xBF & var);
	return send_data2;
}

/*...................................................................................*/
/* uint_8 control_vbr1(uint_16 data_hex)                                           	 */
/*...................................................................................*/
/* Description : add 3 bit of control 101 to the data send                           */
/* Inputs :                                                                          */
/*          data hex  : data hex that you want to convert                            */
/* Output : return send_data1, data to send by SPI                                   */
/*...................................................................................*/

uint_8 control_vbr1(uint_16 data_hex)
{
	uint_8 send_data1, var;
	var = convert_data1(data_hex);

	send_data1= (uint_8)(0x5F & var);

	return send_data1;
}

/*...................................................................................*/
/* uint_8 control_vbr2(uint_16 data_hex)                                           	 */
/*...................................................................................*/
/* Description : add 3 bit of control 100 to the data send                           */
/* Inputs :                                                                          */
/*          data hex  : data hex that you want to convert                            */
/* Output : return send_data1, data to send by SPI                                   */
/*...................................................................................*/

uint_8 control_vbr2(uint_16 data_hex)
{
	uint_8 send_data2, var;
	var = convert_data2(data_hex);

	send_data2= (uint_8)(0x7F & var);
	return send_data2;
}

/*...................................................................................*/
/* uint_8 control_co1(uint_16 data_hex)                                           	 */
/*...................................................................................*/
/* Description : add 3 bit of control 111 to the data send                           */
/* Inputs :                                                                          */
/*          data hex  : data hex that you want to convert                            */
/* Output : return send_data1, data to send by SPI                                   */
/*...................................................................................*/

uint_8 control_co1(uint_16 data_hex)
{
	uint_8 send_data1, var;
	var = convert_data1(data_hex);

	send_data1= (uint_8)(0x1F & var);

	return send_data1;
}

/*...................................................................................*/
/* uint_8 control_co2(uint_16 data_hex)                                           	 */
/*...................................................................................*/
/* Description : add 3 bit of control 110 to the data send                           */
/* Inputs :                                                                          */
/*          data hex  : data hex that you want to convert                            */
/* Output : return send_data1, data to send by SPI                                   */
/*...................................................................................*/

uint_8 control_co2(uint_16 data_hex)
{
	uint_8 send_data2, var;
	var = convert_data2(data_hex);

	send_data2= (uint_8)(0x3F & var);
	return send_data2;

}



