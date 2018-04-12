#include <wiringPiSPI.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>


int main ()
{
	/*
	* channel is the wiringpi name for the chipselect pin 
	* This pin is set to 0 or 1 , depending how  it's connected
	*/
	static const int  CHANNEL = 0 ;
	unsigned char buffer[100];
	int i;
	//buffer[0] = 0x6C;
	//buffer[1] = 0x6D;
	//buffer[2] = 0x6E;
	//buffer[3] = 0x6F;
	//buffer[4] = 0x70;
	printf("début du programme spi mode \n");
	wiringPiSPISetup(CHANNEL, 500000);
	printf("test \n");
	for( i=0 ; i< 3; i++)
	{
	buffer[1]= 0x6C;
	wiringPiSPIDataRW(CHANNEL,buffer,1);
	printf("%c\n",buffer[1]);
	
	buffer[2] = 0x6D;
	wiringPiSPIDataRW(CHANNEL, buffer,1);
	printf("%c \n", buffer[2]);

	buffer[3] = 0x6E;
	wiringPiSPIDataRW(CHANNEL, buffer,1);
	printf("%c \n", buffer[3]); 
	
	sleep (5);
	}	
	printf("fin du programme \n");	
}
