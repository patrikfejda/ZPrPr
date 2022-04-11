// DONE

// Úloha 5.2: Napíšte funkciu int parne(int x[], int pocetx, int y[]), ktorá
// skopíruje všetky párne čísla z poľa x do poľa y v poradí v akom sa nachádzajú
// v poli x a vráti počet prvkov poľa y. Argument pocetx určuje počet prvkov poľa
// x.
// Môžete predpokladať, že argument y, bude mať dostatočnú veľkosť pre všetky
// párne prvky.
// Ukážka volania:
// x = {4, 7, 1, 3, 2, 5, 6}
// pocetx = 7
// pocety = parne(x, pocetx, y); // volanie funkcie
// pocety: 3 // vypis vysledku
// y: {4, 2, 6}

#include <stdio.h>

int parne(int x[], int pocet_x, int y[])
{
	int iy = 0;

	for (int i = 0; i < pocet_x; i++)
	{
		if (!(x[i] % 2))
		{
			y[iy] = x[i];
			iy++;
		}
	}
	return iy;
}

int main()
{
	int x[] = {4, 7, 1, 3, 2, 5, 6};
	int pocet_x, pocet_y;
	pocet_x = sizeof(x) / sizeof(int);

	int y[10];

	pocet_y = parne(x, pocet_x, y);

	printf("Pocet y: %i\n", pocet_y);
	printf("Y: ");
	for (int i = 0; i < pocet_y; i++)
	{
		printf("%i ", y[i]);
	}

	return 0;
}

//gcc uloha2.c -std=c99 -pedantic -Wall -Werror -Wextra -o uloha