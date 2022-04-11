#pragma warning(disable: 4996)
#pragma warning(disable: 6031)
#include <stdio.h>

int main() {

	FILE* vstup, * vystup;
	int a, b, faktorial, i;


	//VSTUP
	if ((vstup = fopen("./cinitele.txt", "r")) == NULL) {
		printf("Vstupny subor sa neda otvorit\n");
		return 0;
	}
	else {
		printf("Vstupny subor je spravne otvoreny\n");
	}

	//VYSTUP
	if ((vystup = fopen("./vysledky.txt", "w")) == NULL) {
		printf("Vystupny subor sa neda otvorit\n");
		return 0;
	}
	else {
		printf("Vystupny subor je spravne otvoreny\n");
	}


	while (fscanf(vstup, "%d %d\n", &a, &b) != EOF) {
		faktorial = 1;
		if (a * b < 12) {
			for (i = 0; i < a * b; i++) {
				faktorial *= a * b - i;
			}
			fprintf(vystup,"%i * %i = %i F: %i\n", a, b, a * b, faktorial);
		}
		else {
			fprintf(vystup,"%i * %i = %i F: ###\n", a, b, a * b);
		}

	}

	fclose(vystup);
	return 0;
}