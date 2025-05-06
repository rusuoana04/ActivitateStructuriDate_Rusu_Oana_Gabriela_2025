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
//functie de initializare HashTable
HashTable initializare(int dimensiune)
{
	HashTable ht;
	ht.dim = dimensiune;
	ht.tabela = (Nod*)malloc(dimensiune * sizeof(Nod));
	for (int i = 0; i < dimensiune; i++)
	{
		ht.tabela[i] = NULL;
	}
	return ht;
}


int main()
{
	return 0;
}