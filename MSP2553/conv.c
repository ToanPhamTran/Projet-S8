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
/* void convert_data1 (int data_16)                                           	     */
/*...................................................................................*/
/* Description : convert the value on an unsigned 8 bit integer                      */
/*               this value has the 5 high bit of the data convert by the ADC        */
/* Inputs :                                                                          */
/*          data_16  : data_16 that you want to convert                            */
/* Output : return data 2 value in unsigned 8 bit integer                            */
/*...................................................................................*/

uint_8 convert_data1(uint_16 data_16)
{
	uint_8 data1;
	data1 = (uint_8)(0xFF & (data_16 >>5));
	return data1;
}

/*...................................................................................*/
/* void convert_data2 (int data_16)                                           	     */
/*...................................................................................*/
/* Description : convert the value on an unsigned 8 bit integer                      */
/*               this value has the 5 low bit of the data convert by the ADC         */
/* Inputs :                                                                          */
/*          data_16 : data_16 that you want to convert                            */
/* Output : return data 2 value in unsigned 8 bit integer                            */
/*...................................................................................*/

uint_8 convert_data2 (uint_16 data_16)
{
	uint_16 trans = 0xFFE0;
	uint_16 trans1= 0x001F;
	uint_16 tamp, tamp1;
	uint_8  data2;

	tamp= (data_16 | trans);
	tamp1 = (tamp & trans1);
	data2 = (uint_8)(0xFF & tamp1);

	return data2;
}

/*...................................................................................*/
/* uint_8 control_lum1(uint_16 data_16)                                           	 */
/*...................................................................................*/
/* Description : add 3 bit of control 001 to the data send                           */
/* Inputs :                                                                          */
/*          data_16  : data_16 that you want to convert                            */
/* Output : return send_data1, data to send by SPI                                   */
/*...................................................................................*/

uint_8 control_lum1(uint_16 data_16)
{
	uint_8 send_data1, var;
	var = convert_data1(data_16);

	send_data1= (uint_8)(0x20 | var);

	return send_data1;
}

/*...................................................................................*/
/* uint_8 control_lum2(uint_16 data_16)                                           	 */
/*...................................................................................*/
/* Description : add 3 bit of control 000 to the data send                           */
/* Inputs :                                                                          */
/*          data_16: data_16 that you want to convert                            */
/* Output : return send_data1, data to send by SPI                                   */
/*...................................................................................*/

uint_8 control_lum2(uint_16 data_16)
{
	uint_8 send_data2, var;
	var = convert_data2(data_16);

	send_data2= (uint_8)(0x00 | var);

	return send_data2;
}

/*...................................................................................*/
/* uint_8 control_so1(uint_16 data_16)                                           	 */
/*...................................................................................*/
/* Description : add 3 bit of control 011 to the data send                           */
/* Inputs :                                                                          */
/*          data_16  : data_16 that you want to convert                            */
/* Output : return send_data1, data to send by SPI                                   */
/*...................................................................................*/

uint_8 control_so1(uint_16 data_16)
{
	uint_8 send_data1, var;
	var = convert_data1(data_16);

	send_data1= (uint_8)(0x60 | var);

	return send_data1;
}

/*...................................................................................*/
/* uint_8 control_so2(uint_16 data_16)                                           	 */
/*...................................................................................*/
/* Description : add 3 bit of control 010 to the data send                           */
/* Inputs :                                                                          */
/*          data_16: data_16 that you want to convert                            */
/* Output : return send_data1, data to send by SPI                                   */
/*...................................................................................*/

uint_8 control_so2(uint_16 data_16)
{
	uint_8 send_data2, var;
	var = convert_data2(data_16);

	send_data2= (uint_8)(0x40 | var);
	return send_data2;
}

/*...................................................................................*/
/* uint_8 control_vbr1(uint_16 data_16)                                           	 */
/*...................................................................................*/
/* Description : add 3 bit of control 101 to the data send                           */
/* Inputs :                                                                          */
/*          data_16  : data_16 that you want to convert                            */
/* Output : return send_data1, data to send by SPI                                   */
/*...................................................................................*/

uint_8 control_vbr1(uint_16 data_16)
{
	uint_8 send_data1, var;
	var = convert_data1(data_16);

	send_data1= (uint_8)(0xA0 | var);

	return send_data1;
}

/*...................................................................................*/
/* uint_8 control_vbr2(uint_16 data_16)                                           	 */
/*...................................................................................*/
/* Description : add 3 bit of control 100 to the data send                           */
/* Inputs :                                                                          */
/*          data_16 : data_16 that you want to convert                            */
/* Output : return send_data1, data to send by SPI                                   */
/*...................................................................................*/

uint_8 control_vbr2(uint_16 data_16)
{
	uint_8 send_data2, var;
	var = convert_data2(data_16);

	send_data2= (uint_8)(0x80 | var);
	return send_data2;
}

/*...................................................................................*/
/* uint_8 control_co1(uint_16 data_16)                                           	 */
/*...................................................................................*/
/* Description : add 3 bit of control 111 to the data send                           */
/* Inputs :                                                                          */
/*          data_16  : data_16 that you want to convert                            */
/* Output : return send_data1, data to send by SPI                                   */
/*...................................................................................*/

uint_8 control_co1(uint_16 data_16)
{
	uint_8 send_data1, var;
	var = convert_data1(data_16);

	send_data1= (uint_8)(0xE0 | var);

	return send_data1;
}

/*...................................................................................*/
/* uint_8 control_co2(uint_16 data_16)                                           	 */
/*...................................................................................*/
/* Description : add 3 bit of control 110 to the data send                           */
/* Inputs :                                                                          */
/*         data_16  : data_16 that you want to convert                            */
/* Output : return send_data1, data to send by SPI                                   */
/*...................................................................................*/

uint_8 control_co2(uint_16 data_16)
{
	uint_8 send_data2, var;
	var = convert_data2(data_16);

	send_data2= (uint_8)(0xC0 | var);
	return send_data2;

}



