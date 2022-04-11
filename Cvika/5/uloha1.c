// DONE

// Úloha 5.1: Napíšte program, ktorý načíta z klávesnice tri čísla oddelené
// medzerami a vypíše ich súčet. Na uloženie prvých dvoch čísel použite
// smerníky na typ integer (pred načítaním si pre uloženie čísel dynamicky
// alokujte pamať), tretie číslo bude uložené do obyčajnej premennej typu
// integer.
// Výstupom programu bude jeden riadok vo formáte: cislo1 + cislo2 + cislo3 =
// sucet
// Ukážka vstupu:
// 1 2 3
// Výstup pre ukážkový vstup:
// 1 + 2 + 3 = 6


#include <stdio.h>
#include <stdlib.h>


int main()
{
	int *a = NULL, *b = NULL;
	int c = 0;

	a = (int *)malloc(1 * sizeof(int));
	b = (int *)malloc(1 * sizeof(int));

	printf("Zadaj 3 cisla oddelene medzerou: ");
	scanf("%i %i %i",a, b, &c);

	printf("Sucet: %i",*a+ *b+ c);





	return 0;
}

//gcc uloha1.c -std=c99 -pedantic -Wall -Werror -Wextra -o uloha