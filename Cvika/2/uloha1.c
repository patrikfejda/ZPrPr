#include <stdio.h>

//najdi prvocislo z <f; g>

int main()
{
	int f, g;
	printf("Zadajte 2 cele cisla oddelene medzerou: ");
	scanf("%i %i", &f, &g);

	for (int i = f; i <= g; i++)
	{
		if (!(i % 3))
			printf("%i ", i);
	}
	printf("\n");

	return 0;
}

//gcc uloha1.c -std=c99 -pedantic -Wall -Werror -Wextra -o uloha1