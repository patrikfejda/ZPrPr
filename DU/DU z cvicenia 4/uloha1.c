//hotovo

#pragma warning(disable : 4996)
#pragma warning(disable : 6031)
#include <stdio.h>

int main()
{
	int vyska, sirka, i, j, k, m;
	
	//Nacitavam kym nebude dobry vstup
	do {
		printf("Zadajte vysku a sirku: ");
		scanf("%i %i", &vyska, &sirka);

	} while (!(vyska % 2) || !(sirka % 2));

	//Horne rameno kriza
	for (i = 0; i < (vyska / 2) ; i++) {
		for (j = 0; j < (sirka / 2); j++) {
			putchar(' ');
		}
		putchar('*');
		for (k = 0; k < (sirka / 2); k++) {
			putchar(' ');
		}
		putchar('\n');
	}

	//Vodorovna cast kriza
	for (m = 0; m < sirka; m++) {
		putchar('*');
	}
	
	putchar('\n');

	//Spodne rameno kriza
	for (i = 0; i < (vyska / 2); i++) {
		for (j = 0; j < (sirka / 2); j++) {
			putchar(' ');
		}
		putchar('*');
		for (k = 0; k < (sirka / 2); k++) {
			putchar(' ');
		}
		putchar('\n');
	}

	return 0;
}