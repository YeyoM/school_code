#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool pagado = false;
float total = 0,
      pago = 0,
      cambio = 0,
      cambiopos = 0;

int main(){
    printf("Ingrese el total a pagar:");
    scanf("%f", &total);
    printf("Ingrese dinero: ");
    scanf("%f", &pago);
    do{
        cambio = (total - pago);
        if ( cambio == 0 ) {
            printf("Gracias por su compra, vuelva pronto! \n");
            pagado = true;
        } if ( cambio < 0 ) {
            cambiopos = abs(cambio);
            printf("Gracias por su compra, su cambio es: %.2f\n", cambiopos);
            pagado = true;
        } if ( cambio > 0 ) {
            printf("Faltan de pagar: %.2f \n", cambio);
            total = cambio;
            cambio = 0;
            printf("Ingrese mas dinero:\n");
            scanf("%f", &pago);
            pagado = false;
        }
    } while ( pagado == false );
    
    return 0;
}