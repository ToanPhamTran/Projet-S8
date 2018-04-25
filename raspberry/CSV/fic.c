#include <stdio.h>
#include <string.h>
//#include <sdlib.h>
#define TAILLE 100
void creation (char *Nom)
{
	FILE *fichier;
	fichier=fopen(Nom, "w");
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

void ajouter (void)
{
	int i=0;
	int j=1; 
	int compt=1;
	int var=1000;
	int tab[TAILLE][TAILLE];
	//int tab[i][j];
	FILE *fichier ;
	fichier = fopen ("test.csv","r+");
	if (fichier != NULL)
	{
	printf("le fichier existe\n");
	for(i=0;i<5;i++)
	{
	 tab[i][j]=fprintf(fichier,"Capteur %d, ",compt);
	compt=compt+1;
	}
	tab[5][j]=fputs("Date, \n",fichier);

	for(j=1;j<5;j++)
		{
		for(i=0;i<5;i++)
			{
			tab[i][j]=fprintf(fichier,"%d,",var);
			}
		
		tab[i][j]=fprintf(fichier,"\n");
		var=var+1;
		}
	}
	else 
	{
	printf("le fichier n'existe pas \n");
	}
	fclose(fichier);
	
}
void main (void)
{
	//int tab[TAILLE][TAILLE];
	//int i, j ; 
	/*
	* cree un fichier en format csv
	*/
	creation("test.csv");
	ajouter();
}
