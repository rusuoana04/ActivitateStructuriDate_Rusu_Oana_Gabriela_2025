#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct StructVoucher
{
	int nrVoucher;
	 char* numeBeneficiar;
	 char* dataExpirare;
	float valoare;
}; typedef struct StructVoucher Voucher;

struct Nod
{
	Voucher info;
	struct Nod* next;
	struct Nod* prev;
}; typedef struct Nod Nod;

struct ListaDubla
{
	Nod* first;
	Nod* last;
	int nrNoduri;
}; typedef struct ListaDubla ListaDubla;

void afisareVoucher(Voucher voucher)
{
	printf("nrVoucher: %d \n", voucher.nrVoucher);
	printf("data expirare: %s \n", voucher.dataExpirare);
	
}


void afisareLista(ListaDubla lista)
{
	Nod* aux = lista.first;
	while (aux)
	{
		afisareVoucher(aux->info);
		aux = aux->next;
	}
}
void afisareListaFinal(ListaDubla lista)
{
	Nod* aux = lista.last;
	while (aux)
	{
		afisareVoucher(aux->info);
		aux = aux->prev;
	}
}

void adaugaVoucher(ListaDubla* lista, Voucher voucherNou)
{
	Nod* nou = (Nod*)malloc(sizeof(Nod));
	nou->info = voucherNou;
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

Voucher citireVoucher(FILE* file)
{
	char buffer[100];
	char sep[4] = ";,\n";
	Voucher v;
	char* aux;

	fgets(buffer, 100, file);
	aux = strtok(buffer, sep);
	v.nrVoucher = atoi(aux);
	aux = strtok(NULL, sep);
	v.numeBeneficiar = malloc(strlen(aux) + 1);
	strcpy(v.numeBeneficiar, aux);
	aux = strtok(NULL, sep);
	v.dataExpirare = malloc(strlen(aux) + 1);
	strcpy(v.dataExpirare, aux);
	aux = strtok(NULL, sep);
	v.valoare = atof(aux);
	return v;
}

ListaDubla citireLista(const char* numeFisier)
{
	FILE* file = fopen(numeFisier, "r");
	ListaDubla lista;
	lista.first = NULL;
	lista.last = NULL;
	lista.nrNoduri = 0;
	while (!feof(file))
	{
		adaugaVoucher(&lista, citireVoucher(file));
	}
	fclose(file);
	return lista;
}

float vouchereDupaData(ListaDubla lista, const char* dataExpirareCautata)
{
	Nod* aux = lista.first;
	float sumaVouchere = 0;

	while (aux)
	{
		if (strcmp(aux->info.dataExpirare, dataExpirareCautata) == 0)
		{
			
			sumaVouchere += aux->info.valoare;
		}
		aux = aux->next;
	}
	return sumaVouchere;
}

int nrBeneficiariPeste2Aparitii(ListaDubla lista, const char* numeCautat)
{
	Nod* aux = lista.first;
	int nrAparitii = 0;
	while (aux)
	{
		if (strcmp(aux->info.numeBeneficiar, numeCautat) == 0)
		{
			nrAparitii++;
		}
		aux = aux->next;
	}
	if (nrAparitii >= 2)
	{
		return nrAparitii;
	}
}


void dezalocare(ListaDubla* lista)
{
	Nod* aux = lista->first;
	while (aux)
	{
		Nod* temp = aux->next;
		if (aux->info.numeBeneficiar != NULL)
		{
			free(aux->info.numeBeneficiar);
		}
		if (aux->info.dataExpirare != NULL)
		{
			free(aux->info.dataExpirare);
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
	ListaDubla lista = citireLista("voucher.txt");
	afisareLista(lista);
	afisareListaFinal(lista);
	
	float sumaVouchere = vouchereDupaData(lista, "data1");
	printf("suma vouchere: %5.2f \n", sumaVouchere);
	int nrAp = nrBeneficiariPeste2Aparitii(lista, "nume1");
	printf("nr aparitii nume1: %d\n", nrAp);
	dezalocare(&lista);
	return 0;
}