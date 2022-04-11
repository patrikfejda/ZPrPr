#pragma warning(disable: 6031)
#pragma warning(disable: 4996)

#include <stdio.h>

int main() {
    int r;
    float O, S, V, S_gule;
    float pi = 3.14;
    printf("Zadajte polomer: ");
    scanf("%d", &r);
    O = pi * 2 * r;
    S = pi * r * r;
    V = 4.0 / 3.0 * pi * r * r * r;
    S_gule = 4 * pi * r * r;
    printf("Obvod kruzice: %f"
        "\nObsah kruhu: %f"
        "\nObjem gule: %f"
        "\nPovrch gule: %f", O, S, V, S_gule);
    return 0;
}