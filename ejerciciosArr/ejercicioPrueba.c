//* @autor: Diego Emilio Moreno Sánchez, 20/10/21
////////////////////////////////////////////////
// este programa, dado un arreglo de numeros, devuelve 
// el numero mayor y la posicion de dicho numero
////////////////////////////////////////////////
#include <stdio.h>

int arr[5];
int may = 0, 
    posmay = 0,
    men = 0,
    posmen = 0;

int main() {
    // guardamos los numeros ingrsados
    for (int i = 0; i <= 4; i++) {
        printf("\nIngrese el numero %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    printf("\nLos numeros ingresados son: \n");
    may = arr[0];
    men = arr[0];
    for (int i = 0; i <= 4; i++){
        printf(" %d ", arr[i]); // mostramos el arreglo
        if (arr[i] > may) {     // evaluamos los numeros
            may = arr[i];       // en caso de que sea mayor, guardamos
            posmay = i;        // el num, y su posicion (i)
        }
        if (arr[i] < men) {
            men = arr[i];
            posmen = i;
        }
    }
    printf("\nEl numero mayor ingresado es: %d, en la posicion: %d", may, posmay);
    printf("\nEl numero menor ingresado es: %d, en la posicion: %d", men, posmen);
    
    return 0;
}