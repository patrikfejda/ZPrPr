// DONE

// Úloha 4.5: Napíšte program, ktorý zo štandardného vstupu načíta reálne čísla
// a, b, c. Pomocou funkcie kvadraticka_rovnica určí korene kvadratickej
// rovnice ax2 + bx + c = 0 (ako riešiť kvadratickú rovnicu s jednou neznámou
// nájdete napr. na https://sk.wikipedia.org/wiki/Kvadratick%C3%A1_rovnica).
// Funkcia kvadraticka_rovnica vráti počet koreňov a ich hodnoty. Program
// návratové hodnoty vypíše na konzolu. Môžete predpokladať, že koeficient a je
// rôzny od 0 (čo ak by sa rovnal 0, ako to ovplyvní program?). Odmocninu
// počítajte pomocou funkcie sqrt z knižnice math.


#include <stdio.h>
#include <math.h>



int kvadraticka_rovnica(float a, float b, float c, float *x1, float *x2) {
	float D;
	D = b*b - 4 * a *c;
	//printf("D: %f \n",D);

	if (D < 0) {
		return 0;
	}
	else if (D == 0) {
		*x1 = -b / 2*a;
		return 1;
	}
	else {
		*x1 = ( -b + sqrt(D) ) / (2*a);
		*x2 = ( -b - sqrt(D) ) / (2*a);
		//printf(" / %.3f %.3f / \n",*x1,*x2);
		return 2;
	}
}

int main()
{
	float a, b, c;
	int pocet_korenov;
	float x1, x2;

	printf("Zadaj 3 realne cisla oddelene medzerou: ");
	scanf("%f %f %f", &a, &b, &c);

	if (a == 0) {
		printf("'A' musi byt rozne od 0.");
		return 1;
	}

	pocet_korenov = kvadraticka_rovnica(a,b,c,&x1,&x2);


	if (pocet_korenov == 0) {
		printf("Pocet korenov je nula!");
	}
	else if (pocet_korenov == 1) {
		printf("Koren je len jeden: &f", x1);
	}
	else if (pocet_korenov==2) {
		printf("Korene su: %.3f %.3f", x1,x2);
	}

	return 0;
}

//gcc uloha5.c -std=c99 -pedantic -Wall -Werror -Wextra -o uloha5