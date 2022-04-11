#include <stdio.h>
#include <math.h>

void tabulka_mocnin(float x, int n)
{
	int umocnene = 1;
	for (int i = 1; i <= n; i++)
	{
		umocnene *= x;
		printf("%.2f ^ %i = %i\n", x, i, umocnene);
	}
}

int main()
{
	float x;
	int n;
	printf("Zadajte 2 cisla oddelene medzerou: ");
	scanf("%f %i", &x, &n);

	tabulka_mocnin(x, n);

	return 0;
}

//gcc uloha2.c -std=c99 -pedantic -Wall -Werror -Wextra -o uloha2