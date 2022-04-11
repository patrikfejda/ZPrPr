#pragma warning(disable: 6031)
#pragma warning(disable: 4996)

#include <stdio.h>

int main() {
    int narodenie_den, narodenie_mesiac, narodenie_rok;
    int dnesny_den, dnesny_mesiac, dnesny_rok;
    int rozdiel_den, rozdiel_mesiac, rozdiel_rok;
    printf("Zadajte datum narodenia v tvare DD MM RRRR: ");
    scanf("%d %d %d", &narodenie_den, &narodenie_mesiac, &narodenie_rok);
    printf("Zadajte dnesny datum v tvare DD MM RRRR: ");
    scanf("%d %d %d", &dnesny_den, &dnesny_mesiac, &dnesny_rok);
    rozdiel_rok = dnesny_rok - narodenie_rok;
    rozdiel_mesiac = dnesny_mesiac - narodenie_mesiac;
    rozdiel_den = dnesny_den - narodenie_den;
    printf("Od narodenia uplynulo priblizne %d dni", rozdiel_den + rozdiel_mesiac * 30 + rozdiel_rok * 365);
    return 0;
}