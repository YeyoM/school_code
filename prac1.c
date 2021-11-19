#include <stdio.h>

main(int argc, char const *argv[]) {
    // Imprimiendo numeros flotantes y enteros
    int num1 = 5, 
        num2 = 10;
    float num3 = 15.11;
    // %i para enteros, %f para flotantes y el .2 para marcar hasta que
    // decimal queremos mostrar, podemos poner .1, .4, etc...
    printf("\nEl numero es: %i, num2: %i, num3: %.2f", num1, num2, num3);

    //Entrada y salida de datos 
    // \n para salto de linea
    int n = 0,
        j = 0;
    printf("\nIngrese dos numero: ");
    // %i para denotar que el numero que vamos a recibir es entero 
    // el &n para asignar a que variable le vamos a asignar el valor de
    // entrada
    scanf("%i %i", &n, &j);
    printf("Los numeros dados son: %i, y %i", n, j);
    
    return 0;
}
