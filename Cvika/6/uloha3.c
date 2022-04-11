// done

// Napíšte rekurzívnu funkciu dlzka(), ktorá vráti dĺžku reťazca.
// Funkciu použite v programe, ktorý pre každý reťazec na štandardnom vstupu
// vypíše jeho dĺžku, oddelenú medzerou. Reťazce na vstupe sú oddelené
// medzerou alebo novým riadkom. Na posledný riadok program vypíše
// správu Najdlhsie slovo ma X znakov, kde X je počet znakov v najdlhšom slove.
// Ukážka vstupu
// Smolkovia su najlepsi!
// 1
// Výstup pre ukážkový vstup
// 9 2 9
// Najdlhsie slovo ma 9 znakov.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int dlzka(char retazec[])
{
	if (strlen(retazec) == 1)
	{
		return 1;
	}
	else
	{
		return 1 + dlzka(retazec + 1);
	}
}

int main()
{
	char retazec[50];
	int max = 0;
	printf("ESCAPE CHAR: . \n");

	while (scanf(" %s", retazec) > 0)
	{
		if (retazec[0] == '.'){
			break;
		}
		printf("%i ", dlzka(retazec));
		if (dlzka(retazec) > max)
		{
			max = dlzka(retazec);
		}
	}

	printf("%i", max);

	return 0;
}

//gcc uloha3.c -std=c99 -pedantic -Wall -Werror -Wextra -o uloha