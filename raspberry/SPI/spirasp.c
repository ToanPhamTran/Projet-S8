
/*
*@Description :Programme permettant la communication SPI du Raspberry PI 3 Model B
*@Projet : HARSH WORK MULTISENSOR - ESIGELEC
*@auteur : Toan PHAM TRAN & Guillaume MONGIS
*/
#include <wiringPiSPI.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include "conversion.h"
#include "fic.h"
int main ()
{
	/*
	* channel is the wiringpi name for the chipselect pin 
	* This pin is set to 0 or 1 , depending how  it's connected
	*/
	static const int TAILLE = 1000;
	static const int CHANNEL = 0 ;
	static const int TEMPS = 2;
	/*
	*Declaration des variables  du programme
	*/
	unsigned char buffer[TAILLE];
	int j=2;
	unsigned short data_lum1;
      	unsigned short data_lum2;
	unsigned short data_so1;
	unsigned short data_so2;
	unsigned short data_vbr1;
	unsigned short data_vbr2;
	unsigned short data_co1;
	unsigned short data_co2;
	unsigned short data1= 0x0000;
	unsigned short data2=0x0000;
	unsigned short result_lum;
	unsigned short result_so;
	unsigned short result_vbr;
	unsigned short result_co;
	
	/****************************************/

	printf("Début du programme spi mode \n");
	creation();
	initialisation();
	wiringPiSPISetup (CHANNEL, 500000);
	printf("Le SPI mode est set  \n");
       	//for(;;)
	do
	{ 
		buffer[0]= 0x30;
		printf("La valeur du buffer 0 avant envoie est (string) : %c\n",buffer[0]);

		/*
		*Le Raspberry envoie la commande 0x30
		*/
		wiringPiSPIDataRW(CHANNEL,buffer,1);
		printf("La valeur du buffer 0 après envoie est (string) : %c\n",buffer[0]);
		/*
		* Le buffer contient la valeur de TXDATA du MSP et on fait 
		* la comparaison data co2
		*/
		
			if ( ((buffer[0]) &  0x60 ) && (!((buffer[0]) & 0x20)))
			{

				data_co2 = buffer[0];
				printf ("data moxoxyde faible  réussi: %c\n\n",buffer[0]);
				/*
				* Il faut clear tout le buffer
				* on clear le buffer
				*/	
				buffer[0]=0x76;
			}
			else
			{
				printf("data monoxyde faible fail \n\n");
				buffer[0]= 0x76;
			}
		sleep(TEMPS);

		buffer[0]= 0x31; //on envoie  la commande 0x32 pou recevoir la donnée du capteur sonore 
		printf("La valeur du buffer 0 avant envoie est (string) : %c\n",buffer[0]);
		/*
		*Le Raspberry envoie un caractere au MSP
		*/
		printf("Le Raspberry envoie un caractere %c\n",buffer[0]);
		wiringPiSPIDataRW(CHANNEL,buffer,1);
		printf("La valeur du buffer 0 après envoie est (string) : %c\n",buffer[0]);
		/*
		* Le buffer contient la valeur de TXDATA du MSP et on fait 
		* la comparaison
		*/
		
			if ( ((buffer[0]) &  0x60 ) && ((buffer[0]) & 0x20))
			{

				data_lum1= buffer[0];
				printf ("data luminosité fort réussi\n\n");
				/*
				* Il faut clear tout le buffer
				* on clear le buffer
				*/	
				buffer[0]=0x76;
			}
			else
			{
				printf("data luminosité fort fail \n\n");
				buffer[0]= 0x76;
			}
		sleep(TEMPS);

		buffer[0]= 0x32; //on envoie  la commande 0x32 pou recevoir la donnée du capteur sonore 
		printf("La valeur du buffer 0 avant envoie est (string) : %c\n",buffer[0]);
		//buffer[1] = i;

		/*
		*Le Raspberry envoie un caractere au MSP
		*/
		printf("Le Raspberry envoie un caractere %c\n",buffer[0]);
		wiringPiSPIDataRW(CHANNEL,buffer,1);
		printf("La valeur du buffer 0 après envoie est (string) : %c\n",buffer[0]);
		/*
		* Le buffer contient la valeur de TXDATA du MSP et on fait 
		* la comparaison
		*/
		
			if (!((buffer[0]) & 0x20))
			{

				data_lum2 = buffer[0];
				printf ("data luminsoté faible  réussi: %c\n\n",buffer[0]);
				result_lum=data_lum(data_lum1,data_lum2);
				printf("La valeur du capteur de luminosité reçu est : %d\n",result_lum);
				
				ajouter(result_lum,j,1);
				/*
				* Il faut clear tout le buffer
				* on clear le buffer
				*/	
				buffer[0]=0x76;
			}
			else
			{
				printf("data luminosité fail \n\n");
				buffer[0]= 0x76;
			}
		sleep(TEMPS);
		
		buffer[0]= 0x33; //on envoie  la commande 0x33 pour recevoir la donnée du capteur sonore 
		printf("La valeur du buffer 0 avant envoie est (string) : %c\n",buffer[0]);

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
		/*
		* Le buffer contient la valeur de TXDATA du MSP et on fait 
		* la comparaison
		*/
		
			if (((buffer[0]) &  0x40 ) && ((buffer[0]) & 0x20))
			{

				data_so1 = buffer[0];
				printf (" data sonore fort réussi\n\n");
				/*
				* Il faut clear tout le buffer
				* on clear le buffer
				*/	
				buffer[0]=0x76;
			}
			else
			{
				printf("data sonore fort fail \n\n");
				buffer[0]= 0x76;
			}
		sleep(TEMPS);

		buffer[0]= 0x34; //on envoie  la commande 0x34 pou recevoir la donnée du capteur vibration 
		
		printf("La valeur du buffer 0 avant envoie est(int): %d\n", buffer[0]);

		/*
		*Le Raspberry envoie un caractere au MSP
		*/
		printf("Le Raspberry envoie un caractere %c\n",buffer[0]);
		wiringPiSPIDataRW(CHANNEL,buffer,1);
		printf("La valeur du buffer après envoie est (string) : %c\n", buffer[0]);
		
		/*
		* Le buffer contient la valeur de TXDATA du MSP et on fait 
		* la comparaison
		*/
		
			if ( ((buffer[0]) &  0x60 ) && (!((buffer[0]) & 0x20)))
			{

				data_so2 = buffer[0];
				printf ("data sonore faible réussi\n\n");
				result_so=data_so(data_so1,data_so2);
				printf("la data sonore reçu est :%d\n",result_so);
				ajouter(result_so,j,2);
				
				/*
				* Il faut clear tout le buffer
				* on clear le buffer
				*/	
				buffer[0]=0x76;
			}
			else
			{
				printf("data sonore faible fail \n\n");
				buffer[0]= 0x76;
			}
		sleep(TEMPS);

		buffer[0]= 0x35; //on envoie  la commande 0x35 pou recevoir la donnée du capteur vibration 
		printf("La valeur du buffer 0 avant envoie est (string) : %c\n",buffer[0]);

		/*
		*Le Raspberry envoie un caractere au MSP
		*/
		printf("Le Raspberry envoie un caractere %c\n",buffer[0]);
		wiringPiSPIDataRW(CHANNEL,buffer,1);
		printf("La valeur capteur vibration du buffer après envoie est (string) : %c\n", buffer[0]); 
		printf("La valeur capteur vibration du buffer après envoie est (int) : %d\n", buffer[0]); 
		/*
		* Le buffer contient la valeur de TXDATA du MSP et on fait 
		* la comparaison
		*/
		
			if ( ((buffer[0]) &  0x20 ) && ((buffer[0]) & 0x60))
			{

				data_vbr1 = buffer[0];
				printf ("data vibration fort réussi\n\n");
				/*
				* Il faut clear tout le buffer
				* on clear le buffer
				*/	
				buffer[0]=0x76;
			}
			else
			{
				printf("data vibration fort fail \n\n");
				buffer[0]= 0x76;
			}
		sleep(TEMPS);

		buffer[0]= 0x36; //on envoie  la commande 0x36 pou recevoir la donnée du capteur co 
		printf("La valeur du buffer 0 avant envoie est (string) : %c\n",buffer[0]);

		/*
		*Le Raspberry envoie un caractere au MSP
		*/
		printf("Le Raspberry envoie un caractere %c\n",buffer[0]);
		wiringPiSPIDataRW(CHANNEL,buffer,1);
		printf("La valeur capteur vibration du buffer après envoie est (string) : %c\n", buffer[0]);
		printf("La valeur capteur vibration du buffer après envoie est (int) : %d\n", buffer[0]);
		/*
		* Le buffer contient la valeur de TXDATA du MSP et on fait 
		* la comparaison
		*/
		
			if (!((buffer[0]) & 0x20))
			{

				data_vbr2 = buffer[0];
				printf ("data vibration faible réussi\n\n");
				result_vbr=data_vbr(data_vbr1,data_vbr2);
				printf("la data vibration reçu est : %d\n",result_vbr);
				ajouter(result_vbr,j,3);
				/*
				* Il faut clear tout le buffer
				* on clear le buffer
				*/	
				buffer[0]=0x76;
			}
			else
			{
				printf("data vibration faible fail \n\n");
				buffer[0]= 0x76;
			}
		sleep(TEMPS);

		buffer[0]= 0x37; //on envoie  la commande 0x37 pou recevoir la donnée du capteur co
		printf("La valeur du buffer 0 avant envoie est (string) : %c\n",buffer[0]);

		/*
		*Le Raspberry envoie un caractere au MSP
		*/
		printf("Le Raspberry envoie un caractere %c\n",buffer[0]);
		wiringPiSPIDataRW(CHANNEL,buffer,1);
		printf("La valeur du buffer après envoie est (string) : %c\n", buffer[0]); 
		/*
		* Le buffer contient la valeur de TXDATA du MSP et on fait 
		* la comparaison so
		*/
		
			if (((buffer[0]) &  0x60 ) && ((buffer[0]) & 0x20))
			{

				data_co1 = buffer[0];
				printf ("Communication fort co réussi\n\n");
				/*
				* Il faut clear tout le buffer
				* on clear le buffer
				*/
				result_co = data_co(data_co1,data_co2);
                                printf("la valeur monoxyde reçu est : %d \n",result_co);
				ajouter(result_co,j,4);
				ajouter(23.5,j,5);
				ajouter_clock(j,5);
				retour(j,5);
	
				buffer[0]=0x76;
			}
			else
			{

				printf("Communication fort co fail \n\n");
				buffer[0]= 0x76;
			}	
		//retour(j,4);
		j=j+1;
	}while(j!=1000);
	printf("Fin du programme \n");	
}


