// Úloha 3.1: Napíšte program, ktorý zo štandardného vstupu (klávesnice) načíta
// znak. Ďalej číta znaky zo súboru znak.txt. Ak program prečítal zo
// štandardného vstupu (klávesnice) 's', vypisuje načítané znaky do
// súboru novy.txt. Ak načítal ľubovoľný iný znak, vypisuje načítané znaky na
// štandardný výstup (obrazovku). Súbor novy.txt alebo štandardný výstup bude
// teda obsahovať presnú kópiu obsahu súboru znak.txt.
// Ukážka vstupu:
// s
// Ukážka súboru znak.txt:
// abrakadabra
// bubu
// Súbor novy.txt pre ukážkový vstup:
// abrakadabra
// bubu

#include <stdio.h>

#define MaxDlzkaRiadkuVsubore 1000

int main()
{

	char znak_zo_vstupu, znak_zo_suboru;

	printf("Zadajte znak (s = vystup do suboru): ");
	scanf("%c", &znak_zo_vstupu);

	FILE *fr = fopen("znak.txt", "r");

	if (fr == NULL)
	{
		printf("Problem s znak.txt!");
		return 0;
	}

	if (znak_zo_vstupu == 's')
	{

		FILE *fw = fopen("novy.txt", "w");

		if (fw == NULL)
		{
			printf("Problem s novy.txt!");
			return 0;
		}

		while ((znak_zo_suboru = fgetc(fr)) != EOF)
		{
			fputc(znak_zo_suboru, fw);
		}

		fclose(fr);
	}
	else
	{
		while ((znak_zo_suboru = fgetc(fr)) != EOF)
		{
			putchar(znak_zo_suboru);
		}
	}

	return 0;
}

//gcc uloha1.c -std=c99 -pedantic -Wall -Werror -Wextra -o uloha