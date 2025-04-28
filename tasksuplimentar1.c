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

float modificaPret(Robot* robot, float pretNou)
{
	robot->pret = pretNou;
}

int main()
{
	Robot robot = citireRobot();
	printf("Robotul citit de la tastatura: \n");
	afisareRobot(robot);


	Robot r1 = creareRobot(1, "robot", 100);
	Robot r2 = creareRobot(2, "robot1", 150);
	Robot r3 = creareRobot(3, "robot2", 90);
	afisareRobot(r1);

	float pretFaraTVA=PretFaraTVA(r1, 0.19);
	printf("pret fara tva: %.2f\n", pretFaraTVA);
	printf("pret robot 3 inainte de modificare %.2f : \n", r3.pret);
	
	float modificaPr = modificaPret(&r3, 200);
	printf("Pret modificat robot 3: %.2f", modificaPr);
	

	return 0;

}