#include <stdio.h>

// inicializamos todas las variables, de valor entero
// que van a recibir los numeros
int n1 = 0, 
    n2 = 0, 
    n3 = 0, 
    n4 = 0;

int main(int argc, char const *argv[]) {
    printf("Ingrese el numero 1: \n");
    scanf("%i", &n1);
    printf("Ingrese el numero 2: \n");
    scanf("%i", &n2);
    printf("Ingrese el numero 3: \n");
    scanf("%i", &n3);
    printf("Ingrese el numero 4: \n");
    scanf("%i", &n4);
    printf("Los numeros en orden inverso, son: %i, %i, %i, %i ", n4, n3, n2, n1);
    return 0;
}

// Mi idea era dentro de un bucle for pedir los valores
// pero creo que todavia falta para eso, pude haberlos 
// guardado en un array pero creo que eso ya es un poco
// mas complejo

/*int main(int argc, char const *argv[]) {
    for (i = 1; i <= 4; i++) {
        printf("Ingrese el numero %d: \n", i);
        scanf("%i", &n1);
    }
    printf("%i", n1);
}*/
