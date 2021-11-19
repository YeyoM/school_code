#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

int n,      // n definira el tamaño de la matriz 
    j, 
    i;      // variables de iteracion

int main() {
    // generamos las matrices
    printf("Ingrese el num de filas y columnas de la matriz: ");
    scanf("%d", &n);
    int mat1[n][n]; 
    int mat2[n][n];
    int mat3[n][n];     // aqui se guardara el resultado
    srand(time(NULL));
    // guardamos la primera matriz
    for ( i = 0; i < n; i++ ) {
        for ( j = 0; j < n; j++ ) {
            mat1[i][j] = rand()%10+1;
        }
    }
    printf("Primer matriz: \n");
    for ( i = 0; i < n; i++ ) {
        for ( j = 0; j < n; j++ ) {
            printf(" %d ", mat1[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    // guardamos la segunda matriz
    for ( i = 0; i < n; i++ ) {
        for ( j = 0; j < n; j++ ) {
            mat2[i][j] = rand()%10+1;
            mat3[i][j] = mat1[i][j] * mat2[i][j];
        }
    }
    printf("Segunda matriz: \n");
    for ( i = 0; i < n; i++ ) {
        for ( j = 0; j < n; j++ ) {
            printf(" %d ", mat2[i][j]);
        }
        printf("\n");
    }
    // mostramos la matriz resultante
    printf("\nMatriz resultante: ");
    printf("\n");
    for ( i = 0; i < n; i++ ) {
        for ( j = 0; j < n; j++ ) {
            printf(" %d ", mat3[i][j]);
        }
        printf("\n");
    }
    return 0;
}