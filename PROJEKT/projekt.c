/*
SEMINARNY PROJEKT Z PREDMETU
ZAKLADY PROCEDURALNEHO PROGRAMOVANIA 1

PATRIK FEJDA
FAKULTA INFORMATIKY A INFORMACNYCH TECHNOLOGII
SLOVENSKA TECHNICKA UNIVERZITA V BRATISLAVE

CVICIACI: MAREK GALINSKI

VYVOJOVE PROSTREDIE: MICROSOFT VISUAL STUDIO 2019
*/

#pragma warning(disable : 4996)
#pragma warning(disable : 6031)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MaxPocetVodicov 50
#define MaxDlzkaRiadkuVsubore 1000
#define MaxDlzkaMenaApriezviska 60
#define MaxDlzkaZnackaAuta 7
#define PocetKol 5
#define MaximalnyCasJednehoKola 1000.00
#define BezvyznamnaDefaultHodnotaNula 0
#define ErrorOtvoreniaSuboru 99

struct vodic
{
    char cele_meno[MaxDlzkaMenaApriezviska];
    char pohlavie;
    int rok;
    char znacka_auta[MaxDlzkaZnackaAuta];
    double casy_kol[PocetKol];
};

struct vodic vodici[MaxPocetVodicov];

/*
----------------
OPERACNE FUNKCIE
----------------
*/

int skuska_otvorenia_suboru(void)
{
    FILE *subor;
    if ((subor = fopen("./tabulka.csv", "r+")) == NULL)
    {
        printf("Vstupny subor sa neda otvorit.\n");
        return ErrorOtvoreniaSuboru;
    }
    else
    {
        printf("Vstupny subor je otvoreny spravne.\n");
    }
    fclose(subor);

    return 0;
}

int nacitanie_suboru_do_structu(int *pocetJazdcov)
{
    FILE *subor;
    subor = fopen("./tabulka.csv", "r+");

    char riadok_text[MaxDlzkaRiadkuVsubore], *substring;
    int id_vodica = 0;
    while (fgets(riadok_text, MaxDlzkaRiadkuVsubore, subor) != NULL)
    {
        substring = strtok(riadok_text, ";");
        strcpy(vodici[id_vodica].cele_meno, substring);

        substring = strtok(NULL, ";");
        vodici[id_vodica].pohlavie = substring[0];

        substring = strtok(NULL, ";");
        vodici[id_vodica].rok = atoi(substring);

        substring = strtok(NULL, ";");
        strcpy(vodici[id_vodica].znacka_auta, substring);

        for (int k = 0; k < PocetKol; k++)
        {
            substring = strtok(NULL, ";");
            vodici[id_vodica].casy_kol[k] = atof(substring);
        }

        id_vodica++;
    }

    fclose(subor);
    *pocetJazdcov = id_vodica; //id_vodica sa inkrementuje aj po poslednom vodicovi, lebo id_vodica zacina od 0

    return 0;
}

/*
---------------
POMOCNE FUNKCIE
---------------
*/

int sumarny_vypis_podla_id_jazdca(int id_jazdca)
{
    printf("\n%s, nar. %i, ", vodici[id_jazdca].cele_meno, vodici[id_jazdca].rok);
    if (vodici[id_jazdca].pohlavie == 'm')
        printf("muz, ");
    else if (vodici[id_jazdca].pohlavie == 'f')
        printf("zena, ");
    else
        printf("POHLAVIE ERROR (neznamy znak: %c), ", vodici[id_jazdca].pohlavie);
    printf("Automobil: %s\nCasy okruhov: %.3lf, %.3lf, %.3lf, %.3lf, %.3lf\n", vodici[id_jazdca].znacka_auta, vodici[id_jazdca].casy_kol[0], vodici[id_jazdca].casy_kol[1], vodici[id_jazdca].casy_kol[2], vodici[id_jazdca].casy_kol[3], vodici[id_jazdca].casy_kol[4]);

    return 0;
}

double priemer_z_n_kol(int id_jazdca, int n)
{
    double sucet = 0;
    for (int k = 0; k < n; k++)
    {
        sucet += vodici[id_jazdca].casy_kol[k];
    }
    return sucet / (double)n;
}

