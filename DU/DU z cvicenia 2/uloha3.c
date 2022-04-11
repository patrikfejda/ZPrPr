#pragma warning(disable: 4996)
#pragma warning(disable: 6031)
#include <stdio.h>

int main()
{
	int cislo;
	printf("Zadajte lubovolne cislo: ");
	scanf("%i", &cislo);
	
	if (cislo % 2 == 0) {
		printf("Cislo je parne.");
	}
	else {
		printf("Cislo je neparne.");
	}

	return 0;
}
