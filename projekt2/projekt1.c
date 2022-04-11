/*
SEMINARNY PROJEKT Z PREDMETU
ZAKLADY PROCEDURALNEHO PROGRAMOVANIA 2

PATRIK FEJDA
FAKULTA INFORMATIKY A INFORMACNYCH TECHNOLOGII
SLOVENSKA TECHNICKA UNIVERZITA V BRATISLAVE

CVICIACI: JAN ZELENKA

KOMPILATOR: GCC

//////////////////////////////////////////////////////////
///// PROSIM KOMPILOVAT A TESTOVAT V GCC (NIE VO VS) /////
//////////////////////////////////////////////////////////
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_GOODS_NAME_LENGTH 52 // 50 + 1 kvoli pocitaniu pozicii + 1 ako istotka
#define MAX_VENDOR_NAME_LENGTH 52
#define MAX_VENDOR_ADRESS_LENGTH 52
#define MAX_LINE_IN_FILE_LENGTH 101 // 50 * 2 pre istotu
#define LINES_IN_FILE_FOR_ONE_GOOD 6
#define LINES_IN_FILE_FOR_ONE_VENDOR 4

#define THE_IS_NO_NEWLINE_AT_THE_END_OF_TXT 1 // z pozorovania vyplynulo ze program ignoruje newline na konci filu

////////
// HELP FUNCTIONS
////////

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

int count_lines_in_file(FILE *file)
{
    char line_text[MAX_LINE_IN_FILE_LENGTH];
    int lines = 0;
    while (fgets(line_text, MAX_LINE_IN_FILE_LENGTH, file) != NULL)
    {
        lines++;
    }

    return lines;
}

// PROJECT FUNCTIONS

int v(FILE **file_goods, FILE **file_vendor, int *number_of_goods, int *number_of_vendors, char **goods_name, int **goods_pcs_in_stock, double **goods_price, double **goods_weight, int **goods_vendor_id, int **vendor_vendor_id, char **vendor_name, char **vendor_adress)
{
    // bezpecne otvorenie filu - ak uz bol otvoreny tak ho najprv zatvorim - p.Zelenka
    if ((*file_goods) == NULL)
    {
        (*file_goods) = open_file("tovar.txt", "r");
    }
    else
    {
        rewind(*file_goods); // posuniem ukazovatel subora na zaciatok
        if (fclose(*file_goods) != 0)
        {
            printf("Nepodarilo sa zavriet subor.");
            return 0;
        }
        *file_goods = NULL;
        (*file_goods) = open_file("tovar.txt", "r");
    }
    if ((*file_vendor) == NULL)
    {
        *file_vendor = open_file("dodavatelia.txt", "r");
    }
    else
    {
        rewind(*file_vendor); // posuniem ukazovatel subora na zaciatok
        if (fclose(*file_vendor) != 0)
        {
            printf("Nepodarilo sa zavriet subor.");
            return 0;
        }
        *file_vendor = NULL;
        (*file_vendor) = open_file("dodavatelia.txt", "r");
    }

    // COUNT NUMBER OF GOODS
    *number_of_goods = (count_lines_in_file(*file_goods));
    *number_of_goods += THE_IS_NO_NEWLINE_AT_THE_END_OF_TXT; // +1 lebo no newline at the end of file
    *number_of_goods /= LINES_IN_FILE_FOR_ONE_GOOD;

    // COUNT NUMBER OF VENDORS
    *number_of_vendors = (count_lines_in_file(*file_vendor));
    *number_of_vendors += THE_IS_NO_NEWLINE_AT_THE_END_OF_TXT; // +1 lebo no newline at the end of file
    *number_of_vendors /= LINES_IN_FILE_FOR_ONE_VENDOR;

    // CLEAR FILES BUFFER
    rewind(*file_goods);
    rewind(*file_vendor);

    // ALLOC MEMORY ACCORDING TO GOODS AND VENDOR NUMBERS QUANTITY - p.Zelenka
    if (*goods_name == NULL)
    {
        (*goods_name) = (char *)malloc((*number_of_goods) * MAX_GOODS_NAME_LENGTH * sizeof(char)); // fakujem 2d pole
    }
    else
    {
        free(*goods_name);
        *goods_name = NULL;
        (*goods_name) = (char *)malloc((*number_of_goods) * MAX_GOODS_NAME_LENGTH * sizeof(char)); // fakujem 2d pole
    }

    if (*goods_pcs_in_stock == NULL)
    {
        *goods_pcs_in_stock = (int *)malloc((*number_of_goods) * sizeof(int));
    }
    else
    {
        free(*goods_pcs_in_stock);
        *goods_pcs_in_stock = NULL;
        *goods_pcs_in_stock = (int *)malloc((*number_of_goods) * sizeof(int));
    }

    if (*goods_price == NULL)
        *goods_price = (double *)malloc((*number_of_goods) * sizeof(double));
    else
    {
        free(*goods_price);
        *goods_price = NULL;
        *goods_price = (double *)malloc((*number_of_goods) * sizeof(double));
    }

    if (*goods_weight == NULL)
        *goods_weight = (double *)malloc((*number_of_goods) * sizeof(double));
    else
    {
        free(*goods_weight);
        *goods_weight = NULL;
        *goods_weight = (double *)malloc((*number_of_goods) * sizeof(double));
    }

    if (*goods_vendor_id == NULL)
        *goods_vendor_id = (int *)malloc((*number_of_goods) * sizeof(int));
    else
    {
        free(*goods_vendor_id);
        *goods_vendor_id = NULL;
        *goods_vendor_id = (int *)malloc((*number_of_goods) * sizeof(int));
    }

    if (*vendor_vendor_id == NULL)
        *vendor_vendor_id = (int *)malloc((*number_of_vendors) * sizeof(int));
    else
    {
        free(*vendor_vendor_id);
        *vendor_vendor_id = NULL;
        *vendor_vendor_id = (int *)malloc((*number_of_vendors) * sizeof(int));
    }

    if (*vendor_name == NULL)
    {
        (*vendor_name) = (char *)malloc((*number_of_vendors) * MAX_VENDOR_NAME_LENGTH * sizeof(char)); // fakujem 2d pole
    }
    else
    {
        free(*vendor_name);
        *vendor_name = NULL;
        (*vendor_name) = (char *)malloc((*number_of_vendors) * MAX_VENDOR_NAME_LENGTH * sizeof(char)); // fakujem 2d pole
    }

    if (*vendor_adress == NULL)
    {
        (*vendor_adress) = (char *)malloc((*number_of_vendors) * MAX_VENDOR_ADRESS_LENGTH * sizeof(char)); // fakujem 2d pole
    }
    else
    {
        free(*vendor_adress);
        *vendor_adress = NULL;
        (*vendor_adress) = (char *)malloc((*number_of_vendors) * MAX_VENDOR_ADRESS_LENGTH * sizeof(char)); // fakujem 2d pole
    }

    char line_text[MAX_LINE_IN_FILE_LENGTH];

    // read file_goods to fields

    for (int i = 0; i < *number_of_goods; i++)
    {
        // goods name  - str[MAX_GOODS_NAME_LENGTH]
        fgets(line_text, MAX_LINE_IN_FILE_LENGTH, *file_goods);
        strcpy(*goods_name + i * MAX_GOODS_NAME_LENGTH, line_text);

        // goods pcs_in_stock - int
        fgets(line_text, MAX_LINE_IN_FILE_LENGTH, *file_goods);
        (*goods_pcs_in_stock)[i] = atoi(line_text);

        // goods price - double
        fgets(line_text, MAX_LINE_IN_FILE_LENGTH, *file_goods);
        (*goods_price)[i] = atof(line_text);

        // goods weight - double
        fgets(line_text, MAX_LINE_IN_FILE_LENGTH, *file_goods);
        (*goods_weight)[i] = atof(line_text);

        // goods vendor_id - int
        fgets(line_text, MAX_LINE_IN_FILE_LENGTH, *file_goods);
        (*goods_vendor_id)[i] = atoi(line_text);

        // blank line
        fgets(line_text, MAX_LINE_IN_FILE_LENGTH, *file_goods);
    }

    // read file_vendor to fields

    for (int i = 0; i < *number_of_vendors; i++)
    {
        // vendor vendor_id - int
        fgets(line_text, MAX_LINE_IN_FILE_LENGTH, *file_vendor);
        (*vendor_vendor_id)[i] = atoi(line_text);

        // vendor name  - str[MAX_VENDOR_NAME_LENGTH]
        fgets(line_text, MAX_LINE_IN_FILE_LENGTH, *file_vendor);
        strcpy(*vendor_name + i * MAX_VENDOR_NAME_LENGTH, line_text);

        // vendor adress  - str[MAX_VENDOR_ADRESS_LENGTH]
        fgets(line_text, MAX_LINE_IN_FILE_LENGTH, *file_vendor);
        strcpy(*vendor_adress + i * MAX_VENDOR_ADRESS_LENGTH, line_text);

        // blank line
        fgets(line_text, MAX_LINE_IN_FILE_LENGTH, *file_vendor);
    }

    ///////////
    // print file_goods to fields
    ///////////

    for (int i = 0; i < *number_of_goods; i++)
    {
        // goods name  - str[MAX_GOODS_NAME_LENGTH]
        printf("Nazov tovaru: %s", (*goods_name + (i * MAX_GOODS_NAME_LENGTH)));

        // goods pcs_in_stock - int
        printf("Pocet kusov na sklade: %i\n", (*goods_pcs_in_stock)[i]);

        // goods price - double
        printf("Cena: %.2lf\n", (*goods_price)[i]);

        // goods weight - double
        printf("Hmotnost: %.4lf\n", (*goods_weight)[i]);

        // goods vendor_id - int
        printf("ID dodavatela: %i\n\n", (*goods_vendor_id)[i]);
    }

    printf("----------------------------------------------------------------------------------------\n");
    printf("----------------------------------------------------------------------------------------\n\n");

    // print file_vendor to fields

    for (int i = 0; i < *number_of_vendors; i++)
    {
        // vendor vendor_id - int
        printf("ID dodavatela: %i\n", (*vendor_vendor_id)[i]);

        // vendor name  - str[MAX_VENDOR_NAME_LENGTH]
        printf("Meno dodavatela: %s", (*vendor_name + (i * MAX_VENDOR_ADRESS_LENGTH)));

        // vendor adress  - str[MAX_VENDOR_ADRESS_LENGTH]
        printf("Adresa dodavatela: %s\n", (*vendor_adress + (i * MAX_VENDOR_ADRESS_LENGTH)));
    }

    return 0;
}

int o(FILE **file_goods)
{
    // otvorenie tovar.txt
    if ((*file_goods) == NULL)
    {
        (*file_goods) = open_file("tovar.txt", "r");
    }
    else
    {
        rewind(*file_goods); // posuniem ukazovatel subora na zaciatok
        if (fclose(*file_goods) != 0)
        {
            printf("Nepodarilo sa zavriet subor.");
            return 0;
        }
        *file_goods = NULL;
        (*file_goods) = open_file("tovar.txt", "r");
    }

    // COUNT NUMBER OF GOODS
    int number_of_goods; // lokalna premenna funkcie o()
    number_of_goods = (count_lines_in_file(*file_goods));
    number_of_goods += THE_IS_NO_NEWLINE_AT_THE_END_OF_TXT; // +1 lebo no newline at the end of file
    number_of_goods /= LINES_IN_FILE_FOR_ONE_GOOD;

    // WHICH VENDOR DOES THE USER WANT?
    int user_input_vendor_id;
    fflush(stdin);
    printf("Zadajte ID dodavatela: ");
    scanf("%i", &user_input_vendor_id);

    char name_of_the_most_expensive_good[MAX_GOODS_NAME_LENGTH] = {"NO GOODS FOUND WITH THIS VENDOR ID!"};
    double price_of_the_most_expensive_good = 0.00; // sem si ukladam aj najdrahsi DOTERAZ - pocas iteracie sa meni

    char name_of_the_actual_product[MAX_GOODS_NAME_LENGTH] = {"ERROR!"};
    double price_of_actual_product = 0.0;
    int vendor_id_actual_product = 0;

    char line_text[MAX_LINE_IN_FILE_LENGTH];
    char at_least_one_product_found = 0; // toto porebujem na toto: prvy produkt od vendora X = najdrahsi

    rewind(*file_goods);

    for (int i = 0; i < number_of_goods; i++)
    {

        // goods name  - str[MAX_GOODS_NAME_LENGTH]
        fgets(line_text, MAX_LINE_IN_FILE_LENGTH, *file_goods);
        strcpy(name_of_the_actual_product, line_text);

        // goods pcs_in_stock - int
        fgets(line_text, MAX_LINE_IN_FILE_LENGTH, *file_goods);
        // I IGNORE THIS LINE

        // goods price - double
        fgets(line_text, MAX_LINE_IN_FILE_LENGTH, *file_goods);
        price_of_actual_product = atof(line_text);

        // goods weight - double
        fgets(line_text, MAX_LINE_IN_FILE_LENGTH, *file_goods);
        // I IGNORE THIS LINE

        // goods vendor_id - int
        fgets(line_text, MAX_LINE_IN_FILE_LENGTH, *file_goods);
        vendor_id_actual_product = atoi(line_text);

        // blank line
        fgets(line_text, MAX_LINE_IN_FILE_LENGTH, *file_goods);

        if (vendor_id_actual_product == user_input_vendor_id)
        {
            if (at_least_one_product_found == 0)
            {
                // ak je toto prvy product tak ho nastavim ako najdrajsi
                at_least_one_product_found++;
                price_of_the_most_expensive_good = price_of_actual_product;
                strcpy(name_of_the_most_expensive_good, name_of_the_actual_product);
            }
            else if (price_of_actual_product > price_of_the_most_expensive_good)
            {
                price_of_the_most_expensive_good = price_of_actual_product;
                strcpy(name_of_the_most_expensive_good, name_of_the_actual_product);
            }
        }
    }
    printf("Najdrahsi tovar je: %s\n", name_of_the_most_expensive_good);

    return 0;
}

int n(FILE **file_goods, FILE **file_vendor, int *number_of_goods, int *number_of_vendors, char **goods_name, int **goods_pcs_in_stock, double **goods_price, double **goods_weight, int **goods_vendor_id, int **vendor_vendor_id, char **vendor_name, char **vendor_adress)
{
    // bezpecne otvorenie filu - ak uz bol otvoreny tak ho najprv zatvorim - p.Zelenka
    if (((*file_goods) == NULL) || ((*file_vendor) == NULL))
    {
        // JEDEN ALEBO DRUHY SUBOR ESTE NIKDY NEBOLI OTVORENE TAKZE FUNKCIA KONCI
        printf("Este nebola vykonana funkcia v().\n");
        return 0;
    } // NEDAVAM ELSE{} KEDZE HO VDAKA `RETURN 0;` NETREBA A ZBYTOCNE BY LEN ZAVADZAL

    // COUNT NUMBER OF GOODS
    rewind(*file_goods);
    *number_of_goods = (count_lines_in_file(*file_goods));
    *number_of_goods += THE_IS_NO_NEWLINE_AT_THE_END_OF_TXT; // +1 lebo no newline at the end of file
    *number_of_goods /= LINES_IN_FILE_FOR_ONE_GOOD;

    // COUNT NUMBER OF VENDORS
    rewind(*file_vendor);
    *number_of_vendors = (count_lines_in_file(*file_vendor));
    *number_of_vendors += THE_IS_NO_NEWLINE_AT_THE_END_OF_TXT; // +1 lebo no newline at the end of file
    *number_of_vendors /= LINES_IN_FILE_FOR_ONE_VENDOR;

    // CLEAR FILES BUFFER
    rewind(*file_goods);
    rewind(*file_vendor);

    // ALLOC MEMORY ACCORDING TO GOODS AND VENDOR NUMBERS QUANTITY - p.Zelenka
    if (*goods_name == NULL)
    {
        (*goods_name) = (char *)malloc((*number_of_goods) * MAX_GOODS_NAME_LENGTH * sizeof(char)); // fakujem 2d pole
    }
    else
    {
        free(*goods_name);
        *goods_name = NULL;
        (*goods_name) = (char *)malloc((*number_of_goods) * MAX_GOODS_NAME_LENGTH * sizeof(char)); // fakujem 2d pole
    }

    if (*goods_pcs_in_stock == NULL)
    {
        *goods_pcs_in_stock = (int *)malloc((*number_of_goods) * sizeof(int));
    }
    else
    {
        free(*goods_pcs_in_stock);
        *goods_pcs_in_stock = NULL;
        *goods_pcs_in_stock = (int *)malloc((*number_of_goods) * sizeof(int));
    }

    if (*goods_price == NULL)
        *goods_price = (double *)malloc((*number_of_goods) * sizeof(double));
    else
    {
        free(*goods_price);
        *goods_price = NULL;
        *goods_price = (double *)malloc((*number_of_goods) * sizeof(double));
    }

    if (*goods_weight == NULL)
        *goods_weight = (double *)malloc((*number_of_goods) * sizeof(double));
    else
    {
        free(*goods_weight);
        *goods_weight = NULL;
        *goods_weight = (double *)malloc((*number_of_goods) * sizeof(double));
    }

    if (*goods_vendor_id == NULL)
        *goods_vendor_id = (int *)malloc((*number_of_goods) * sizeof(int));
    else
    {
        free(*goods_vendor_id);
        *goods_vendor_id = NULL;
        *goods_vendor_id = (int *)malloc((*number_of_goods) * sizeof(int));
    }

    if (*vendor_vendor_id == NULL)
        *vendor_vendor_id = (int *)malloc((*number_of_vendors) * sizeof(int));
    else
    {
        free(*vendor_vendor_id);
        *vendor_vendor_id = NULL;
        *vendor_vendor_id = (int *)malloc((*number_of_vendors) * sizeof(int));
    }

    if (*vendor_name == NULL)
    {
        (*vendor_name) = (char *)malloc((*number_of_vendors) * MAX_VENDOR_NAME_LENGTH * sizeof(char)); // fakujem 2d pole
    }
    else
    {
        free(*vendor_name);
        *vendor_name = NULL;
        (*vendor_name) = (char *)malloc((*number_of_vendors) * MAX_VENDOR_NAME_LENGTH * sizeof(char)); // fakujem 2d pole
    }

    if (*vendor_adress == NULL)
    {
        (*vendor_adress) = (char *)malloc((*number_of_vendors) * MAX_VENDOR_ADRESS_LENGTH * sizeof(char)); // fakujem 2d pole
    }
    else
    {
        free(*vendor_adress);
        *vendor_adress = NULL;
        (*vendor_adress) = (char *)malloc((*number_of_vendors) * MAX_VENDOR_ADRESS_LENGTH * sizeof(char)); // fakujem 2d pole
    }

    char line_text[MAX_LINE_IN_FILE_LENGTH];

    // read file_goods to fields

    for (int i = 0; i < *number_of_goods; i++)
    {
        // goods name  - str[MAX_GOODS_NAME_LENGTH]
        fgets(line_text, MAX_LINE_IN_FILE_LENGTH, *file_goods);
        strcpy(*goods_name + i * MAX_GOODS_NAME_LENGTH, line_text);

        // goods pcs_in_stock - int
        fgets(line_text, MAX_LINE_IN_FILE_LENGTH, *file_goods);
        (*goods_pcs_in_stock)[i] = atoi(line_text);

        // goods price - double
        fgets(line_text, MAX_LINE_IN_FILE_LENGTH, *file_goods);
        (*goods_price)[i] = atof(line_text);

        // goods weight - double
        fgets(line_text, MAX_LINE_IN_FILE_LENGTH, *file_goods);
        (*goods_weight)[i] = atof(line_text);

        // goods vendor_id - int
        fgets(line_text, MAX_LINE_IN_FILE_LENGTH, *file_goods);
        (*goods_vendor_id)[i] = atoi(line_text);

        // blank line
        fgets(line_text, MAX_LINE_IN_FILE_LENGTH, *file_goods);
    }

    // read file_vendor to fields

    for (int i = 0; i < *number_of_vendors; i++)
    {
        // vendor vendor_id - int
        fgets(line_text, MAX_LINE_IN_FILE_LENGTH, *file_vendor);
        (*vendor_vendor_id)[i] = atoi(line_text);

        // vendor name  - str[MAX_VENDOR_NAME_LENGTH]
        fgets(line_text, MAX_LINE_IN_FILE_LENGTH, *file_vendor);
        strcpy(*vendor_name + i * MAX_VENDOR_NAME_LENGTH, line_text);

        // vendor adress  - str[MAX_VENDOR_ADRESS_LENGTH]
        fgets(line_text, MAX_LINE_IN_FILE_LENGTH, *file_vendor);
        strcpy(*vendor_adress + i * MAX_VENDOR_ADRESS_LENGTH, line_text);

        // blank line
        fgets(line_text, MAX_LINE_IN_FILE_LENGTH, *file_vendor);
    }

    return 0;
}

int s(int *number_of_goods, char **goods_name, int **goods_pcs_in_stock, double **goods_price, double **goods_weight, int **goods_vendor_id, int **vendor_vendor_id, char **vendor_name, char **vendor_adress)
{ // mozno prijimam zbytocne vela argumentov, ale to neni bug ale feature - overujem vsetky ci nie su NULL a pokila je aspon 1 tak funkcia konci
    if ((*goods_name == NULL) || (*goods_pcs_in_stock == NULL) || (*goods_price == NULL) || (*goods_weight == NULL) || (*goods_vendor_id == NULL) || (*vendor_vendor_id == NULL) || (*vendor_name == NULL) || (*vendor_adress == NULL))
    {
        printf("\nPolia nie su vytvorene.\n");
        return 0;
    }

    // WHICH VENDOR DOES THE USER WANT?
    int user_input_vendor_id;
    fflush(stdin);
    printf("Zadajte ID dodavatela: ");
    scanf("%i", &user_input_vendor_id);

    for (int i = 0; i < *number_of_goods; i++)
    {
        if ((*goods_vendor_id)[i] == user_input_vendor_id)
        {
            for (unsigned int p = 0; p < strlen((*goods_name + (i * MAX_GOODS_NAME_LENGTH))) - 1; p++)
            {
                // strlen vracia unsigned int takze preto unsigned int p = 0
                // -1 lebo posledny znak je \n a presne preto robim cely tento for
                putchar((*goods_name + (i * MAX_GOODS_NAME_LENGTH))[p]);
            }
            printf(" (%i na sklade)\n", (*goods_pcs_in_stock)[i]);
        }
    }

    return 0;
}

int h(int *number_of_goods, char **goods_name, int **goods_pcs_in_stock, double **goods_price, double **goods_weight, int **goods_vendor_id, int **vendor_vendor_id, char **vendor_name, char **vendor_adress)
{ // mozno prijimam zbytocne vela argumentov, ale to neni bug ale feature - overujem vsetky ci nie su NULL a pokila je aspon 1 tak funkcia konci
    if ((*goods_name == NULL) || (*goods_pcs_in_stock == NULL) || (*goods_price == NULL) || (*goods_weight == NULL) || (*goods_vendor_id == NULL) || (*vendor_vendor_id == NULL) || (*vendor_name == NULL) || (*vendor_adress == NULL))
    {
        printf("\nPolia nie su vytvorene.\n");
        return 0;
    }

    int number_of_products_in_interval[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int interval_bottom_boundary[10] = {0, 10, 20, 30, 40, 50, 60, 70, 80, 90};
    int interval_top_boundary[10] = {9, 19, 29, 39, 49, 59, 69, 79, 89, 99};

    for (int product = 0; product < *number_of_goods; product++)
    {
        for (unsigned int interval = 0; interval < (sizeof(number_of_products_in_interval) / sizeof(int)); interval++) // sizeof je tam na to, keby som zmenil intervaly nech nemusim menit cely kod
        {
            if ((interval_bottom_boundary[interval] < ((*goods_pcs_in_stock)[product])) && (((*goods_pcs_in_stock)[product]) < interval_top_boundary[interval]))
            { // som v intervale?
                number_of_products_in_interval[interval]++;
                // break; <== radsej nedavam, lebo ak by sa v buducnosti zmenili intervaly a niekto by sa v nich pomylil tak neni sanca ze by niekto spravne oddebugoval pricinu s tymto breakom
            }
        }
    }

    printf("\n");
    for (unsigned int interval = 0; interval < (sizeof(number_of_products_in_interval) / sizeof(int)); interval++)
    {
        printf("<%i,%i> : %i\n", interval_bottom_boundary[interval], interval_top_boundary[interval], number_of_products_in_interval[interval]);
    }

    return 0;
}

int p(FILE **file_goods, int *number_of_goods, char **goods_name, int **goods_pcs_in_stock, double **goods_price, double **goods_weight, int **goods_vendor_id, int **vendor_vendor_id, char **vendor_name, char **vendor_adress)
{ // mozno prijimam zbytocne vela argumentov, ale to neni bug ale feature - overujem vsetky ci nie su NULL a pokila je aspon 1 tak funkcia konci
    if ((*goods_name == NULL) || (*goods_pcs_in_stock == NULL) || (*goods_price == NULL) || (*goods_weight == NULL) || (*goods_vendor_id == NULL) || (*vendor_vendor_id == NULL) || (*vendor_name == NULL) || (*vendor_adress == NULL))
    {
        printf("\nPolia nie su vytvorene.\n");
        return 0;
    }

    if ((*file_goods) == NULL)
    {
        (*file_goods) = open_file("tovar.txt", "r");
    }
    else
    {
        rewind(*file_goods); // posuniem ukazovatel subora na zaciatok
        if (fclose(*file_goods) != 0)
        {
            printf("Nepodarilo sa zavriet subor.");
            return 0;
        }
        *file_goods = NULL;
        (*file_goods) = open_file("tovar.txt", "r");
    }

    // WHICH PRODUCT DOES THE USER WANT?
    char user_input_goods_name[MAX_GOODS_NAME_LENGTH] = {"NO PRODUCT FOUND"};
    fflush(stdin);
    printf("Zadajte meno produktu: ");
    fgets(user_input_goods_name, MAX_GOODS_NAME_LENGTH, stdin);

    int product_found_i = -1; // index najdeneho produktu, -1 znamena ze nenajdeny

    for (int i = 0; i < *number_of_goods; i++)
    {
        if (strcmp(user_input_goods_name, (*goods_name + (i * MAX_GOODS_NAME_LENGTH))) == 0)
        {
            product_found_i = i;
            break; // NASIEL SOM i produktu, ak sa volaju 2 produkty rovnako tak najdem ten prvy
        }
    }

    if (product_found_i == -1)
    {
        printf("PRODUCKT NENAJDENY!\n");
        return 0;
    }

    int user_input_goods_pcs_in_stock = -1;
    fflush(stdin);
    printf("Zadajte mnozstvo na sklade: ");
    scanf("%i", &user_input_goods_pcs_in_stock);

    (*goods_pcs_in_stock)[product_found_i] = user_input_goods_pcs_in_stock;

    // OTVORIM SUBOR NA WRITE - predtym som mal len read
    rewind(*file_goods);
    if (fclose(*file_goods) != 0)
    {
        printf("Nepodarilo sa zavriet subor.");
        return 0;
    }
    *file_goods = NULL;
    (*file_goods) = open_file("tovar.txt", "w");
    // subor na write som si otvoril az ked som mal iste ze mam vsetky vstupy validne a ze sa mi vsetko vypise spravne..
    // lebo ja to robim stylom ze write mi subor premaze a ja ho cely odznova napisem z toho pola
    // a pokial by pri printe bol nejaky problem, tak by som stratil data

    for (int i = 0; i < *number_of_goods; i++)
    {
        // goods name  - str[MAX_GOODS_NAME_LENGTH]
        fprintf(*file_goods, "%s", (*goods_name + (i * MAX_GOODS_NAME_LENGTH)));

        // goods pcs_in_stock - int
        fprintf(*file_goods, "%i\n", (*goods_pcs_in_stock)[i]);

        // goods price - double
        fprintf(*file_goods, "%.2lf\n", (*goods_price)[i]);

        // goods weight - double
        fprintf(*file_goods, "%.4lf\n", (*goods_weight)[i]);

        // goods vendor_id - int
        fprintf(*file_goods, "%i", (*goods_vendor_id)[i]);

        // newline
        if (i != *number_of_goods) // z pozorovanie
        {
            fprintf(*file_goods, "\n\n");
        }
    }

    // ZAVRIEM SUBOR NECH SA ULOZI ZAPIS
    // OTVORIM SUBOR NA READ
    rewind(*file_goods);
    if (fclose(*file_goods) != 0)
    {
        // AK SA NEPODARIL SUBOR ZAVRIET TAK SME PRISLI O DATA :(
        printf("Nepodarilo sa zavriet subor.");
        return 0;
    }
    *file_goods = NULL;
    (*file_goods) = open_file("tovar.txt", "r");

    printf("Aktualny pocet kusov na sklade tovaru ");
    for (unsigned int p = 0; p < strlen((*goods_name + (product_found_i * MAX_GOODS_NAME_LENGTH))) - 1; p++)
    {
        // strlen vracia unsigned int takze preto unsigned int p = 0
        // -1 lebo posledny znak je \n a presne preto robim cely tento for
        putchar((*goods_name + (product_found_i * MAX_GOODS_NAME_LENGTH))[p]);
    }

    printf(" je: %i.\n", (*goods_pcs_in_stock)[product_found_i]);

    return 0;
}

int z(int *number_of_goods, char **goods_name, int **goods_pcs_in_stock, double **goods_price, double **goods_weight, int **goods_vendor_id, int **vendor_vendor_id, char **vendor_name, char **vendor_adress)
{ // mozno prijimam zbytocne vela argumentov, ale to neni bug ale feature - overujem vsetky ci nie su NULL a pokila je aspon 1 tak funkcia konci
    if ((*goods_name == NULL) || (*goods_pcs_in_stock == NULL) || (*goods_price == NULL) || (*goods_weight == NULL) || (*goods_vendor_id == NULL) || (*vendor_vendor_id == NULL) || (*vendor_name == NULL) || (*vendor_adress == NULL))
    {
        printf("\nPolia nie su vytvorene.\n");
        return 0;
    }

    double x, y;
    printf("Zadajte interval <x,y>: ");
    fflush(stdin);
    scanf("%lf %lf", &x, &y);

    if (x > y)
    {
        printf("Prve cislo musi byt mensie ako druhe cislo.\n");
        return 0;
    }

    char *field_of_product_names_unsorted;
    double *field_of_product_weights_unsorted;
    int i_products_in_range = 0; // index of products in range <x,y>

    field_of_product_names_unsorted = (char *)malloc((*number_of_goods) * MAX_GOODS_NAME_LENGTH * sizeof(char)); // fakujem 2d pole
    field_of_product_weights_unsorted = (double *)malloc((*number_of_goods) * sizeof(double));

    for (int i = 0; i < *number_of_goods; i++)
    {
        if ((*goods_weight)[i] >= x && (*goods_weight)[i] <= y)
        {
            field_of_product_weights_unsorted[i_products_in_range] = (*goods_weight)[i];
            strcpy(&field_of_product_names_unsorted[i_products_in_range * MAX_GOODS_NAME_LENGTH], (*goods_name + (i * MAX_GOODS_NAME_LENGTH)));
            i_products_in_range++;
        }
    }

    double temp;
    char temp_char_field[MAX_GOODS_NAME_LENGTH] = {"ERROR"};
    for (int c = 0; c < i_products_in_range; c++)
    {
        for (int n = c + 1; n < i_products_in_range; n++)
        {
            if (field_of_product_weights_unsorted[c] > field_of_product_weights_unsorted[n])
            {
                temp = field_of_product_weights_unsorted[c];
                field_of_product_weights_unsorted[c] = field_of_product_weights_unsorted[n];
                field_of_product_weights_unsorted[n] = temp;

                strcpy(temp_char_field, &field_of_product_names_unsorted[c * MAX_GOODS_NAME_LENGTH]);
                strcpy(&field_of_product_names_unsorted[c * MAX_GOODS_NAME_LENGTH], &field_of_product_names_unsorted[n * MAX_GOODS_NAME_LENGTH]);
                strcpy(&field_of_product_names_unsorted[n * MAX_GOODS_NAME_LENGTH], temp_char_field);

            }
        }
    }
    for (int i = 0; i < i_products_in_range; i++)
    {
        for (unsigned int p = 0; p < strlen(&field_of_product_names_unsorted[i * MAX_GOODS_NAME_LENGTH]) - 1; p++)
        {
            // strlen vracia unsigned int takze preto unsigned int p = 0
            // -1 lebo posledny znak je \n a presne preto robim cely tento for
            putchar(field_of_product_names_unsorted[(i * MAX_GOODS_NAME_LENGTH) + p]);
        }
        //printf(" %.4lf", field_of_product_weights_unsorted[i]);
        printf("\n");
    }

    free(field_of_product_names_unsorted);
    free(field_of_product_weights_unsorted);
    field_of_product_names_unsorted = NULL;
    field_of_product_weights_unsorted = NULL;

    return 0;
}

////////
// MAIN FUNCTIONS
////////

int main()
{
    // files

    FILE *file_goods = NULL, *file_vendor = NULL;
    int number_of_goods = 0, number_of_vendors = 0;

    // // goods attributes

    char *goods_name = NULL;
    int *goods_pcs_in_stock = NULL;
    double *goods_price = NULL;
    double *goods_weight = NULL;
    int *goods_vendor_id = NULL;

    // vendor attributes
    int *vendor_vendor_id = NULL;
    char *vendor_name = NULL;
    char *vendor_adress = NULL;

    ////
    char console_input;

    do
    {
        printf("\nZadajte funkciu, ktoru si prajete vykonat: ");
        fflush(stdin);
        scanf("%c", &console_input);
        fflush(stdin);

        switch (console_input)
        {
        case 'v':
            v(&file_goods, &file_vendor, &number_of_goods, &number_of_vendors, &goods_name, &goods_pcs_in_stock, &goods_price, &goods_weight, &goods_vendor_id, &vendor_vendor_id, &vendor_name, &vendor_adress);
            break;
        case 'o':
            o(&file_goods);
            break;
        case 'n':
            n(&file_goods, &file_vendor, &number_of_goods, &number_of_vendors, &goods_name, &goods_pcs_in_stock, &goods_price, &goods_weight, &goods_vendor_id, &vendor_vendor_id, &vendor_name, &vendor_adress);
            break;
        case 's':
            s(&number_of_goods, &goods_name, &goods_pcs_in_stock, &goods_price, &goods_weight, &goods_vendor_id, &vendor_vendor_id, &vendor_name, &vendor_adress);
            break;
        case 'h':
            h(&number_of_goods, &goods_name, &goods_pcs_in_stock, &goods_price, &goods_weight, &goods_vendor_id, &vendor_vendor_id, &vendor_name, &vendor_adress);
            break;
        case 'p':
            p(&file_goods, &number_of_goods, &goods_name, &goods_pcs_in_stock, &goods_price, &goods_weight, &goods_vendor_id, &vendor_vendor_id, &vendor_name, &vendor_adress);
            break;
        case 'z':
            z(&number_of_goods, &goods_name, &goods_pcs_in_stock, &goods_price, &goods_weight, &goods_vendor_id, &vendor_vendor_id, &vendor_name, &vendor_adress);
            break;
        case 'k':
            break; //OSETRENIE ABY NEZBEHOL DEFAULT
        default:
            printf("\nZADALI STE NESPRAVNY PRIKAZ, SKUSTE ZNOVA\n");
            //printf("ZADANE PISMENO char: %c ascii: %i\n", console_input, console_input); // debug vypis 
            break;
        }
    } while (console_input != 'k');

    // FUNKCIA K:
    free(goods_name);
    free(goods_pcs_in_stock);
    free(goods_price);
    free(goods_weight);
    free(goods_vendor_id);
    free(vendor_vendor_id);
    free(vendor_name);
    free(vendor_adress);

    fclose(file_goods);
    fclose(file_vendor);

    printf("\n\nPROGRAM USPESNE UKONCENY!\n\n");
    return 0;
}

//gcc projekt1.c -std=c99 -pedantic -Wall -Werror -Wextra -o projekt ;; ./projekt