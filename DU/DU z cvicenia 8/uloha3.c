// Napíšte program, ktorý načíta zo vstupu nepárne číslo N (od 1 do 15) a
// na výstup zo znakov 'x' a '.' (bodka) nakreslí špirálu ohraničenú
// štvorcom NxN podľa príkladu nižšie.

#pragma warning(disable : 4996)
#pragma warning(disable : 6031)
#include <stdio.h>

#define prvyposledny (riadok==1)||(riadok==N)||(stlpec==N)
#define prvystlpec (stlpec == 1 && riadok>2)
#define tretiRiadok ((N>3)&&(riadok==3)&&(stlpec<=N-2))
#define predposlstpec ((N>5) && (stlpec == (N-2)) && riadok > 3 && riadok <= (N-2) )
#define predposlednyriadok ((N>5) && (riadok == N-2) && stlpec > 2 && stlpec <= (N-2) )
#define druhystlpec ((N>7) && (stlpec == 3) && riadok > 4 && riadok < (N-2) )
#define tretiriadok ((N>7) && (riadok == 5) && stlpec > 3 && stlpec <= (N-4) )
#define tretistlpecsprava ((N>8) && (stlpec == (N-4)) && riadok > 4 && riadok <= (N-4) )
#define tretipredposlednyriadok ((N>11) && (riadok == N-4) && stlpec > 4 && stlpec <= (N-4) )
#define tretistlpec ((N>11) && (stlpec == 5) && riadok > 6 && riadok < (N-4) )
#define stvrtyriadok ((N>11) && (riadok == 7) && stlpec > 4 && stlpec <= (N-6) )
#define poslednyzvyslo ((N==15) && (stlpec == 9) && riadok > 6 && riadok < (N-6) )
#define poslednyvodorovne ((N==15) && (riadok == 9) && stlpec > 6 && stlpec <= (N-6) )


int main()
{
	int N;

	do {
		printf("Zadajte neparne cislo z int <1;15>: ");
		scanf("%i",&N);
	} while (!(N % 2) || (N < 1) || (N > 15));

	for (int riadok = 1; riadok <= N; riadok++) {
		printf("\n");
		for (int stlpec = 1; stlpec <= N; stlpec++) {
			if (prvyposledny|| prvystlpec || tretiRiadok|| predposlstpec || predposlednyriadok || druhystlpec || tretiriadok || tretistlpecsprava || tretipredposlednyriadok || tretistlpec || stvrtyriadok || poslednyzvyslo|| poslednyvodorovne)
				printf("%c",219);
			else
				printf(" ");
		}
	}
	
	return 0;
}