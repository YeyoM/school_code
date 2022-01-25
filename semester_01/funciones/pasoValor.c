// @autores: Hector Robles Perez, Angel David Ortiz Quiroz, Diego Emilio Moreno Sanchez
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// definimos las constantes que son los precios de cada material
#define PRECIO_ACERO 104.5
#define PRECIO_MADERA 95.5
#define PRECIO_COBRE 97.0
#define PRECIO_PLASTICO 50.0

// declaracion de funciones
void menu();
void pagoEnCaja(float totalPagar);
float calcularPago(float cant, float precio);

// declaracion de variables
bool salir = false,
     pagado = false;
int opcion;
int acero=0, madera=0, cobre=0, plastico=0;
float cantidad,
      acumPago, 
      pago;

int main() {
	printf("Bienvenido a la ferreteria Yeyo, que desea hacer?\n");
    do {
        menu();
        printf("\n");
        printf("Ingrese una opcion: ");
        scanf("%d", &opcion);
        switch (opcion){
        system("cls");
        case 1:
            printf("Ingrese la cantidad en kg del material que desee comprar: ");
            scanf("%f", &cantidad);
            pago = calcularPago(cantidad, PRECIO_ACERO);
            acumPago += pago;
            acero = acero + cantidad;
            system("cls");
            printf("\nSu compra tiene un costo actual de: $%g\n", acumPago);   
            pago = 0;
            break;
        case 2:
            printf("Ingrese la cantidad de tablas del material que desee comprar: ");
            scanf("%f", &cantidad);
            pago = calcularPago(cantidad, PRECIO_MADERA);
            acumPago += pago;
            madera = madera + cantidad;
            system("cls");
            printf("\nSu compra tiene un costo actual de: $%g\n", acumPago);   
            pago = 0;
            break;
        case 3:
            printf("Ingrese la cantidad en kg del material que desee comprar: ");
            scanf("%f", &cantidad);
            pago = calcularPago(cantidad, PRECIO_PLASTICO);
            acumPago += pago;
            plastico = plastico + cantidad;
            system("cls");
            printf("\nSu compra tiene un costo actual de: $%g\n", acumPago);   
            pago = 0;
            break;
        case 4:
            printf("Ingrese la cantidad en kg del material que desee comprar: ");
            scanf("%f", &cantidad);
            pago = calcularPago(cantidad, PRECIO_COBRE);
            acumPago += pago;
            cobre = cobre + cantidad;
            system("cls");
            printf("\nSu compra tiene un costo actual de: $%g\n", acumPago);   
            pago = 0;
            break;
        case 5:
            // el 5 sera proceder con el pago
            if ( acumPago == 0 ) {
                printf("Todavia no ha incluido ningun articulo a la compra\n");
            } else {
                printf("Se continuara a cobrar su compra\n");
                pagoEnCaja(acumPago);
                pagado = true;
                salir = true;
            }
            break;
        case 6:
		    // La compra se reiniciara desde 0
		    printf("\n"),main();
		    
        case 7:
            if (acumPago == 0 || pagado == true) {
                printf("Que tenga un buen dia");
                exit(0);
            } else {
                printf("Todavia tiene articulos sin pagar\n");
                printf("Por favor proceda a --Continuar al pago--");
            }
            // tenemos que revisar que no pueda salir si no ha pagado o si el pago es menor al precio
            break;
        default:
            printf("Ingrese una opcion valida\n");
            break;
        }
    } while ( salir == false );
    return 0;
}

// funciones
void menu(){
    printf("Menu de compra \n");
    printf("1.- Comprar Acero a $%.2f el kg\n", PRECIO_ACERO);
    printf("2.- Comprar Madera a $%.2f la tabla\n", PRECIO_MADERA);
    printf("3.- Comprar Plastico a $%.2f el kg\n", PRECIO_PLASTICO);
    printf("4.- Comprar Cobre a $%.2f el kg\n", PRECIO_COBRE);
    printf("5.- Continuar al pago\n");
    printf("6.- Reiniciar mi compra\n");
    printf("7.- Salir del programa\n");
}
void pagoEnCaja(float totalPagar) {
    float pagoU = 0,
	falta = 0, 
    cambio = 0;
    printf("Usted va a comprar:\n");
    if(acero>0){
    	printf("\n%d kg de acero\n",acero);
	}
	if(madera>0){
		printf("\n%d tablas de madera\n",madera);
	}
	if(plastico>0){
		printf("\n%d kg de plastico\n",plastico);
	}
	if(cobre>0){
		printf("\n%d kg de cobre\n",cobre);
	}
    printf("\nEl total a Pagar es: %.2f\n", totalPagar);
    printf("Ingrese dinero: ");
    scanf("%f", &pagoU);
    do {
        cambio = pagoU-totalPagar;
        falta = totalPagar-pagoU;
        if( cambio < 0 ) {
            printf("Faltan de pagar: %.2f\n", falta);
            printf("Ingrese el dinero total: ");
            scanf("%f", &pagoU);
        } else if ( cambio > 0 ) {
            printf("Su cambio es: %.2f\n", cambio);
            cambio = 0;
            pagado = true;    
        } else {
            printf("Gracias por su compra");
            pagado = true;    
        }
    } while ( pagado == false );
}

float calcularPago(float cant, float precio) {
    float result = 0.0;
    result = cant * precio;
    return result;
}
