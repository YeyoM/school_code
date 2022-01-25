#include <stdio.h>

int n1 = 0,
    cuad = 0,
    cub = 0;

int main(){
    printf("Ingrese el numero:\n");
    scanf("%i", &n1);
    cuad = n1 * n1;
    cub = n1 * n1 * n1;
    printf("El cuadrado de %i es: %i \n", n1, cuad);
    printf("El cubo de %i es: %i", n1, cub);
    return 0;
}
