#pragma warning(disable: 4996)
#pragma warning(disable: 6031)
#include <stdio.h>

int main()
{
	char pismeno1, pismeno2;
	printf("Zadajte 2 male pismena oddelene medzerou: \n");
	scanf("%c %c", &pismeno1, &pismeno2);
	printf("%c %i \n", pismeno1 - ' ', pismeno1 - ' ');
	printf("%c %i \n", pismeno2 - ' ', pismeno2 - ' ');
	return 0;
}