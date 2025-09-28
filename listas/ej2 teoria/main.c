#include <stdio.h>
#include <stdlib.h>

typedef struct nodito {
 char fecha[9];
 float imp;
 struct nodito * sig;} nodito;
 typedef nodito * SubLista;

typedef struct nodoC {
 int numC;
 float cred, deuda;
 struct nodoC * sig;
 SubLista sub;} nodoC;
 typedef nodoC * TListaC;

 void actdeuda(TListaC L, int nro_c, char fecha[],float importe);

int main()
{
    TListaC L;
    int nro_c;
    float importe;
    char fecha[9];
    void actdeuda(L,nro_c,fecha,importe);
    return 0;
}

void actdeuda(TListaC L, int nro_c, char fecha[],float importe){
    TListaC aux;
    SubLista nuevo,act,ant;
    aux=L;
    while (aux->numC != nro_c)
        aux=aux->sig;
    nuevo=(nodito)malloc(sizeof(nodito));
    nuevo->imp=importe;
    strcpy(nuevo->fecha,fecha);
    aux->deuda-=importe;
    act=aux->sub;
    while (act != NULL && strcmp(fecha,act->fecha)<0){
        ant=act; act=act->sig;
    }
    if (act==aux->sub){
        nuevo->sig=aux->sub;
        aux->sub=nuevo;
    }
    else{
        nuevo->sig=act;
        ant->sig=nuevo;
    }
}
