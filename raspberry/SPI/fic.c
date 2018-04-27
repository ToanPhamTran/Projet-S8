
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define TAILLE 1000
#define RTC_SECS         0
#define RTC_MINS         1
#define RTC_HOURS        2
#define RTC_DATE         3
#define RTC_MONTH        4
#define RTC_DAY          5
#define RTC_YEAR         6
#define RTC_WP           7
#define RTC_TC           8
#define RTC_BM          31

#include <time.h>

#include <wiringPi.h>
#include <ds1302.h>

static unsigned int masks [] = { 0x7F, 0x7F, 0x3F, 0x3F, 0x1F, 0x07, 0xFF } ;

static int bcdToD (unsigned int byte, unsigned int mask)
{
  unsigned int b1, b2 ;
  byte &= mask ;
  b1 = byte & 0x0F ;
  b2 = ((byte >> 4) & 0x0F) * 10 ;
  return b1 + b2 ;
}
static int setLinuxClock (void)
{
  char dateTime [20] ;
  char command [64] ;
  int  clock [8] ;


  printf ("Setting the Linux Clock from the DS1302... ") ; fflush (stdout) ;

  ds1302clockRead (clock) ;

// [MMDDhhmm[[CC]YY][.ss]]

  sprintf (dateTime, "%02d%02d%02d%02d%02d%02d.%02d",
        bcdToD (clock [RTC_MONTH], masks [RTC_MONTH]),
        bcdToD (clock [RTC_DATE],  masks [RTC_DATE]),
        bcdToD (clock [RTC_HOURS], masks [RTC_HOURS]),
        bcdToD (clock [RTC_MINS],  masks [RTC_MINS]),
        20,
        bcdToD (clock [RTC_YEAR],  masks [RTC_YEAR]),
        bcdToD (clock [RTC_SECS],  masks [RTC_SECS])) ;

  sprintf (command, "/bin/date %s", dateTime) ;
  system (command) ;

  return 0 ;
}


void creation ()
{
	FILE *fichier;
	fichier=fopen("capteur.csv", "w");
	if(fichier== NULL)
	{
		puts("problème à l'ouverture du fichier\n");
	}
	else	
	{
		printf("ouverture ok\n");		
	}		
	fclose(fichier);

}

void initialisation()
{
	int tab[TAILLE][TAILLE];
	FILE *fichier ;
	fichier = fopen ("capteur.csv","r+");
	if (fichier != NULL)
	{
	printf("le fichier existe\n");
	tab[1][1]=fprintf(fichier,"Capteur Luminosite,");
	tab[1][2]=fprintf(fichier,"Capteur Sonore,");
	tab[1][3]=fprintf(fichier,"Capteur Vibration,");
	tab[1][4]=fprintf(fichier,"Capteur Monoxyde de carbone,");
	tab[1][5]=fprintf(fichier,"Capteur Temperature,");
	tab[1][6]=fprintf(fichier,"Date,\n");
	
	}
	else 
	{
	printf("le fichier n'existe pas \n");
	}
	fclose(fichier);
}

void ajouter (unsigned short data, int ligne, int colonne)
{
	int tab[TAILLE][TAILLE];
	FILE *fichier ;
	fichier = fopen ("capteur.csv","a");
	if (fichier != NULL)
	{
	printf("le fichier existe\n");
	tab[ligne][colonne]=fprintf(fichier,"%d,", data);
	}
	else 
	{
	printf("le fichier n'existe pas \n");
	}
	fclose(fichier);
	
}

void ajouter_clock(int ligne, int colonne)
{
	int tab[TAILLE][TAILLE];
  	int clock [8] ;
	FILE *fichier ;
	fichier = fopen ("capteur.csv","a");
	if (fichier != NULL)
	{
  	wiringPiSetup () ;
  	ds1302setup   (0, 1, 2) ;
	//setLinuxClock ();
   	ds1302clockRead (clock) ;
    	tab[ligne][colonne]=fprintf (fichier, " %2d:%02d:%02d",
	bcdToD (clock [2], masks [2]) +2 , bcdToD (clock [1], masks [1]), bcdToD (clock [0], masks [0])) ;

    	tab[ligne][colonne] = fprintf (fichier," %2d/%02d/%04d",
	bcdToD (clock [3], masks [3]) , bcdToD (clock [4], masks [4]) , bcdToD (clock [6], masks [6]) + 2000) ;
	
	}
	else 
	{
	printf("le fichier n'existe pas \n");
	}
	fclose(fichier);
}
void retour(int ligne, int colonne)
{
	int tab[TAILLE][TAILLE];
	FILE *fichier ;
	fichier = fopen ("capteur.csv","a");
	if (fichier != NULL)
	{
	printf("le fichier existe\n");
	tab[ligne][colonne]=fprintf(fichier,"\n");
	}
	else 
	{
	printf("le fichier n'existe pas \n");
	}
	fclose(fichier);
	
}

