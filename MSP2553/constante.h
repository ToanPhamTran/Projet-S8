/*
 * @Name : constante.h
 * @Created on: 17 avr. 2018
 * @Author : PHAM TRAN Toan
 * @Description : Program which declare the name of the variable and the port use on the MSP
 * 				  and the type of the variable use on this projet
 * @Project : HARSH WORK MULTI SENSOR - ESIGELEC PROJECT S8
 * @Environment : Code composer studio
 * @GitHub : https://github.com/ToanPhamTran/Projet-S8
 */

#ifndef CONSTANTE
#define CONSTANTE
/*
 * Schema of the MSP :
 *    				      MSP430G253
 *                      -----------------
 *              SOMI <-|P1.1             |
 *              SIMO ->|P1.2             |
 * Luminosity Sensor ->|P1.3             |
 *     CLK RASPBERRY ->|P1.4         P1.7|<- Carbon monoxide Sensor
 *      Sound Sensor ->|P1.5        P1.6 |<- Vibration Sensor
 */
/*
 * Declaration of all the type use in the project
 * ******************************************************************
 */

/*
 * unsigned 8 bit integer
 * min = 0
 * max = 255
 */
typedef unsigned char uint_8;

/*
 * unsigned char 16 bit integer
 * min = 0
 * max = 65535
 */
typedef unsigned short uint_16;

/*
 * *******************************************************************
 */

 /*
  * Declaration of all the port use by the SPI communication & pother
  */
#define LED BIT0
#define SIMO BIT1
#define SOMI BIT2
#define CLK BIT4

/*
 * ********************************************************************
 */

/*
 * Declaration of all the port use by the Sensor in the project
 */
#define CAPT_LUM BIT3
#define CAPT_SO	 BIT5
#define CAPT_VBR BIT6
#define CAPT_CO  BIT7


#endif




