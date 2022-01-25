//* @autor: Diego Emilio Moreno Sánchez, 20/10/21
////////////////////////////////
// Este programa pide 10 numeros, luego ordena 
// de mayor a menor dicho arreglo de numeros
////////////////////////////////
#include <stdio.h>

// iniclializamos las variables
int arr[10];
int n1, 
    n2,
    posn1,
    posn2,
    temporal;

int main() {
    // guardamos el arreglo
    for (int i = 0; i <= 9; i++) {
        printf("\nIngrese el numero %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    
    for (int i = 0; i <= 9; i++){
        for (int j = i + 1; j <= 9; j++) {  
            if(arr[i] < arr[j]) {   // si el arreglo en la posicion i es meno a i + 1
                temporal = arr[i];  // intercambiamos arr[i] con arr[j]
                arr[i] = arr[j];    // con la ayuda de una variable auxiliar
                arr[j] = temporal;    
            } 
        }
       
    }
    printf("\n");
    for (int i = 0; i <= 9; i++) {
        printf(" %d ", arr[i]);
    }
    return 0;
}