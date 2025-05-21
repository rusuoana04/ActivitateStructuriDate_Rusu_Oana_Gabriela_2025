#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct StructMagazin
{
	int id;
	char* nume;
	float pret;
}; typedef struct StructMagazin Magazin;

struct Nod
{
	Magazin info;
	struct Nod* st;
	struct Nod* dr;
}; typedef struct Nod Nod;

void afisareMagazin(Magazin magazin)
{
	printf("id: %d \n", magazin.id);
	printf("nume: %s \n", magazin.nume);
	printf("pret: %5.2f \n", magazin.pret);

}
Magazin citireMagazin(FILE* file)
{
	char buffer[100];
	char sep[3] = ";,\n";
	Magazin m;
	m.id = -1;
	m.nume = NULL;
	m.pret = 0;
	fgets(buffer, 100, file);
	
	char* aux;
	m.id = atoi(strtok(buffer, sep));
	aux = strtok(NULL, sep);
	m.nume = malloc(strlen(aux) + 1);
	strcpy_s(m.nume, strlen(aux) + 1, aux);
	m.pret = atof(strtok(NULL, sep));
	return m;
}

Nod* initializare(Magazin magazin, Nod* st, Nod* dr)
{
	Nod* nou = (Nod*)malloc(sizeof(Nod));
	nou->info = magazin;
	nou->st = st;
	nou->dr = dr;
	return nou;

}

Nod* inserareNod(Nod* rad, Magazin magazin)
{
	if (rad)
	{
		if (rad->info.id > magazin.id)
		{
			rad->st = inserareNod(rad->st, magazin);
		}
		else
		{
			rad->dr = inserareNod(rad->dr, magazin);
		}
		return rad;
	}
	else
	{
		return initializare(magazin, NULL, NULL);
	}
}

void afisareArbore(Nod* rad)
{
	if (rad)
	{
		afisareArbore(rad->st);
		afisareMagazin(rad->info);
		afisareArbore(rad->dr);

	}
}

Magazin cautareMagazin(Nod* rad, int id)
{
	if (rad)
	{
		if (rad->info.id == id)
		{
			return rad->info;
		}
		else
		{
			if (rad->info.id < id)
			{
				return cautareMagazin(rad->dr, id);
			}
			else
			{
				return cautareMagazin(rad->st, id);
			}
		}
	}
	else
	{
		Magazin magazin;
		magazin.id = -1;
		magazin.nume = NULL;
		magazin.pret = 0;
		return magazin;
	}
}

Nod* citireArbore(const char* numeFisier)
{
	FILE* file = fopen(numeFisier, "r");
	Nod* rad = NULL;
	while (!feof(file))
	{
		Magazin m = citireMagazin(file);
		rad = inserareNod(rad, m);
	}
	fclose(file);
	return rad;

}



int main()
{
	Nod* nod = citireArbore("magazine.txt");
	afisareArbore(nod);
	Magazin m=cautareMagazin(nod, 2);
	afisareMagazin(m);
	return 0;
}