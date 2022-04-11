// DONE

// Úloha 5.3: Napíšte program, ktorý bude počítať hodnoty funkcií a ich derivácií
// v danom bode. Program obsahuje aspoň dve derivovateľné funkcie napríklad
// f1(x) = 10x -19, f2(x) = 5/x2
// (ak chcete pracovať s komplikovanejšími
// funkciami pozrite si knižnicu math
// https://en.cppreference.com/w/c/numeric/math
// http://www.cplusplus.com/reference/cmath/). Funkcia deriv vypočíta
// numerickú deriváciu funkcie f() v bode x podľa vzťahu: f‘(x) =
// f ( x+ϵ )−f ( x )
// ϵ
// kde ϵ je presnosť výpočtu (napr. 0.001). Program načíta zo štandardného
// vstupu dve reálne čísla r1 a r2 a vypíše tabuľku hodnôt funkcií f1 a f2 a ich
// derivácií na intervale <r1, r2> s krokom STEP.

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define STEP 0.1
#define PRESNOST_VYPOCTU_DERIVACIE 0.001

double deriv(double (*f)(double), double x)
{
	return ((f(x + PRESNOST_VYPOCTU_DERIVACIE) - f(x)) / PRESNOST_VYPOCTU_DERIVACIE);
}

double f1(double x)
{
	return (10 * x - 19);
}

double f2(double x)
{
	return (5 / (x * x));
}

int main()
{

	double r1, r2;

	printf("Zadajte interval <r1,r2>: ");
	scanf("%lf %lf", &r1, &r2);

	if (r1 >= r2) {
		printf("R1 MUSI BYT MENSIE AKO R2!!");
		exit(1);
	}

	printf("|   x  | f1(x) | f1`(x) |--|   x  | f2(x) | f2`(x) |\n");
	printf("----------------------------------------------------\n");

	for (double i = r1; i < r2 + STEP; i += STEP)
	{
		printf("| %.2lf | %.2lf  | %.2lf  |--| %.2lf | %.2lf  | %.2lf  |\n", i, f1(i), deriv(f1, i), i, f2(i), deriv(f2, i));
	}

	return 0;
}

//gcc uloha3.c -std=c99 -pedantic -Wall -Werror -Wextra -o uloha