#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct Magazin {
	int id;
	char* denumire;
	char* localitate;
	float suprafata;
	int numar_angajati;
}; typedef struct Magazin Magazin;

struct Nod
{
	Magazin info;
	struct Nod* next;
}; typedef struct Nod Nod;

Magazin creareMagazin(int id, const char* denumire, const char* localitate, float suprafata, int nrAngajati)
{
	Magazin m;
	m.id = id;
	m.denumire = (char*)malloc(sizeof(char)*strlen(denumire) + 1);
	strcpy(m.denumire, denumire);
	m.localitate = (char*)malloc(sizeof(char) * strlen(localitate) + 1);
	strcpy(m.localitate, localitate);
	m.suprafata = suprafata;
	m.numar_angajati = nrAngajati;

	return m;
}

void afisareMagazin(Magazin magazin)
{
	printf("Id: %d \n", magazin.id);
	printf("denumire: %s \n", magazin.denumire);
	printf("localitate: %s \n", magazin.localitate);
	printf("suprafata: %5.2f\n", magazin.suprafata);
	printf("numar_angajati: %d\n", magazin.numar_angajati);


}

Magazin afisareLista(Nod* cap)
{
	while (cap!=NULL)
	{
		afisareMagazin(cap->info);
		cap = cap->next;
	}
}

void adaugareMagazinLista(Nod** cap, Magazin magazinNou)
{
	Nod* nou = (Nod*)malloc(sizeof(Nod));
	nou->info = magazinNou;
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


Magazin citireMagazin(FILE* file)
{
	char buffer[100];
	char sep[4] = ";,\n";
	Magazin m;
	fgets(buffer, 100, file);
	char* aux;
	aux = strtok(buffer, sep);
	m.id = atoi(aux);
	aux = strtok(NULL, sep);
	m.denumire = (char*)malloc(strlen(aux) + 1);
	strcpy(m.denumire, aux);
	aux = strtok(NULL, sep);
	m.localitate = (char*)malloc(strlen(aux) + 1);
	strcpy(m.localitate, aux);
	aux = strtok(NULL, sep);
	m.suprafata = atof(aux);
	aux = strtok(NULL, sep);
	m.numar_angajati = atoi(aux);
	return m;

}

Nod* citireLista(const char* numeFisier)
{
	FILE* file = fopen(numeFisier, "r");
	Nod* cap = NULL;
	if (file)
	{
		while (!feof(file))
		{
			adaugareMagazinLista(&cap, citireMagazin(file));
		}
		fclose(file);
	}
	return cap;
}


void modificareDenumire(Nod* cap, const char* denumireCautata, const char* localitateCautata, const char* denumireNoua)
{
	
	
	while (cap)
	{
		if (strcmp(cap->info.denumire, denumireCautata)==0 || 
			strcmp(cap->info.localitate,localitateCautata)==0)
		{
			free(cap->info.denumire);
			cap->info.denumire = (char*)malloc(strlen(denumireNoua) + 1);
			strcpy(cap->info.denumire, denumireNoua);
			
		}
		cap = cap->next;


		
	}
}

float nrMediuAngajati(Nod* cap, const char* localitateCautata)
{
	int nrAngajati = 0;
	int nrLocatii = 0;

	while (cap)
	{
		if (strcmp(cap->info.localitate, localitateCautata) == 0)
		{
			nrLocatii++;
			nrAngajati += cap->info.numar_angajati;
		}
		cap = cap->next;
	}

	

	return (float)nrAngajati / nrLocatii;
}




void dezalocare(Nod** cap)
{
	while (*cap)
	{
		Nod* aux = *cap;
		(*cap) = aux->next;
		if (aux->info.denumire != NULL)
		{
			free(aux->info.denumire);
		}
		if (aux->info.localitate != NULL)
		{
			free(aux->info.localitate);
		}
		free(aux);
	}
}



int main()
{
	Magazin m1 = creareMagazin(1, "magazin1", "adresa1", 100, 10);
	printf("Magazin1: \n");
	afisareMagazin(m1);
	printf("\n afisare lisat: \n");
	Nod* cap = citireLista("magazin1.txt");
	afisareLista(cap);
	adaugareMagazinLista(&cap, m1);
	printf("\n afisare lisata modificata: \n");
	afisareLista(cap);
	modificareDenumire(cap, "magazin1", "adresa", "magazinNou");

	printf("\n afisare lisata modificata: \n");
	afisareLista(cap);

	float medie = nrMediuAngajati(cap, "adresa1");
	printf("Numar mediu angajati in localitatea 'adresa1': %.2f\n", medie);
	dezalocare(&cap);

	return 0;
}