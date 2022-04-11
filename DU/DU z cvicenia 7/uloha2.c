// Napíšte program, v ktorom funkcia main() načíta celé číslo a vytvorí pole o veľkosti 5,
// následne zavolá funkciu void vytvorpole(), ktorá toto pole naplní hodnotami. Ak
// zadané číslo bolo párne, naplní ho párnymi číslami od 32 vyššie, ak nepárne, naplní
// ho nepárnymi číslami od 73 vyššie. Funkcia main() toto pole následne celé vypíše.

#pragma warning(disable : 4996)
#pragma warning(disable : 6031)
#include <stdio.h>

int vytvorpole(int a, int pole[])
{
	if (a % 2)
	{
		for (int i = 0; i < 5; i++)
		{
			pole[i] = 73 + (2 * i + 2);
		}
		return 0;
	}
	if (!(a % 2))
	{
		for (int i = 0; i < 5; i++)
		{
			pole[i] = 32 + (2 * i + 2);
		}
		return 0;
	}
}

int main()
{
	int a, pole[5];
	printf("ZADAJTE CELE CISLO: ");
	scanf("%i", &a);
	vytvorpole(a, pole);
	printf("\nPOLE:");
	for (int i = 0; i < 5; i++)
	{
		printf(" %i", pole[i]);
	}
	return 0;
}