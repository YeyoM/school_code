//----------------------------------------------------------------
// @autor: Diego Emilio Moreno Sanchez. Fecha: 04/11/21
// ejercicio funciones de calculadora
//----------------------------------------------------------------
#include <stdio.h>
#include <stdbool.h>
#include <conio.h>

// funciones
void    suma(int nums);
void    resta(int nums);
float   division(float num1, float num2);
void    multi(int nums);
int     potencia(int base, int exponente);
double  factorial(int num);
void    menu();

// variables
bool salir  = false;
int op      = 0,
    nums    = 0,
    i       = 0,
    numf,
    base, 
    exponente;
float num1, 
      num2;

//main
int main() {
    do {
        menu(); // muestra el menu
        printf("Digite una opcion valida: ");
        scanf("%d", &op);
        printf("\n");
        switch (op) {
        case 1:
            printf("Ingrese cuantos numeros desea sumar: ");
            scanf("%d", &nums);
            printf("\n");
            suma(nums);
            break;
        case 2:
            printf("Ingrese cuantos numeros desea restar: ");
            scanf("%d", &nums);
            printf("\n");
            resta(nums);
            break;
        case 3:
            printf("Ingrese el numerador: ");
            scanf("%f", &num1);
            printf("\n");
            printf("Ingrese el divisor: ");
            scanf("%f", &num2);
            printf("\n");
            printf("El resultado es: %.2f", division(num1, num2));
            break;
        case 4:
            printf("Ingrese cuantos numeros desea multiplicar: ");
            scanf("%d", &nums);
            printf("\n");
            multi(nums);
            break;
        case 5:
            printf("Ingrese la base: ");
            scanf("%d", &base);
            printf("\n");
            printf("Ingrese el exponente: ");
            scanf("%d", &exponente);
            printf("\n");
            printf("El resultado es: %d", potencia(base, exponente));
            break;
        case 6:
            printf("Ingrese el numero para calcular su factorial: ");
            scanf("%d", &numf);
            printf("\n");
            printf("El resultado es: %g", factorial(numf));
            break;
        case 7:
            printf("Gracias por usar la Calculadora\n");
            salir = true;
            break;
        default:
            printf("Ingerse una opcion valida\n");
            break;
        }
        printf("\n");
    } while ( salir == false );
    return 0;
}

float result    = 0.0,
      num       = 0.0;

void    suma(int nums){
    for (i = 0; i < nums; i++) {
        printf("Digite el numero %d: ", i+1);
        scanf("%f", &num);
        result += num;
    }
    printf("\n");
    printf("El resultado es: %.2f\n", result);
}
void    resta(int nums){
    for (i = 0; i < nums; i++) {
        printf("Digite el numero %d: ", i+1);
        scanf("%f", &num);
        if ( i == 0 ) {
            result = num;
        } else {
            result -= num;
        }
    }
    printf("\n");
    printf("El resultado es: %.2f\n", result);
}
float   division(float num1, float num2) {
    result = num1 / num2;
    return (result);
}
void    multi(int nums){
    result = 1;
    for (i = 0; i < nums; i++) {
        printf("Digite el numero %d: ", i+1);
        scanf("%f", &num);
        result = result * num;
    }
    printf("\n");
    printf("El resultado es: %.2f\n", result);
}
int     potencia(int base, int exponente){
    result = 1;
    for (i = 0; i < exponente; i++) {
        result = result * base;
    }
    return (result);
}
double  factorial(int num){
    if (num <= 2) {
        return num;
    } else {
        return num * factorial(num - 1);
    }
}
void    menu(){
    printf("\n");
    printf("Menu Calculadora\n");
    printf("1.- Suma\n");
    printf("2.- resta\n");
    printf("3.- division\n");
    printf("4.- multiplicacion\n");
    printf("5.- potencia\n");
    printf("6.- factorial\n");
    printf("7.- salir\n");
}