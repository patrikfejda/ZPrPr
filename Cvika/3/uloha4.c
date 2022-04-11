// Úloha 3.4: Napíšte program, ktorý načíta číslo N. Ak je N < 1, N > 15 alebo je N párne
// číslo, program vypíše chybu Zly vstup a skončí. Ak bude program pokračovať, zo
// znakov '*' a '-' (medzera) nakreslí hviezdu veľkosti NxN (hviezdu je možné rozdeliť na
// dve časti – "X" a "+").
// Ukážka vstupu:
// 9
// Výstup pre ukážkový vstup:
// *---*---*
// -*--*--*-
// --*-*-*--
// ---***---
// *********
// ---***---
// --*-*-*--
// -*--*--*-
// *---*---*
// Poznámka: Znak '-' vo výstupe reprezentuje medzeru.

#include <stdio.h>

int main()
{
	int N;
	printf("Zadajte cele cislo: ");
	scanf("%i", &N);

	if ((N < 1) || (N > 15) || !(N % 2))
	{
		printf("Zly vstup.");
		return 1;
	}

	for (int y = 1; y <= N; y++)
	{
		for (int x = 1; x <= N; x++)
		{
			if ((x-1==N/2)||(y-1==N/2)||(x==y)||(x == N-y+1))
			{
				printf("*");
			}
			else {
				printf(" ");
			}
		}
			printf("\n");

	}

	return 0;
}

//gcc uloha4.c -std=c99 -pedantic -Wall -Werror -Wextra -o uloha