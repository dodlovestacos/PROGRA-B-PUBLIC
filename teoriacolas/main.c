#include <stdio.h>
#include <stdlib.h>
#include "colas.h"
void Aparece_X(TCola *C , int X, int *contador);

int main()
{
    TCola C;
    int X, contador = 0;

    ArmarCola(&C);
    printf("ingrese un valor X:");
    scanf("%d", &X);
    Aparece_X(&C, X, &contador);
    printf("Cantidad de veces aparece X: %d", contador);
    return 0;
}

void Aparece_X(TCola *C , int X, int *contador){
    TelementoC val;

    while( !VaciaC(*C) ){
        SacaC( C , &val);
        if (val == X)
            (*contador)++;
    }
}