int najlepsie_kolo(int id, double *najlepsi_cas_doteraz, int *id_vodica_najlepsie_kolo, int *id_kola_najlepsie_kolo)
{ // FUNKCIA JE SPUSTANA PRE KAZDEHO JAZDCA SAMOSTATNE
    for (int k = 0; k < PocetKol; k++)
    {
        if (vodici[id].casy_kol[k] < *najlepsi_cas_doteraz)
        {
            *id_vodica_najlepsie_kolo = id;
            *id_kola_najlepsie_kolo = k;
            *najlepsi_cas_doteraz = vodici[id].casy_kol[k];
        }
    }
    return 0;
}

int najlepsie_kolo_vypis(int id_vodica_najlepsie_kolo, int id_kola_najlepsie_kolo)
{
    printf("\nNajlepsie kolo: %.3lf\nJazdec: %s\nCislo kola: %i\n",
           vodici[id_vodica_najlepsie_kolo].casy_kol[id_kola_najlepsie_kolo],
           vodici[id_vodica_najlepsie_kolo].cele_meno, id_kola_najlepsie_kolo + 1);

    return 0;
}

/*
--------------
HLAVNE FUNKCIE
--------------
*/

int sum(pocetJazdcov)
{
    printf("\n******************************");
    printf("\n* SUM - SUMARNY VYPIS HODNOT *");
    printf("\n******************************\n");

    for (int id = 0; id < pocetJazdcov; id++)
    {
        sumarny_vypis_podla_id_jazdca(id);
    }

    return 0;
}

int driver(int pocetJazdcov)
{
    printf("\n********************************");
    printf("\n* DRIVER - PODROBNE STATISTIKY *");
    printf("\n********************************\n");

    char referecnePriezvisko[MaxDlzkaMenaApriezviska];

    printf("\nZadajte priezvisko jazdca: ");
    scanf(" %s", referecnePriezvisko);

    for (int id = 0; id < pocetJazdcov; id++)
    {
        char *priezviskoAktualnehoJazdca;
        priezviskoAktualnehoJazdca = strrchr(vodici[id].cele_meno, ' ');
        if (strstr(priezviskoAktualnehoJazdca, referecnePriezvisko))
        {

            printf("\n%s\nnar. %i,", vodici[id].cele_meno, vodici[id].rok);

            if (vodici[id].pohlavie == 'm')
                printf(" muz, ");
            else if (vodici[id].pohlavie == 'f')
                printf(" zena, ");
            else
                printf("POHLAVIE ERROR (neznamy znak: %c), ", vodici[id].pohlavie);

            printf("\nAutomobil: %s\n\nCasy okruhov: %.3lf, %.3lf, %.3lf, %.3lf, %.3lf\n", vodici[id].znacka_auta, vodici[id].casy_kol[0], vodici[id].casy_kol[1], vodici[id].casy_kol[2], vodici[id].casy_kol[3], vodici[id].casy_kol[4]);

            int id_kola_najlepsi_cas = BezvyznamnaDefaultHodnotaNula;
            int id_kola_najhorsi_cas = BezvyznamnaDefaultHodnotaNula;

            for (int k = 0; k < PocetKol; k++)
            {
                if (vodici[id].casy_kol[k] <= vodici[id].casy_kol[id_kola_najlepsi_cas])
                    id_kola_najlepsi_cas = k;
                if (vodici[id].casy_kol[k] >= vodici[id].casy_kol[id_kola_najhorsi_cas])
                    id_kola_najhorsi_cas = k;
            }

            printf("\nNajlepsie kolo: %.3lf", vodici[id].casy_kol[id_kola_najlepsi_cas]);
            printf("\nNajhorsie kolo: %.3lf", vodici[id].casy_kol[id_kola_najhorsi_cas]);
            printf("\nPriemerne kolo: %.3lf", priemer_z_n_kol(id, PocetKol));
        }
    }

    return 0;
}

int lap(pocetJazdcov)
{
    printf("\n********************************");
    printf("\n* LAP - VYPIS NAJLEPSIEHO KOLA *");
    printf("\n********************************\n");

    int id_vodica_najlepsie_kolo = BezvyznamnaDefaultHodnotaNula;
    int id_kola_najlepsie_kolo = BezvyznamnaDefaultHodnotaNula;
    double najlepsi_cas_doteraz = MaximalnyCasJednehoKola;
    for (int id = 0; id < pocetJazdcov; id++)
    {
        najlepsie_kolo(id, &najlepsi_cas_doteraz, &id_vodica_najlepsie_kolo, &id_kola_najlepsie_kolo);
    }
    najlepsie_kolo_vypis(id_vodica_najlepsie_kolo, id_kola_najlepsie_kolo);

    return 0;
}

