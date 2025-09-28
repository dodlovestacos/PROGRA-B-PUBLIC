#include <stdio.h>
#include <stdlib.h>
#define DIM 20

void CargaMatriz(int A[DIM][DIM],int *N,int *M); // A matriz con sus dimensiones / N,M ingresadas por usuario y con * pq son punteros (se determinan adentro de la funcion)
void SumaFilas(int A[DIM][DIM], int N, int M, int V[DIM]);

int main()
{
    int A[DIM][DIM], N, M, V[DIM];
    CargaMatriz(A, &N, &M);
    SumaFilas(A,N,M,V);
    return 0;
}

void CargaMatriz(int A[DIM][DIM],int *N,int *M)
{
    int i,j;
    printf("Ingrese la cantidad filas: ");
    scanf("%d",N);
    printf("Ingrese la cantidad columnas: ");
    scanf("%d",M);
    for (i=0; i< *N; i++)
    {
        for (j=0; j< *M; j++)
        {
            printf("Ingrese el contenido de la posicion %d %d",i,j);
            scanf("%d", &A[i][j]);
        }
    }
}

void SumaFilas(int A[DIM][DIM], int N, int M, int V[DIM])
{
    int i,j;
    for (i=0; i<N; i++)
    {
        V[i]=0;
        for (j=0; j<M; j++)
        {
            V[i] += A[i][j];
        }
        printf("Suma: %d",V[i]);
    }
}
