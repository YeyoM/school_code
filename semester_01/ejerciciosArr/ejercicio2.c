//* @autor: Diego Emilio Moreno Sánchez, 20/10/21
////////////////////////////////
// Este programa pide 10 numeros, luego lee dos mas
// e indica si estos dos numeros se encuentran en
// los primeros 10, y en que posicion
////////////////////////////////
#include <stdio.h>
#include <stdbool.h>

int arr[10];
int n1, 
    n2,
    posn1,
    posn2;
bool encontradon1 = false;
bool encontradon2 = false;

int main() {
    // leemos los primeros 10 numeros
    for (int i = 0; i <= 9; i++) {
        printf("\nIngrese el numero %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    // leemos los siguientes dos numeros
    printf("\nIngrese otro numero: ");
    scanf("%d", &n1);
    printf("\nIngrese otro numero: ");
    scanf("%d", &n2);

    // imprimimos los numeros ingresados
    printf("\nLos numeros ingresados son: \n");
    for (int i = 0; i <= 9; i++){
        printf(" %d ", arr[i]);
        // condicionales para identificar si los numeros ya se encontraron
        if (arr[i] == n1) {
            posn1 = i + 1;
            encontradon1 = true; // en caso de que si ponemos true
        } if ( arr[i] == n2) {
            posn2 = i + 1;
            encontradon2 = true; // en caso de que si ponemos true
        }
    }

    // imprimimos los resultados
    if( encontradon1 == true ) {
        printf("\n%d se enontro en la posicion %d\n", n1, posn1);
    } else {
        printf("%d no se encontro", n1);
    }
    if( encontradon2 == true ) {
        printf("\n%d se enontro en la posicion %d\n", n2, posn2);
    } else {
        printf("%d no se encontro", n2);
    }

    return 0;
}