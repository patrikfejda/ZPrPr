// 3. Napíšte program, ktorý vo funkcii main() prečíta celé číslo „a“, a následne zavolá
// funkciu vynasob(), ktorá je typu void. Táto funkcia načíta druhé celé číslo „b“, a tieto
// zadané čísla vynásobí a uloží do premennej „s“. Funkcia main() ďalej zavolá funkciu
// void vysledok(), ktorá vypíše vypočítaný súčin čísel „a“ a „b“ z premennej „s“. Všetky
// tri celočíselné premenné sú lokálne premenné funkcie main(). Žiadne iné celočíselné
// premenné nemôžete použiť. Funkcie vynasob() a vysledok() nesmú pracovať
// s ničím iným, než s ukazovateľmi. Ukazovateľov použite koľko chcete.
// Ukážka fungovania programu:
// Zadaj 1. cislo:
// 7
// Zadaj 2. cislo:
// 9
// Vysledok je: 63

#pragma warning(disable : 4996)
#pragma warning(disable : 6031)
#include <stdio.h>

void vynasob(int a, int *b, int *s)
{
	printf("ZADAJTE CELE CISLO B: ");
	scanf("%i", b);
	*s = a * *b;
	return 0;
}

void vysledok(int s)
{
	printf("SUCIN A a B je: %i", s);

	return 0;
}

int main()
{

	int a, b, s;
	printf("ZADAJTE CELE CISLO A: ");
	scanf("%i", &a);
	vynasob(a, &b, &s);
	vysledok(s);

	return 0;
}