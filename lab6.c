#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct StructuraMasina
{
	int id;
	char* nume;
	float pret;
}; typedef struct StructuraMasina Masina;

struct Nod
{
	Masina info;
	struct Nod* next;
}; typedef struct Nod Nod;

struct HashTable
{
	Nod** tabela;
	int dim;
}; typedef struct HashTable HashTable;

void afisareMasina(Masina masina)
{
	printf("ID: %d\n", masina.id);
	printf("Nume: %s\n", masina.nume);
	printf("Pret: %.2f\n", masina.pret);
}

void afisareLista(Nod* cap)
{
	while (cap)
	{
		afisareMasina(cap->info);
		cap = cap->next;
	}
}

void adaugaMasinaLista(Nod* cap, Masina masinaNoua)
{
	Nod* aux = cap;
	while (aux->next)
	{
		aux = aux->next;
	}
	Nod* nou = (Nod*)malloc(sizeof(Nod));
	nou->info = masinaNoua;
	nou->next = NULL;
	aux->next = nou;
}

int main()
{
	return 0;
}