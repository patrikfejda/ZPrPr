#pragma warning(disable: 4996)
#pragma warning(disable: 6031)
#include <stdio.h>

int main() {
	unsigned int N, i, factorial = 1;
	printf("Zadajte cele kladne cislo: ");
	scanf("%i", &N);
	for (i = 0; i < N; i++) {
		factorial *= N - i;
	}
	printf("Fajtorial cisla %i je %i",N, factorial);
	return 0;
}