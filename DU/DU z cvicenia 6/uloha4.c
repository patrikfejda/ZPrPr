// 4. Napíšte program, ktorý z prvého riadku vstupu načíta celé číslo n a alokuje v pamäti blok n
// položiek pre znaky. Potom zo štandardného vstupu načíta n znakov a vypíše ich odzadu. (Využite
// ukazovateľovú aritmetiku.)
// Ukážka vstupu:
// 4
// ahojky
// Výstup pre ukážkový vstup:
// joha


#pragma warning(disable: 4996)
#pragma warning(disable: 6031)
#include <stdio.h>
#include <string.h>
#define n 4

int main() {
    int i;

    //int n;
    //printf("Zadajte dlzku slova: ");
    //scanf("%i", &n);
   
    char slovo[n];

    printf("Slovo:");
    for (i = 0; i < n; i++) {
        scanf("%c", &slovo[i]);
    }

    for (int l = n - 1; l >= 0; l--) {
        printf("%c", slovo[l]);
    }

    return 0;
}