// Vytvorte (dynamické) pole záznamov o tovare v potravinách.
// Jednotlivé záznamy majú obsahovať názov tovaru, výrobcu, počet kusov a
// jednotkovú cenu. Zoznam udržiavajte stále usporiadaný podľa názvov tovarov.
// Umožnite používateľovi pridať nový tovar. Na prácu s dynamickým poľom
// záznamov využívajte ukazateľovú aritmetiku.
// Pomôcky: Pri pridávaní záznamu do poľa, je potrebné nájsť miesto, kam sa
// má nový záznam pridávať. Všetky záznamy, od tejto pozície ďalej, posunúť na
// pozíciu o jedno väčšiu a na voľné miesto zapísať nový záznam.
// Na porovnanie reťazcov môžete použiť funkciu strcmp() z knižnice string.h -
// http://www.cplusplus.com/reference/cstring/strcmp/
// Na kopírovanie reťazcov môžete použiť funkciu strcpy() z knižnice string.h -
// http://www.cplusplus.com/reference/cstring/strcpy/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tovar
{
	char Nazov_tovaru[64];
	char Nazov_vyrobcu[64];
	int Pocet_Kusov;
	float Cena_Kus;
} TOVAR;

int zorad_abecedne(TOVAR **zoznam_tovarov, int pocet)
{

	TOVAR *temp;
	for (int i = 0; i < pocet; i++)
	{

		int min = i;
		for (int j = i + 1; j < pocet; j++)
		{
			if (strcmp(zoznam_tovarov[j]->Nazov_tovaru, zoznam_tovarov[min]->Nazov_tovaru) < 0)
			{
				min = j;
			}

		}

		if (min != i)
		{
			temp = zoznam_tovarov[i];
			zoznam_tovarov[i] = zoznam_tovarov[min];
			zoznam_tovarov[min] = temp;
		}
	}
	return 0;
}

int main()
{
	TOVAR *pole = NULL;

	int pocet_tovarov = 10;

	pole = (TOVAR *)malloc(pocet_tovarov * sizeof(TOVAR));

	char random_meno[20] = {"XXXXXXXXXX"};

	// naplnenenie pola
	for (int i = 0; i < pocet_tovarov; i++)
	{
		for (int a = 0; a < 5; a++)
		{
			if (a == 0)
			{
				random_meno[a] = 'A' + rand() % ('z' - 'a');
			}
			else if (a == 4)
			{
				random_meno[a] = '\0';
			}
			else
				random_meno[a] = 'a' + rand() % ('z' - 'a');
		}

		strcpy(pole[i].Nazov_tovaru, random_meno);
		for (int a = 0; a < 5; a++)
		{
			if (a == 0)
			{
				random_meno[a] = 'A' + rand() % ('z' - 'a');
			}
			else if (a == 4)
			{
				random_meno[a] = '\0';
			}
			else
				random_meno[a] = 'a' + rand() % ('z' - 'a');
		}
		strcpy(pole[i].Nazov_vyrobcu, random_meno);
		pole[i].Cena_Kus = i + 0.01;
		pole[i].Pocet_Kusov = i;
	}

	// vypis

	for (int i = 0; i < pocet_tovarov; i++)
	{
		printf("%s %s %.2lf %i\n", pole[i].Nazov_tovaru, pole[i].Nazov_vyrobcu, pole[i].Cena_Kus, pole[i].Pocet_Kusov);
	}

	// usporiadanie

	zorad_abecedne(&pole, pocet_tovarov);
	printf("\n\n|||||||||||||||||\n\n");

	// vypis

	for (int i = 0; i < pocet_tovarov; i++)
	{
		printf("%s %s %.2lf %i\n", pole[i].Nazov_tovaru, pole[i].Nazov_vyrobcu, pole[i].Cena_Kus, pole[i].Pocet_Kusov);
	}

	return 0;
}

//gcc uloha1.c -std=c99 -pedantic -Wall -Werror -Wextra -o uloha ;; ./uloha