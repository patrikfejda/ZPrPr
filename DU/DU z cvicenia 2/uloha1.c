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
	printf("Vase BMI je: %f", bmi);

	return 0;
}