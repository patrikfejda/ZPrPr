#pragma warning(disable: 4996)
#pragma warning(disable: 6031)
#include <stdio.h>

#define NAJVACSIECISLO 9999999

int main()
{
	int N;
	printf("Zadajte cele cislo N: ");
	scanf("%i", &N);
	float MAX = 0, MIN = NAJVACSIECISLO, nacitane_cislo;

	for (int i = 0; i < N; i++) {
		scanf("%f", &nacitane_cislo);
		if (nacitane_cislo > MAX) {
			MAX = nacitane_cislo;
		}
		if (nacitane_cislo < MIN) {
			MIN = nacitane_cislo;
		}
	}

	printf("Minimum: %.3f \nMaximum: %.3f", MIN, MAX);


	return 0;
}