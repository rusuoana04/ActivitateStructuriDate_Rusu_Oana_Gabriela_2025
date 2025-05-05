#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct Robot
{
	int id;
	char* nume;
	float pret;
}; typedef struct Robot Robot;

//functie de citire de la tastatura
Robot citireRobot()
{
	Robot r;
	char buffer[100];
	printf("Introduceti ID-ul robotului: ");
	scanf("%d", &r.id);
	printf("Introduceti numele robotului: ");
	scanf("%s", buffer);
	r.nume = (char*)malloc(strlen(buffer) + 1);
	strcpy(r.nume, buffer);
	printf("Introduceti pretul robotului: ");
	scanf("%f", &r.pret);
	return r;
}

Robot creareRobot(int id, const char* nume, float pret)
{
	Robot r;
	r.id = id;
	r.nume = (char*)malloc(strlen(nume) + 1);
	strcpy(r.nume, nume);
	r.pret = pret;
	return r;
}
//functie de afisare 
void afisareRobot(Robot robot)
{
	printf("Id: %d\n", robot.id);
	printf("Nume: %s\n", robot.nume);
	printf("Pret: %.2f\n", robot.pret);
}
//functie de calculare pret fara tva
float PretFaraTVA(Robot robot, float tva)
{
	float pret = robot.pret - (robot.pret * tva);
	return pret;
}
//functie de modificare pret pentru un Robot

void modificaPret(Robot* robot, float pretNou)
{
	robot->pret = pretNou;
}


//functie de copiere vector roboti dupa pret peste 100
void copiereRobotiScumpi(Robot* vector, int nrElemente, float prag, Robot** vectorNou, int* nrRezultate)
{
	int dimensiune = 0;
	for (int i = 0; i < nrElemente; i++)
	{
		if (vector[i].pret >= prag)
		{
			dimensiune++;
		}
	}
	*vectorNou = (Robot*)malloc(dimensiune * sizeof(Robot));
	int k = 0;
	for (int i = 0; i < nrElemente; i++)
	{
		if (vector[i].pret >= prag) 
		{
			(*vectorNou)[k].id = vector[i].id;
			(*vectorNou)[k].nume = (char*)malloc(strlen(vector[i].nume) + 1);
			strcpy((*vectorNou)[k].nume, vector[i].nume);
			(*vectorNou)[k].pret = vector[i].pret;
			k++;
		}
	}
	*nrRezultate = dimensiune;
}





void dezalocare(Robot* robot)
{
	if (robot->nume != NULL)
	{
		free(robot->nume);
	}
	robot->nume = NULL;
	
}


int main() {
	Robot robot = citireRobot();
	printf("Robotul citit de la tastatura:\n");
	afisareRobot(robot);

	Robot r1 = creareRobot(1, "robot", 100);
	Robot r2 = creareRobot(2, "robot1", 150);
	Robot r3 = creareRobot(3, "robot2", 90);
	afisareRobot(r1);

	float pretfaraTVA = PretFaraTVA(r1, 0.19f);
	printf("Pret fara TVA: %.2f\n", pretfaraTVA);

	printf("Pret robot 3 inainte de modificare: %.2f\n", r3.pret);
	modificaPret(&r3, 200);
	printf("Pret modificat robot 3: %.2f\n", r3.pret);

	int nrRoboti = 3;
	Robot* vector = (Robot*)malloc(nrRoboti * sizeof(Robot));
	for (int i = 0; i < nrRoboti; i++) {
		printf("\nIntroduceti date robot %d:\n", i + 1);
		vector[i] = citireRobot();
	}

	printf("\nAfisare vector roboti:\n");
	for (int i = 0; i < nrRoboti; i++) {
		afisareRobot(vector[i]);
	}

	Robot* vectorNou = NULL;
	int nrRezultate = 0;
	copiereRobotiScumpi(vector, nrRoboti, 100.0f, &vectorNou, &nrRezultate);

	printf("\n--- Roboti cu pret >= 100 ---\n");
	for (int i = 0; i < nrRezultate; i++) {
		afisareRobot(vectorNou[i]);
	}

	for (int i = 0; i < nrRoboti; i++) {
		dezalocare(&vector[i]);
	}
	free(vector);

	for (int i = 0; i < nrRezultate; i++) {
		dezalocare(&vectorNou[i]);
	}
	free(vectorNou);

	dezalocare(&robot);
	dezalocare(&r1);
	dezalocare(&r2);
	dezalocare(&r3);

	return 0;
}