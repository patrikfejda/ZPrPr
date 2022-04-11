#pragma warning(disable: 4996)
#pragma warning(disable: 6031)
#include <stdio.h>

float priemerna_spotreba(int litre_paliva, int pocet_km) {
	return ((float)litre_paliva / ((float)pocet_km / 100));
}


int main() {
	int prejdena_vzdialenost, spotrebovane_palivo;

	printf("Zadajte prejdenu vzdialenost automobilu v km: ");
	scanf("%i", &prejdena_vzdialenost);
	printf("Zadajte objem spotrebovaneho paliva v l: ");
	scanf("%i", &spotrebovane_palivo);

	printf("Priemerna spotreba automobilu v l/100 km je cca: %.2f", priemerna_spotreba(spotrebovane_palivo, prejdena_vzdialenost));

	return 0;
}