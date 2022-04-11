// Úloha 3.5: Napíšte program, ktorý rozšíri úlohu 3.4 nasledovným spôsobom. Zo
// štandardného vstupu načítajte tri celé čísla N, R a S. Čísla R a S sú z intervalu <1,7>.
// Číslo R (resp. S) určuje počet opakovaní základného vzoru vedľa seba (resp. pod
// sebou).
// Ukážka vstupu:
// 9 3 2
// 2
// Výstup pre ukážkový vstup:
// *---*---**---*---**---*---*
// -*--*--*--*--*--*--*--*--*-
// --*-*-*----*-*-*----*-*-*--
// ---***------***------***---
// ***************************
// ---***------***------***---
// --*-*-*----*-*-*----*-*-*--
// -*--*--*--*--*--*--*--*--*-
// *---*---**---*---**---*---*
// *---*---**---*---**---*---*
// -*--*--*--*--*--*--*--*--*-
// --*-*-*----*-*-*----*-*-*--
// ---***------***------***---
// ***************************
// ---***------***------***---
// --*-*-*----*-*-*----*-*-*--
// -*--*--*--*--*--*--*--*--*-
// *---*---**---*---**---*---*
// Poznámka: Znak '-' vo výstupe reprezentuje medzeru.

#include <stdio.h>

int main()
{
	int N, R, S;
	printf("Zadajte 3 cele cisla odelene medzerou (N R S): ");
	scanf("%i %i %i", &N, &R, &S);

	if ((N < 1) || (N > 15) || !(N % 2) || (R < 1) || (R > 7) || (S < 1) || (S > 7))
	{
		printf("Zly vstup.");
		return 1;
	}

	for (int My = 1; My <= R; My++)
	{
		for (int y = 1; y <= N; y++)
		{
			for (int Mx = 1; Mx <= S; Mx++)
			{
				for (int x = 1; x <= N; x++)
				{
					if ((x - 1 == N / 2) || (y - 1 == N / 2) || (x == y) || (x == N - y + 1))
					{
						printf("*");
					}
					else
					{
						printf(" ");
					}
				}
			}
			printf("\n");
		}
	}

	return 0;
}

//gcc uloha5.c -std=c99 -pedantic -Wall -Werror -Wextra -o uloha5