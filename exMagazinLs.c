#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct StructuraMagazin
{
	int id;
	
	char* nume;
	float suprafata;
}; typedef struct StructuraMagazin Magazin;

struct Nod
{
	Magazin info;
	struct Nod* next;

}; typedef struct Nod Nod;

void afisareLista(Magazin magazin)
{
	printf("Id: %d\n", magazin.id);
	printf("Nume: %s\n", magazin.nume);
	printf("Suprafata: %5.2f\n", magazin.suprafata);
	


}

Magazin citireMagazinDinFisier(FILE* file)
{
	char buffer[100];
	char separatoare[4] = ";,\n";
	Magazin m;
	fgets(buffer, 100, file);

	char* aux;
	aux = strtok(buffer, separatoare);
	m.id = atoi(aux);
	aux = strtok(NULL, separatoare);
	m.nume = (char*)malloc(strlen(aux) + 1);
	strcpy(m.nume, aux);
	aux = strtok(NULL, separatoare);
	m.suprafata = atof(aux); 
	return m;
}


void afisareListaMagazine(Nod* cap)
{
	while (cap!=NULL)
	{
		afisareLista(cap->info);
		cap = cap->next;
	}
}

void adaugaMagazinListaFinal(Nod** cap, Magazin magazinNou)
{
	Nod* nou = (Nod*)malloc(sizeof(Nod));
	nou->info = magazinNou;
	nou->next = NULL;
	if (*cap)
	{
		Nod* aux = *cap;
		while (aux->next)
		{
			aux = aux->next;
		}
		aux->next = nou;
	}
	else
	{
		*cap = nou;
	}

}

void adaugareMagazinListaInceput(Nod** cap, Magazin magazinNou)
{
	Nod* nou = (Nod*)malloc(sizeof(Nod));
	nou->info = magazinNou;
	nou->next = *cap;
	*cap = nou;
}

Nod* citireListaMagazinFisier(const char* numeFisier)
{
	Nod* cap = NULL;
	FILE* file = fopen(numeFisier, "r");
	if (file)
	{
		while (!feof(file))
		{
			adaugaMagazinListaFinal(&cap, citireMagazinDinFisier(file));
		}
		fclose(file);
	}
	
	return cap;
	
}

void stergereMagazinLista(Nod** cap, int idCautat)
{
	Nod* aux = *cap;
	Nod* prev = NULL;

	while (aux != NULL && aux->info.id != idCautat)
	{
		prev = aux;
		aux = aux->next;
	}

	if (aux != NULL)
	{
		if (prev == NULL)
			*cap = aux->next;
		else
			prev->next = aux->next;

		free(aux->info.nume);
		free(aux);
	}
}

void dezalocare(Nod** cap)
{
	while (*cap)
	{
		Nod* aux = *cap;
		(*cap) = aux->next;
		if (aux->info.nume != NULL)
		{
			free(aux->info.nume);

		}
		free(aux);
	}
}


int main()
{
	Nod* cap= citireListaMagazinFisier("magazin.txt");
	afisareListaMagazine(cap);
	//testare functie de adaugaMagazinListaFinal
	Magazin m1;
	m1.id = 4;
	m1.nume = (char*)malloc(strlen("Magazin4") + 1);
	strcpy(m1.nume, "Magazin4");

	m1.suprafata = 400;
	printf("\n------------------------------------- \n");
	printf("\n Adaugare magazin la finalul listei: \n");
	adaugaMagazinListaFinal(&cap, m1);
	afisareListaMagazine(cap);
	//testare functie de adaugaMagazinListaInceput
	printf("\n------------------------------------- \n");
	printf("\n Adaugare magazin la inceputul listei: \n");
	Magazin m2;
	m2.id = 5;
	m2.nume = (char*)malloc(strlen("Magazin5") + 1);
	strcpy(m2.nume, "Magazin5");

	m2.suprafata =500;
	adaugareMagazinListaInceput(&cap, m2);
	afisareListaMagazine(cap);
	stergereMagazinLista(&cap, 2);
	printf("\n Stergere masina: \n");
	afisareListaMagazine(cap);
	dezalocare(&cap);
	return 0;
}

