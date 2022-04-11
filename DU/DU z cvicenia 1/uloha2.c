#pragma warning(disable: 6031)
#pragma warning(disable: 4996)

#include <stdio.h>

int main() {
    int priemer_inch, vzdialenost_km;
    float pocet_otoceni;
    float pi = 3.14;
    printf("Zadajte priemer kolesa v palcoch: ");
    scanf("%d", &priemer_inch);
    printf("Zadajte vzdialesnost v km: ");
    scanf("%d", &vzdialenost_km);
    /*zakladna jednotka = cm */
    pocet_otoceni = ((vzdialenost_km * 100000) / (pi * priemer_inch * 2.54));
    printf("Koleso sa na ceste otoci %f krat", pocet_otoceni);
    return 0;
}