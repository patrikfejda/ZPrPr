#pragma warning(disable : 4996)
#pragma warning(disable : 6031)
#include <stdio.h>

int stav_uctu = 10000;

int instrukcie(void)
{
	printf(
		"\nCo si prajete vykonat?\n"
		"\n1. vlozit peniaze na ucet\n"
		"2. vybrat peniaze z uctu\n"
		"3. zobrazenie stavu uctu\n"
		"4. koniec cinnosti automatu\n"
		"\nvyberte moznost: ");
}

int vklad(int vyska)
{
	stav_uctu += vyska;
	printf("\nVas stav uctu bol navyseny o %i eur", vyska);
}

int vyber(int vyska)
{
	stav_uctu -= vyska;
	printf("\nVvas stav uctu bol znizeny o %i eur", vyska);
}

int stav(void)
{
	printf("\nVas stav je %i eur", stav_uctu);
}

int main()
{
	int volba, suma;
	stav();
	do
	{
		instrukcie();
		scanf("%i", &volba);

		if (volba == 1) {
			printf("\nKolko eur si prajete vlozit na ucet? ");
			scanf("%i", &suma);
			vklad(suma);
		}
		else if (volba == 2) {
			printf("\nKolko eur si prajete vybrat z uctu? ");
				scanf("%i", &suma);
			vyber(suma);
		}
		else if (volba == 3) {
			stav();
		}
	} while (volba != 4);

	printf("\nKONIEC");

	return 0;
}





