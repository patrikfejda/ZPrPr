//hotovo

#pragma warning(disable: 4996)
#pragma warning(disable: 6031)
#include <stdio.h>


int main()
{
	int vyska, sirka, riadok, i;

	//Nacitavam kym nebude dobry vstup
	do {
		printf("Zadajte vysku a sirku: ");
		scanf("%i %i", &vyska, &sirka);
	} while (!(vyska % 2) || !(sirka % 2));


	for (riadok = 1; riadok <= vyska; riadok++) {
		//hviedy: sirka - pocet cisel  
		for (i = 0; i < ((sirka - (2 * riadok - 1)) / 2); i++) {
			putchar('*');
		}

		for (i = 0; i < (2 * riadok - 1); i++) {
			if (riadok < 10) {
				putchar(48 + riadok);
			}
			else if (riadok == 10) {
				putchar('0');
			}
			else {
				putchar(54 + riadok);
			}
		}

		for (i = 0; i < ((sirka - (2 * riadok - 1)) / 2); i++) {
			putchar('*');
		}

		putchar('\n');
	}
	return 0;
}