#include <stdio.h>
#include <stdlib.h>

// declaramos las constantes para las dimensiones del arreglo
#define R 3
#define C 3

// definimos el arreglo (solo de numeros enteros)
int enteros[R][C];

// definimos 
int r, c;

int main() {
    printf("Este programa contruye un arreglo \n");
    printf("Introduce los valores que se solicitan: \n");
    // pedimos los valores a los usuarios
    for (r = 0; r < R; r++) {
        for (c = 0; c < C; c++) {
            printf("\nIngrese el valor en [%d][%d]: ", r, c);
            scanf("%d", &enteros[r][c]);
        }
    }
    // mostramos el arreglo resultante
    printf("El arreglo resultante es: \n");
    for(r = 0; r < R; r++) {
        for (c = 0; c < C; c++) {
            printf("\t%d", enteros[r][c]);
        }
        printf("\n");
    }
    return 0;
}
