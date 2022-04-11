// DONE

// Úloha 4.2: Napíšte funkciu maximum, ktorá dostane na vstupe adresu na dve
// celé čísla a vráti adresu na celé číslo, ktoré je väčšie. Program načíta zo
// štandardného vstupu dve celé čísla. Zavolá funkciu maximum, odovzdá jej
// adresy premenných, kde sú načítané hodnoty uložené a vypíše väčšie číslo.
// Pozor funkcia maximum vráti na výstupe adresu na premennú, kde je uložené
// väčšie číslo.

#include <stdio.h>


int *maximum(int *pa, int *pb) {	
	if (*pa > *pb) {
		return pa;
	}
	else {
		return pb;
	}
}

int main()
{
	int a, b;
	int *pa, *pb;

	pa = &a;
	pb = &b;

	printf("Zadaj 2 cele cisla oddelene medzerou: ");
	scanf("%i %i", pa, pb);

	printf("\nMaximum je %i!", *maximum(pa, pb));
	return 0;
}

//gcc uloha2.c -std=c99 -pedantic -Wall -Werror -Wextra -o uloha