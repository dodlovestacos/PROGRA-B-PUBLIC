//16
void insertar(arbol *ABB, TelemA x){
    arbol nuevo,aux,ant; 
    int lado; //1 = salio por izq; 0 = salio por der;

    nuevo = (arbol)malloc(sizeof(nodo));
    nuevo->dato = x;
    nuevo->izq = NULL;
    nuevo->der = NULL;

    if(*ABB == NULL)
        *ABB = nuevo;
    else{
        aux = *ABB;           
        while(aux != NULL){
            ant = aux;
             if(aux->dato<x){
                aux->izq = aux;
                lado = 1;
             }else{
                aux->der = aux;
                lado = 0;
             }
        }
        if(lado)
            ant->izq = nuevo;
        else
            ant->der = nuevo;
    }
}

//19
int cantarboles(arbol a){
    if(a == NULL)
        return 0;
    return 1 + cantarboles(a->der);
}

//20
// a 
int nivimp(arbol a, int nivel){ //nivel empieza en 1
    if(a == NULL)
        return 0;
    else{
        if(nivel % 2 == 1)
            return 1 + nivimp(a->izq,nivel+1) + nivimp(a->der,nivel);
        else
            return nivimp(a->izq,nivel+1) + nivimp(a->der,nivel);
    }
}
// b
//afuera muestra la div cantk/tot = promedio
void prom(arbol a, int k, int *cantk, int *tot){
    if(a != NULL){
        *tot++;
        if(grado(a->izq) == k)
            *cantk++;
    }
    prom(a->izq,k,cantk,tot);
    prom(a->der,k,cantk,tot);
}
int grado(arbol a){
    if(a == NULL)
        return 0;
    return 1 + grado(a->der);
}
//c
void altura(arbola a, int *hmax, int hact){ // hmax y hact = 0
    if(a != NULL){
        if(a->izq != NULL){
            if(hact == *hmax)
                *hmax+1;
            altura(a->izq,h,hact+1)
        }
        altura(a->der,h,hact);
    }
}
//d
//le paso raiz->izq en primera instancia 
int GRoriginal(arbol a){
    if(a == NULL)
        return 0;
    return 1 + GRoriginal(a->der);
}

//21
//a
int canthk(arbol a, int k){
    int h = 1;
    if(a == NULL)
        return 0;
    altura(a->izq,&h,0);
    if(h >= k)
        return 1 + canthk(a->der,k);
    else
        return canthk(a->der,k);
}
//b
void genV(arbol a, int vec[]){
    int max,i=0; arbol aux;
    aux = a;
    while(aux != NULL){
        max = aux->dato;
        buscamax(aux->izq,&max);
        vec[i] = max;
        i++;
        aux = aux->der;
    }
}
void buscamax(arbol a, int *max){
    if(a != NULL){
        if(a->dato > *max)
            *max = a->dato;
        buscamax(aux->izq,&max);
        buscamax(aux->der,&max);
    }
}
//c ?