// Úloha č. 5: Napíšte v jazyku C program, ktorý generuje a následne analyzuje dáta o pacientoch, ktorí
// boli hospitalizovaní počas obdobia jedného roka v nemocnici. Absolútne početnosti hospitalizácií vložte
// do globálneho jednorozmerného poľa. Navrhnite pracovné funkcie, ktoré zistia nasledujúce ukazovatele:
// • priemerný počet hospitalizovaných pacientov,
// • mesiac s najmenším počtom hospitalizácií,
// • mesiac s najväčším počtom hospitalizácií,
// • kvartál s najmenším počtom hospitalizácií, 
// 3
// • kvartál s najväčším počtom hospitalizácií.
// Vstup: absolútne početnosti hospitalizovaných pacientov v jednotlivých mesiacoch roka.
// Výstup: vypočítané štatistické ukazovatele. 



#pragma warning(disable: 4996)
#pragma warning(disable: 6031)
#include <stdio.h>

#define MIN_POCET_PACIENTOV 100;
#define MAX_POCET_PACIENTOV 500;

int mesiac_s_max, mesiac_s_min;

int random_pocet(void) {
	int pocet;
	pocet = rand() % MAX_POCET_PACIENTOV;
	pocet += MIN_POCET_PACIENTOV;
	return pocet;
}

int je_max(i, doterajsi_max, cislo) {
	if (cislo >= doterajsi_max) {
		mesiac_s_max = 1 + i;
		return cislo;
	}
	return doterajsi_max;
}

int je_min(i, doterajsi_min, cislo) {
	if (cislo <= doterajsi_min) {
		mesiac_s_min = 1 + i;
		return cislo;
	}
	return doterajsi_min;
}


int main() {

	int i, pocet_pacientov[12];
	int max = 0, min = MAX_POCET_PACIENTOV;
	int sucet = 0;
	int kvartal1 = 0, kvartal2 = 0, kvartal3 = 0, kvartal4 = 0;

	printf("Za mesiace januar - december bolo hospitalizovanych tolkoto pacientov:\n");

	for (i = 0; i < 12; i++) {
		pocet_pacientov[i] = random_pocet();
		printf("%i. %i\n",i+1, pocet_pacientov[i]);
		max = je_max(i, max, pocet_pacientov[i]);
		min = je_min(i, min, pocet_pacientov[i]);
		sucet += pocet_pacientov[i];




		if (i >= 0 && i <= 2) {
			kvartal1 += pocet_pacientov[i];
		}

		else if (i >= 3 && i <= 5) {
			kvartal2 += pocet_pacientov[i];

		}

		else if (i >= 6 && i <= 8) {
			kvartal3 += pocet_pacientov[i];
		}

		else if (i >= 9 && i <= 11) {
			kvartal4 += pocet_pacientov[i];
		}




	}

	printf("Mesiac s max: %i hodnota: %i \nMesiac s min: %i hodnota: %i\n", mesiac_s_max, max,mesiac_s_min, min);

	printf("Mesacny priemer je %i\n", sucet / 12);


	printf("Kvartal s max: %s \n", kvartal1 > kvartal2 && kvartal2 > kvartal3 && kvartal3 > kvartal4 ? "kvartal2" : 
		kvartal2 > kvartal3 && kvartal3 > kvartal4 ? "kvartal2" : 
		kvartal3 > kvartal4 ? "kvartal3" : "kvartal4");

	printf("Kvartal s min: %s \n", kvartal1 < kvartal2 && kvartal2 < kvartal3 && kvartal3 < kvartal4 ? "kvartal2" :
		kvartal2 < kvartal3 && kvartal3 < kvartal4 ? "kvartal2" :
		kvartal3 < kvartal4 ? "kvartal3" : "kvartal4");

	printf(
		"Pocty za kvartaly:\n"
		"Kvartal 1: %i\n"
		"Kvartal 2: %i\n"
		"Kvartal 3: %i\n"
		"Kvartal 4: %i\n", kvartal1,kvartal2,kvartal3,kvartal4);

	return 0;
}