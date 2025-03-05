//002 - Laborator 1 - Functii utilizate si structura Telefon

#include <stdio.h>
#include<stdlib.h>

struct Telefon {
	int id;
	int RAM;
	char* producator;
	float pret;
	char serie;

};

struct Telefon initializare(int id, int ram, const char* producator,float pret, char serie)
{
	struct Telefon t;
	t.id = id;
	t.RAM = ram;
	t.producator = (char*)malloc(sizeof(char) * (strlen(producator) + 1));
	strcpy_s(t.producator, strlen(producator) + 1, producator);
	t.pret = pret;
	t.serie = serie;

	return t;
}

void afisare(struct Telefon t)
{
	printf("% d. Telefonul %s , seria %c,  are %d Gb Ram, costa %5.2f Ron\n", t.id, t.producator, t.serie, t.RAM, t.pret);
}

//trebuie sa punem pointer la telefon
void modificaPret(struct Telefon* t, float noulPret)
{
	if (noulPret > 0)
	{
		t->pret = noulPret;
	}
	
}

void dezalocare(struct Telefon* t)
{

}



int main() {
	
	struct Telefon t;
	//" " folosim pt sir caractere char* si '' pt un singur caracter
	t = initializare(1, 256, "Samsung", 2000.5, 'A');

	 afisare( t);

	 modificaPret(&t, 1000);
	 afisare(t);
	return 0;
}