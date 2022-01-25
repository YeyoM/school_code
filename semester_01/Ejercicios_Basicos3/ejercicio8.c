#include <stdio.h>

int edad = 0,                           // definimos el espacio donde guardaremos tmporalmente cada edad
    mayor = 0,                          // definimos los acumuladores para los mayores y menores de edad
    menor = 0;

int main() {
    for (int i = 0; i < 10; i++){
        printf("\nIngrese la edad de la persona %d: ", i+1);
        scanf("%d", &edad);
        if ( edad >= 18 ){
            mayor++;                    // si la edad es mayor o igual a 18 sumamos al contador de mayores de edad
        } else {
            menor++;                    // si la edad es menor a 18 sumamos al contador de menores de edad
        }
    }
    printf("\n%d son menores de edad, y %d son mayores de edad", menor, mayor);
    
    return 0; 
}