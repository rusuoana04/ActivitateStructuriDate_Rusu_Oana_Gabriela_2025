//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
////trebuie sa folositi fisierul masini.txt
////sau va creati un alt fisier cu alte date
//
//struct StructuraMasina {
//	int id;
//	int nrUsi;
//	float pret;
//	char* model;
//	char* numeSofer;
//	unsigned char serie;
//};
//typedef struct StructuraMasina Masina;
//
////creare structura pentru un nod dintr-o lista dublu inlantuita
//
//struct Nod
//{
//	Masina info;
//	struct Nod* next;
//	struct Nod* prev;
//};
//typedef struct Nod Nod;
//
////creare structura pentru Lista Dubla 
//
//struct ListaDubla
//{
//	//sau putem sa denumim nodurile Nod* cap, Nod* coada;
//	Nod* first;
//	Nod* last;
//	//cream o variabila care sa retina nr de noduri si sa putem sa le incrementam
//	int nrNoduri;
//};
//typedef struct ListaDubla ListaDubla;
//
//Masina citireMasinaDinFisier(FILE* file) {
//	char buffer[100];
//	char sep[3] = ",\n";
//	fgets(buffer, 100, file);
//	char* aux;
//	Masina m1;
//	aux = strtok(buffer, sep);
//	m1.id = atoi(aux);
//	m1.nrUsi = atoi(strtok(NULL, sep));
//	m1.pret = atof(strtok(NULL, sep));
//	aux = strtok(NULL, sep);
//	m1.model = malloc(strlen(aux) + 1);
//	strcpy_s(m1.model, strlen(aux) + 1, aux);
//
//	aux = strtok(NULL, sep);
//	m1.numeSofer = malloc(strlen(aux) + 1);
//	strcpy_s(m1.numeSofer, strlen(aux) + 1, aux);
//
//	m1.serie = *strtok(NULL, sep);
//	return m1;
//}
//
//void afisareMasina(Masina masina) {
//	printf("Id: %d\n", masina.id);
//	printf("Nr. usi : %d\n", masina.nrUsi);
//	printf("Pret: %.2f\n", masina.pret);
//	printf("Model: %s\n", masina.model);
//	printf("Nume sofer: %s\n", masina.numeSofer);
//	printf("Serie: %c\n\n", masina.serie);
//}
//
////functie afisare lista masini dela inceput catre sfarsit
//void afisareListaMasiniDeLaInceput(ListaDubla lista) 
//{
//	Nod* aux = lista.first;
//	while (aux)
//	{
//		afisareMasina(aux->info);
//		aux = aux->next;
//	}
//}
////functie afisare lista masini de la sfarsit la inceput
//void afisareListaMasiniDeLaSfarsit(ListaDubla lista) 
//{
//	Nod* aux = lista.last;
//	while (aux)
//	{
//		afisareMasina(aux->info);
//		aux = aux->prev;
//	}
//}
////functie adaugare masina in lista la final
//void adaugaMasinaInListaLaFinal(ListaDubla* lista, Masina masinaNoua)
//{
//	//trebuie sa cream un nou nod si sa ii alocam spatiu
//	Nod* nou = (Nod*)malloc(sizeof(Nod));
//	nou->info = masinaNoua;//shallow copy
//	nou->next = NULL;
//	nou->prev = lista->last;
//	if (lista->last != NULL)
//	{
//		//daca exista ultimul nod, setam urmatorul nod ca fiind noul nod creat
//		lista->last->next = nou;
//	}
//	//daca lista e goala, setam primul nod ca fiind noul nod creat
//	else
//	{
//		lista->first = nou;
//	}
//
//	lista->last = nou;
//	lista->nrNoduri++;
//
//}
////functie adaugare masina in lista la inceput
//void adaugaLaInceputInLista(ListaDubla* lista, Masina masinaNoua) 
//{
//	Nod* nou = (Nod*)malloc(sizeof(Nod));
//	nou->info = masinaNoua;//shallow copy
//	//mutam primul nod din lista ca fiind urmatorul nod 
//	nou->next = lista->first;
//	//setam nodul predecesor capului listei la null
//	nou->prev = NULL;
//
//	if (lista->first!=NULL)
//	{
//		//setam nodul predecesor primului nod din lista existent deja ca fiind noul nod pe care vrem sa il inseram
//		lista->first->prev = nou;
//	}
//	else
//	{
//		//daca lista e goala setam ultimul nod ca fiind noul nod creat
//		lista->last = nou;
//	}
//	//setam primul nod ca fiind nodul nou pe care vrem sa il inseram in lista
//	lista->first = nou;
//	lista->nrNoduri++;
//}
//
//
////functie citireLDMasiniDinFisier
//ListaDubla citireLDMasiniDinFisier(const char* numeFisier) 
//{
//	FILE* file = fopen(numeFisier, "r");
//	ListaDubla lista;
//	lista.first = NULL;
//	lista.last = NULL;
//	lista.nrNoduri = 0;
//	while (!feof(file))
//	{
//		adaugaMasinaInListaLaFinal(&lista, citireMasinaDinFisier(file));
//	}
//	fclose(file);
//	return lista;
//}
////functie de dezalocare lista dubla
//
//void dezalocareLDMasini(ListaDubla* lista) {
//	
//	
//		Nod* p = lista->first;
//		while (p)
//		{
//			Nod* aux = p;
//			p = p->next;
//			if (aux->info.model != NULL)
//			{
//				free(aux->info.model);
//			}
//			if (aux->info.numeSofer != NULL)
//			{
//				free(aux->info.numeSofer);
//			}
//			free(aux);
//		}
//		
//		lista->first = NULL;
//		lista->last = NULL;
//		lista->nrNoduri = 0;
//
//	
//}
//
//float calculeazaPretMediu(/*lista de masini*/) {
//	//calculeaza pretul mediu al masinilor din lista.
//	return 0;
//}
//
//void stergeMasinaDupaID(/*lista masini*/ int id) {
//	//sterge masina cu id-ul primit.
//	//tratati situatia ca masina se afla si pe prima pozitie, si pe ultima pozitie
//}
//
//char* getNumeSoferMasinaScumpa(/*lista dublu inlantuita*/) {
//	//cauta masina cea mai scumpa si 
//	//returneaza numele soferului acestei maasini.
//	return NULL;
//}
//
//int main() {
//
//	ListaDubla lista = citireLDMasiniDinFisier("masini.txt");
//	printf("\n Afisare lista  de la inceput la sfarsit: \n");
//	afisareListaMasiniDeLaInceput(lista);
//	printf("\n ------------------------------------------------------ \n ");
//	printf("\n Afisare lista  de la sfarsit  la inceput: \n ");
//	afisareListaMasiniDeLaSfarsit(lista);
//	//Testare functie de adaugare masina la final in lista dubla
//	printf("Adaugare masina lista  la final: \n ");
//	Masina m1;
//	m1.id = 11;
//	m1.nrUsi = 4;
//	m1.pret = 2000;
//	m1.model = "Model1";
//	m1.numeSofer = "Sandel";
//	m1.serie = 'G';
//	
//	adaugaMasinaInListaLaFinal(&lista, m1);
//	afisareListaMasiniDeLaInceput(lista);
//	printf("\n ------------------------------------------------------ \n ");
//	//Testare functie de adaugare masina la inceput in lista dubla
//	printf("Adaugare masina lista  la inceput: \n ");
//	adaugaLaInceputInLista(&lista, m1);
//	afisareListaMasiniDeLaInceput(lista);
//	dezalocareLDMasini(&lista);
//
//
//	return 0;
//}