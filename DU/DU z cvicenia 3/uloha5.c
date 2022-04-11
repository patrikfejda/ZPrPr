#pragma warning(disable: 4996)
#pragma warning(disable: 6031)
#include <stdio.h>

int main() {

	/* default hodnota spravnej postupnosti je 1 a ak bude porusena podmienka tak ju zmenim na 0 */

	int N, nacitane_cislo, i, maximum_dalsieho_cisla, spravna_postupnost = 1;
	float minimum_dalsieho_cisla;

	/* nacitanie cisla */
	printf("Zadajte cele cislo: ");
	scanf("%i", &N);
	
	/* zbehne N-krat */ 
	for (i = 0; i < N; i++) {
		scanf("%i", &nacitane_cislo);

		/* pre i=0 cislo zistujem ci patri do intervalu <0;10> */
		if (!i && (nacitane_cislo < 0 || nacitane_cislo > 10)) {
			spravna_postupnost = 0;
		}

		/* pre i>0 cislo zistujem ci ze v intervale <min,max> */
		/* podmienka zbehne len ak spravna_postupnost = 1 - setrenie vypoctami */
		else if (i && spravna_postupnost && (nacitane_cislo < minimum_dalsieho_cisla || nacitane_cislo > maximum_dalsieho_cisla)) {
			spravna_postupnost = 0;
		}
		maximum_dalsieho_cisla = 2 * nacitane_cislo;
		minimum_dalsieho_cisla = (float)nacitane_cislo / 2;


		/* po odkomentovani nasledovneho kodu nebude program nacitavat dalej cisla ak je postupnost nespravna */
		/*
		if (!spravna_postupnost) {
			break;
		}
		*/

	}
	if (spravna_postupnost) {
		printf("Postupnost je spravna");
	}
	else {
		printf("Postupnost je nespravna");
	}
	return 0;
}