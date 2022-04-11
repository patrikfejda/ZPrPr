// Úloha 3.7: Napíšte program, ktorý rekurzívnou funkciou vypočíta ciferný súčet čísla. Na
// vstupe je dané kladné celé číslo N, na výstup program vypíše jedno číslo: ciferný súčet
// čísla N.
// Ukážka vstupu:
// 56
// Výstup pre ukážkový vstup:
// 11

#include <stdio.h>

// credits: https://www.javatpoint.com/sum-of-digits-program-in-c
// int iter_sum_sucet(int n)
// {
// 	int sum = 0;
// 	while (n > 0)
// 	{
// 		sum = sum + n % 10;
// 		n = n / 10;
// 	}
// 	return sum;
// }

int rekur_sum_sucet(int n)
{
	if (n > 0)
		return n % 10 + rekur_sum_sucet(n / 10);
	else
		return 0;
}

int main()
{
	int n;
	printf("Zadaj cislo: ");
	scanf("%i", &n);

	// na porovnanie
	//printf("(ITER) Ciferny sucet je: %i\n", iter_sum_sucet(n));

	printf("(REKUR) Ciferny sucet je: %i", rekur_sum_sucet(n));

	return 0;
}

//gcc uloha7.c -std=c99 -pedantic -Wall -Werror -Wextra -o uloha