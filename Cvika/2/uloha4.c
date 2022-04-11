#include <stdio.h>

long reverzne_cislo(long x)
{
	int cislovka_na_pozicii;
	long opacne = 0;
	while (x != 0)
	{
		cislovka_na_pozicii = x % 10;
		opacne *= 10;
		opacne += cislovka_na_pozicii;
		x /= 10;
	}
	return opacne;
}

int je_palindrom(long x, long reverzne_cislo)
{
	if (x == reverzne_cislo)
	{

		printf("CISLO %ld JE PALINDROM", x);
		return 0;
	}
	else
	{
		printf("CISLO %ld NIE JE PALINDROM", x);
		return 0;
	}
}

int main()
{
	long x;
	printf("Zadajte cele cislo: ");

	while (scanf("%ld", &x))
	{

		printf("%ld\n", reverzne_cislo(x));
		je_palindrom(x, reverzne_cislo(x));
		printf("\n");
	}

	return 0;
}

//gcc uloha4.c -std=c99 -pedantic -Wall -Werror -Wextra -o uloha4