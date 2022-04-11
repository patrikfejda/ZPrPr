// done

// Napíšte rekurzívnu funkciu samohlasky(), ktorá vráti počet
// jednoduchých samohlások v reťazci. Znaky a, e, i, o, u, y považujte za
// jednoduché samohlásky, dvojhlásky neuvažujte (počítajte ako dve jednoduché
// samohlásky). Funkciu použite v programe, ktorý pre každý reťazec na
// štandardnom vstupu vypíše počet jednoduchých samohlások na samostatný
// riadok. Reťazce na vstupe sú oddelené medzerou alebo novým riadkom.
// Ukážka vstupu
// Smolkovia su najlepsi!
// Výstup pre ukážkový vstup
// 4
// 1
// 3

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int samohlasky(char retazec[])
{
	if (strlen(retazec) == 0)
	{
		return 0;
	}
	else
	{
		int je_samohlaska = 0;
		if ((retazec[0] == 'a') || (retazec[0] == 'e') || (retazec[0] == 'i') || (retazec[0] == 'o') || (retazec[0] == 'u') || (retazec[0] == 'A') || (retazec[0] == 'E') || (retazec[0] == 'I') || (retazec[0] == 'O') || (retazec[0] == 'U'))
		{
			je_samohlaska++;
		}
		return je_samohlaska + samohlasky(retazec + 1);
	}
}

int main()
{
	char retazec[50];
	printf("ESCAPE CHAR: . \n");

	while (scanf(" %s", retazec) > 0)
	{
		if (retazec[0] == '.')
		{
			break;
		}
		printf("%i\n", samohlasky(retazec));
	}

	return 0;
}

//gcc uloha4.c -std=c99 -pedantic -Wall -Werror -Wextra -o uloha