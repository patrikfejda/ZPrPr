#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *open_file(char file_name[32], char mode[5])
{
    FILE *file;
    if ((file = fopen(file_name, mode)) == NULL)
    {
        printf("Neotvoreny subor.\n");
        exit(1);
    }
    return file;
}

int main()
{
    // files

    FILE *file_goods = NULL;
    file_goods = open_file("tovar.txt", "w");

    fprintf(file_goods, "Radio\n27\n45.72\n1.3\n4\n\nTelevizor\n11\n104.70\n3.4\n4\n\nCeruzka\n94\n0.49\n0.07\n2\n\nNotebook\n5\n1500\n1.7\n1\n\nPeracnik\n20\n6.49\n0.2612\n2\n\nKavovar\n13\n84.21\n2.3\n3\n\nTesla\n1\n45999.99\n2200.0\n4\n\nKava\n20\n7.99\n0.5\n3\n\niPhone X\n12\n1200\n0.3\n1\n\nCaj\n80\n4.59\n0.2\n3\n\niPad\n7\n500\n0.5\n1\n\nPero\n76\n3.2\n0.08\n2\n");
    printf("DONE");
    fclose(file_goods);

    return 0;
}

//gcc reset.c -std=c99 -pedantic -Wall -Werror -Wextra -o reset ;; ./reset