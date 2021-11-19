#include <stdio.h>

float pago_c = 0,
      pago = 0,
      cambio = 0;

int main(){
    printf("Ingrese el total a pagar:\n");
    scanf("%f", &pago);
    printf("Ingrese el dinero para pagar: \n");
    scanf("%f", &pago_c);
    cambio = pago - pago_c;
    printf("Su cambio es: $%.1f\n", cambio);
    return 0;
}
