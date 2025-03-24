//#include <stdio.h>
//#include <stdbool.h>
//#include <stdlib.h>
//#include <string.h>
//
////definire strustura
//struct fruct
//{
//    char* denumire;
//    float gramaj;
//    int nrZile;
//    bool areSambure;
//};
//
//////functie afisare
////void afisareVectorFructe(struct fruct* fructe, int nrFructe)
////{
////    for (int i = 0; i < nrFructe; i++)
////    {
////        printf("%s, %5.2f, %d, %s \n", fructe[i].denumire, fructe[i].gramaj, fructe[i].nrZile, fructe[i].areSambure ? "Da" : "Nu");
////    }
////}
////
//////functie citire vector
////struct fruct* citireVectorFructe(int nrFructe)
////{
////    struct fruct* fructe;
////    fructe = (struct fruct*)malloc(nrFructe * sizeof(struct fruct));
////
////    for (int i = 0; i < nrFructe; i++)
////    {
////        printf("denumire: ");
////        char aux[20];
////        scanf_s("%19s", aux, (unsigned)_countof(aux));
////        fructe[i].denumire = (char*)malloc((strlen(aux) + 1) * sizeof(char));
////        strcpy_s(fructe[i].denumire, strlen(aux) + 1, aux);
////        printf("gramaj: ");
////        scanf_s("%f", &fructe[i].gramaj);
////        printf("nr zile: ");
////        scanf_s("%d", &fructe[i].nrZile);
////        printf("are sambure: (0-nu; 1-da):");
////        scanf_s("%d", &fructe[i].areSambure);
////    }
////    return fructe;
////}
//
//
////afisare matrice
//
////void afisareMatriceInt(int matrice[][10], int n, int m)
////{
////    for (int i = 0; i < n; i++)
////    {
////        for (int j = 0; j < m; j++) 
////        {
////            printf("%d ", matrice[i][j]);
////        }
////        printf("\n");
////    }
////}
//
//
//
//
//
//int main()
//{
//
//    ////testare stuct in main
//    //struct fruct mar;
//    //mar.denumire = (char*)malloc((strlen("mar") + 1) * sizeof(char));
//    //strcpy_s(mar.denumire, strlen("mar") + 1, "mar");
//    //mar.gramaj = 120.4;
//    //mar.nrZile = 1;
//    //mar.areSambure = false;
//
//    //printf("%s, %5.2f, %d, %s", mar.denumire, mar.gramaj, mar.nrZile, mar.areSambure ? "Da" : "Nu");
//    ////eliberare memorie atribut alocat dinamic
//    //free(mar.denumire);
//
//    ////vector static
//    //const int nrFructe = 10;
//    //struct fruct* fructe = (struct fruct*)malloc(nrFructe * sizeof(struct fruct));
//    //
//   
//    //for (int i = 0; i < nrFructe; i++)
//    //{
//    //    fructe[i].denumire = (char*)malloc(sizeof(char) * (strlen("portocala") + 1));
//    //    strcpy_s(fructe[i].denumire, strlen("portocala") + 1, "portocala");
//    //    fructe[i].gramaj = 200;
//    //    fructe[i].nrZile = 2;
//    //    fructe[i].areSambure = false;
//    //}
//    //afisareVectorFructe(fructe, nrFructe);
//
//    //for (int i = 0; i < nrFructe; i++)
//    //{
//    //    free(fructe[i].denumire);
//    //}
//    //free(fructe);
//
//    ////vector alocat dinamic
//    //const int nrFructe3 = 3;
//    //struct fruct* fructeDinamic;
//    //fructeDinamic = citireVectorFructe(nrFructe3);
//
//
//    //if (fructeDinamic != NULL) {
//    //    afisareVectorFructe(fructeDinamic, nrFructe3);
//
//    //    for (int i = 0; i < nrFructe3; i++)
//    //    {
//    //        free(fructeDinamic[i].denumire);
//    //    }
//    //    free(fructeDinamic);
//    //}
//
//
//
//    //matrice alocata static
//
//   /* int n = 4;
//    int m = 5;
//    int matrice[10][10];
//
//    for (int i = 0; i < n; i++)
//    {
//        for (int j = 0; j < m; j++) 
//        {
//            matrice[i][j] = i * j;
//        }
//    }
//
//    afisareMatriceInt(matrice, n, m);*/
//
//    return 0;
//}
