#define _CRT_SECURE_NO_WARNINGS
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

//functie copiere primele elemente

struct Telefon* copiazaPrimeleNElemente(struct Telefon* vector, int nrElemente, int nrElementeCopiate) {
	
	struct Telefon *vectorNou=NULL;
	vectorNou = (struct Telefon*)malloc(sizeof(struct Telefon) * nrElementeCopiate);
	for (int i = 0; i < nrElementeCopiate; i++)
	{
		vectorNou[i] = vector[i];
		//trebuie sa facem deep copy pentru atributul alocat dinamic
		vectorNou[i].producator = (char*)malloc(sizeof(char) * (strlen(vector[i].producator) + 1));
		strcpy_s(vectorNou[i].producator, strlen(vector[i].producator) + 1, vector[i].producator);
	}

	return vectorNou;
}
//dezalocare vector

void dezalocare(struct Telefon** vector, int* nrElemente)
{
	for (int i = 0; i < (*nrElemente); i++)
	{
		if ((*vector)[i].producator != NULL)
		{
			free((*vector)[i].producator);

		}
		free(*vector);
		*vector = NULL;
		*nrElemente = 0;
	}
}















void copiazaTelefoaneScumpe(struct Telefon* vector, char nrElemente, float pretMinim, struct Telefon** vectorNou, int* dimensiune) {
	
	*dimensiune = 0;
	for (int i = 0; i < nrElemente; i++)
	{
		if (vector[i].pret >= pretMinim)
		{
			(*dimensiune)++;
		}
	}
	if ((*vectorNou) != NULL)
	{
		free(*vectorNou);
	}

	*vectorNou = (struct Telefon*)malloc(sizeof(struct Telefon) * (*dimensiune));
	int k = 0;
	for (int i = 0; i < nrElemente; i++)
	{
		if (vector[i].pret >= pretMinim)
		{
			(*vectorNou)[k] = vector[i];
			(*vectorNou)[k].producator = (char*)malloc (strlen(vector[i].producator) + 1);
			strcpy_s((*vectorNou)[k].producator, strlen(vector[i].producator) + 1, vector[i].producator);
			k++;
		}
	}

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
	printf("vector telefoane: \n");
	afisareVector(telefoane, nrTelefoane);

	struct Telefon* primeleTelefoane=NULL;
	int nrPrimeleTelefoane = 2;
	primeleTelefoane=copiazaPrimeleNElemente(telefoane, nrTelefoane, nrPrimeleTelefoane);
	printf("\n\n vector telefoane copiate: \n");
	afisareVector(primeleTelefoane, nrPrimeleTelefoane);
	dezalocare(&primeleTelefoane, &nrPrimeleTelefoane);
	afisareVector(primeleTelefoane, nrPrimeleTelefoane);

	//copiaza telefoane scumpe
	printf("\n \n copiaza telefoane scumpe: \n");
	struct Telefon* telefoaneScumpe = NULL;
	int nrTelefoaneScumpe = 0;
	copiazaTelefoaneScumpe(telefoane, nrTelefoane, 1000, &telefoaneScumpe, &nrTelefoaneScumpe);
	afisareVector(telefoaneScumpe, nrTelefoaneScumpe);


	return 0;
}