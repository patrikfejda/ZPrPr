// Úloha 5.7: Napíšte program, ktorý zistí počet riadkov n v súbore neusporiadane.txt,
// alokuje v pamäti dva bloky po n položiek reálnych čísel a do prvého bloku
// načíta čísla zo súboru. Predpokladajte, že súbor obsahuje v každom riadku
// práve jedno reálne číslo. Predpokladajte, že súbor neobsahuje rovnaké číslo
// viackrát. Potom prekopírujte obsah z prvého bloku do druhého tak, aby čísla v
// druhom bloku boli vzostupne usporiadané. Nakoniec program zapíše obsah
// usporiadaného bloku do suboru usporiadane.txt. Program negeneruje žiaden
// výstup na štandardný výstup. Využite ukazovateľovú aritmetiku.
// Ukážka súboru neusporiadane.txt:
// 4.8
// 9.26
// 1.45
// Ukážka súboru usporiadane.txt po vykonaní programu:
// 1.45
// 4.8
// 9.26

#include <stdio.h>
#include <stdlib.h>

// funkcia prebrata z mojho projektu:

FILE *open_file(char file_name[32], char mode[5])
{
	FILE *file;
	if ((file = fopen(file_name, mode)) == NULL)
	{
		printf("Subor sa nepodarilo otvorit.\n");
		exit(1);
	}
	return file;
}

// funkcia prebrata z mojho projektu:

int count_lines_in_file(FILE *file)
{
	char line_text[1000];
	int lines = 0;
	while (fgets(line_text, 1000, file) != NULL)
	{
		lines++;
	}

	fseek(file, 0, SEEK_SET);

	return lines;
}

// kod inspirovany z: https://stackoverflow.com/questions/36940643/sorting-an-array-of-double-in-c/36941720

void sortpole(double pole[], int dlzka_pola)
{
	double temp;
	for (int i = 0; i < dlzka_pola; ++i)
	{
		for (int j = i + 1; j < dlzka_pola; ++j)
		{
			if (pole[i] > pole[j])
			{
				temp = pole[i];
				pole[i] = pole[j];
				pole[j] = temp;
			}
		}
	}
}

// koniec inspirovaneho kodu

int main()
{
	FILE *f1 = NULL, *f2 = NULL;

	f1 = open_file("neusporiadane.txt", "r");
	f2 = open_file("usporiadane.txt", "w");

	double *blok1, *blok2;
	int pocet_riadkov = count_lines_in_file(f1);

	blok1 = (double *)malloc(pocet_riadkov * sizeof(double));
	blok2 = (double *)malloc(pocet_riadkov * sizeof(double));

	for (int i = 0; i < pocet_riadkov; i++)
	{
		fscanf(f1, "%lf", &blok1[i]);
		blok2[i] = blok1[i];
		//printf("%lf\n", blok1[i]);
	}
	//printf("++++++++\n");

	sortpole(blok2, pocet_riadkov);

	for (int i = 0; i < pocet_riadkov; i++)
	{
		fprintf(f2, "%.3lf\n", blok2[i]);
	}

	return 0;
}

//gcc uloha7.c -std=c99 -pedantic -Wall -Werror -Wextra -o uloha