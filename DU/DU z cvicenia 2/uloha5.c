#pragma warning(disable: 4996)
#pragma warning(disable: 6031)
#include <stdio.h>

int main()
{
	int pocet_jadier;
	printf("Zadajte pocet jadier mikroprocesora: ");
	scanf("%i", &pocet_jadier);

	printf("Vas pocitac ma osadeny %i-jadrovy procesor\n",pocet_jadier);

	return 0;
}