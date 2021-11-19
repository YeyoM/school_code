#include <stdio.h>

int main(){
    int trabajador = 0;
    float sueldo = 0,
          total = 0;
    for (int i = 0; i < 10; i++){
        trabajador = i + 1;
        printf("Ingrese el sueldo del trabajador %i: ", trabajador);
        scanf("%f", &sueldo);    
        total += sueldo;
    }
    printf("Total a pagar: %.2f\n", total);
    
    return 0;
}