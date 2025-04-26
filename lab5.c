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

//creare structura pentru un nod dintr-o lista dublu inlantuita

struct Nod
{
	Masina info;
	struct Nod* next;
	struct Nod* prev;
};
typedef struct Nod Nod;

//creare structura pentru Lista Dubla 

struct ListaDubla
{
	//sau putem sa denumim nodurile Nod* cap, Nod* coada;
	Nod* first;
	Nod* last;
	//cream o variabila care sa retina nr de noduri si sa putem sa le incrementam
	int nrNoduri;
};
typedef struct ListaDubla ListaDubla;

Masina citireMasinaDinFisier(FILE* file) {
	char buffer[100];
	char sep[3] = ",\n";
	fgets(buffer, 100, file);
	char* aux;
	Masina m1;
	aux = strtok(buffer, sep);
	m1.id = atoi(aux);
	m1.nrUsi = atoi(strtok(NULL, sep));
	m1.pret = atof(strtok(NULL, sep));
	aux = strtok(NULL, sep);
	m1.model = malloc(strlen(aux) + 1);
	strcpy_s(m1.model, strlen(aux) + 1, aux);

	aux = strtok(NULL, sep);
	m1.numeSofer = malloc(strlen(aux) + 1);
	strcpy_s(m1.numeSofer, strlen(aux) + 1, aux);

	m1.serie = *strtok(NULL, sep);
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

//functie afisare lista masini dela inceput catre sfarsit
void afisareListaMasiniDeLaInceput(ListaDubla lista) 
{
	Nod* aux = lista.first;
	while (aux)
	{
		afisareMasina(aux->info);
		aux = aux->next;
	}
}
//functie afisare lista masini de la sfarsit la inceput
void afisareListaMasiniDeLaSfarsit(ListaDubla lista) 
{
	Nod* aux = lista.last;
	while (aux)
	{
		afisareMasina(aux->info);
		aux = aux->prev;
	}
}
//functie adaugare masina in lista la final
void adaugaMasinaInListaLaFinal(ListaDubla* lista, Masina masinaNoua)
{
	//trebuie sa cream un nou nod si sa ii alocam spatiu
	Nod* nou = (Nod*)malloc(sizeof(Nod));
	nou->info = masinaNoua;//shallow copy
	nou->next = NULL;
	nou->prev = lista->last;
	if (lista->last != NULL)
	{
		//daca exista ultimul nod, setam urmatorul nod ca fiind noul nod creat
		lista->last->next = nou;
	}
	//daca lista e goala, setam primul nod ca fiind noul nod creat
	else
	{
		lista->first = nou;
	}

	lista->last = nou;

}
//functie adaugare masina in lista la inceput
void adaugaLaInceputInLista(ListaDubla* lista, Masina masinaNoua) 
{
	Nod* nou = (Nod*)malloc(sizeof(Nod));
	nou->info = masinaNoua;//shallow copy
	//mutam primul nod din lista ca fiind urmatorul nod 
	nou->next = lista->first;
	//setam nodul predecesor capului listei la null
	nou->prev = NULL;

	if (lista->first!=NULL)
	{
		//setam nodul predecesor primului nod din lista existent deja ca fiind noul nod pe care vrem sa il inseram
		lista->first->prev = nou;
	}
	else
	{
		//daca lista e goala setam ultimul nod ca fiind noul nod creat
		lista->last = nou;
	}
	//setam primul nod ca fiind nodul nou pe care vrem sa il inseram in lista
	lista->first = nou;
}



void* citireLDMasiniDinFisier(const char* numeFisier) {
	//functia primeste numele fisierului, il deschide si citeste toate masinile din fisier
	//prin apelul repetat al functiei citireMasinaDinFisier()
	//ATENTIE - la final inchidem fisierul/stream-ul
}

void dezalocareLDMasini(/*lista dubla de masini*/) {
	//sunt dezalocate toate masinile si lista dublu inlantuita de elemente
}

float calculeazaPretMediu(/*lista de masini*/) {
	//calculeaza pretul mediu al masinilor din lista.
	return 0;
}

void stergeMasinaDupaID(/*lista masini*/ int id) {
	//sterge masina cu id-ul primit.
	//tratati situatia ca masina se afla si pe prima pozitie, si pe ultima pozitie
}

char* getNumeSoferMasinaScumpa(/*lista dublu inlantuita*/) {
	//cauta masina cea mai scumpa si 
	//returneaza numele soferului acestei maasini.
	return NULL;
}

int main() {


	return 0;
}