// Vrátnik v kine dostal za úlohu zistiť, kto chodí do kina najčastejšie.
// Pomôžte mu a napíšte program, ktorý to spraví namiesto neho. Na vstupe sú
// mená, každé tvorí jeden reťazec bez medzier. Na výstup napíšte meno, ktoré
// sa na vstupe vyskytovalo najčastejšie. Predpokladajte, že do kina chodí
// najviac 100 rôznych ľudí.
// Pomôcka: Na porovnanie reťazcov môžete použiť funkciu strcmp() z knižnice
// string.h - http://www.cplusplus.com/reference/cstring/strcmp/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXDLZKARIADKU 64

int main()
{
	FILE *file;
	if ((file = fopen("mena.txt", "r")) == NULL)
	{
		printf("ERROR!");
		return 0;
	}

	char names[100][64];
	int pocet_krat[100];

	for (int x = 0; x < 100; x++)
	{
		pocet_krat[x] = 1;
	}
	char name_already_exists = 0;

	char riadok[MAXDLZKARIADKU];
	int index = 0;

	while (fgets(riadok, MAXDLZKARIADKU, file) != NULL)
	{
		name_already_exists = 0;
		// zistim ci meno existuje a ak ano tak pripocitam
		for (int index_meno_zoznam = 0; index_meno_zoznam < 100; index_meno_zoznam++)
		{
			if (0 == strcmp(names[index_meno_zoznam], riadok))
			{
				name_already_exists = 1;
				pocet_krat[index_meno_zoznam] += 1;
			}
		}

		// ak neexsituje tak vytvorim
		if (!name_already_exists)
		{
			strcpy(names[index++], riadok);
		}
	}

	int max_index = 0;
	for (int x = 0; x < 100; x++)
	{
		if (pocet_krat[x] > pocet_krat[max_index])
		{
			max_index = x;
		}
	}

	printf("Najviac: %i krat prisiel: %s",pocet_krat[max_index],names[max_index]);
		fclose(file);
	printf("\nuspesne ukoncene\n");
	return 0;
}

//gcc uloha2.c -std=c99 -pedantic -Wall -Werror -Wextra -o uloha ;; ./uloha

// char name_already_exists = 0;
// for (int i = 0; i < 100; i++)
// {
// 	if (0 == strcmp(names[i], riadok))
// 	{
// 		name_already_exists = 1;
// 	}
// }

// if (name_already_exists)
// {
// 	pocet_krat[index]++;
// 	index++;
// }
// else
// {
// 	strcpy(names[index], riadok);
// 	pocet_krat[index] = 0;
// 	index++;
// }

// 	pocet_riadkov++;
// }
// rewind(file);

// printf("Nasiel som %i mien\n", index);

// // najdem max
// int index_s_max = 0;

// for (int i = 0; i < 100; i++)
// {
// 	if (pocet_krat[i] > pocet_krat[index_s_max])
// 	{
// 		index_s_max = i;
// 	}
// }

// printf("Najviac krat (%i-krat) bol/bola v kine: %s", pocet_krat[index_s_max], names[index_s_max]);