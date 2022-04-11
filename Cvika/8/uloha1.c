// Vytvorte  štruktúru s názvom Zajazd, ktorá bude obsahovať položky
// id (integer),
// osoba (ukazovateľ na char),
// mesto (ukazovateľ na char),
// rok_nar (integer),
// poc_dni (integer).

// Vytvorte statické pole štruktúry pre 10 osôb, toto pole naplňte údajmi (z textového súboru alebo klávesnice)
// a vypíšte na obrazovku. Napĺňanie a výpis realizujte cez funkciu  a pridajte ďalšiu operáciu (realizovanú cez funkciu)
// s načítanou štruktúrou (zoradenie, vyhľadanie a pod.) .

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct zajazd
{
	int id;
	char *osoba;
	char *mesto;
	int rok_nar;
	int poc_dni;
} Zajazd;

int vypis_udajov(Zajazd osoba[10])
{
	for (int i = 0; i < 10; i++)
	{
		printf("%i, %s, %s, %i, %i\n", osoba[i].id, osoba[i].osoba, osoba[i].mesto, osoba[i].rok_nar, osoba[i].poc_dni);
	}

	return 0;
}

int vyhladanie(Zajazd osoba[10])
{

	int id;
	printf("Zadajte ID osoby, o ktorej chcete zobrazit info: ");
	fflush(stdin);
	scanf("%i", &id);

	if (id < 0 || id > 10)
	{
		printf("Take ID neznam.");
		return 0;
	}

	printf("Meno a priezvisko: %s\n", osoba[id].osoba);
	printf("Mesto: %s\n", osoba[id].mesto);
	printf("Rok narodenia: %i\n", osoba[id].rok_nar);
	printf("Pocet dni: %i\n", osoba[id].poc_dni);

	return 0;
}

int main()
{
	Zajazd osoba[10];
	char random_meno[20] = {"XXXXXXXXXX"};

	for (int i = 0; i < 10; i++)
	{

		osoba[i].id = i;
		osoba[i].rok_nar = 1970 + rand() % 50;
		osoba[i].poc_dni = 1 + rand() % 10;

		osoba[i].osoba = (char *)malloc(30 * sizeof(char));
		for (int a = 0; a < 19; a++)
		{
			if (a == 0)
			{
				random_meno[a] = 'A' + rand() % ('z' - 'a');
			}
			else if (a == 19)
			{
				random_meno[a] = '\0';
			}
			else if (a == 10)
			{
				random_meno[a] = ' ';
			}
			else
				random_meno[a] = 'a' + rand() % ('z' - 'a');
		}
		strcpy(osoba[i].osoba, random_meno);
		osoba[i].mesto = (char *)malloc(30 * sizeof(char));
		for (int a = 0; a < 10; a++)
		{
			if (a == 0)
			{
				random_meno[a] = 'A' + rand() % ('z' - 'a');
			}
			else if (a == 9)
			{
				random_meno[a] = '\0';
			}
			else
				random_meno[a] = 'a' + rand() % ('z' - 'a');
		}
		strcpy(osoba[i].mesto, random_meno);
	}

	vypis_udajov(osoba);

	vyhladanie(osoba);

	return 0;
}

//gcc uloha1.c -std=c99 -pedantic -Wall -Werror -Wextra -o uloha ;; ./uloha