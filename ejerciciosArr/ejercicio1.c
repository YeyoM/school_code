//* @autor: Diego Emilio Moreno Sánchez, 20/10/21
////////////////////////////////
// Este programa pide 10 numeros e imprime la cantidad 
// de numeros pares que se encuentran, cual es el valor 
// maximo y cual es el minimo
////////////////////////////////
#include <stdio.h>

int arr[10];

int main() {
    // guardamos los numeros
    for (int i = 0; i <= 9; i++) {
        printf("\nIngrese el numero %d: ", i + 1); 
        scanf("%d", &arr[i]);
    }
    // inicializar las variables de mayor, menor y pares
    int may = arr[0], 
        min = arr[0],
        pares = 0;
    // imprimimos los numeros
    printf("\nLos numeros ingresados son: \n");
    for (int i = 0; i <= 9; i++){
        printf(" %d ", arr[i]);
        // analizamos cual es el mayor
        if (arr[i] > may) {
            may = arr[i];
        }
        // analizamos cual es par
        if (arr[i] % 2 == 0 ) {
            pares++;
        }
        // analizamos cual es el menor
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    // imprimimos los resultados
    printf("\nEl numero mayor ingresado es: %d", may);
    printf("\nEl numero menor ingresado es: %d", min);
    printf("\nEl numero de numeros pares es: %d", pares);
    
    return 0;
}