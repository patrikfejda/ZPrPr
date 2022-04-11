#pragma warning(disable: 4996)
#pragma warning(disable: 6031)
#include <stdio.h>

int main()
{
	float hmotnost, bmi, vyska;
	printf("Zadajte vasu vysku v centimetroch a hmotnost v kg: ");
	scanf("%f %f", &vyska, &hmotnost);
	vyska /= 100.0;
	bmi = hmotnost / (vyska * vyska);
	printf("BMI: %.3f", bmi);

	return 0;
}