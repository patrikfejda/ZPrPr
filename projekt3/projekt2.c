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

#define MAX_NAME_LENGTH 52
#define MAX_ADRESS_LENGTH 102
#define MAX_LINE_IN_FILE_LENGTH 110
typedef struct guest
{
	char name[MAX_NAME_LENGTH];
	char adress[MAX_ADRESS_LENGTH];
	int reservation_start;
	int reservation_end;
	struct guest *next;
} GUEST;

typedef struct room
{
	int room_number;
	int number_of_beds;
	double price;
	GUEST *room_guest; // typ hosta uz mam vygenerovany
	struct room *next;
} ROOM;

// HELP FUNCTIONS

FILE *open_file(char file_name[32], char mode[5])
{
	FILE *file;
	if ((file = fopen(file_name, mode)) == NULL)
	{
		printf("Zaznamy neboli nacitane.\n");
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

int arrange_rooms(ROOM *Hotel, int number_of_rooms) // https://www.geeksforgeeks.org/c-program-bubble-sort-linked-list/
{
	// ak este nebola vykonana funkcia n()
	if (Hotel == NULL)
	{
		return 0;
	}

	ROOM *actual_room;

	for (int i = 0; i < number_of_rooms; i++)
	{
		actual_room = Hotel;

		while (actual_room->next != NULL)
		{
			if (actual_room->room_number > actual_room->next->room_number) // aktualne cislo izby > cislo dalsej izby
			{

				int temp_room_number = actual_room->room_number;
				actual_room->room_number = actual_room->next->room_number;
				actual_room->next->room_number = temp_room_number;

				int temp_number_of_beds = actual_room->number_of_beds;
				actual_room->number_of_beds = actual_room->next->number_of_beds;
				actual_room->next->number_of_beds = temp_number_of_beds;

				double temp_price = actual_room->price;
				actual_room->price = actual_room->next->price;
				actual_room->next->price = temp_price;

				GUEST *temp_room_guest = actual_room->room_guest;
				actual_room->room_guest = actual_room->next->room_guest;
				actual_room->next->room_guest = temp_room_guest;

				// menim iba hodnoty, nemenim next kedze next mi v podstate nahradza poradie v liste vramci bublesortu
			}
			actual_room = actual_room->next; // posuvam sa na dalsiu izbu
		}
	}

	return 0;
}

void free_memory(ROOM **Hotel)
{
	if (*Hotel != NULL) // ak uz bol hotel nacitany tak musim free() vsetky izby a guests
	{
		ROOM *room = *Hotel;
		ROOM *room_to_free = room;
		GUEST *guest = NULL;
		GUEST *guest_to_free = NULL;

		while (room != NULL)
		{
			guest = room->room_guest;
			while (guest->next != NULL)
			{ // uvolnit vsetkych hosti v izbe
				guest_to_free = guest;
				guest = guest->next;
				free(guest_to_free);
			}
			free(guest);

			room_to_free = room;
			room = room->next;	// posuniem sa na dalsiu izbu
			free(room_to_free); // uvolnit izbu
		}

		room = NULL;
		*Hotel = NULL;
	}
}

// PROJECT FUNCTIONS

int n(FILE **file, ROOM **Hotel, int *number_of_rooms)
{
	// OTVORENIE SUBORU

	if ((*file) == NULL) // subor este nebol otvoreny
	{
		(*file) = open_file("hotel.txt", "r");
	}
	else
	{
		rewind(*file);
		if (fclose(*file) != 0)
		{
			printf("Neda sa zavriet subor.");
			exit(1);
		}
		*file = NULL; // pre istotu
		*file = open_file("hotel.txt", "r");
	}

	if (*Hotel != NULL) // ak uz bol hotel nacitany tak musim free() vsetky izby a guests
	{
		ROOM *room = *Hotel;
		ROOM *room_to_free = room;
		GUEST *guest = NULL;
		GUEST *guest_to_free = NULL;

		while (room != NULL)
		{
			guest = room->room_guest;
			while (guest->next != NULL)
			{ // uvolnit vsetkych hosti v izbe
				guest_to_free = guest;
				guest = guest->next;
				free(guest_to_free);
			}
			free(guest);

			room_to_free = room;
			room = room->next;	// posuniem sa na dalsiu izbu
			free(room_to_free); // uvolnit izbu
		}

		room = NULL;
		*Hotel = NULL;
	}

	*number_of_rooms = 0;

	int lines_in_file = 0;
	lines_in_file = count_lines_in_file(*file);
	printf(">>Pocet riadkov v subore: %i\n", lines_in_file);

	int max_number_of_rooms = 0;
	max_number_of_rooms = lines_in_file / 8; // izba s 1 hostom je na 8 riadkov
	max_number_of_rooms += 1;

	rewind(*file);
	GUEST *POM_first_guest;
	ROOM *POM_room;

	char line_text[MAX_LINE_IN_FILE_LENGTH];
	fgets(line_text, MAX_LINE_IN_FILE_LENGTH, *file);
	line_text[strlen(line_text) - 1] = '\0'; // odstranenie enteru
	while (1)								 // 1 -> len docasna konstanta kym nevymyslim dobry while
	{
		if (strcmp(line_text, "---") == 0)
		{
			(*number_of_rooms)++;
			// mozem nacitat izbu, nacitam do pomocnej a potom priradim do spajaneho zoznamu
			POM_room = (ROOM *)calloc(1, sizeof(ROOM));

			POM_room->room_guest = NULL; //nastvavim si na NULL
			POM_room->next = NULL;		 //nastvavim si na NULL

			// ROOM NUMBER
			fgets(line_text, MAX_LINE_IN_FILE_LENGTH, *file);
			POM_room->room_number = atoi(line_text);

			// NUMBER OF BEDS
			fgets(line_text, MAX_LINE_IN_FILE_LENGTH, *file);
			POM_room->number_of_beds = atoi(line_text);

			// PRICE
			fgets(line_text, MAX_LINE_IN_FILE_LENGTH, *file);
			POM_room->price = atof(line_text);

			fgets(line_text, MAX_LINE_IN_FILE_LENGTH, *file);
			line_text[strlen(line_text) - 1] = '\0'; // odstranenie enteru

			if (strcmp(line_text, "#") == 0)
			{
				while (strcmp(line_text, "#") == 0)
				{
					//idem nacitavat ludi
					POM_first_guest = (GUEST *)calloc(1, sizeof(GUEST)); // do tejto premennej nacitam noveho hosta

					// GUEST NAME
					fgets(line_text, MAX_LINE_IN_FILE_LENGTH, *file);
					strcpy(POM_first_guest->name, line_text);

					// GUEST ADRESS
					fgets(line_text, MAX_LINE_IN_FILE_LENGTH, *file);
					strcpy(POM_first_guest->adress, line_text);

					// GUEST RESERVATION START
					fgets(line_text, MAX_LINE_IN_FILE_LENGTH, *file);
					POM_first_guest->reservation_start = atoi(line_text);

					// GUEST RESERVATION END
					fgets(line_text, MAX_LINE_IN_FILE_LENGTH, *file);
					POM_first_guest->reservation_end = atoi(line_text);
					POM_first_guest->next = NULL;

					//priradim nacitaneho cloveka izbe na koniec spajaneho zoznamu
					if (POM_room->room_guest == NULL) // ak je to prvy host
						POM_room->room_guest = POM_first_guest;
					else
					{
						GUEST *POM_guest = POM_room->room_guest; // pomocna premenna
						while (POM_guest->next != NULL)			 // idem na koniec spajaneho zoznamu hosti danej izby
							POM_guest = POM_guest->next;
						POM_guest->next = POM_first_guest; //poslednemu hostovi priradim ukazovatel nacitaneho hosta
					}

					fgets(line_text, MAX_LINE_IN_FILE_LENGTH, *file);
					line_text[strlen(line_text) - 1] = '\0'; // odstranenie enteru
				}
			}
			else
			{
				//izba nema cloveka
			}

			if ((*Hotel) == NULL) // moj zoznam izieb je prazdny
				(*Hotel) = POM_room;
			else
			{
				ROOM *POM_roomXX = (*Hotel);	 // pomocna premenna
				while (POM_roomXX->next != NULL) // idem na koniec spajaneho zoznamu izieb
					POM_roomXX = POM_roomXX->next;
				POM_roomXX->next = POM_room; //poslednej izbe priradim ukazovatel nacitanej izby
			}
		}
		else
		{
			break; // ukoncenie nacitavania
		}
	}
	printf("Nacitalo sa %i zaznamov.\n", *number_of_rooms);

	return (0);
}

int v(ROOM **Hotel, int number_of_rooms)
{

	ROOM *actual_room = *Hotel;
	GUEST *actual_guest = NULL;

	for (int i = 0; i < number_of_rooms; i++)
	{
		printf("----------------------------\n----------------------------\n");
		printf("Izba cislo: %i\n", actual_room->room_number);
		printf("Pocet lozok: %i\n", actual_room->number_of_beds);
		printf("Cena: %.2lf\n", actual_room->price);
		printf("Zoznam hosti:\n");

		actual_guest = actual_room->room_guest;

		while (actual_guest != NULL)
		{
			printf("Meno: %s", actual_guest->name);
			printf("Adresa: %s", actual_guest->adress);
			printf("Zaciatok rezervacie: %i\n", actual_guest->reservation_start);
			printf("Koniec rezervacie: %i\n", actual_guest->reservation_end);

			actual_guest = actual_guest->next;
			if (actual_guest != NULL)
			{
				printf("############################\n");
			}
		}

		actual_room = actual_room->next;
	}

	return 0;
}

int r(FILE **file, ROOM **Hotel, int *number_of_rooms)
{
	if (*file == NULL || *Hotel == NULL)
	{
		printf("Funkcia N este nebola vykonana!\n");
		return 0;
	}

	// NACITAVAM STDIN DO VAR

	int room_number_add = 0;
	fflush(stdin);
	printf("Cislo izby: ");
	scanf("%i", &room_number_add);

	int number_of_beds_add = 0;
	fflush(stdin);
	printf("Pocet posteli: ");
	scanf("%i", &number_of_beds_add);

	double price_add = 0.0;
	fflush(stdin);
	printf("Cena: ");
	scanf("%lf", &price_add);

	int number_of_guests = 0;
	fflush(stdin);
	printf("Pocet hosti: ");
	scanf("%i", &number_of_guests);

	(*number_of_rooms)++;

	// VAR DO STRUCTU

	ROOM *POM_room;
	POM_room = (ROOM *)calloc(1, sizeof(ROOM));

	POM_room->room_number = room_number_add;
	POM_room->number_of_beds = number_of_beds_add;
	POM_room->price = price_add;
	POM_room->next = NULL;

	// PRIDAM NEW ROOM NA KONIEC HOTELA

	ROOM *room_in_hotel = NULL;
	room_in_hotel = *Hotel;
	while (room_in_hotel->next != NULL)
	{
		room_in_hotel = room_in_hotel->next;
	}
	room_in_hotel->next = POM_room;

	// NACITAVAM HOSTI

	GUEST *first_guest, *POM_first_guest;

	first_guest = (GUEST *)calloc(number_of_guests, sizeof(GUEST));

	POM_first_guest = first_guest;
	char line_text[MAX_LINE_IN_FILE_LENGTH];

	for (int i = 1; i <= number_of_guests; i++)
	{
		printf("HOST %i\n", i);

		//idem nacitavat ludi
		POM_first_guest = (GUEST *)calloc(1, sizeof(GUEST)); // do tejto premennej nacitam noveho hosta

		// GUEST NAME
		printf("Meno: ");
		fflush(stdin);
		fgets(line_text, MAX_LINE_IN_FILE_LENGTH, stdin);
		strcpy(POM_first_guest->name, line_text);

		// GUEST ADRESS
		printf("Adresa: ");
		fflush(stdin);
		fgets(line_text, MAX_LINE_IN_FILE_LENGTH, stdin);
		strcpy(POM_first_guest->adress, line_text);

		// GUEST RESERVATION START
		printf("Zaciatok rezervacie: ");
		fflush(stdin);
		fgets(line_text, MAX_LINE_IN_FILE_LENGTH, stdin);
		POM_first_guest->reservation_start = atoi(line_text);

		// GUEST RESERVATION END
		printf("Koniec rezervacie: ");
		fflush(stdin);
		fgets(line_text, MAX_LINE_IN_FILE_LENGTH, stdin);
		POM_first_guest->reservation_end = atoi(line_text);

		POM_first_guest->next = NULL;

		//priradim nacitaneho cloveka izbe na koniec spajaneho zoznamu
		if (POM_room->room_guest == NULL) // ak je to prvy host
			POM_room->room_guest = POM_first_guest;
		else
		{
			GUEST *POM_guest = POM_room->room_guest; // pomocna premenna
			while (POM_guest->next != NULL)			 // idem na koniec spajaneho zoznamu hosti danej izby
				POM_guest = POM_guest->next;
			POM_guest->next = POM_first_guest; //poslednemu hostovi priradim ukazovatel nacitaneho hosta
		}
	}

	// ZAPIS DO SUBORU

	// OTVORIM SUBOR NA WRITE

	if ((*file) == NULL) // subor este nebol otvoreny
	{
		printf("PATRIK TENTO PRIPAD NEMOZE NASTAT, AK NASTAL NIECO SI KOLOSIALNE POKAZIL!!!!");
	}
	else
	{
		rewind(*file);
		if (fclose(*file) != 0)
		{
			printf("Neda sa zavriet subor.");
			exit(1);
		}
		*file = NULL; // pre istotu
		*file = open_file("hotel.txt", "w");
	}

	ROOM *actual_room;
	actual_room = (ROOM *)calloc(1, sizeof(ROOM));
	actual_room = *Hotel;

	GUEST *actual_guest;
	actual_guest = (GUEST *)calloc(1, sizeof(GUEST));
	actual_guest = NULL;

	do
	{
		fprintf(*file, "---\n");

		// room number
		fprintf(*file, "%i\n", actual_room->room_number);

		// room number of beds
		fprintf(*file, "%i\n", actual_room->number_of_beds);

		// room price
		fprintf(*file, "%.2lf\n", actual_room->price);

		actual_guest = NULL;
		actual_guest = actual_room->room_guest;

		do
		{
			fprintf(*file, "#\n");

			// guest name
			fprintf(*file, "%s", actual_guest->name);

			// guest adress
			fprintf(*file, "%s", actual_guest->adress);

			// reservation start
			fprintf(*file, "%i\n", actual_guest->reservation_start);

			// reservation end
			fprintf(*file, "%i\n", actual_guest->reservation_end);

			actual_guest = actual_guest->next;

		} while (actual_guest != NULL);

		actual_room = actual_room->next;

	} while (actual_room != NULL);

	// OTVORIM SUBOR NA READ

	if ((*file) == NULL) // toto sa nemoze stat
	{
		(*file) = open_file("hotel.txt", "r");
	}
	else
	{
		rewind(*file);
		if (fclose(*file) != 0)
		{
			printf("Neda sa zavriet subor.");
			exit(1);
		}
		*file = NULL; // pre istotu
		*file = open_file("hotel.txt", "r");
	}

	return 0;
}

int z(FILE **file, ROOM **Hotel, int *number_of_rooms)
{
	if (*file == NULL || *Hotel == NULL)
	{
		printf("Funkcia N este nebola vykonana!\n");
		return 0;
	}

	// NACITAVAM STDIN DO VAR

	int room_number_to_delete = 0;
	fflush(stdin);
	printf("Cislo izby: ");
	scanf("%i", &room_number_to_delete);

	ROOM *actual_room = NULL, *previous_room = NULL;

	// najdem izbu

	previous_room = NULL;
	actual_room = *Hotel;

	while ((actual_room->next != NULL) && (actual_room->room_number != room_number_to_delete))
	{
		previous_room = actual_room;
		actual_room = actual_room->next;
	}

	// uvolnim pamat + "zmazen ho takymto sposobom"
	// before A -> B -> C -> D (chcem zmazat B)
	// nastavim A.next = C
	// after A -> C -> D

	if (previous_room != NULL)
	{
		previous_room->next = actual_room->next; // vid vysvetlenie vyssie
	}
	else
	{ // user vybral prvu izbu
		*Hotel = actual_room->next;
	}

	// free memory guest

	GUEST *guest = NULL;
	GUEST *guest_to_free = NULL;

	guest = actual_room->room_guest;
	while (guest->next != NULL)
	{ // uvolnit vsetkych hosti v izbe
		guest_to_free = guest;
		guest = guest->next;
		free(guest_to_free);
	}
	free(guest);

	// free memory room

	free(actual_room);

	(*number_of_rooms)--;

	// ZAPIS DO SUBORU

	// OTVORIM SUBOR NA WRITE

	if ((*file) == NULL) // subor este nebol otvoreny
	{
		printf("PATRIK TENTO PRIPAD NEMOZE NASTAT, AK NASTAL NIECO SI KOLOSIALNE POKAZIL!!!!");
	}
	else
	{
		rewind(*file);
		if (fclose(*file) != 0)
		{
			printf("Neda sa zavriet subor.");
			exit(1);
		}
		*file = NULL; // pre istotu
		*file = open_file("hotel.txt", "w");
	}

	// ROOM *actual_room; // uz je hore
	actual_room = (ROOM *)calloc(1, sizeof(ROOM));
	actual_room = *Hotel;

	GUEST *actual_guest;
	actual_guest = (GUEST *)calloc(1, sizeof(GUEST));
	actual_guest = NULL;

	do
	{
		fprintf(*file, "---\n");

		// room number
		fprintf(*file, "%i\n", actual_room->room_number);

		// room number of beds
		fprintf(*file, "%i\n", actual_room->number_of_beds);

		// room price
		fprintf(*file, "%.2lf\n", actual_room->price);

		actual_guest = NULL;
		actual_guest = actual_room->room_guest;

		do
		{
			fprintf(*file, "#\n");

			// guest name
			fprintf(*file, "%s", actual_guest->name);

			// guest adress
			fprintf(*file, "%s", actual_guest->adress);

			// reservation start
			fprintf(*file, "%i\n", actual_guest->reservation_start);

			// reservation end
			fprintf(*file, "%i\n", actual_guest->reservation_end);

			actual_guest = actual_guest->next;

		} while (actual_guest != NULL);

		actual_room = actual_room->next;

	} while (actual_room != NULL);

	// OTVORIM SUBOR NA READ

	if ((*file) == NULL) // toto sa nemoze stat
	{
		(*file) = open_file("hotel.txt", "r");
	}
	else
	{
		rewind(*file);
		if (fclose(*file) != 0)
		{
			printf("Neda sa zavriet subor.");
			exit(1);
		}
		*file = NULL; // pre istotu
		*file = open_file("hotel.txt", "r");
	}

	printf("Rezervacia izby cislo %i bola zrusena.\n", room_number_to_delete);

	return 0;
}

int h(ROOM **Hotel, int number_of_room)
{
	if (*Hotel == NULL)
	{
		printf("Funkcia N este nebola vykonana!\n");
		return 0;
	}

	int reference_date = 0;
	fflush(stdin);
	printf("Zadajte datum (RRRRMMDD): ");
	scanf("%i", &reference_date);

	char found_at_leats_one_room = 0;
	char room_reserved = 0;

	ROOM *actual_room = NULL;
	GUEST *actual_guest = NULL;

	actual_room = *Hotel;

	for (int i = 0; i < number_of_room; i++)
	{
		room_reserved = 0;
		actual_guest = actual_room->room_guest;

		do
		{ // cyklus zbehne a najde ci v danej izbe ma na dany den ma aspon 1 host rezervaciu
			if ((actual_guest->reservation_start <= reference_date) && (actual_guest->reservation_end >= reference_date))
			{
				room_reserved = 1;
				found_at_leats_one_room = 1;
				break;
			}
			actual_guest = actual_guest->next;
		} while (actual_guest != NULL);

		if (room_reserved)
		{
			printf("%i\n", actual_room->room_number);
		}
		actual_room = actual_room->next;
	}

	if (!found_at_leats_one_room)
	{
		printf("K datumu %i neevidujeme rezervaciu.\n", reference_date);
	}

	return 0;
}

int a(FILE **file, ROOM **Hotel)
{
	if (*file == NULL || *Hotel == NULL)
	{
		printf("Funkcia N este nebola vykonana!\n");
		return 0;
	}

	// NACITAVAM STDIN DO VAR

	int room_number_to_change = 0;
	fflush(stdin);
	printf("Cislo izby: ");
	scanf("%i", &room_number_to_change);

	int number_of_beds_to_change = 0;
	fflush(stdin);
	printf("Pocet posteli: ");
	scanf("%i", &number_of_beds_to_change);

	// najdem izbu

	ROOM *actual_room = NULL;

	actual_room = *Hotel;

	while ((actual_room->next != NULL) && (actual_room->room_number != room_number_to_change))
	{
		actual_room = actual_room->next;
	}

	// zapis

	actual_room->number_of_beds = number_of_beds_to_change;

	// ZAPIS DO SUBORU

	// OTVORIM SUBOR NA WRITE

	if ((*file) == NULL) // subor este nebol otvoreny
	{
		printf("PATRIK TENTO PRIPAD NEMOZE NASTAT, AK NASTAL NIECO SI KOLOSIALNE POKAZIL!!!!");
	}
	else
	{
		rewind(*file);
		if (fclose(*file) != 0)
		{
			printf("Neda sa zavriet subor.");
			exit(1);
		}
		*file = NULL; // pre istotu
		*file = open_file("hotel.txt", "w");
	}

	actual_room = (ROOM *)calloc(1, sizeof(ROOM));
	actual_room = *Hotel;

	GUEST *actual_guest;
	actual_guest = (GUEST *)calloc(1, sizeof(GUEST));
	actual_guest = NULL;

	do
	{
		fprintf(*file, "---\n");

		// room number
		fprintf(*file, "%i\n", actual_room->room_number);

		// room number of beds
		fprintf(*file, "%i\n", actual_room->number_of_beds);

		// room price
		fprintf(*file, "%.2lf\n", actual_room->price);

		actual_guest = NULL;
		actual_guest = actual_room->room_guest;

		do
		{
			fprintf(*file, "#\n");

			// guest name
			fprintf(*file, "%s", actual_guest->name);

			// guest adress
			fprintf(*file, "%s", actual_guest->adress);

			// reservation start
			fprintf(*file, "%i\n", actual_guest->reservation_start);

			// reservation end
			fprintf(*file, "%i\n", actual_guest->reservation_end);

			actual_guest = actual_guest->next;

		} while (actual_guest != NULL);

		actual_room = actual_room->next;

	} while (actual_room != NULL);

	// OTVORIM SUBOR NA READ

	if ((*file) == NULL) // toto sa nemoze stat
	{
		(*file) = open_file("hotel.txt", "r");
	}
	else
	{
		rewind(*file);
		if (fclose(*file) != 0)
		{
			printf("Neda sa zavriet subor.");
			exit(1);
		}
		*file = NULL; // pre istotu
		*file = open_file("hotel.txt", "r");
	}

	return 0;
}

////////
// MAIN FUNCTIONS
////////

int main()
{
	FILE *file = NULL;
	ROOM *Hotel = NULL;
	int number_of_rooms = 0;

	char console_input;
	do
	{
		printf("\nZadajte funkciu, ktoru si prajete vykonat: ");
		fflush(stdin);
		scanf("%c", &console_input);
		fflush(stdin);

		switch (console_input)
		{
		case 'n':
			n(&file, &Hotel, &number_of_rooms);
			break;
		case 'v':
			arrange_rooms(Hotel, number_of_rooms);
			v(&Hotel, number_of_rooms);
			break;
		case 'r':
			r(&file, &Hotel, &number_of_rooms);
			break;
		case 'z':
			z(&file, &Hotel, &number_of_rooms);
			break;
		case 'h':
			arrange_rooms(Hotel, number_of_rooms);
			h(&Hotel, number_of_rooms);
			break;
		case 'a':
			a(&file, &Hotel);
			break;
		case 'k':
			break; //OSETRENIE ABY NEZBEHOL DEFAULT
		default:
			printf("\nZADALI STE NESPRAVNY PRIKAZ, SKUSTE ZNOVA\n");
			//printf("ZADANE PISMENO char: %c ascii: %i\n", console_input, console_input); // debug vypis
			break;
		}
	} while (console_input != 'k');

	// close file
	if ((file) != NULL)
	{
		if (fclose(file) != 0)
		{
			printf("Neda sa zavriet subor.");
			exit(1);
		}
		file = NULL;
	}

	free_memory(&Hotel);

	printf("\n\nPROGRAM USPESNE UKONCENY!\n\n");
	return 0;
}

//gcc projekt2.c -std=c99 -pedantic -Wall -Werror -Wextra -o projekt ;; ./projekt

// how to STRUCTS:

// GUEST Jozko;

//     Jozko.name[0] = 'a';
//     Jozko.reservation_start = 69;
//     ROOM izba1;
//     izba1.room_number =1;
//     izba1.price = 100;
//     izba1.room_guest = &Jozko;
//     printf("%i",izba1.room_guest->reservation_start);