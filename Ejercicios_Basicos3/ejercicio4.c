#include <stdio.h>

#define libro 100.00
#define cuaderno 15.50
#define plumas 2.35

float total = 0,                                                    // definimos todas las variables
      total_lib = 0,                                                // el total de libros, cuadernos y plumas
      total_cuad = 0,                                               
      total_plum = 0,
      cant_lib = 0,                                                 // la cantidad de libros, cuadernos y plumas
      cant_cuad = 0,
      cant_plum = 0;

int main() {
    printf("\nIngrese cuantos libros comprara: ");
    scanf("%f", &cant_lib);
    printf("\nIngrese cuantos cuadernos comprara: ");
    scanf("%f", &cant_cuad);
    printf("\nIngrese cuantas plumas comprara: ");
    scanf("%f", &cant_plum);
    total_lib = cant_lib * libro;                                   // calculamos el total a pagar de cada tipo de producto
    total_cuad = cant_cuad * cuaderno;
    total_plum = cant_plum * plumas;
    printf("\nEl total a pagar de libros es: $%.2f", total_lib);
    printf("\nEl total a pagar de cuadernos es: $%.2f", total_cuad);
    printf("\nEl total a pagar de plumas es: $%.2f", total_plum);
    total = total_plum + total_cuad + total_lib;                    // calculamos el total a pagar y lo mostramos
    printf("\nEl total a pagar es de: $%.2f", total);
    return 0;
}
