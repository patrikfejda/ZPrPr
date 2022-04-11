// done

// Napíšte program, ktorý zo vstupu postupne načítava slová – každé
// zapísané v samostatnom riadku, a vypisuje všetky slová obsahujúce hviezdičku. Pozície
// hviezdičiek vyznačí šípkami (znakmi ‘^’) v nasledujúcom riadku, pozri ukážkový príklad.
// Ukážka vstupu:
// toto*je*priklad*
// bezHviezdiciek
// *s*hviezdickami*
// Výstup pre ukážkový vstup:
// toto*je*priklad*
//  ^ ^ ^
// *s*hviezdickami*
// ^ ^ ^

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
		int obsahujem_hviezdicku = 0;
		for (unsigned i = 0; i < strlen(retazec); i++)
		{
			if (retazec[i] == '*')
			{
				obsahujem_hviezdicku++;
				break;
			}
		}
		if (obsahujem_hviezdicku)
		{
			printf("%s\n", retazec);
			for (unsigned i = 0; i < strlen(retazec); i++)
			{
				if (retazec[i] == '*')
				{
					printf("^");
				}
				else
				{
					printf(" ");
				}
			}
			printf("\n");
		}
	}

	return 0;
}

//gcc uloha1.c -std=c99 -pedantic -Wall -Werror -Wextra -o uloha ;; ./uloha