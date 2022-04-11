// DONE

// Úloha 4.4: Napíšte program na výpočet obsahu a obvodu obdĺžnika. Vytvorte
// funkciu nacitaj, ktorá načíta a pomocou argumentov vráti dve reálne čísla.
// Ďalej vytvorte funkciu vypocitaj, ktorá ako argumenty dostane dĺžky strán
// obdĺžnika a prostredníctvom argumentov vráti obsah a obvod obdĺžnika. V
// hlavnom programe volajte funkciu nacitaj na načítanie rozmerov obdĺžnika a
// funkciu vypocitaj na výpočet obsahu a obvodu obdĺžnika. Program vypíše
// obsah a obvod obdĺžnika zaokrúhlený na tri desatinné miesta.
// Ukážka vstupu:
// 3.5 4.75
// Výstup pre ukážkový vstup:
// Obsah: 16.625
// Obvod: 16.500

#include <stdio.h>

void nacitaj(float *pa, float *pb) {
	printf("Zadaj 2 realne cisla: ");
	scanf("%f %f", pa, pb);
}


void vypocitaj(float a, float b, float *obvod, float *obsah) {

	*obsah = a * b;
	*obvod = 2 * (a + b);
}


int main()
{
	float a, b, obvod, obsah;

	nacitaj(&a, &b);

	vypocitaj(a, b, &obvod, &obsah);

	printf("A: %.3f\nB: %.3f\nObvod: %.3f\nObsah: %.3f",a,b,obvod, obsah);


	return 0;
}

//gcc uloha4.c -std=c99 -pedantic -Wall -Werror -Wextra -o uloha