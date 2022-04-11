// Úloha 3.2: Napíšte program, ktorý číta znaky zo súboru vstup.txt po riadkoch
// (pozrite si dokumentáciu s príkladmi použitia funkcií fgets
// http://www.cplusplus.com/reference/cstdio/fgets/ a fputs
// http://www.cplusplus.com/reference/cstdio/fputs/). Každý riadok prepíše do
// súboru cisla.txt. Po každom prepísanom riadku na ďalšom riadku uvedie
// počet malých písmen z prečítaného riadku. Ak súbor už predtým existoval a
// obsahoval nejaké dáta, program tieto dáta nezmaže a svoj výstup napíše na
// koniec súboru cisla.txt. Program nečíta žiaden vstup zo štandardného vstupu
// a nevypisuje žiaden výstup na štandardný výstup. Predpokladajte, že
// posledný riadok je vždy ukončený koncom riadku.
// Ukážka súboru vstup.txt:
// ahoj123
// x*Y*z
// Ukážka súboru cisla.txt pred spustením programu:
// qwerty
// 6
// Súbor cisla.txt po spustení programu:
// qwerty
// 6
// ahoj123
// 4
// x*Y*z
// 2

#include <stdio.h>

#define MaxDlzkaRiadkuVsubore 100

int main()
{
	int pocet_lowercase_pismen_riadok, i;

	FILE *fr = fopen("vstup.txt", "r");
	if (fr == NULL)
	{
		printf("Problem s vstup.txt!");
		return 0;
	}

	FILE *fa = fopen("cisla.txt", "a");
	if (fa == NULL)
	{
		printf("Problem s cisla.txt!");
		return 0;
	}

	char riadok_text[MaxDlzkaRiadkuVsubore];

	while (fgets(riadok_text, MaxDlzkaRiadkuVsubore, fr) != NULL)
	{
		fputs(riadok_text, fa);


		pocet_lowercase_pismen_riadok = 0;
		i = 0;

		while (riadok_text[i])
		{
			if (riadok_text[i] >= 'a' && riadok_text[i] <= 'z')
			{
				pocet_lowercase_pismen_riadok++;
			}

			i++;
			
		}
		fprintf(fa, "%i\n", pocet_lowercase_pismen_riadok);
	}

	fputs("\n======\n",fa);

	return 0;
}

//gcc uloha2.c -std=c99 -pedantic -Wall -Werror -Wextra -o uloha