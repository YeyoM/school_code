// @autor: Diego Emilio Moreno Sanchez, 22/10/21
// Examen Parcial 2 
// ID 264776
// Analisis 
// Objetivo: Dado un numero, imprimir su tabla de multiplicacion de 1 a 10
// Datos de entrada: Un numero
// Datos de salida: La tabla de multiplicacion de 1 a 10
///////////////////////////////////////////////////////////////////////////
#include <stdio.h>

// inicializamos las variables
int num = 0,
    result = 0,
    opcion = 0,
    i = 1,
    j = 1;

int main() {
    printf("Ingrese un numero, para mostrar su tabla de multiplicacion: ");
    scanf("%d", &num);
    printf("\n");
    printf("1.- While\n");
    printf("2.- For\n");
    printf("3.- Salir\n");
    while (opcion != 3){
    	printf("Con que ciclo ejecutara su tabla de multiplicar: ");
    	scanf("%d", &opcion);
    	printf("\n");
        if (opcion == 1) { // imprimir la tabla con while
        	printf("Numero para la tabla: %d\n", num);
            while (j <= 10) {
                result = num * j;
                printf("%d * %d = %d\n", num, j, result);
                j++;
            }
        } else if (opcion == 2) { // imprimir la tabla con for
        	printf("Numero para la tabla: %d\n", num);
            for (i = 1; i <= 10; i++){
                result = num * i;
                printf("%d * %d = %d\n", num, i, result);
            }
        } else if(opcion == 3) { // salir
        	printf("Gracias por usar este programa\n");
        } 
		else { // opcion incorrecta
            printf("Ingrese una opcion correcta\n");
        }
        j = 1;
        i = 1;
    }
    return 0;
}
