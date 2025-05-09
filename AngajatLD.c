#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


struct StructuraAngajat
{
	int id;
	const char* nume;
	const char* functie;
	float salariu;
	int bonus;
}; typedef struct StructuraAngajat Angajat;

struct Nod
{
	Angajat info;
	struct Nod* next;
	struct Nod* prev;
}; typedef struct Nod Nod;

struct ListaDubla
{
	Nod* first;
	Nod* last;
	int nrNoduri;
}; typedef struct ListaDubla ListaDubla;

void afisareAngajat(Angajat angajat)
{
	printf("Id: %d \n", angajat.id);
	printf("Nume: %s \n", angajat.nume);
	printf("Functie: %s \n", angajat.functie);
	printf("Salariu: %5.2f \n", angajat.salariu);
	printf("Bonus: %d \n", angajat.bonus);
}

void afisareLista(ListaDubla lista)
{
	Nod* aux = lista.first;
	while (aux)
	{
		afisareAngajat(aux->info);
		aux = aux->next;
	}
}
void afisareListaFinal(ListaDubla lista)
{
	Nod* aux = lista.last;
	while (aux)
	{
		afisareAngajat(aux->info);
		aux = aux->prev;
	}
}

void adaugaAngajat(ListaDubla* lista, Angajat angajatNou)
{
	Nod* nou = (Nod*)malloc(sizeof(Nod));
	nou->info = angajatNou;
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

Angajat citesteAngajat(FILE* file)
{
	char buffer[100];
	char sep[4] = ";,\n";
	Angajat a;
	char* aux;
	fgets(buffer, 100, file);
	aux = strtok(buffer, sep);
	a.id = atoi(aux);
	aux = strtok(NULL, sep);
	a.nume = malloc(strlen(aux) + 1);
	strcpy(a.nume, aux);
	aux = strtok(NULL, sep);
	a.functie = malloc(strlen(aux) + 1);
	strcpy(a.functie, aux);
	aux = strtok(NULL, sep);
	a.salariu = atof(aux);
	aux = strtok(NULL, sep);
	a.bonus = atoi(aux);
	return a;
}

ListaDubla citesteLista(const char* numeFisier)
{
	FILE* file = fopen(numeFisier, "r");
	ListaDubla lista;
	lista.first = NULL;
	lista.last = NULL;
	lista.nrNoduri = 0;
	while (!feof(file))
	{
		adaugaAngajat(&lista, citesteAngajat(file));
	}
	fclose(file);
	return lista;
}

void stergereAngajat(ListaDubla* lista, int idCautat)
{
	Nod* aux = lista->first;
	while (aux)
	{
		if (aux->info.id == idCautat) {
			if (aux == lista->first)
			{
				lista->first = aux->next;
			}
			if (aux == lista->last)
			{
				lista->last = aux->prev;
			}
			if (aux->prev)
			{
				aux->prev->next = aux->next;
			}
			if (aux->next)
			{
				aux->next->prev = aux->prev;
			}
			free(aux->info.nume);
			free(aux->info.functie);
			free(aux);
			lista->nrNoduri--;
			return;
		}
		aux = aux->next;
	}
}


void dezalocare(ListaDubla* lista)
{
	Nod* aux = lista->first;
	while (aux->next)
	{
		Nod* temp = aux->next;
		if (aux->info.nume != NULL)
		{
			free(aux->info.nume);
		}
		if (aux->info.functie != NULL)
		{
			free(aux->info.functie);
		}
		free(aux);
		aux = temp;
	}
	lista->first = NULL;
	lista->last = NULL;
	lista->nrNoduri = 0;
}

int main()
{
	ListaDubla lista = citesteLista("angajat.txt");
	printf("\n-----------Afisare lista:------------\n");
	afisareLista(lista);
	printf("\n-----------Afisare lista final-inceput:------------\n");
	afisareListaFinal(lista);
	stergereAngajat(&lista, 1);
	printf("\n-----------Afisare lista dupa stergere:------------\n");
	afisareLista(lista);
	dezalocare(&lista);
	
	return 0;
}