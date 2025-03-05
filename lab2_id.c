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

struct Telefon initializare()
{
	struct Telefon t;
	t.id = 1;
	t.RAM = 0;
	return t;
}

void afisare(struct Telefon t)
{

}

void modifica_Atribut(struct Telefon t)
{

}

void dezalocare(struct Telefon* t)
{

}



int main() {
	
	struct Telefon t;
	return 0;
}