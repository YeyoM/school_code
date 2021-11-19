#include <stdio.h>

// inicializamos las variables que van a recibir los
// valores dados por el ususario

int mat = 0;

float cal1 = 0,
      cal2 = 0,
      cal3 = 0,
      cal4 = 0,
      cal5 = 0,
      prom = 0;

int main(){
    // Lectura de Datos
    printf("Ingrese su matricula: \n");
    scanf("%i", &mat);
    printf("Ingrese su primer calificacion: \n");
    scanf("%f", &cal1);
    printf("Ingrese su segunda calificacion: \n");
    scanf("%f", &cal2);
    printf("Ingrese su tercera calificacion: \n");
    scanf("%f", &cal3);
    printf("Ingrese su cuarta calificacion: \n");
    scanf("%f", &cal4);
    printf("Ingrese su quinta calificacion: \n");
    scanf("%f", &cal5);
    // Hacemos la oprecacion
    prom = (cal1 + cal2 + cal3 + cal4 + cal5) / 5;
    // Imprimimos el resultado
    printf("La calificacion del alumno con la matricula: %i, es: %.2f", mat, prom);
    return 0;
}
