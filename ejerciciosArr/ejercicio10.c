//* @autor: Diego Emilio Moreno Sánchez, 20/10/21
////////////////////////////////
// Este programa pide 8 numeros y luego otros 8,
// dividir los primeros con los segundos (el primero con el primero...)
// y al final muestra todos los numeros resultantes
////////////////////////////////
#include <stdio.h>

// inicializamos los arreglos
float arr[8];
float arr2[8];
float arr3[8];

int main() {
    // guardamos el primer arreglo
    printf("Ingrese los primeros 8 numeros\n");
    for (int i = 0; i <= 7; i++) {
        printf("\nIngrese el numero %d: ", i + 1);
        scanf("%f", &arr[i]);
    }
    // guardamos el segundo arreglo
    printf("Ingrese los siguientes 8 numeros\n");
    for (int i = 0; i <= 7; i++) {
        printf("\nIngrese el numero %d: ", i + 1);
        scanf("%f", &arr2[i]);
    }
    // creamos el nuevo arreglo
    for (int i = 0; i <= 7; i++){
        arr3[i] = arr[i] / arr2[i];
    }
    printf("\n");
    // imprimimos el resultado
    printf("Los numeros resultantes son: \n");
    for (int i = 0; i <= 7; i++){
        printf(" %.1f ", arr3[i]);
    }
    return 0;
}