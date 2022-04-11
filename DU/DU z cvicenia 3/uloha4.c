#pragma warning(disable: 4996)
#pragma warning(disable: 6031)
#include <stdio.h>

int main() {
	double R;
	printf("Zadajte realne cislo: ");
	scanf("%lf", &R);
	printf("Obycajne pretypovanie %i \n", (int)R);
	printf("Matematicky spravne pretypovanie %.0lf",R);
	return 0;
}