// done

// Napíšte program, ktorý zo súboru mena.txt načíta mená do plne
// dynamického dvojrozmerného poľa (definovaného cez ukazovateľ na ukazovateľ). Meno
// môže obsahovať viac slov. Pre každé meno alokujte práve tak dlhé pole, ktoré je
// potrebné na uloženie tohto mena. Predpokladajte, že v súbore je každé meno zapísané
// vo zvlášť riadku a aj za posledným menom je znak konca riadku.
// Po načítaní mien do poľa použite algoritmus minsort na usporiadajte mená tak, že
// výmenu dvojíc mien realizujte presmerovaním ich ukazovateľov. Usporiadané pole mien
// vypíšte na obrazovku tak, že bude každé meno vo zvlášť riadku (viď ukážkový výstup).
// V prípade, že sa nepodarí otvoriť súbor, či alokovať pole, program síce nevypíše žiadnu
// chybovú správu, ale korektne skončí.
// Algoritmus minsort usporadúva pole prvkov tak, že vždy v časti poľa nájde najmenší
// prvok a vymení ho s prvým prvkom tejto časti poľa. Začína s celým n-prvkovým poľom
// (od indexu 0 do n-1), po výmene (najmenšieho prvku poľa s prvkom na indexe 0) sa
// pracuje s časťou poľa od indexu 1 po n-1. Po ďalšej výmene (najmenšieho prvku z časti
// poľa od indexu 1 po n-1 s prvkom na indexe 1) znova pracuje s kratším poľom (od
// indexu 2 po n-1) až pokým nepracujeme len s 2-prvkovou časťou poľa (od indexu n-2 po
// n-1) – potom už bude pole usporiadané.
// Ukážka súboru mena.txt:
// Jozko
// Anicka
// Lucka
// Zuzanka
// Janusenecko
// Peto
// Výstup pre ukážku:
// Anicka
// Janusenecko
// Jozko
// Lucka
// Peto
// Zuzanka

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXDLZKARIADKU 64

int zorad_abecedne(char **zoznam_mien, int pocet_ludi)
{
	char *temp;
	for (int i = 0; i < pocet_ludi; i++)
	{
		int min = i;
		for (int j = i + 1; j < pocet_ludi; j++)
		{
			if (strcmp(zoznam_mien[j], zoznam_mien[min]) < 0)
			{
				min = j;
			}
		}
		if (min != i)
		{
			temp = zoznam_mien[i];
			zoznam_mien[i] = zoznam_mien[min];
			zoznam_mien[min] = temp;
		}
	}
	return 0;
}

int main()
{
	FILE *file;
	if ((file = fopen("mena.txt", "r")) == NULL)
	{
		printf("ERROR!");
		return 0;
	}

	char **zoznam_mien;
	char riadok[MAXDLZKARIADKU];
	int pocet_ludi = 0;
	while (fgets(riadok, MAXDLZKARIADKU, file) != NULL)
	{
		pocet_ludi++;
	}
	rewind(file);
	zoznam_mien = (char **)malloc(pocet_ludi * sizeof(char *));
	if ((zoznam_mien) == NULL)
	{
		printf("ERROR!");
		return 0;
	}

	char *aktualne_meno;
	for (int i = 0; i < pocet_ludi; i++)
	{
		fgets(riadok, MAXDLZKARIADKU, file);
		aktualne_meno = (char *)malloc(strlen(riadok) * sizeof(char));
		if ((zoznam_mien) == NULL)
		{
			printf("ERROR!");
			return 0;
		}
		strcpy(aktualne_meno, riadok);
		aktualne_meno[strlen(riadok) - 1] = '\0';
		zoznam_mien[i] = aktualne_meno;
	}

	zorad_abecedne(zoznam_mien, pocet_ludi);

	for (int i = 0; i < pocet_ludi; i++)
	{
		printf("%s\n", zoznam_mien[i]);
	}

	return 0;
}

//gcc uloha2.c -std=c99 -pedantic -Wall -Werror -Wextra -o uloha ;; ./uloha