#pragma warning(disable: 4996)
#pragma warning(disable: 6031)
#include <stdio.h>

int main()
{
	float o1, o2, Er;
	printf("Zadajte objem lavej srdcovej komory pred kontrakciou: ");
	scanf("%f", &o1);

	printf("Zadajte objem lavej srdcovej komory po kontrakcii: ");
	scanf("%f", &o2);

	Er = (((o1 - o2) / o1) * 100.0);


	printf("Percentualna hodnota ejekcnej frakcie vasho srdca je cca %.0f percent\n",Er);
	if (Er >= 55.0 && Er <= 75.0) {
		printf("Srdce pracuje spravne");
	}
	else {
		printf("Srdce pracuje nespravne");
	}

	return 0;
}