#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
	struct Nod* prev;
}; typedef struct Nod Nod;

struct ListaDubla
{
	Nod* first;
	Nod* last;
	int nrNoduri;
}; typedef struct ListaDubla ListaDubla;

void afisareMagazin(Magazin magazin)
{
	printf("Id: %d \n", magazin.id);
	printf("Nume: %s \n", magazin.nume);
	printf("suprafata: %5.2f \n", magazin.suprafata);
}

Magazin citireMagazinDinFisier(FILE* file)
{
	char buffer[100];
	char separatoare[4] = ";,\n";
	fgets(buffer, 100, file);
	Magazin m;
	char* aux;
	aux = strtok(buffer, separatoare);
	m.id = atoi(aux);
	aux = strtok(NULL, separatoare);
	m.nume = malloc(strlen(aux) + 1);
	strcpy(m.nume, aux);
	aux = strtok(NULL, separatoare);
	m.suprafata = atof(aux);
	return m;
}

void afisareListaDeLaInceput(ListaDubla lista)
{
	Nod* aux = lista.first;
	while (aux)
	{
		afisareMagazin(aux->info);
		aux = aux->next;
	}
}

void afisareListaDeLaSfarsit(ListaDubla lista)
{
	Nod* aux = lista.last;
	while (aux)
	{
		afisareMagazin(aux->info);
		aux = aux->prev;
	}
}

void adaugareMagazinListaFinal(ListaDubla* lista, Magazin magazinNou)
{
	Nod* nou = (Nod*)malloc(sizeof(Nod));
	nou->info = magazinNou;
	nou->next = NULL;
	nou->prev = lista->last;
	if (lista->last != NULL)
	{
		lista->last->next = nou;
	}
	else
	{
		lista->first = nou;
	}
	lista->last = nou;
	lista->nrNoduri++;
}

ListaDubla citireLDMagazinDinFisier( const char* numeFisier)
{
	FILE* file = fopen(numeFisier, "r");
	ListaDubla lista;
	lista.first = NULL;
	lista.last = NULL;
	lista.nrNoduri = 0;
	while (!feof(file))
	{
		adaugareMagazinListaFinal(&lista, citireMagazinDinFisier(file));
	}
	fclose(file);
	return lista;
}


int main()
{
	ListaDubla lista = citireLDMagazinDinFisier("magazin.txt");
	afisareListaDeLaInceput(lista);
	printf("\n--------------------------------- \n");

	printf("adaugare magazin la finalul listei: \n");
	Magazin m1;
	m1.id = 4;
	m1.nume = (char*)malloc(strlen("Magazin4") + 1);
	strcpy(m1.nume, "Magazin4");
	m1.suprafata = 400;
	adaugareMagazinListaFinal(&lista, m1);
	afisareListaDeLaInceput(lista);


	return 0;

}