int gender(pocetJazdcov)
{
    printf("\n*****************************************");
    printf("\n* GENDER - VYPIS NAJLEPSIEHO KOLA M / F *");
    printf("\n*****************************************\n");

    char reference_pohlavie;
    printf("\nZadajte pohlavie m / f: ");
    scanf(" %c", &reference_pohlavie);

    int id_vodica_najlepsie_kolo = BezvyznamnaDefaultHodnotaNula;
    int id_kola_najlepsie_kolo = BezvyznamnaDefaultHodnotaNula;
    double najlepsi_cas_doteraz = MaximalnyCasJednehoKola;
    for (int id = 0; id < pocetJazdcov; id++)
    {
        if (vodici[id].pohlavie == reference_pohlavie)
            najlepsie_kolo(id, &najlepsi_cas_doteraz, &id_vodica_najlepsie_kolo, &id_kola_najlepsie_kolo);
    }
    najlepsie_kolo_vypis(id_vodica_najlepsie_kolo, id_kola_najlepsie_kolo);

    return 0;
}

int brand(int pocetJazdcov)
{

    printf("\n***************************************");
    printf("\n* BRAND - NAJLEPSIE KOLO PODLA ZNACKY *");
    printf("\n***************************************\n");

    //POLE S 1. PISMENAMI ZNACIEK AUT (ABY SOM MOHOL POUZIT FOR CYKLUS)
    char referencnaZnackaAuta[] = {'p', 'b', 'h', 'f'};

    int id_vodica_najlepsie_kolo = BezvyznamnaDefaultHodnotaNula;
    int id_kola_najlepsie_kolo = BezvyznamnaDefaultHodnotaNula;

    for (int z = 0; z < 4; z++) //ZBEHNE PRE KAZDU ZNACKU
    {
        double najlepsi_cas_doteraz = MaximalnyCasJednehoKola;
        char asponJedenJazdec = 0;
        for (int id = 0; id < pocetJazdcov; id++)
        {
            if (vodici[id].znacka_auta[0] == referencnaZnackaAuta[z])
            {
                najlepsie_kolo(id, &najlepsi_cas_doteraz, &id_vodica_najlepsie_kolo, &id_kola_najlepsie_kolo);
                asponJedenJazdec++;
            }
        }
        if (asponJedenJazdec)
        {
            printf("\nZnacka: %s", vodici[id_vodica_najlepsie_kolo].znacka_auta);
            najlepsie_kolo_vypis(id_vodica_najlepsie_kolo, id_kola_najlepsie_kolo);
        }
        else
            printf("\nTATO ZNACKA SA NENACHADZA V TABULKE!\n");
    }

    return 0;
}

int year(int pocetJazdcov)
{
    printf("\n**************************************************");
    printf("\n* YEAR - NAJLEPSIE KOLO VODICA STARSIEHO AKO ROK *");
    printf("\n**************************************************\n");

    int referencnyRok;
    printf("\nZadajte referencny rok: ");
    scanf("%i", &referencnyRok);

    int id_vodica_najlepsie_kolo = BezvyznamnaDefaultHodnotaNula;
    int id_kola_najlepsie_kolo = BezvyznamnaDefaultHodnotaNula;
    double najlepsi_cas_doteraz = MaximalnyCasJednehoKola;
    for (int id = 0; id < pocetJazdcov; id++)
    {
        if (vodici[id].rok < referencnyRok)
        {
            najlepsie_kolo(id, &najlepsi_cas_doteraz, &id_vodica_najlepsie_kolo, &id_kola_najlepsie_kolo);
        }
    }

    printf(
        "\n%s"
        "\nnar. %i"
        "\nNajlepsie kolo: %.3lf"
        "\nCislo kola: %i\n",
        vodici[id_vodica_najlepsie_kolo].cele_meno, vodici[id_vodica_najlepsie_kolo].rok,
        vodici[id_vodica_najlepsie_kolo].casy_kol[id_kola_najlepsie_kolo], id_kola_najlepsie_kolo + 1);

    return 0;
}

