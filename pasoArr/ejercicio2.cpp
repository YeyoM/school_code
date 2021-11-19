#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

void insertarNumero(int&, int&);

int arreglo[5];

int main(int argc, char* argv[]) {
    srand(time(NULL));
    printf("Creamos el arreglo\n");
    crearVector(arreglo);
    printf("\n");
    obtenerNumeros(arreglo);
    return 0;
}

void crearVector(int arr[]) {
    int i;
    for (i = 0; i < 5; i++) {
        arr[i] = rand()%10+1;
        printf("%d ", arr[i]);
    }
}
void obtenerNumeros(int arr[]) {
    int i, 
        may = arr[0], 
        men = arr[0];
    for (i = 0; i < 5; i++) {
        if (arr[i] > may) {
            may = arr[i];
        }
        if (arr[i] < men) {
            men = arr[i];
        }
    }
    printf("El menor numero es: %d\n", men);
    printf("El mayor numero es: %d\n", may);
}