#pragma warning(disable: 6031)
#pragma warning(disable: 4996)

#include <stdio.h>
#include <math.h>

int main() {
    int a, b, c;
    float D, x1, x2, x;
    printf("Zadajte cleny v rovnici v tvare a b c: ");
    scanf("%d %d %d", &a, &b, &c);
    D = b * b - 4 * a * c;
    if (D < 0) {
        printf("Priklad nema vysledok");
        return 0; 
    }
    if (D == 0) {
        x = (-(float)b) / (2 * a);
        printf("Koren kvadratickej rovnice je:"
            "\nx = %f", x);
        return 0;
    }
    x1 = (-(float)b + sqrt(D)) / (2 * a);
    x2 = (-(float)b - sqrt(D)) / (2 * a);
    printf("Korene kvadratickej rovnice su:"
    "\nx1 = %f"
    "\nx2 = %f",x1,x2);
    return 0;
}