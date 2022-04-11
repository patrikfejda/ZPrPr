// DONE

// Úloha 5.5: Napíšte funkciu int nasobky(int x[], int pocetx, int y[], int k),
// ktorá z poľa x prekopíruje do poľa y všetky násobky čísla k (k >= 0), v poradí v
// akom sa nachádzajú v poli x a vráti počet prvkov poľa y. Argument pocetx
// určuje počet prvkov poľa x.
// Môžete predpokladať, že argument y, bude mať dostatočnú veľkosť pre všetky
// násobky čísla k, ktoré sú v poli x.
// Ukážka volania:
// x = {4, 7, 10, 1, 3, 9, 2, 5, 8, 6}
// pocetx = 10
// pocety = nasobky(x, pocetx, y, 2); // volanie funkcie
// pocety: 5 // vypis vysledku
// y: {4, 10, 2, 8, 6}



#include <stdio.h>
#include <stdlib.h>

int nasobky(int x[], int pocet_x, int y[], int k)
{
	int iy = 0;

	for (int i = 0; i < pocet_x; i++)
	{
		if (!(x[i] % k))
		{
			y[iy] = x[i];
			iy++;
		}
	}
	return iy;
}

int main()
{
	int x[] = {4, 7, 10, 1, 3, 9, 2, 5, 8, 6};
	int pocet_x, pocet_y;
	pocet_x = sizeof(x) / sizeof(int);

	//int y[pocet_x];
	int y[10];

	int k = 1;
	printf("Zadajte k: ");
	scanf("%i", &k);

	pocet_y = nasobky(x, pocet_x, y, k);

	printf("Pocet y: %i\n", pocet_y);
	printf("Y: ");
	for (int i = 0; i < pocet_y; i++)
	{
		printf("%i ", y[i]);
	}

	return 0;
}

//gcc uloha5.c -std=c99 -pedantic -Wall -Werror -Wextra -o uloha5