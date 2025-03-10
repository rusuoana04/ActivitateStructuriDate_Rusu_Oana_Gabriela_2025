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

//functie citire vector
struct fruct* citireVectorFructe(int nrFructe)
{
    struct fruct* fructe;
    fructe = (struct fruct*)malloc(nrFructe * sizeof(struct fruct));

    for (int i = 0; i < nrFructe; i++)
    {
        printf("denumire: ");
        char aux[20];
        scanf("%s", aux);
        fructe[i].denumire = (char*)malloc((strlen(aux) + 1) * sizeof(char));
        strcpy(fructe[i].denumire, aux);
        printf("gramaj: ");
        scanf("%f", &fructe[i].gramaj);
        printf("nr zile: ");
        scanf("%d", &fructe[i].nrZile);
        printf("are sambure: (0-nu; 1-da):");
        scanf("%d", &fructe[i].areSambure);
    }
    return fructe;
}
int main()
{

    //testare stuct in main
    struct fruct mar;
    mar.denumire = (char*)malloc((strlen("mar") + 1) * sizeof(char));
    strcpy(mar.denumire, "mar");
    mar.gramaj = 120.4;
    mar.nrZile = 1;
    mar.areSambure = false;

    printf("%s, %5.2f, %d, %s", mar.denumire, mar.gramaj, mar.nrZile, mar.areSambure ? "Da" : "Nu");
    free(mar.denumire);
    return 0;
}