int average(int pocetJazdcov)
{
    printf("\n**********************************");
    printf("\n* AVERAGE - VYPIS PRIEMERNYCH KOL*");
    printf("\n**********************************\n");

    double aktualny_priemer, najlepsi_priemer_zatial = MaximalnyCasJednehoKola;
    int id_vodica_najlepsi_priemer = BezvyznamnaDefaultHodnotaNula;

    for (int id = 0; id < pocetJazdcov; id++)
    {
        aktualny_priemer = priemer_z_n_kol(id, PocetKol);

        printf("\n%s - %.3lf\n", vodici[id].cele_meno, aktualny_priemer);

        if (aktualny_priemer < najlepsi_priemer_zatial)
        {
            najlepsi_priemer_zatial = aktualny_priemer;
            id_vodica_najlepsi_priemer = id;
        }
    }

    printf("\n\nNajlepsie:\n%s - %.3lf\n", vodici[id_vodica_najlepsi_priemer].cele_meno, najlepsi_priemer_zatial);

    return 0;
}

int under(int pocetJazdcov)
{
    printf("\n************************************");
    printf("\n* UNDER - VYPIS KOL POD URCENY CAS *");
    printf("\n************************************\n");

    double referencny_cas;
    printf("\nZadajte referencny cas: ");
    scanf("%lf", &referencny_cas);
    printf("\n");

    int asponJedenJazdec = 0;

    for (int id = 0; id < pocetJazdcov; id++)
    {
        //POCITANIE RYCHLEJSICH KOL
        int pocetRychlejsichKol = 0;
        for (int k = 0; k < PocetKol; k++)
        {
            if (vodici[id].casy_kol[k] < referencny_cas)
            {
                //printf("i: %i k: %i, %i + 1 = %i\n",i ,k, pocetRychlejsichKol, pocetRychlejsichKol + 1);
                pocetRychlejsichKol++;
                asponJedenJazdec++;
            }
        }
        //VYPIS PRETEKARA (LEN AK DAL ASPON 1 LEPSIE KOLO AKO REF.)
        //VYPIS NA 3 CASTI
        // 1. MENO - 2. POCET LEPSICH KOL - 3. CASY KOL + \n
        if (pocetRychlejsichKol > 0)
        {

            // 1. CAST - MENO
            printf("%s - ", vodici[id].cele_meno);

            // 2. CAST - POCET LEPSICH KOL
            if (pocetRychlejsichKol == 1)
                printf("1 kolo");
            else if (pocetRychlejsichKol == 5)
                printf("5 kol");
            else
                printf("%i kola", pocetRychlejsichKol);

            // 3. CAST - CASY KOL
            for (int k = 0; k < PocetKol; k++)
            {
                if (vodici[id].casy_kol[k] < referencny_cas)
                {
                    printf(", %i (%.3lf)", k + 1, vodici[id].casy_kol[k]);
                }
            }
            printf("\n");
        }
    }
    if (!asponJedenJazdec)
        printf("ANI JEDEN JAZDEC NEPRESIEL KOLO POD REFERENCNY CAS!\n");
    return 0;
}

