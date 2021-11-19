#include <stdio.h>

float n1 = 0,
      n2 = 0,
      sum = 0,
      res = 0,
      mul = 0;

int main() {
    printf("Ingrese el primer numero: \n");
    scanf("%f", &n1);
    printf("Ingrese el segundo: \n");
    scanf("%f", &n2);
    sum = n1 + n2;
    res = n1 - n2;
    mul = n1 * n2;
    printf("Los resultados de las operaciones son \n");
    printf("suma: %.2f, resta: %.2f, multiplicacion: %.2f", sum, res, mul);
    return 0;
}
