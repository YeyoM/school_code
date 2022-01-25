#include <stdio.h>

int n1 = 0;
int factorial_n = 1; 
int factorial_n2 = 1;
int resultado = 0;

int main() {
    printf("Ingrese el valor de n: \n");
    scanf("%d", & n1);
    for (int i = 2; i <= n1; i++) {
        //aqui calcular cada combinacion desde (2,2) hasta (n,2)
        for(int j = 2; j <= i; j++) {
            //aqui calcular el resultado del factorial de n
            factorial_n = factorial_n * j;
        }
        for(int k = 1; k <= (i - 2); k++) {
            //aqui calcular el resultado del factorial de n - 2
            factorial_n2 = factorial_n2 * k;
        }
        resultado = (factorial_n / 2) / (factorial_n2);
        printf("Combinaciones de (%i, 2): %d\n", i, resultado);
        resultado = 0;
        factorial_n2 = 1;
        factorial_n = 1;
    }
    system("pause");
    return 0;
}