int change(int pocetJazdcov)
{
    printf("\n****************************");
    printf("\n* CHANGE - ZMENA CASU KOLA *");
    printf("\n****************************\n");

    int idJazdcaNaZmenu = BezvyznamnaDefaultHodnotaNula;
    char referecnePriezvisko[MaxDlzkaMenaApriezviska];

    //Z PRIEZVISKA ZISTIM ID JAZDCA (ID JAZDCA = RIADOK, RIADKOVANIE ZACINA OD NULY)
    printf("\nZadajte priezvisko jazdca: ");
    scanf(" %s", referecnePriezvisko);

    for (int id = 0; id < pocetJazdcov; id++)
    {
        char *priezviskoAktualnehoJazdca;
        priezviskoAktualnehoJazdca = strrchr(vodici[id].cele_meno, ' ');
        if (strstr(priezviskoAktualnehoJazdca, referecnePriezvisko))
            idJazdcaNaZmenu = id;
    }

    int idKolaNaZmenu;
    double NovyCasKola;
    printf("\nZadajte cislo kola a novy cas (odelene medzerou): ");
    scanf(" %i %lf", &idKolaNaZmenu, &NovyCasKola);
    idKolaNaZmenu--; //LEBO PROGRAMATORI POCITAJU OD NULY :)

    FILE *subor, *temp;
    int aktualnyRiadok = 0;
    char riadok_text[MaxDlzkaRiadkuVsubore];

    subor = fopen("./tabulka.csv", "r");
    temp = fopen("temp.csv", "w");

    while (fgets(riadok_text, MaxDlzkaRiadkuVsubore, subor) != NULL)
    {
        if (aktualnyRiadok != idJazdcaNaZmenu)
        {
            fprintf(temp, "%s", riadok_text);
        }
        else
        {
            fprintf(temp, "%s;", vodici[idJazdcaNaZmenu].cele_meno);
            fprintf(temp, "%c;", vodici[idJazdcaNaZmenu].pohlavie);
            fprintf(temp, "%i;", vodici[idJazdcaNaZmenu].rok);
            fprintf(temp, "%s;", vodici[idJazdcaNaZmenu].znacka_auta);
            for (int k = 0; k < PocetKol; k++)
            {
                if (k == idKolaNaZmenu)
                    fprintf(temp, "%.3lf", NovyCasKola);
                else
                    fprintf(temp, "%.3lf", vodici[idJazdcaNaZmenu].casy_kol[k]);
                if (k < 4)
                    fprintf(temp, ";");
                else
                    fprintf(temp, "\n");
            }
        }
        aktualnyRiadok++;
    }

    fclose(subor);
    fclose(temp);
    remove("./tabulka.csv");
    rename("temp.csv", "tabulka.csv");

    printf("\nJazdcovi s menom '%s' bol zmemeny cas %i. kola z %.3lf na %.3lf\n", vodici[idJazdcaNaZmenu].cele_meno, idKolaNaZmenu + 1, vodici[idJazdcaNaZmenu].casy_kol[idKolaNaZmenu], NovyCasKola);

    return 0;
}

int newdriver()
{
    printf("\n**************************************");
    printf("\n* NEWDRIVER - PRIDANIE NOVEHO JAZDCA *");
    printf("\n**************************************\n");

    FILE *subor;
    subor = fopen("./tabulka.csv", "a");
    char c;
    fprintf(subor, "\n");
    getchar(); //dam prec \n

    printf("\nZadaj meno a priezvisko: ");
    while ((c = getchar()) != '\n')
    {
        fprintf(subor, "%c", c);
    }
    fprintf(subor, ";");

    printf("\nZadaj pohlavie m / f: ");
    while ((c = getchar()) != '\n')
    {
        fprintf(subor, "%c", c);
    }
    fprintf(subor, ";");

    printf("\nZadaj rok narodenia: ");
    while ((c = getchar()) != '\n')
    {
        fprintf(subor, "%c", c);
    }
    fprintf(subor, ";");

    printf("\nZadaj znacku auta: ");
    while ((c = getchar()) != '\n')
    {
        fprintf(subor, "%c", c);
    }
    fprintf(subor, ";");

    for (int k = 0; k < PocetKol; k++)
    {
        printf("\nZadaj cas %i. kola: ", k + 1);
        while ((c = getchar()) != '\n')
        {
            fprintf(subor, "%c", c);
        }
        if (k != 4)
            fprintf(subor, ";");
    }

    //fprintf(subor, "\n%s", str);
    fclose(subor);

    return 0;
}

int rmdriver(pocetJazdcov)
{
    printf("\n**************************************");
    printf("\n* REMOVE DRIVER - ODSTRANENIE JAZDCA *");
    printf("\n**************************************\n");

    int idJazdcaNaOdstranenie = -1; //lebo warning C6001; lebo ak by som zadal zly vstup tak vymaze prveho
    char referecnePriezvisko[MaxDlzkaMenaApriezviska];

    printf("\nZadajte priezvisko jazdca: ");
    scanf(" %s", referecnePriezvisko);

    for (int id = 0; id < pocetJazdcov; id++)
    {
        char *priezviskoAktualnehoJazdca;
        priezviskoAktualnehoJazdca = strrchr(vodici[id].cele_meno, ' ');
        if (strstr(priezviskoAktualnehoJazdca, referecnePriezvisko))
            idJazdcaNaOdstranenie = id;
    }

    if (idJazdcaNaOdstranenie == -1)
    {
        printf("\nNenasiel som jazdca s priezviskom: %s\nProsim skontrolujte ci ste priezvisko napisali spravne alebo ci nemate zapnuty CAPS LOCK\n", referecnePriezvisko);
        return 0;
    }

    FILE *subor, *temp;
    int aktualnyRiadok = 0;
    char riadok_text[MaxDlzkaRiadkuVsubore];

    subor = fopen("./tabulka.csv", "r");
    temp = fopen("temp.csv", "w");

    while (fgets(riadok_text, MaxDlzkaRiadkuVsubore, subor) != NULL)
    {
        if (aktualnyRiadok != idJazdcaNaOdstranenie)
        {
            fprintf(temp, "%s", riadok_text);
        }
        aktualnyRiadok++;
    }

    fclose(subor);
    fclose(temp);
    remove("./tabulka.csv");
    rename("temp.csv", "tabulka.csv");

    printf("\nJazdec s menom '%s' bol vymazany.\n", vodici[idJazdcaNaOdstranenie].cele_meno);

    return 0;
}

