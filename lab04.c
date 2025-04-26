#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//trebuie sa folositi fisierul masini.txt
//sau va creati un alt fisier cu alte date

struct StructuraMasina {
	int id;
	int nrUsi;
	float pret;
	char* model;
	char* numeSofer;
	unsigned char serie;
};
typedef struct StructuraMasina Masina;

//creare structura pentru un nod dintr-o lista simplu inlantuita

struct Nod
{
	Masina info;
	//pointer la urmatorul nod
	struct Nod* next;
};
typedef struct Nod Nod;

Masina citireMasinaDinFisier(FILE* file) {
	char buffer[100];
	char separatoare[4] = ",\n";
	fgets(buffer, 100, file);
	char* aux;
	Masina m1;
	aux = strtok(buffer, separatoare);
	m1.id = atoi(aux);
	m1.nrUsi = atoi(strtok(NULL, separatoare));
	m1.pret= atof(strtok(NULL, separatoare));
	aux = strtok(NULL, separatoare);
	m1.model = malloc(strlen(aux) + 1);
	strcpy_s(m1.model, strlen(aux) + 1, aux);

	aux = strtok(NULL, separatoare);
	m1.numeSofer = malloc(strlen(aux) + 1);
	strcpy_s(m1.numeSofer, strlen(aux) + 1, aux);

	m1.serie = *strtok(NULL, separatoare);
	return m1;
}

void afisareMasina(Masina masina) {
	printf("Id: %d\n", masina.id);
	printf("Nr. usi : %d\n", masina.nrUsi);
	printf("Pret: %.2f\n", masina.pret);
	printf("Model: %s\n", masina.model);
	printf("Nume sofer: %s\n", masina.numeSofer);
	printf("Serie: %c\n\n", masina.serie);
}

void afisareListaMasini(Nod* cap)
{
	while (cap!=NULL)
	{
		//afisam informatia utila de pe nodul curect
		afisareMasina(cap->info);
		//mutam nodul pe pozitia urmatoare
		cap = cap->next;

	}
}

void adaugaMasinaInLista(Nod* *cap, Masina masinaNoua) 
{
	Nod* nou = (Nod*)malloc(sizeof(Nod));
	nou->info = masinaNoua;;//shallow copy;
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



void adaugaLaInceputInLista(Nod* * cap, Masina masinaNoua) {
	//adauga la inceputul listei o noua masina pe care o primim ca parametru
	Nod* nou = (Nod*)malloc(sizeof(Nod));
	nou->info = masinaNoua;
	nou->next = *cap;
	*cap = nou;
}

Nod* citireListaMasiniDinFisier(const char* numeFisier) {
	//functia primeste numele fisierului, il deschide si citeste toate masinile din fisier
	//prin apelul repetat al functiei citireMasinaDinFisier()
	//ATENTIE - la final inchidem fisierul/stream-ul
	Nod* cap = NULL;
	FILE* f = fopen(numeFisier, "r");
	if (f)
	{
		while (!feof(f))
		{
			// lista cu inserare la sfarsit
			adaugaMasinaInLista(&cap, citireMasinaDinFisier(f));
			
		}
	}
	fclose(f);
	return cap;

}

//dezalocare lista
void dezalocareListaMasini(Nod** cap) {
	while (*cap)
	{
		Nod* aux = *cap;
		(*cap) = aux->next;
		if (aux->info.model)
		{
			free(aux->info.model);
		}
		if (aux->info.numeSofer)
		{
			free(aux->info.numeSofer);
		}
		free(aux);
	}
}


void stergeMasiniDinSeria(/*lista masini*/ char serieCautata) {
	//sterge toate masinile din lista care au seria primita ca parametru.
	//tratati situatia ca masina se afla si pe prima pozitie, si pe ultima pozitie
}



int main() {
	Nod* cap = citireListaMasiniDinFisier("masini.txt");
	afisareListaMasini(cap);

	return 0;
}