/*
*@Description :Programme permettant la communication SPI du Raspberry PI 3 Model B
*@Projet : HARSH WORK MULTISENSOR - ESIGELEC
*@auteur : Toan PHAM TRAN & Guillaume MONGIS
*/
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
	static const int TAILLE = 100;
	static const int  CHANNEL = 0 ;
	/*
	*Declaration des variables  du programme
	*/
	unsigned char buffer[TAILLE];
	int i;
	/*
	******************************************
	*/

	//buffer[0] = 0x6C;
	//buffer[1] = 0x6D;
	//buffer[2] = 0x6E;
	//buffer[3] = 0x6F;
	//buffer[4] = 0x70;

	printf("Début du programme spi mode \n");
	wiringPiSPISetup(CHANNEL, 500000);
	printf("Le SPI mode est set  \n");
	for( i=0 ; i< 10; i++)	
	{ 
		/*
		* On stocke le caractère 'a' dans le buffer pour l'envoyer
		* au MSP (SLAVE)
		*/
		buffer[0]= 0x61;
		printf("La valeur du buffer 0 avant envoie est (string) : %c\n",buffer[0]);
		printf("La valeur du buffer 0 avant envoie est(int): %d\n", buffer[0]);
		buffer[1] = i;

		/*
		*Le Raspberry envoie un caractere au MSP
		*/
		printf("Le Raspberry envoie un caractere %c\n",buffer[0]);
		wiringPiSPIDataRW(CHANNEL,buffer,1);
		/*
		* Le buffer stocke la valeur TX du MSP à partir 
		*de la deuxième itération
		*/
		printf("La valeur du buffer après envoie est (string) : %c\n", buffer[0]); 
		printf("La valeur du buffer après envoie  est (int) : %d\n",buffer[0]);
		sleep(5);
		/*
		* Le buffer contient la valeur de TXDATA du MSP et on fait 
		* la comparaison
		*/
		if ((buffer[0]) == (0x6C))
		{
			printf ("Communication réussi\n\n");
			/*
			* Il faut clear tout le buffer
			* on clear le buffer
			*/	
			buffer[0]=0x76;
		}
		else
		{
			printf("Communication fail \n\n");
			buffer[0]= 0x76;
		}
	}
		
	printf("Fin du programme \n");	
}


