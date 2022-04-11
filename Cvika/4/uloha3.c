// DONE

// Úloha 4.3: Vytvorte funkciu, ktorá prevedie zlomok do základného tvaru.
// Funkcia má ako argumenty dve čísla (volané odkazom). Argumenty vyjadrujú
// čitateľa a menovateľa zlomku. Funkciu otestujte v krátkom programe, ktorého
// vstupom je jeden riadok obsahujúci 2 celé čísla oddelené medzerou. Prvé z
// čísel predstavuje čitateľa a druhé menovateľa zlomku. Výstupom programu je
// riadok obsahujúci správu Zakladny tvar zlomku: c/m, kde c je čitateľ a m menovateľ
// zlomku v základnom tvare.
// Ukážka vstupu:
// 12 60
// Výstup pre ukážkový vstup:
// Zakladny tvar zlomku: 1/5

#include <stdio.h>
#include <math.h>

void zakladny_tvar(int *c, int *m)
{
	int a, b;
	int delitel = 0;

	// i need: a >= b because the for iteration interval

	if (*c >= *m)
	{

		a = *c;
		b = *m;
	}
	else
	{

		b = *c;
		a = *m;
	}

	for (int i = 1; i < a; i++)
	{
		if (!(a % i) && !(b % i))
		{
			delitel = i;
		}
	}

	*c /= delitel;
	*m /= delitel;



}

int main()
{

	int c, m;

	printf("Zadaj 2 cele cisla oddelene medzerou: ");
	scanf("%i %i", &c, &m);
	printf("Zakladny tvar: %i / %i\n", c, m);


	zakladny_tvar(&c, &m);

	printf("Zakladny tvar: %i / %i\n", c, m);

	return 0;
}

//gcc uloha3.c -std=c99 -pedantic -Wall -Werror -Wextra -o uloha