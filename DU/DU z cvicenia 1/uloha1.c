#pragma warning(disable: 6031)
#pragma warning(disable: 4996)

#include <stdio.h>

int main() {
    float Stupne_Faranheita, Stupne_Celzia;
    printf("Zadajte pocet stupnost Faranheita: ");
    scanf("%f", &Stupne_Faranheita);
    Stupne_Celzia = ((5.0 / 9.0) * (Stupne_Faranheita - 32));
    printf("%f Stupnov Faranheita sa rovna %f Stupnov Celzia", Stupne_Faranheita, Stupne_Celzia);
    return 0;
}