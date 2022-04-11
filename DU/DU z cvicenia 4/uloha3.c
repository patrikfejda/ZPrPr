//hotovo

#pragma warning(disable: 4996)
#pragma warning(disable: 6031)
#include <stdio.h>

int main() {

	FILE *subor;
	char c; 
	int pa = 0, pe = 0, pi = 0, po = 0, pu = 0, py = 0;

	if ((subor = fopen("./vstup.txt", "r")) == NULL) {
		printf("Subor sa neda otvorit\n");
	}
	else {
		printf("Subor je spravne otvoreny\n");
	}
	while ((c = getc(subor)) != EOF) {
		if(c == 'a' || c == 'A')
			pa++;
		if(c == 'e' || c == 'E')
			pe++;
		if (c == 'i' || c == 'I')
			pi++;
		if (c == 'o' || c == 'O')
			po++;
		if (c == 'u' || c == 'U')
			pu++;
		if (c == 'y' || c == 'Y')
			py++;
	}

	printf("A/a - %i krat\n"
		"E/e - %i krat\n"
		"I/i - %i krat\n"
		"O/o - %i krat\n"
		"U/u - %i krat\n"
		"Y/y - %i krat\n", pa, pe, pi, po, pu, py);

	return 0;
}