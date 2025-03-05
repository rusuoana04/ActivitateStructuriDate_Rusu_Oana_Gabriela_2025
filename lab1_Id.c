//lab1 sdd-001 - Crearea unui Repository pe GitHub si setarea in VisualStudio 2022
#include <stdio.h>

int main() {

    printf("Salutare!\nIntroduceti un nr intreg: ");

    int variabila=0;
  //trebuie folosit scanf_s
     scanf_s("%d", &variabila);
     printf("Ai introdus: %d", variabila);
    

    return 0;
}