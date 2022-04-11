#pragma warning(disable: 4996)
#pragma warning(disable: 6031)
#include <stdio.h>

int main() {

	int N; 
	scanf("%i", &N);

	if (N < 1 || N > 15) {
		printf("Cislo nie je z daneho intervalu.");
		return 1;
	}

	for (int riadok = 1; riadok <= N; riadok++) {
		printf("%i:", riadok);
		for (int s = N; s >= riadok; s--) {
			printf(" %i", s);
		}
		printf("\n");	
	}
	return 0;
}
