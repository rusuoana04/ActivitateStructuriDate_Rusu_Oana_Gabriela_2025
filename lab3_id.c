#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

//definire strustura
struct fruct
{
    char* denumire;
    float gramaj;
    int nrZile;
    bool areSambure;
};

//functie afisare
void afisareVectorFructe(struct fruct* fructe, int nrFructe)
{
    for (int i = 0; i < nrFructe; i++)
    {
        printf("%s, %5.2f, %d, %s \n", fructe[i].denumire, fructe[i].gramaj, fructe[i].nrZile, fructe[i].areSambure ? "Da" : "Nu");
    }
}