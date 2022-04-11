// Vytvorte program, ktorý zistí, či je daný štvorec magický. Štvorec je
// magický vtedy, keď súčet prvkov vo všetkých riadkoch, stĺpcoch a
// uhlopriečkach je rovnaký. Program vytvorí staticky pole N × N prvkov
// (napr. N = 20). Potom zo štandardného vstupu načíta rozmer štvorca n
// (pričom n <= N) a do statického poľa načíta prvky štvorca. Ak bude n <
// N, nevyužije sa celý štvorec, ale len jeho časť. Ak je n > N, program
// skončí s chybovou správou. Potom program vo funkcii int magicky()
// zistí, či je štvorec magický. Nakoniec program na obrazovku vypíše
// výsledok.

#pragma warning(disable : 4996)
#pragma warning(disable : 6031)
#include <stdio.h>

#define N 20

int main()
{
	int pole[N][N];
	int n;
	int suctyRiadkov[N], suctyStlpcov[N];

	for (int i = 0; i < N; i++) {
		suctyRiadkov[i] = 0;
		suctyStlpcov[i] = 0;
	}

	printf("Zadajte cislo n: ");
	scanf("%i", &n);

	if (n > N) {
		printf("\nCislo n bolo vacsie ako %i", N);
		return 0;
	}

	for (int riadok = 0; riadok < n; riadok++) {
		for (int stlpec = 0; stlpec < n; stlpec++) {
			scanf("%i", &pole[riadok][stlpec]);
			suctyRiadkov[riadok] += pole[riadok][stlpec];
			suctyStlpcov[stlpec] += pole[riadok][stlpec];
		}
	}

	int magicky = 1;
	for (int i = 0; i < n-1; i++) {
		int SucetRiadkuN = suctyRiadkov[i];
		int SucetRiadkuNplus1 = suctyRiadkov[i+1];
		int SucetStlpcauN = suctyStlpcov[i];
		int SucetStlpcaNplus1 = suctyStlpcov[i+1];

		if ((SucetRiadkuN != SucetRiadkuNplus1) || (SucetStlpcauN != SucetStlpcaNplus1))
			magicky = 0;
	}

	printf("\nStvorec %s\n",magicky ? "je magicky." : "NIE JE magicky.");
	



	return 0;
}