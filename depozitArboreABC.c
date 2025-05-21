#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct StructDepozit
{
	int id;
	char* nume;
	char* adresa;
	int nrAngajati;
	float suprafata;
}; typedef struct StructDepozit Depozit;

struct Nod
{
	Depozit info;
	struct Nod* st;
	struct Nod* dr;
}; typedef struct Nod Nod;

void afisareDepozit(Depozit d)
{
	printf("id: %d\n", d.id);
	printf("nume: %s\n", d.nume);
	printf("adresa: %s\n", d.adresa);
	printf("nrAngajati: %d\n", d.nrAngajati);
	printf("suprafata: %5.2f\n", d.suprafata);
}

void afisareArbore(Nod* rad)
{
	if (rad)
	{
		afisareArbore(rad->st);
		afisareDepozit(rad->info);
		afisareArbore(rad->dr);
	}
}

Nod* initializareNod(Depozit d, Nod* st, Nod* dr)
{
	Nod* nou = (Nod*)malloc(sizeof(Nod));
	nou->info = d;
	nou->st = st;
	nou->dr = dr;
	return nou;
}

Nod* inserareNod(Nod* rad, Depozit depozit)
{
	if (rad)
	{
		if (rad->info.id < depozit.id)
			rad->dr = inserareNod(rad->dr, depozit);
		else
			rad->st = inserareNod(rad->st, depozit);
		return rad;
	}
	else
	{
		return initializareNod(depozit, NULL, NULL);
	}
}

Depozit cautareDepozit(Nod* rad, int id)
{
	if (rad)
	{
		if (rad->info.id == id)
			return rad->info;
		else if (rad->info.id < id)
			return cautareDepozit(rad->dr, id);
		else
			return cautareDepozit(rad->st, id);
	}
	else
	{
		Depozit d;
		d.id = -1;
		d.nume = NULL;
		d.adresa = NULL;
		d.nrAngajati = 0;
		d.suprafata = 0;
		return d;
	}
}

Depozit citireDepozit(FILE* file)
{
	char buffer[100];
	char sep[3] = ";,\n";
	Depozit d;
	d.id = -1;
	d.nume = NULL;
	d.adresa = NULL;
	d.nrAngajati = 0;
	d.suprafata = 0;

	if (fgets(buffer, 100, file))
	{
		char* aux;
		aux = strtok(buffer, sep);
		if (aux != NULL)
			d.id = atoi(aux);

		aux = strtok(NULL, sep);
		if (aux != NULL)
		{
			d.nume = malloc(strlen(aux) + 1);
			strcpy(d.nume, aux);
		}

		aux = strtok(NULL, sep);
		if (aux != NULL)
		{
			d.adresa = malloc(strlen(aux) + 1);
			strcpy(d.adresa, aux);
		}

		aux = strtok(NULL, sep);
		if (aux != NULL)
			d.nrAngajati = atoi(aux);

		aux = strtok(NULL, sep);
		if (aux != NULL)
			d.suprafata = atof(aux);
	}
	return d;
}

Nod* citireArbore(const char* numeFisier)
{
	FILE* file = fopen(numeFisier, "r");
	Nod* nod = NULL;

	if (file)
	{
		while (!feof(file))
		{
			Depozit d = citireDepozit(file);
			if (d.id != -1 && d.nume != NULL && d.adresa != NULL)
				nod = inserareNod(nod, d);
		}
		fclose(file);
	}
	else
	{
		printf("Eroare la deschiderea fisierului.\n");
	}
	return nod;
}

void dezalocare(Nod* rad)
{
	if (rad)
	{
		dezalocare(rad->st);
		dezalocare(rad->dr);
		free(rad->info.nume);
		free(rad->info.adresa);
		free(rad);
	}
}

int main()
{
	Nod* nod = citireArbore("depozit.txt");
	afisareArbore(nod);
	 Depozit d = cautareDepozit(nod, 2);
	 afisareDepozit(d);
	dezalocare(nod);
	return 0;
}
