//* @autor: Diego Emilio Moreno Sánchez, 20/10/21
////////////////////////////////
// Este programa pide 8 numeros, luego cada
// numero en multiplicado por 2, al final se
// muestran los primeros 8 numeros y los siguientes 8
////////////////////////////////
#include <stdio.h>

int arr[8];
int arr2[8];

int main() {
    // guardamos el primer arreglo
    for (int i = 0; i <= 7; i++) {
        printf("\nIngrese el numero %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    // imprimimos los numeros ingresados
    printf("\nLos numeros ingresados son: \n");
    for (int i = 0; i <= 7; i++){
        printf(" %d ", arr[i]);
        // multiplicamos por 2 cada numero
        arr2[i] = arr[i] * 2;
    }
    printf("\n");
    // imprimimos los numeros ingresados
    printf("Los numeros resultantes son: \n");
    for (int i = 0; i <= 7; i++){
        printf(" %d ", arr2[i]);
    }
    return 0;
}