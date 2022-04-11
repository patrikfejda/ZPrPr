// 5. Napíšte program, ktorý zistí počet jednotlivých písmen v každom riadku súboru. Vstupom
// programu je jeden riadok obsahujúci meno súboru. Výstupom je histogram výskytu písmen
// zapísaný v prehľadnej tabuľke, kde prvý riadok bude obsahovať všetky písmená abecedy
// prehľadne oddelené. Každý ďalší riadok bude obsahovať číslo riadku a vždy pod písmenami budú
// zarovnané počty výskytov tohto písmena v jednotlivých riadkoch súboru (nerozlišujte medzi
// veľkými a malými písmenami). Počty výskytov uveďte ako najviac dvojciferné celé číslo
// predchádzané jednou medzerou. Všetky riadky výstupu budú ukončené znakom konca riadku.
// Ukážka vstupu:
// subor.txt
// Ukážka obsahu súboru subor.txt:
// Toto je ukazkovy subor.
// V subore su pismena.
// Výstup pre ukážkový vstup:
//  A B C D E F G H I J K L M N O P Q R S T U V W X Y Z
//  1 1 1 0 0 1 0 0 0 0 1 2 0 0 0 4 0 0 1 1 2 2 1 0 0 1 1
//  2 1 1 0 0 2 0 0 0 1 0 0 0 1 1 1 1 0 1 3 0 2 1 0 0 0 0

#pragma warning(disable : 4996)
#pragma warning(disable : 6031)
#include <stdio.h>

int vypis_prvy_riadok(void)
{
    printf("A B C D E F G H I J K L M N O P Q R S T U V W X Y Z");
    return 0;
}

int vypis(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z)
{
    printf("\n%i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i", a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z);
    return 0;
}

int main()
{

    FILE* subor;
    char znak;
    int a = 0, b = 0, c = 0, d = 0, e = 0, f = 0, g = 0, h = 0, i = 0, j = 0, k = 0, l = 0, m = 0, n = 0, o = 0, p = 0, q = 0, r = 0, s = 0, t = 0, u = 0, v = 0, w = 0, x = 0, y = 0, z = 0;

    if ((subor = fopen("./vstup.txt", "r")) == NULL) {
        printf("Subor sa neda otvorit\n");
    }
    else {
        printf("Subor je spravne otvoreny\n");
    }
    vypis_prvy_riadok();
    while ((znak = getc(subor)) != EOF)
    {
        if (znak == 'a' || znak == 'A')
            a++;
        else if (znak == 'b' || znak == 'B')
            b++;
        else if (znak == 'c' || znak == 'C')
            c++;
        else if (znak == 'd' || znak == 'D')
            d++;
        else if (znak == 'e' || znak == 'E')
            e++;
        else if (znak == 'f' || znak == 'F')
            f++;
        else if (znak == 'g' || znak == 'G')
            g++;
        else if (znak == 'h' || znak == 'H')
            h++;
        else if (znak == 'i' || znak == 'I')
            i++;
        else if (znak == 'j' || znak == 'J')
            j++;
        else if (znak == 'k' || znak == 'K')
            k++;
        else if (znak == 'l' || znak == 'L')
            l++;
        else if (znak == 'm' || znak == 'M')
            m++;
        else if (znak == 'n' || znak == 'N')
            n++;
        else if (znak == 'o' || znak == 'O')
            o++;
        else if (znak == 'p' || znak == 'P')
            p++;
        else if (znak == 'q' || znak == 'Q')
            q++;
        else if (znak == 'r' || znak == 'R')
            r++;
        else if (znak == 's' || znak == 'S')
            s++;
        else if (znak == 't' || znak == 'T')
            t++;
        else if (znak == 'u' || znak == 'U')
            u++;
        else if (znak == 'v' || znak == 'V')
            v++;
        else if (znak == 'w' || znak == 'W')
            w++;
        else if (znak == 'x' || znak == 'X')
            x++;
        else if (znak == 'y' || znak == 'Y')
            y++;
        else if (znak == 'z' || znak == 'Z')
            z++;
        else if (znak == 10) {
            vypis(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z);
            a = 0, b = 0, c = 0, d = 0, e = 0, f = 0, g = 0, h = 0, i = 0, j = 0, k = 0, l = 0, m = 0, n = 0, o = 0, p = 0, q = 0, r = 0, s = 0, t = 0, u = 0, v = 0, w = 0, x = 0, y = 0, z = 0;
        }
    }

    return 0;
}