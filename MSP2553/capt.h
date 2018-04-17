/*
 * @Name : capt.h
 * @Created on: 17 avr. 2018
 * @Author : PHAM TRAN Toan
 * @Description : Program which regroup the function to get the data by the sensor
 * @Project : HARSH WORK MULTI SENSOR - ESIGELEC PROJECT S8
 * @Environment : Code composer studio
 * @GitHub : https://github.com/ToanPhamTran/Projet-S8
 */

#include "ADC.h"
#include "constante.h"

#ifndef CAPTEUR
#define CAPTEUR

/*...................................................................................*/
/* void InitPort_capt (void)                                                         */
/*...................................................................................*/
/* Description : Initialize the pin use by the sensor                                */
/* Inputs :                                                                          */
/*        void                                                                       */
/* Output : void                							                         */
/*...................................................................................*/

void InitPort_capt(void);

/*...................................................................................*/
/* void Conv_LUM (void)                                                              */
/*...................................................................................*/
/* Description : convert the data received by the sensor on 10 bits with the ADC     */
/* Inputs :                                                                          */
/*          void                                                                     */
/* Output : return tamp a value on 10 bits                							 */
/*...................................................................................*/

uint_16 Conv_LUM(void);

/*...................................................................................*/
/* void Conv_SO (void)                                                               */
/*...................................................................................*/
/* Description : convert the data received by the sensor on 10 bits with the ADC     */
/* Inputs :                                                                          */
/*          void                                                                     */
/* Output : return tamp a value on 10 bits                					         */
/*...................................................................................*/

uint_16 Conv_S0(void);

/*...................................................................................*/
/* void Conv_VBR (void)                                                              */
/*...................................................................................*/
/* Description : convert the data received by the sensor on 10 bits with the ADC     */
/* Inputs :                                                                          */
/*          void                                                                     */
/* Output : return tamp a value on 10 bits                						     */
/*...................................................................................*/

uint_16 Conv_VBR(void);

/*...................................................................................*/
/* void Conv_CO (void)                                                               */
/*...................................................................................*/
/* Description : convert the data received by the sensor on 10 bits with the ADC     */
/* Inputs :                                                                          */
/*          void                                                                     */
/* Output : return tamp a value on 10 bits                							 */
/*...................................................................................*/
uint_16 Conv_CO(void);


#endif

