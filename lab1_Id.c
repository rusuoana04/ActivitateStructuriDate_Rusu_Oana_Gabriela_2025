//lab1 sdd-001 - Crearea unui Repository pe GitHub si setarea in VisualStudio 2022
#include <stdio.h>

int main() {

    printf("Salutare!\nIntroduceti un nr intreg: ");

    int variabila=0;
  //trebuie folosit scanf_s
     scanf_s("%d", &variabila);
     printf("Ai introdus: %d", variabila);
     printf("Introduceti un nr real: ");
     //citirea unei variabile reale
 float variabila=0.0;
 scanf_s("%f", &variabila);
 //punem 5.2f ca sa ne apara numarul cu 2 zecimale
  printf("Ai introdus: %5.2f", variabila);


    return 0;
}