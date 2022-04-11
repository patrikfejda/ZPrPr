#pragma warning(disable: 4996)
#pragma warning(disable: 6031)
#include <stdio.h>

int main()
{
	float hmotnost, bmi, vyska;
	printf("Zadajte vasu hmotnost v kg: ");
	scanf("%f", &hmotnost);
	printf("Zadajte vasu vysku v metroch: ");
	scanf("%f", &vyska);
	bmi = hmotnost / (vyska * vyska);
	if (bmi < 19.0) {
		printf("Ste podvyziveny.");
	}
	else if (bmi > 25.0) {
		printf("Mate nadvahu.");
	}
	else {
		printf("Mate normalnu hmotnost.");
	}

	return 0;
}