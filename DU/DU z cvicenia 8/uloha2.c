// Napíšte program, ktorý z načítanej postupnosti čísel vytvorí histogram
// koreň-a-list pre čísla. Podobne ako pre mestskú hromadnú dopravu sa
// po hodinách vypisujú minúty príchodu autobusov.
// Tento histogram pre každú číslicu, ktorá sa vyskytuje na pozícií desiatok,
// vypíše všetky číslice predstavujúce jednotky v týchto číslach,
// usporiadané vzostupne.
// Štandardný vstup obsahuje až do konca čísla z intervalu <0, 99>. Nie je
// vopred zadaný počet čísel na vstupe, čítajte do konca vstupu. Na
// štandardný výstup vypíšte histogram/grafikon podľa požiadaviek.

#pragma warning(disable : 4996)
#pragma warning(disable : 6031)
#include <stdio.h>


int main()
{
	int PocetJednotiekVdesiatkach[10];

	for (int i = 0; i < 10; i++)
		PocetJednotiekVdesiatkach[i] = 0;
	int nacitaneCislo;
	int pocetCelychDesiatok;
	printf("Zadajte cisla <0;99> oddelene medzerou a na konci dajte 'x': ");

	int navrat = 1;
	do {
		navrat = scanf("%d", &nacitaneCislo);
		pocetCelychDesiatok = nacitaneCislo / 10;

		if (nacitaneCislo == 100)
			break;
		//debug: printf("\ncislo: %i pocet desiatok: %i", nacitaneCislo, pocetCelychDesiatok);

		PocetJednotiekVdesiatkach[pocetCelychDesiatok]++;



	} while (navrat>0);
	//printf("\n");
	for (int i = 0; i < 10; i++)
		printf("\n%i | %i", i, PocetJednotiekVdesiatkach[i]);

	return 0;
}