/*
--------------
SWITCH FUNKCIE
--------------
*/

int print_main_switch_options(void)
{
    printf(
        "\n ___________________________________________"
        "\n|                                           |"
        "\n| ZVOLTE SI JEDNU Z NASLEDUJUCICH MOZNOSTI  |"
        "\n|                                           |"
        "\n| s - sumarny vypis hodnot                  |"
        "\n| d - vypis hodnot podla jazdca             |"
        "\n| l - vypis najlepsieho kola                |"
        "\n| g - najlepsie kolo podla pohlavia         |"
        "\n| b - najlepsie kolo podla znacky           |"
        "\n| y - vypis najlepsieho kola podla roku     |"
        "\n| a - vypis najlepsieho priemerneho kola    |"
        "\n| u - jazdci s kolom pod cas                |"
        "\n| c - prepisanie hodnoty nejakeho kola      |"
        "\n| n - pridanie noveho jazdca                |"
        "\n| r - vymazanie jazdca                      |"
        "\n| x - ukoncenie programu                    |"
        "\n|___________________________________________|"
        "\n\nVasa volba: ");
    return 0;
}

int main_switch(char volba, int pocetJazdcov)
{
    switch (volba)
    {
    case 's':
        nacitanie_suboru_do_structu(&pocetJazdcov);
        sum(pocetJazdcov);
        break;
    case 'd':
        nacitanie_suboru_do_structu(&pocetJazdcov);
        driver(pocetJazdcov);
        break;
    case 'l':
        nacitanie_suboru_do_structu(&pocetJazdcov);
        lap(pocetJazdcov);
        break;
    case 'g':
        nacitanie_suboru_do_structu(&pocetJazdcov);
        gender(pocetJazdcov);
        break;
    case 'b':
        nacitanie_suboru_do_structu(&pocetJazdcov);
        brand(pocetJazdcov);
        break;
    case 'y':
        nacitanie_suboru_do_structu(&pocetJazdcov);
        year(pocetJazdcov);
        break;
    case 'a':
        nacitanie_suboru_do_structu(&pocetJazdcov);
        average(pocetJazdcov);
        break;
    case 'u':
        nacitanie_suboru_do_structu(&pocetJazdcov);
        under(pocetJazdcov);
        break;
    case 'c':
        nacitanie_suboru_do_structu(&pocetJazdcov);
        change(pocetJazdcov);
        break;
    case 'n':
        newdriver();
        nacitanie_suboru_do_structu(&pocetJazdcov);
        sum(pocetJazdcov);
        break;
    case 'r':
        nacitanie_suboru_do_structu(&pocetJazdcov);
        rmdriver(pocetJazdcov);
        break;
    case 'x':
        break; //OSETRENIE ABY NEZBEHOL DEFAULT
    default:
        printf("\nZADALI STE NESPRAVNY PRIKAZ, SKUSTE ZNOVA\n");
        printf("DEBUG: char: %c ascii: %i", volba, volba);
        break;
    }
    return 0;
}

/*
------------
MAIN FUNKCIA
------------
*/

int main()
{
    char volba;
    int pocetJazdcov;
    if (skuska_otvorenia_suboru() != 0)
    {
        return ErrorOtvoreniaSuboru; //KONIEC PROGRAMU
    }
    nacitanie_suboru_do_structu(&pocetJazdcov);

    printf("Pocet vsetkych jazdcov: %i\n", pocetJazdcov);

    do
    {
        print_main_switch_options();
        scanf(" %c", &volba);
        main_switch(volba, pocetJazdcov);

    } while (volba != 'x');
    printf("\n\n*******************\n* KONIEC PROGRAMU *\n*******************\n\n");

    return 0;
}