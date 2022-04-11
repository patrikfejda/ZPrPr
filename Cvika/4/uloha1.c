// DONE

// Úloha 4.1: Napíšte procedúru vymen_ukazovatele, ktorá dostane na vstupe
// adresy dvoch ukazovateľov na celočíselné premenné a následne vymení ich
// hodnoty t.j. adresy premenných, na ktoré ukazujú. Program na konzolu vypíše
// stav (hodnoty daných ukazovateľov) pred a po zavolaní procedúry
// vymen_ukazovatele.

#include <stdio.h>


void vymen_ukazovatele(int **pa, int **pb) {
	int *px;

	px = *pa;
	*pa = *pb;
	*pb = px;

}

int main()
{
	int a, b;
	a = 1;
	b = 2;
	int *pa, *pb;

	pa = &a;
	pb = &b;

	printf("A: %i Pointer A: %i\n", a, pa);
	printf("B: %i Pointer B: %i\n", b, pb);

	vymen_ukazovatele(&pa, &pb);

	// toto sa nemoze: 
	// &a = pa;
	// &b = pb;



	printf("A: %i Pointer A: %i\n", a, pa);
	printf("B: %i Pointer B: %i", b, pb);


	return 0;
}

//gcc uloha1.c -std=c99 -pedantic -Wall -Werror -Wextra -o uloha