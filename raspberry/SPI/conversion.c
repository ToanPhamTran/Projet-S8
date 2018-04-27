#include <stdio.h>
#include <string.h>
#include "conversion.h"

int data_lum(unsigned short hight, unsigned short low)
{
	unsigned short data_hight, data_low;
	unsigned short data_tampon = 0x0000; 
	unsigned short data_tampon2 = 0x0000;
	unsigned short result;
	data_hight = (unsigned short)(0xDF & hight);
	data_low = (unsigned short)(0xFF & low);
	
	data_tampon2 = (unsigned short)(data_tampon | data_low);
	result = (unsigned short)(data_tampon2 | data_hight<<5);
	
	return result;
}

int data_so(unsigned short hight, unsigned short low)
{
	unsigned short data_hight, data_low;
	unsigned short data_tampon = 0x0000; 
	unsigned short data_tampon2 = 0x0000;
	unsigned short result;
	data_hight = (unsigned short)(0x9F & hight);
	data_low = (unsigned short)(0xBF & low);
	
	data_tampon2 = (unsigned short)(data_tampon | data_low);
	result = (unsigned short)(data_tampon2 | data_hight<<5);
	
	return result;
}

int data_vbr(unsigned short hight, unsigned short low)
{
	unsigned short data_hight, data_low;
	unsigned short data_tampon = 0x0000; 
	unsigned short data_tampon2 = 0x0000;
	unsigned short result;
	data_hight = (unsigned short)(0x5F & hight);
	data_low = (unsigned short)(0x7F & low);
	
	data_tampon2 = (unsigned short)(data_tampon | data_low);
	result = (unsigned short)(data_tampon2 | data_hight<<5);
	
	return result;
}

int data_co(unsigned short hight, unsigned short low)
{
	unsigned short data_hight, data_low;
	unsigned short data_tampon = 0x0000; 
	unsigned short data_tampon2 = 0x0000;
	unsigned short result;
	data_hight = (unsigned short)(0x1F & hight);
	data_low = (unsigned short)(0x3F & low);
	
	data_tampon2 = (unsigned short)(data_tampon | data_low);
	result = (unsigned short)(data_tampon2 | data_hight<<5);
	
	return result;
}



