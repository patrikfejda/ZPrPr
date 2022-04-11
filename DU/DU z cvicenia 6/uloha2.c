// 2. Napíšte funkciu int nasobky(int x[], int pocetx, int y[], int k), ktorá z poľa x prekopíruje do poľa y
// všetky násobky čísla k(k >= 0) (zadaneho na standardny vstup), v poradí v akom sa nachádzajú v
// poli x a vráti počet prvkov poľa y. Argument pocetx určuje počet prvkov poľa x.
// Môžete predpokladať, že argument y, bude mať dostatočnú veľkosť pre všetky násobky čísla k,
// ktoré sú v poli x.
// Ukážka volania:
// x = {4, 7, 10, 1, 3, 9, 2, 5, 8, 6}
// pocetx = 10
// pocety = nasobky(x, pocetx, y, 2); // volanie funkcie
// pocety: 5 // vypis vysledku
// y: {4, 10, 2, 8, 6}

#pragma warning(disable: 4996)
#pragma warning(disable: 6031)
#include <stdio.h>

int nasobky(int x[], int pocetx, int y[], int k) {
	int pocet = 0;
	for (int i = 0; i < pocetx; i++) {
		if (x[i] % k == 0) {
			y[pocet] = x[i];
			printf("%i, ", x[i]);
			pocet++;
		}
	}
	return pocet;
}

int main() {
	int k;
	int x[20] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20 }, y[20];
	int pocetx = 20, pocety;

	printf("Zadajte cislo k (k>=0): ");
	scanf("%i", &k);

	print("%i", nasobky(x, pocetx, y, 2));

	return 0;
}