// 22 : 2 = 11 zv 0

// Výstup: 10110.

#pragma warning(disable : 4996)
#pragma warning(disable : 6031)
#include <stdio.h>

int dec_to_binary(int decimal) {

	char zvysok[32], i;
	for (i = 0; decimal > 0; i++) {
		zvysok[i] = decimal % 2;
		decimal /= 2;
	}
	for (i = i - 1; i >= 0; i--) {
		printf("%i", zvysok[i]);
	}
	return 0;
}

int main() {
	int decimal;
	printf("Zadajte cislo v desiatkovej sustave: ");
	scanf("%d", &decimal);

	printf("Vase cislo vyzera v binarnej sustave takto: ");
	dec_to_binary(decimal);
	return 0;
}