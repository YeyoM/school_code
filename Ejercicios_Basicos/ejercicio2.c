#include <stdio.h>

// inicializamos las variables que van a recibir los
// valores dados por el ususario, y una mas para 
// almacenar el resultado
int n1 = 0,
    n2 = 0,
    res = 0;

int main(){
    // Lectura de Datos
    printf("Ingrese el numero 1: \n");
    scanf("%i", &n1);
    printf("Ingrese el numero 2: \n");
    scanf("%i", &n2);
    // Hacemos la oprecacion
    res = ((n1 + n2) * (n1 + n2)) / 3;
    // Imprimimos el resultado
    printf("Resultado: %i\n", res);
    return 0;
}
