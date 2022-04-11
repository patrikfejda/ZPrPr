// Napíšte program, ktorý vo funkcii main() načíta dve celé čísla, a následne zavolá
// funkciu sucet(), ktorá je typu void. Funkcia sucet() vypočíta súčet dvoch zadaných
// čísel a výsledok uloží do premennej „s“, ktorá je lokálnou premennou funkcie main().
// Funkcia sucet() nesmie používať žiadne lokálne premenné iné ako ukazovatele.
// Program nesmie používať žiadne globálne premenné. Výpis výsledku vykoná funkcia
// main().
// Ukážka fungovania programu:
// Zadaj dve cisla oddelene medzerou:
// 31 65
// Sucet cisel je: 96

#pragma warning(disable : 4996)
#pragma warning(disable : 6031)
#include <stdio.h>

void sucet(int a, int b, int *ps)
{
	*ps = a + b;
}

int main()
{
	int a, b, s;
	printf("ZADAJTE 2 CELE CISLA ODELENE MEDZEROU: ");
	scanf("%i %i", &a, &b);
	sucet(a, b, &s);
	printf("SUCET CISEL JE: %i", s);
	return 0;
}