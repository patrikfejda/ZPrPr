// done

// Napíšte funkciu int delitele(int x[], int pocetx, int y[], int k),
// ktorá z poľa x prekopíruje do poľa y všetky delitele čísla k, v poradí v ako sa
// nachádzajú v poli x a vráti počet prvkov poľa y. Argument pocetx určuje počet
// prvkov poľa x.
// Môžete predpokladať, že argument y, bude mať dostatočnú veľkosť pre všetky
// delitele čísla k, ktoré sú v poli x.
// Ukážka volania:
// x = {4, 7, 10, 2, 3, 9, 6, 5, 8, 12}
// pocetx = 10
// pocety = delitele(x, pocetx, y, 24); // volanie funkcie
// pocety: 6
// vypis vysledku
// y: {4, 2, 3, 6, 8, 12}

#include <stdio.h>
#include <stdlib.h>

int delitele(int x[], int pocetx, int y[], int k)
{
	int i_y = 0;
	for (int i = 0; i < pocetx; i++)
	{
		if (!(k % x[i]))
		{
			y[i_y] = x[i];
			i_y++;
		}
	}
	return i_y;
}

int main()
{
	int x[] = {4, 7, 10, 2, 3, 9, 6, 5, 8, 12};
	int pocetx = 0;
	pocetx = sizeof(x) / sizeof(int);;

	int y[15];
	int pocety = 0;

	pocety = delitele(x, pocetx, y, 24);

	printf("Pocet y: %i\n", pocety);

	for (int i = 0; i < pocety; i++)
	{
		printf("%i ", y[i]);
	}

	return 0;
}

//gcc uloha1.c -std=c99 -pedantic -Wall -Werror -Wextra -o uloha