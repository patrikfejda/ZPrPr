// Úloha 3.6: Napíšte program, ktorý rekurzívnou funkciou vypočíta súčet nepárnych
// kladných celých čísel menších ako N. Na vstupe je dané kladné celé číslo N, na výstup
// program vypíše jedno číslo: súčet všetkých nepárnych kladných celých čísel menších
// ako N.
// Ukážka vstupu:
// 10
// Výstup pre ukážkový vstup:
// 25

#include <stdio.h>
#include <stdlib.h>

int rek_sucet(int X)
{
	if (X < 1)
		return 0;
	else if (X % 2)
		return (X + rek_sucet(X - 2));
	return rek_sucet(X-1); // osetrenie parneho vstupu PARNE => NEPARNE
}

int main()
{

	int N;
	printf("Zadajte cele cislo: ");
	scanf("%i", &N);

	printf("Sucet neparnych cisel: %i", rek_sucet(N));

	return 0;
}

//gcc uloha6.c -std=c99 -pedantic -Wall -Werror -Wextra -o uloha6