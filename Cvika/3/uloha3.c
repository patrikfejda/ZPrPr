// Úloha 3.3: Napíšte program, ktorý určí, či majú dva
// súbory prvy.txt a druhy.txt rovnaký obsah. Program nečíta žiadne dáta zo
// 1
// štandardného vstupu. Ak majú súbory rovnaký obsah, program vypíše Subory su
// identicke Ak súbory rovnaký obsah nemajú, vypíše program Pocet roznych
// znakov: nasledovaný medzerou, počtom rôznych znakov v súboroch a ukončený koncom
// riadku. i-ty znak v jednom súbore považujte za rôzny od i-teho znaku v druhom súbore,
// ak oba znaky existujú (t.j. ani jeden súbor nemá menej ako i znakov) a príslušné znaky
// sa nerovnajú. Ak majú súbory nerovnakú dĺžku, na výstup program vypíše ešte jeden
// riadok obsahujúci správu Jeden zo suborov je dlhsi o x znakov Pričom x je počet znakov
// o ktoré je jeden zo súborov dlhší. Správa je nasledovaná koncom riadku.
// Ukážka súboru prvy.txt:
// ahoj
// Ukážka súboru druhy.txt:
// ahujx
// *
// Výstup pre ukážkové súbory:
// Pocet roznych znakov: 1
// Jeden zo suborov je dlhsi o 3 znakov

#include <stdio.h>
#include <math.h>

int main()
{

	//praca so subormi

	FILE *f1 = fopen("prvy.txt", "r");
	if (f1 == NULL)
	{
		printf("Problem s prvy.txt!");
		return 0;
	}

	FILE *f2 = fopen("druhy.txt", "r");
	if (f2 == NULL)
	{
		printf("Problem s druhy.txt!");
		return 0;
	}

	//premenne

	char znak1, znak2;
	int rozdiel_dlzky_suborov = 0;
	int pocet_rozdielnych_znakov = 0;

	do
	{
		znak1 = fgetc(f1);
		znak2 = fgetc(f2);

		if (znak1 < 0 && znak2 < 0)
		{
			//printf("break\n");
			break;
		}
		else if (znak1 < 0 || znak2 < 0)
		{
			rozdiel_dlzky_suborov++;
		}

		else if (znak1 != znak2)
		{
			pocet_rozdielnych_znakov++;
		}

	} while (1);

	if (pocet_rozdielnych_znakov)
	{
		printf("Pocet rozdielnych znakov: %i\n", pocet_rozdielnych_znakov);
	}
	else if (!rozdiel_dlzky_suborov)
	{
		printf("Subory su rovnake.\n");
	}
	if (rozdiel_dlzky_suborov)
	{
		printf("Rozdiel dlzky: %i\n", rozdiel_dlzky_suborov);
	}

	return 0;
}

//gcc uloha3.c -std=c99 -pedantic -Wall -Werror -Wextra -o uloha