//4 subyacente esta inicializada con 0, n va de 0 al valor de la matriz
void armar(int mat[][MAX], int subyacente[][], int n, int i, int j){
    if(i<=n){
        if(j<=n){
            if(mat[i][j] == 1){
                subyacente[i][j]++;
                subyacente[j][i]++;
            }
            amar(mat,subyacente,n,i,j+1);
        }else
            amar(mat,subyacente,n,i+1,0);
    }
}

//6
typedef struct nodo{
    int adyacente;
    struct nodo *sig;
}nodo;
typedef nodo * TL;
typedef struct{
    int vertice;
    TL adyacencia;
}TV;

int entrada(TV vec[], int vertice, int n){
    int suma=0, i;
    TL aux;
    for (i=0;i<=n;i++){
        aux = vec[i].adyacencia;
        while (aux != NULL && aux->dato!=vertice)
            aux = aux->sig;
        if(aux!=NULL)
            suma++;
    }
    return suma;
}
int salida(TV vec[], int vertice, int n){
    int suma=0, i;
    TL aux;
    while(vec[i].vertice != vertice)
        i++;
    aux = vertice[i].adyacencia;
    while(aux != NULL){
        suma++;
        aux = aux->sig;
    }
    return suma;
}
int grado(TV vec[], int vertice, int n){
    int suma=0, i;
    TL aux;
    for(i=0;i<=n;i++){
        aux = vec[i].adyacencia;
        if(vec[i].vertice == vertice)
            while(aux != NULL){
                suma++;
                aux = aux->sig;
            }
        else{
            while (aux != NULL && aux->dato!=vertice)
                aux = aux->sig;
            if(aux!=NULL)
                suma++;
        }
    }
    return suma;
}

//8c
int verifica(int mat[][MAX],int X,int n,int j){
    if(j<=n){
        if(abajo(mat,X,0,j)||derecha(mat,X,n,j,j+1))
            return verifica(mat,X,n,j+1)
        else
            return 0;
    }
    return 1;
}
int abajo(int mat[][MAX],int X,int i,int j){
    if(i<=j){
        if(mat[i][j]>X)
            return 1;
        else
            return abajo(mat,X,i+1,j);
    }
    return 0;
}
int derecha(int mat[][MAX],int X,int n,int i,int j){
    if(j<=n){
        if(mat[i][j]>X)
            return 1;
        else
            return derecha(mat,X,n,i,j+1);
    }
    return 0;
}

//9 es buena idea crear un vector de totales y buscar el maximo de ahi?
//asi recorro una vez las listas de ady

//11a
//previamente muestro el nodo inicial,i=indice nodo inicial, j=0
void profundidad(int mat[][MAX],int n,int i, int j,int visitados[],int x){
    if(i<=n){
        if(j<=n){
            if(mat[i][j]>0){
                if(!encontrar(x,j)){
                    x++;
                    visitados[x] == 1;
                    printf("%d",j+1);
                    profundidad(mat,n,j,j+1,visitados,x);
                }
            }
            profundidad(mat,n,i,j+1,visitados,x);
        }
    }
}
//11b
void amplitud(int mat[][MAX], int n, int inicio, int visitados[]){
    int i,j,x=0;
    visitados[x] = inicio;
    printf("%d",inicio);
    for(i=0;i<=n,i++){
        for(j=0;j<=n;j++){
            if(mat[i][j]>0 && !encontrar(x,j)){
                x++;
                visitados[x]==1;
                printf("%d",j+1);
            }
        }
    } 
}
int encontrar(int x,int j){
    int i=0;
    while(i<=x && i!=j){
        i++;
    }
    if(i>x)
        return 0;
    else
        return 1;
}
//11c
void marcar_componente(int matriz[][MAX], int n, int v, int visitados[]) {
    visitados[v] = 1;
    for (int w = 0; w<n; w++) {
        if (matriz[v][w] != 0 && !visitados[w]) {
            marcar_componente(matriz, n, w, visitados);
        }
    }
}
int contar_componentes(int matriz[][MAX], int n) {
    int visitados[];
    int cantidad = 0;
    iniciaV(visitados,n);//valor 0
    for (int v = 0; v < n; v++) {
        if (!visitados[v]) {
            marcar_componente(matriz, n, v, visitados);
            cantidad++;
        }
    }
    return cantidad;
}

//12a ?????????
void profundidad(int vec[], int n, int v,int visitados[]){
    int i;
    TL aux;
    visitados[v] = 1;
    printf("%d",v+1);
    for(i=0;i<n;i++){
        aux = vec[i].L;
        if (aux != NULL && !visitados[i])
            profundidad(vec,n,i,visitados);
        if(aux != NULL)
            aux=aux->sig;
    }
}

//13a
