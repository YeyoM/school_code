//* este progrma calcula el factorial recursivo de n

// directivas
#include <stdio.h>
#include <stdlib.h>

// Declaracion de funciones
double factorial(int n);
int n;

// Programa main
int main() {
    printf("Calcula el factorial de un numero\n");
    printf("Introduce el valor de n: ");
    scanf("%d", &n);
    // llamado a la funcion 
    printf("El factorial de %d es: %g", n, factorial(n));
    return 0;
}

// Cuerpo de la funcion recursiva
double factorial(int n){
    if (n <= 2) {
        return n;
    } else {
        return n * factorial(n - 1);
    }
}