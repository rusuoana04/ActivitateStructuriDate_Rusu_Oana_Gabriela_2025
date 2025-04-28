//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//struct StructuraFarmacie
//{
//	
//	char* denumire;
//	char* adresa;
//	unsigned char nrAngajati;
//	float suprafata;
//}; typedef struct StructuraFarmacie Farmacie;
//
//struct Nod
//{
//	Farmacie info;
//	struct Nod* next;
//	struct Nod* prev;
//}; typedef struct Nod Nod;
//
//struct ListaDubla
//{
//	Nod* first;
//	Nod* last;
//	int nrNoduri;
//
//}; typedef struct ListaDubla ListaDubla;
//
//
//Farmacie creareFarmacie(const char* denumire, const char* adresa, unsigned char nrAngajati, float suprafata)
//{
//	Farmacie f;
//	f.denumire = (char*)malloc(strlen(denumire) + 1);
//	strcpy(f.denumire, denumire);
//	f.adresa = (char*)malloc(strlen(adresa) + 1);
//	strcpy(f.adresa, adresa);
//	f.nrAngajati = nrAngajati;
//	f.suprafata = suprafata;
//	return f;
//
//}
//
//void adaugaFarmacieLista(ListaDubla* lista, Farmacie farmacieNoua)
//{
//	Nod* nou = (Nod*)malloc(sizeof(Nod));
//	nou->info = farmacieNoua;
//	nou->next = NULL;
//	nou->prev = lista->last;
//	if (lista->last != NULL)
//	{
//		lista->last->next = nou;
//	}
//	else
//	{	
//		lista->first = nou;
//	}
//	lista->last = nou;
//	lista->nrNoduri++;
//}
//
//
//void afisareFarmacie(Farmacie farmacie)
//{
//	printf("Denumire: %s\n", farmacie.denumire);
//	printf("Adresa: %s\n", farmacie.adresa);
//	printf("NrAngajati: %d\n", farmacie.nrAngajati);
//	printf("Suprafata: %5.2f\n", farmacie.suprafata);
//
//}
//
//void afisareLista(ListaDubla lista)
//{
//	Nod* aux = lista.first;
//	while (aux)
//	{
//		afisareFarmacie(aux->info);
//		aux = aux->next;
//	}
//}
//
//int suprafataPrag(ListaDubla lista, float prag)
//{
//	int contor = 0;
//	Nod* aux = lista.first;
//	while (aux)
//	{
//		if ( aux->info.suprafata < prag)
//		{
//			contor++;
//		}
//		aux = aux->next;
//	}
//	return contor;
//}
//
//void selectareFarmacie(ListaDubla lista, const char* numeSelectat)
//{
//	Nod* aux = lista.first;
//	
//	while (aux)
//	{
//		if (strcmp(aux->info.denumire,numeSelectat)==0)
//		{
//			afisareFarmacie(aux->info);
//		}
//		aux = aux->next;
//	}
//}
//
//ListaDubla stergereFarmacie(ListaDubla* lista, unsigned char prag)
//{
//	Nod* aux = lista->first;
//	
//	while (aux)
//	{
//		Nod* temp = aux->next;
//		if (aux->info.nrAngajati >= prag)
//		{
//			
//			if (aux->prev)
//			{
//				aux->prev->next = aux->next;
//			}
//			else
//			{
//				lista->first = aux->next;
//			}
//			if (aux->next)
//			{
//				aux->next->prev = aux->prev;
//			}
//			else
//			{
//				lista->last = aux->prev;
//			}
//			free(aux->info.denumire);
//			free(aux->info.adresa);
//			free(aux);
//			lista->nrNoduri--;
//		}
//		aux = temp;
//	}
//
//
//	
//	
//
//
//}
//void dezalocareLD(ListaDubla* lista)
//{
//
//	Nod* aux = lista->first;
//	while (aux)
//	{
//		Nod* temp = aux->next;
//		if (aux->info.denumire != NULL)
//		{
//			free(aux->info.denumire);
//		}
//		if (aux->info.adresa != NULL)
//		{
//			free(aux->info.adresa);
//		}
//		free(aux);
//
//		
//
//
//	}
//	lista->first = NULL;
//	lista->last = NULL;
//	lista->nrNoduri = 0;
//}
//
//
//
//
//int main()
//{
//	ListaDubla l1;
//	l1.first = NULL;
//	l1.last = NULL;
//	l1.nrNoduri = 0;
//
//	Farmacie f1= creareFarmacie("Farmacie1", "Adresa1", 5, 10);
//	Farmacie f2 = creareFarmacie("Farmacie2", "Adresa2", 5, 11);
//	Farmacie f3 = creareFarmacie("Farmacie3", "Adresa3", 10, 30);
//	Farmacie f4 = creareFarmacie("Farmacie4", "Adresa4", 8, 20);
//	Farmacie f5 = creareFarmacie("Farmacie5", "Adresa5", 2, 8);
//	
//	adaugaFarmacieLista(&l1, f1);
//	adaugaFarmacieLista(&l1, f2);
//	adaugaFarmacieLista(&l1, f3);
//	adaugaFarmacieLista(&l1, f4);
//	adaugaFarmacieLista(&l1, f5);
//
//	afisareFarmacie(f1);
//	afisareLista(l1);
//
//	printf("nr farmacii cu suprafata mai mica de 10: %d\n ", suprafataPrag(l1, 10));
//	printf("afisare farmacie dupa nume:\n"); 
//	selectareFarmacie(l1, "Farmacie1");
//	printf("stergere farmacie dupa angajati :\n");
//	stergereFarmacie(&l1, 8);
//	afisareLista(l1);
//	dezalocareLD(&l1);
//	return 0;
//}
