// done

// Napíšte rekurzívnu funkciu najdi(char *s, char c), ktorá zisti, ci sa
// znak c nachádza v reťazci s. Funkciu použite v programe, ktorý pre každý
// reťazec na štandardnom vstupe vypíše pozíciu znaku c v reťazci s.
// Ukážka vstupu
// Smolkovia k
// Smolkovia r
// Výstup pre ukážkový vstup
// Znak k je na pozicii 4 v Smolkovia
// Znak r sa v Smolkovia nenachadza

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int najdi(char *s, char c)
{
	if (strlen(s) == 0)
	{
		return 0;
	}
	else
	{
		if (s[0] == c)
		{
			return 1;
		}
		else if (najdi(s + 1, c) >= 1)
		{
			return 1 + najdi(s + 1, c);
		}
		else
		{
			return 0;
		}
	}
}

int main()
{
	char retazec[50];
	char znak;
	int vysledok = 0;
	printf("ESCAPE CHAR: . \n");

	while (scanf(" %s", retazec) > 0)
	{
		if (retazec[0] == '.')
		{
			break;
		}
		vysledok = 0;

		scanf(" %c", &znak);

		vysledok = najdi(retazec, znak);

		if (vysledok == 0)
		{
			printf("Znak %c sa v %s nenachadza\n", znak, retazec);
		}
		else
		{
			printf("Znak %c je na pozicii %i v %s\n", znak, vysledok, retazec);
		}
		fflush(stdin);
	}

	return 0;
}

//gcc uloha3.c -std=c99 -pedantic -Wall -Werror -Wextra -o uloha ;; .\uloha