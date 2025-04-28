//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
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
//struct Nod
//{
//	Masina info;
//	struct Nod* next;
//}; typedef struct Nod Nod;
//
//
//Masina citireMasinaDinFisier(FILE* file) {
//	char buffer[100];
//	char separatoare[4] = ",\n";
//	fgets(buffer, 100, file);
//	char* aux;
//	Masina m1;
//	aux = strtok(buffer, separatoare);
//	m1.id = atoi(aux);
//	m1.nrUsi = atoi(strtok(NULL, separatoare));
//	m1.pret = atof(strtok(NULL, separatoare));
//	aux = strtok(NULL, separatoare);
//	m1.model = malloc(strlen(aux) + 1);
//	strcpy_s(m1.model, strlen(aux) + 1, aux);
//
//	aux = strtok(NULL, separatoare);
//	m1.numeSofer = malloc(strlen(aux) + 1);
//	strcpy_s(m1.numeSofer, strlen(aux) + 1, aux);
//
//	m1.serie = *strtok(NULL, separatoare);
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
//void afisareMasinaLista(Nod* cap)
//{
//	while (cap != NULL)
//	{
//		afisareMasina(cap->info);
//		cap = cap->next;
//	}
//}
//
//void adaugareMasinaLista(Nod** cap, Masina masinaNoua)
//{
//	Nod* nou=(Nod*)malloc(sizeof(Nod));
//	nou->info = masinaNoua;
//	nou->next = NULL;
//	if (*cap)
//	{
//		Nod* aux = *cap;
//		while (aux->next)
//		{
//			aux = aux->next;
//		}
//		aux->next = nou;
//	}
//	else
//	{ 
//		*cap = nou;
//	}
//	
//}
//
//
//
//
//
//
//
//int main() {
//
//
//	return 0;
//}