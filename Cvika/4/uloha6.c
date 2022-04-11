// Úloha 4.6: Napíšte funkciu priesecnik_priamok, ktorá určí priesečník priamok
// [x1, y1] – [x2, y2] a [x3, y3] – [x4, y4]. Funkcia vráti 1 ak majú priamky
// jeden priesečník, inak vráti 0. Pri výpočte použite reprezentáciu priamok cez
// ich všeobecné rovnice ax + by + c = 0. Po úpravách dostávame, že a = y1 –
// y2, b = x2 – x1, c = x1*y2 - y1*x2. Z rovníc priamok vieme, že súradnice
// priesečníku sú x = b1*c2 – c1*b2, y = c1*a2 – a1*c2. Toto platí za
// predpokladu, že determinant = a1*b2 – b1*a2 je nenulový. Pozor jednotlivé
// súradnice priesečníka treba znormalizovať hodnotou determinantu.
// Vstup : A = (1, 1), B = (4, 4)
//  C = (1, 8), D = (2, 4)
// Vystup : Suradnice priesecniku priamok AB a CD su (2.4, 2.4).
// Vstup : A = (0, 1), B = (0, 4)
//  C = (1, 8), D = (1, 4)
// Output : Priamky AB a CD su paralelne.

#include <stdio.h>

int priesecnik_priamok(float Ax, float Ay, float Bx, float By, float Cx, float Cy, float Dx, float Dy)
{
	if ((Ax - Bx) / (Ay-By) ==  (Cx - Dx) / (Cy-Dy))
	{
		printf("Priamky su rovnobezne.");
		return 0;
	}

		// priamka 1
		float a1, b1, c1;

	a1 = Ay - By;
	b1 = Bx - Ax;
	c1 = Ax * By - Ay * Bx;

	// priamka 2

	float a2, b2, c2;

	a2 = Cy - Dy;
	b2 = Dx - Cx;
	c2 = Cx * Dy - Cy * Dx;

	// priesecnik
	float x, y;
	x = (b1 * c2) - (c1 * b2);
	y = (c1 * a2) - (a1 * c2);

	// predelim determinantom
	x /= a1*b2 - b1*a2;
	y /= a1*b2 - b1*a2;


	printf("Priesecnik: [%.3f,%.3f]", x, y);
	return 1;
}

int main()
{
	float Ax, Ay, Bx, By, Cx, Cy, Dx, Dy;

	// printf("Zadaj suradnice bodu A [x,y]: ");
	// scanf("%f %f", Ax, Ay);

	// printf("Zadaj suradnice bodu B [x,y]: ");
	// scanf("%f %f", Bx, By);

	// printf("Zadaj suradnice bodu C [x,y]: ");
	// scanf("%f %f", Cx, Cy);

	// printf("Zadaj suradnice bodu D [x,y]: ");
	// scanf("%f %f", Dx, Dy);

	// TEST DATA:

	Ax = 1;
	Ay = 1;

	Bx = 4;
	By = 4;

	Cx = 1;
	Cy = 8;

	Dx = 2;
	Dy = 4;

	priesecnik_priamok(Ax, Ay, Bx, By, Cx, Cy, Dx, Dy);

	return 0;
}

//gcc uloha6.c -std=c99 -pedantic -Wall -Werror -Wextra -o uloha6