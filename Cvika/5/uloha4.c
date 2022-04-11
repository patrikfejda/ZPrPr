// DONE

// Úloha 5.4: Napíšte program, ktorý z prvého riadku vstupu načíta celé číslo n a
// alokuje v pamäti blok n položiek pre znaky. Potom zo štandardného vstupu
// načíta n znakov a vypíše ich odzadu. (Využite ukazovateľovú aritmetiku.)
// Ukážka vstupu:
// 4
// ahojky
// Výstup pre ukážkový vstup:
// joha

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n;
	char *pole =NULL;

	printf("Zadaj velkost pola: ");
	scanf("%i", &n);

	pole = (char *)malloc(n * sizeof(char));

	printf("Zadajte vyraz: ");
	scanf("%s",pole);

	for (int i = n-1; i>=0;i--){
		//printf("%c\n",(pole[i])); // toto je to iste ako riadok dole
		printf("%c",*(pole+i));
	}

	return 0;
}

//gcc uloha4.c -std=c99 -pedantic -Wall -Werror -Wextra -o uloha