#pragma warning(disable: 4996)
#pragma warning(disable: 6031)
#include <stdio.h>

float zvysenie_vykonnosti(int stary_cas, int novy_cas) {
	return ((float)stary_cas / novy_cas);
}

int main() {
	int tseq, tpar;

	printf("Zadajte cas spracovania sekvencneho programu v ms: ");
	scanf("%i", &tseq);
	printf("Zadajte cas spracovania paralelneho programu v ms: ");
	scanf("%i", &tpar);

	printf("Koeficient zvysenia vykonnosti sekvencneho programu po paralelizacii je cca: %.2f", zvysenie_vykonnosti(tseq, tpar));

	return 0;
}