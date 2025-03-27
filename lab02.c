#include<stdio.h>
#include<malloc.h>

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
	//modificam functia de afisare ca atunci cand dezalocam atributul alocat dinamic sa nu avem eroare si punem o verificare daca char* e null
	void afisare(struct Telefon t)
	{
		if (t.producator != NULL)
		{
			printf("% d. Telefonul %s , seria %c,  are %d Gb Ram, costa %5.2f Ron\n", t.id, t.producator, t.serie, t.RAM, t.pret);
		}
		else
		{
			printf("% d. Telefonul din seria %c,  are %d Gb Ram, costa %5.2f Ron\n", t.id, t.serie, t.RAM, t.pret);
		}
	}


	//implementare si testare functie afisareVector
void afisareVector(struct Telefon* vector, int nrElemente) {
	for (int i = 0; i < nrElemente; i++)
	{
		afisare(vector[i]);
	}
}

struct Sablon* copiazaPrimeleNElemente(struct Telefon* vector, int nrElemente, int nrElementeCopiate) {
	//copiem intr-un vector nou pe care il vom returna primele nrElementeCopiate
	struct Telefon *vectorNou=NULL;

	return vectorNou;
}

void dezalocare(struct Telefon** vector, int* nrElemente) {
	//dezalocam elementele din vector si vectorul
}

void copiazaAnumiteElemente(struct Telefon* vector, char nrElemente, float prag, struct Telefon** vectorNou, int* dimensiune) {
	//parametrul prag poate fi modificat in functie de 
	// tipul atributului ales pentru a indeplini o conditie
	//este creat un nou vector cu elementele care indeplinesc acea conditie
}

struct Telefon getPrimulElementConditionat(struct Telefon* vector, int nrElemente, const char* conditie) {
	//trebuie cautat elementul care indeplineste o conditie
	//dupa atributul de tip char*. Acesta este returnat.
	struct Telefon t;
	t.id = 1;

	return t;
}
	


int main() {
	struct Telefon* telefoane = NULL;
	int nrTelefoane = 3;
	//alocam memorie pentru vectorul alocat dinamic de telefoane;
	telefoane=(struct Telefon*)malloc(sizeof(struct Telefon)* nrTelefoane);

	telefoane[0] = initializare(1, 64, "Telefon1", 1000, 'A');
	telefoane[1] = initializare(2, 64, "Telefon2", 2000, 'B');
	telefoane[2] = initializare(3, 64, "Telefon3", 3000, 'C');

	afisareVector(telefoane, nrTelefoane);

	return 0;
}