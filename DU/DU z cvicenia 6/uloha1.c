// Napíšte funkciu int parne(int x[], int pocetx, int y[]), ktorá skopíruje všetky párne čísla z
// poľa x do poľa y v poradí v akom sa nachádzajú v poli x a vráti počet prvkov poľa y.
// Argument pocetx určuje počet prvkov poľa x.
// Môžete predpokladať, že argument y, bude mať dostatočnú veľkosť pre všetky párne
// prvky.
// Ukážka volania:
// x = {4, 7, 1, 3, 2, 5, 6}
// pocetx = 7
// pocety = parne(x, pocetx, y); // volanie funkcie
// pocety: 3 // vypis vysledku
// y: {4, 2, 6}


#pragma warning(disable: 4996)
#pragma warning(disable: 6031)
#include <stdio.h>

int x[10] = {1,2,3,4,5,6,7,8,9,10}, y[10];

int parne(int x[], int pocetx, int y[]) {
	int pocety = 0;
	for (int i = 0; i < pocetx; i++) {
		if (x[i] % 2 == 0) {
			y[pocety] = x[i];
			printf("%i, ", x[i]);
			pocety++;
		}
	}
	return pocety;
}

int main() {

	int pocetx = 10, pocety;
	printf("\nPocet y je: %i", parne(x, pocetx, y));

	return 0;
}