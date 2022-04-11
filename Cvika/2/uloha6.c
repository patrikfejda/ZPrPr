#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE *subor = fopen("text.txt", "r");

	if (subor == NULL)
	{
		printf("Problem s text.txt!");
		return 0;
	}

	int pocet_medzier = 0, chcem_pokracovat = 1;
	char znak;

	while ((znak = fgetc(subor)) && chcem_pokracovat)
	{
		switch (znak)
			{
			case 'x':
				printf("Precital som X\n");
				break;
			case 'X':
				printf("Precital som X\n");
				break;
			case 'y':
				printf("Precital som Y\n");
				break;
			case 'Y':
				printf("Precital som Y\n");
				break;
			case '#':
				printf("Precital som riadiaci znak\n");
				break;
			case '$':
				printf("Precital som riadiaci znak\n");
				break;
			case '&':
				printf("Precital som riadiaci znak\n");
				break;
			case ' ':
				pocet_medzier += 1;
				break;
			case '*':
				printf("KONIEC\n");
				chcem_pokracovat = 0;
				break;
			}
	}

	printf("Pocet medzier: %i", pocet_medzier);
	return 0;
}

//gcc uloha6.c -std=c99 -pedantic -Wall -Werror -Wextra -o uloha6