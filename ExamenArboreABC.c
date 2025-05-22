#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct structExamen
{
	int cod;
	char* denumire;
	char* numeProf;
	int durata;
	int nrStudenti;
}; typedef struct structExamen Examen;

struct Nod 
{
	Examen info;
	struct Nod* st;
	struct Nod* dr;
}; typedef struct Nod Nod;

void afisareExamen(Examen examen)
{
	printf("cod: %d\n", examen.cod);
	printf("denumire: %s\n", examen.denumire);
	printf("numeProf: %s\n", examen.numeProf);
	printf("durata: %d\n", examen.durata);
	printf("nrStudenti: %d\n", examen.nrStudenti);
}

void afisareArbore(Nod* rad)
{
	if (rad)
	{
		afisareArbore(rad->st);
		afisareExamen(rad->info);
		afisareArbore(rad->dr);
	}
}

Nod* initializareNod(Examen e, Nod* st, Nod* dr)
{
	Nod* nou = (Nod*)malloc(sizeof(Nod));
	nou->info = e;
	nou->st = st;
	nou->dr = dr;
	return nou;
}

Nod* inserareNod(Nod* rad, Examen e)
{
	if (rad)
	{
		if (rad->info.cod < e.cod)
		{
			rad->dr = inserareNod(rad->dr, e);
		}
		else
		{
			rad->st = inserareNod(rad->st, e);
		}
		return rad;
	}
	else
	{
		return initializareNod(e, NULL, NULL);
	}
}

Examen cautareExamen(Nod* rad, int cod)
{
	if (rad)
	{
		if (rad->info.cod == cod)
		{
			return rad->info;
		}
		if (rad->info.cod < cod)
		{
			return cautareExamen(rad->dr, cod);
		}
		else
		{
			return cautareExamen(rad->st, cod);
		}
	}
	else
	{
		Examen e;
		e.cod = -1;
		e.denumire = NULL;
		e.numeProf = NULL;
		e.durata = 0;
		e.nrStudenti = 0;
		return e;
	}
}


Examen citireExamen(FILE* file)
{
	char buffer[100];
	char sep[3] = ";,\n";
	Examen e;
	e.cod = -1;
	e.denumire = NULL;
	e.numeProf = NULL;
	e.durata = 0;
	e.nrStudenti = 0;
	if (fgets(buffer, 100, file))
	{
		char* aux;
		aux = strtok(buffer, sep);
		if (aux != NULL)
		{
			e.cod = atoi(aux);
		}
		aux = strtok(NULL, sep);
		if (aux != NULL)
		{
			e.denumire = malloc(strlen(aux) + 1);
			strcpy(e.denumire, aux);
		}
		aux = strtok(NULL, sep);
		if (aux != NULL)
		{
			e.numeProf = malloc(strlen(aux) + 1);
			strcpy(e.numeProf, aux);
		}
		aux = strtok(NULL, sep);
		if (aux != NULL)
		{
			e.durata = atoi(aux);
		}
		aux = strtok(NULL, sep);
		if (aux != NULL)
		{
			e.nrStudenti = atoi(aux);
		}

	}
	return e;
}

Nod* citireArbore(const char* numeFisier)
{
	FILE* file = fopen(numeFisier, "r");
	Nod* rad = NULL;
	if (file)
	{
		
		while (!feof(file))
		{
			Examen e = citireExamen(file);
			if (e.cod != -1 && e.denumire != NULL && e.numeProf != NULL)
			{
				rad = inserareNod(rad, e);
			}

		}
		fclose(file);
	}
	else
	{
		printf("Eroare citire\n");
	}
	return rad;
	
}

int calculDurataOre(Nod* rad, const char* numeProf)
{
	if (!rad)
		return 0;

	int suma = 0;
	if (strcmp(rad->info.numeProf, numeProf) == 0)
	{
		suma += rad->info.durata;
	}
	suma += calculDurataOre(rad->st, numeProf);
	suma += calculDurataOre(rad->dr, numeProf);
	return suma;
}

Nod* modificaNrStudenti(Nod* rad,int cod, int nrStudActualizat )
{
	if (rad)
	{
		if (rad->info.cod == cod)
		{
			rad->info.nrStudenti = nrStudActualizat;
		}
		
	}
	return rad;
}




int calculNrTotalStudenti(Nod* rad)
{
	if (!rad)
		return 0;

	return rad->info.nrStudenti + calculNrTotalStudenti(rad->st) + calculNrTotalStudenti(rad->dr);

	
		
	
}


void dezalocare(Nod* rad)
{
	if (rad)
	{
		dezalocare(rad->st);
		dezalocare(rad->dr);
		free(rad->info.denumire);
		free(rad->info.numeProf);
		free(rad);
	}
}

int inaltimeArbore(Nod* rad)
{
	if (!rad)
		return 0;
	int hSt = inaltimeArbore(rad->st);
	int hDr = inaltimeArbore(rad->dr);
	if (hSt > hDr)
	{
		return 1 + hSt;
	}
	else
	{
		return 1 + hDr;
	}
}

void afisarePeNivele(Nod* rad, int nivelCautat, int nivelCurent)
{
	if (rad)
	{
		if (nivelCautat == nivelCurent)
		{
			afisareExamen(rad->info);
		}
		else
		{
			afisarePeNivele(rad->st, nivelCautat, nivelCautat + 1);
			afisarePeNivele(rad->dr, nivelCautat, nivelCurent + 1);
		}
	}
	else
	{
		return 0;
	}
}



int main()
{
	Nod* nod = citireArbore("examen.txt");
	afisareArbore(nod);
	Examen e = cautareExamen(nod, 3);
	afisareExamen(e);
	
	int totalore= calculDurataOre(nod, "nume3");
	printf("\n-------------------------------- \n");
	printf("calcul ore: %d\n", totalore);

	modificaNrStudenti(nod, 1, 1);
	printf("\n-------------------------------- \n");
	printf("apelare functie de modificare studenti cod 1: \n");
	afisareArbore(nod);
	

	int sumastud = calculNrTotalStudenti(nod);
	printf("\n-------------------------------- \n");
	printf("calcul studenti: %d\n", sumastud);
	printf("\n-------------------------------- \n");
	
	int inaltime = inaltimeArbore(nod);
	printf("inaltime arbore: %d \n",inaltime);
	printf("\n-------------------------------- \n");
	afisarePeNivele(nod, 2, 1);
	dezalocare(nod);
	return 0;
}