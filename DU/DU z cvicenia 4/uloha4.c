#pragma warning(disable: 4996)
#pragma warning(disable: 6031)
#include <stdio.h>

int main() {

	FILE* vstup, * vystup;
	char riadok_text[1000];
	int riadok_pocet = 1;

	//VSTUP
	if ((vstup = fopen("./vstup.txt", "r")) == NULL) {
		printf("Vstupny subor sa neda otvorit\n");
	}
	else {
		printf("Vstupny subor je spravne otvoreny\n");
	}

	//VYSTUP
	if ((vystup = fopen("./vystup.txt", "w")) == NULL) {
		printf("Vystupny subor sa neda otvorit\n");
	}
	else {
		printf("Vystupny subor je spravne otvoreny\n");
	}

	while (fgets(riadok_text, 1000, vstup) != NULL) {
		if (riadok_pocet % 2 == 0) {
			printf("%s", riadok_text);
			fputs(riadok_text, vystup);
		}
		riadok_pocet++;
	}

	fclose(vystup);
	return 0;
}