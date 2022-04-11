// done

// Napíšte funkciu odstran_male_pismena() , ktorá vo vstupnom reťazci
// odstráni písmená malej anglickej abecedy a počet odstránených písmen vráti
// ako návratovú hodnotu.
// Ukážka vstupu
// SlovenskaRepublika
// Výstup pre ukážkový vstup
// Retazec po uprave:SR
// Bolo odstranenych 16 znakov


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXDLZKARETAZCA 100

int odstran_male_pismena(char *retazec)
{
	char temp_retazec[MAXDLZKARETAZCA] = {"ERROR ERROR ERROR"};
	int index_temp = 0;
	for (unsigned int i = 0;i<strlen(retazec);i++){
		if (retazec[i] < 'a' || retazec[i] > 'z' ){
			temp_retazec[index_temp++] =  retazec[i];
		}
	}
	temp_retazec[index_temp] = '\0';

	int odstanenych_pismen = strlen(retazec) - strlen(temp_retazec); 
	strcpy(retazec,temp_retazec);
	return odstanenych_pismen;
}

int main()
{
	char retazec[MAXDLZKARETAZCA];
	int pocet_odstanenych_pismen = 0;

	scanf("%s", retazec);

	
	pocet_odstanenych_pismen = odstran_male_pismena(retazec);
	printf("Retazec po uprave: %s\nBolo odstranenych %i znakov",retazec, pocet_odstanenych_pismen);

	return 0;
}

//gcc uloha4.c -std=c99 -pedantic -Wall -Werror -Wextra -o uloha ;; ./uloha