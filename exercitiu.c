//#include <stdlib.h>
//#include <string.h>
//#include <malloc.h>
//
//struct Telefon
//{
//	int id;
//	int RAM;
//	char* producator;
//	float pret;
//	char serie;
//};
//
//struct Telefon initializare(int id, int ram, const char* producator, float pret, char serie)
//
//{
//	struct Telefon t;
//	t.id = id;
//	t.RAM = ram;
//	t.producator = (char*)malloc(sizeof(char) * (strlen(producator) + 1));
//	strcpy_s(t.producator, strlen(producator) + 1, producator);
//	t.pret = pret;
//	t.serie = serie;
//	return t;
//}
//
//void afisare(struct Telefon t)
//{
//	if (t.producator != NULL)
//	{
//		printf("%d, %d, %s, %5.2f, %c", t.id, t.RAM, t.producator, t.pret, t.serie);
//
//	}
//	else
//	{
//		printf("%d, %d, %5.2f, %c", t.id, t.RAM, t.pret, t.serie);
//	}
//}
//
//void dezalocare(struct Telefon* t)
//{
//	if (t->producator != NULL)
//	{
//		free(t->producator);
//		t->producator = NULL;
//	}
//}
//
//
//
//
//int main()
//{
//	struct Telefon telefon;
//	telefon = initializare(1, 64, "telefon1", 100, 'A');
//	afisare(telefon);
//	dezalocare(&telefon);
//
//	return 0;
//
//}