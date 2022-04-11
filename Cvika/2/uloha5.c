#include <stdio.h>
#include <stdlib.h>

void vypis(float x, int i, FILE *subor)
{
	//printf("%i * %.2f = %.2f\n",i, x, i*x);
	fprintf(subor, "%i * %.2f = %.2f\n",i, x, i*x);
}

int main()
{
    FILE *subor = fopen("nasobky.txt", "w");

	if (subor == NULL) 
    { 
        printf("Problem s nasobky.txt!"); 
        return 0; 
    } 
	
	float x;
	printf("Zadajte realne cislo: ");
	scanf("%f", &x);

	for (int i = 1; i<= 10; i++) {
		vypis(x,i, subor);
	}

	return 0;
}

//gcc uloha5.c -std=c99 -pedantic -Wall -Werror -Wextra -o uloha5