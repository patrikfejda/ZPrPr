// DONE

//  Napíšte program, ktorý zistí počet jednotlivých písmen v každom
// riadku súboru. Vstupom programu je jeden riadok obsahujúci meno súboru.
// Výstupom je histogram výskytu písmen zapísaný v prehľadnej tabuľke, kde prvý
// riadok bude obsahovať všetky písmená abecedy prehľadne oddelené. Každý
// ďalší riadok bude obsahovať číslo riadku a vždy pod písmenami budú zarovnané
// počty výskytov tohto písmena v jednotlivých riadkoch súboru (nerozlišujte medzi
// veľkými a malými písmenami). Počty výskytov uveďte ako najviac dvojciferné
// celé číslo predchádzané jednou medzerou. Všetky riadky výstupu budú ukončené
// znakom konca riadku.
// Ukážka vstupu:
// subor.txt
// Ukážka obsahu súboru subor.txt:
// Toto je ukazkovy subor.
// V subore su pismena.
// Výstup pre ukážkový vstup:
//  A B C D E F G H I J K L M N O P Q R S T U V W X Y Z
//  1 1 1 0 0 1 0 0 0 0 1 2 0 0 0 4 0 0 1 1 2 2 1 0 0 1 1
//  2 1 1 0 0 2 0 0 0 1 0 0 0 1 1 1 1 0 1 3 0 2 1 0 0 0 0

#include <stdio.h>

int main()
{
	FILE *file;
	if ((file = fopen("subor.txt", "r")) == NULL)
	{
		printf("Neotvoreny subor.\n");
		return 0;
	}

	for (char c = 65; c <= 90; c++)
	{
		printf("%c ", c);
	}
	printf("\n");

	char character;

	char pismena[30];
	for (int c = 65; c <= 90; c++)
	{
		pismena[c] = 0;
	}
	int riadok = 1;
	while (fscanf(file, "%c", &character) != EOF)
	{
		for (int c = 65; c <= 90; c++)
		{
			if ((character == c) || ((character - 'a' + 'A') == c))
			{
				pismena[c] += 1;
				break;
			}
		}
		if (character == '\n')
		{
			printf("%i ", riadok);
			for (int c = 65; c <= 90; c++)
			{
				printf("%i ", pismena[c]);
				pismena[c] = 0;
			}
			riadok += 1;
			printf("\n");
		}
	}

	printf("%i ", riadok);
	for (int c = 65; c <= 90; c++)
	{
		printf("%i ", pismena[c]);
	}

	return 0;
}

//gcc uloha2.c -std=c99 -pedantic -Wall -Werror -Wextra -o uloha