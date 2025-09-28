#include <stdio.h>
#include <stdlib.h>

int main()
{
  int cuentoVoc(TLista L, int k){
    TLista aux;
    int cont=0,i=1;
    char car;

    aux=L;
    while((aux=!NULL)&&(i<=k)){
        car=toupper(aux->dato);
        if(car=='A'||car=='E'||car=='I'||car=='O'||car=='U')
            cont++;
        aux=aux->sig;
        i++;
    }
    return cont;
}
}
