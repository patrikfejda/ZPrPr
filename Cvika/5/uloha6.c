// DONE

// Úloha 5.6: Napíšte program, ktorý slová zo súborov prvy.txt a druhy.txt
// zapíše do súboru treti.txt striedavo tak, že každé nepárne slovo v súbore
// treti.txt bude zo súboru prvy.txt a každé párne zo súboru druhy.txt v poradí,
// ako boli v pôvodných súboroch. Každé (aj posledné) slovo v súbore treti.txt
// bude nasledované medzerou. Naviac, pred každým slovom bude značka
// vyjadrujúca, z ktorého súboru slovo pochádza. Ak zo súboru prvy.txt, značkou
// je znak +, ak zo súboru druhy.txt, značkou je znak -. Ak niektorý zo súborov
// obsahuje viac slov ako druhý, potom tieto budú zapísané za sebou na konci
// súboru treti.txt. Predpokladajte, že slová obsahujú len písmená a oddelené
// môžu byť len jednou medzerou alebo jedným znakom konca riadku.
// Ukážka súboru prvy.txt:
// Ahojte
// nasi studenti
// ktori maju radi programovanie
// Ukážka súboru druhy.txt:
// vsetci mili
// Ukážka súboru treti.txt:
// +Ahojte -vsetci +nasi -mili +studenti +ktori +maju +radi +programovanie

#include <stdio.h>
#include <stdlib.h>

#define MAX_DLZKA_RETAZCA 128

FILE *open_file(char file_name[32], char mode[5])
{
	FILE *file;
	if ((file = fopen(file_name, mode)) == NULL)
	{
		printf("Subor sa nepodarilo otvorit.\n");
		exit(1);
	}
	return file;
}

int main()
{
	FILE *f1 = NULL, *f2 = NULL, *f3 = NULL;
	char string1[MAX_DLZKA_RETAZCA], string2[MAX_DLZKA_RETAZCA];

	char neskoncilf1 = 1, neskoncilf2 = 1;

	f1 = open_file("prvy.txt", "r");
	f2 = open_file("druhy.txt", "r");
	f3 = open_file("treti.txt", "w");

	do
	{
		neskoncilf1 = fscanf(f1, "%s", string1);
		neskoncilf2 = fscanf(f2, "%s", string2);

		if (neskoncilf1 == 1)
		{
			//printf("+%s ", string1);
			fprintf(f3,"+%s ", string1);

		}
		if (neskoncilf2 == 1)
		{
			//printf("-%s ", string2);
			fprintf(f3,"-%s ", string2);

		}

	} while (neskoncilf1 == 1 || neskoncilf2 == 1);

	fclose(f3);
	return 0;
}

//gcc uloha6.c -std=c99 -pedantic -Wall -Werror -Wextra -o uloha6