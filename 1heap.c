#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct StructMagazin
{
	int id;
	char* nume;
	float pret;
}; typedef struct StructMagazin Magazin;

struct Heap
{
	Magazin* vector;
	int lungime;
	int nrMasini;
}; typedef struct Heap Heap;


void afisareMagazin(Magazin magazin)
{
	printf("id: %d \n", magazin.id);
	printf("nume: %s \n", magazin.nume);
	printf("pret: %5.2f \n", magazin.pret);

}

Magazin citireMagazin(FILE* file)
{
	char buffer[100];
	char sep[3] = ";,\n";
	fgets(buffer, 100, file);
	Magazin m;
	char* aux;
	m.id = atoi(strtok(buffer, sep));
	aux = strtok(NULL, sep);
	m.nume = malloc(strlen(aux) + 1);
	strcpy_s(m.nume, strlen(aux) + 1, aux);
	m.pret = atof(strtok(NULL, sep));
	return m;
}

Heap initializareHeap(int lungime)
{
	Heap h;
	h.lungime = lungime;
	h.nrMasini = 0;
	h.vector = (Magazin*)malloc(sizeof(Magazin) * lungime);
	return h;
}

void filtrareHeap(Heap heap, int pozNod)
{
	int pozFiuSt = 2 * pozNod + 1;
	int pozFiuDr = 2 * pozNod + 2;
	int pozMax = pozNod;
	if (pozFiuSt < heap.nrMasini && heap.vector[pozMax].id < heap.vector[pozFiuSt].id)
	{
		pozMax = pozFiuSt;
	}
	if (pozFiuDr < heap.nrMasini && heap.vector[pozMax].id < heap.vector[pozFiuDr].id)
	{
		pozMax = pozFiuDr;
	}
	if (pozMax != pozNod)
	{
		Magazin aux = heap.vector[pozMax];
		heap.vector[pozMax] = heap.vector[pozNod];
		heap.vector[pozNod] = aux;
		if (pozMax <= (heap.nrMasini - 2) / 2)
		{
			filtrareHeap(heap, pozMax);
		}
	}
}

Heap citireHeap(const char* numeFisier, int lungime)
{
	FILE* file = fopen(numeFisier, "r");
	Heap heap = initializareHeap(lungime);
	while (!feof(file))
	{
		heap.vector[heap.nrMasini++] = citireMagazin(file);
	}
	fclose(file);
	for (int i = (heap.nrMasini - 2) / 2; i >= 0; i--)
	{
		filtrareHeap(heap, i);
	}
	return heap;
}

void afisareHeap(Heap heap)
{
	for (int i = 0; i < heap.nrMasini; i++)
	{
		afisareMagazin(heap.vector[i]);
	}
}

int main()
{

	Heap heap = citireHeap("magazine.txt", 3);
	afisareHeap(heap);
	return 0;
}

















