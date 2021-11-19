//* @autor: Diego Emilio Moreno Sánchez, 20/10/21
////////////////////////////////
// Este programa pide 10 numeros, luego los guarda en un
// arreglo, y genera uno nuevo con los cuadrados de dichos 
// numeros
////////////////////////////////
#include <stdio.h>

// inicializamos los arreglos
int arr[10];
int arr2[10];

int main() {
    // guardamos el primer arreglo
    for (int i = 0; i <= 9; i++) {
        printf("\nIngrese el numero %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    // imprimir los numeros
    printf("\nLos numeros ingresados son: \n");
    for (int i = 0; i <= 9; i++){
        printf(" %d ", arr[i]);
        // aqui mismo se convierten en cuadrados 
        // y guardamos en un nuevo arreglo
        arr2[i] = arr[i] * arr[i];
    }
    printf("\n");
    // imprimir los cuadrados
    printf("Los cuadrados son: \n");
    for (int i = 0; i <= 9; i++){
        printf(" %d ", arr2[i]);
    }
    
    return 0;
}