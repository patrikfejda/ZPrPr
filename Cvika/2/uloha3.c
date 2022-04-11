#include <stdio.h>
#include <math.h>


int zisti_prvocislo(int x)
{
	for (int delitel = 2; delitel <= sqrt(x); delitel++)
	{
		if (x % delitel == 0)
		{
			return -1;
		}
	}
	return 1;
}

int main()
{
	int a, b, naspon_jedno_prvocislo = 0;
	printf("Zadajte 2 cele cisla oddelene medzerou: ");
	scanf("%i %i", &a, &b);

	for (int i = a; i <= b; i++)
	{
		if (zisti_prvocislo(i) == 1)
		{
			naspon_jedno_prvocislo = 1;
			printf("%i ", i);
		}
	}
	if (!naspon_jedno_prvocislo)
		printf("ANI JEDNO PRVOCISLO!");
	printf("\n");

	return 0;
}

//gcc uloha3.c -std=c99 -pedantic -Wall -Werror -Wextra -o uloha3