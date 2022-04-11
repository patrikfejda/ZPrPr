// 4. Napíšte program, ktorý vo funkcii main() načíta 2 celé čísla „a“ a „b“ a následne
// zavolá funkciu void prehod(), ktorá prehodí hodnoty týchto dvoch premenných
// medzi sebou. Vo funkcii prehod() použite dva ukazovatele a jednu pomocnú
// celočíselnú premennú. Výpis prehodených hodnôt má na starosti funkcia main().
// Ukážka fungovania programu:
// Zadaj hodnotu premennej a:
// 35
// Zadaj hodnotu premennej b:
// 88
// Hodnota a:88, b:35

#pragma warning(disable : 4996)
#pragma warning(disable : 6031)
#include <stdio.h>

void prehod(int *a, int *b)
{
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

int main()
{

	int a, b, s;
	int *pa, *pb;
	printf("ZADAJTE 2 CELE CISLA (A, B) ODELENE MEDZEROU: ");
	scanf("%i %i", &a, &b);
	pa = &a;
	pb = &b;
	printf("\nA: %i, B: %i", a, b);
	prehod(pa, pb);
	printf("\nPREHADZUJEM A a B");
	printf("\nA: %i, B: %i", a, b);
	return 0;
}