////////////////////////////////////////////////////////////////////////////////////////////////
// Programa que almacena una matriz de adyacencia de algun vertice de n nodos
////////////////////////////////////////////////////////////////////////////////////////////////
#include <stdio.h>

int nodo = 0;

int main() {
    printf("\n.:Programa que almacena una matriz de adyacencia:.\n");
    printf("Si existe conexion entre nodos digite   1\n");
    printf("En caso contrario ingrese               0\n");
    printf("\nIngrese el numero de nodos del grafo: ");
    scanf("%d", &nodo);
    int matriz[nodo][nodo]; // inicializamos 2 arreglos, uno para guardar la matriz
    int grados[nodo];       // el otro para guardar los grados de cada nodo
    for (int i = 0; i < nodo; i++){
        for (int j = 0; j < nodo; j++){
            // guardamos los valores en la matriz, suponiendo que es 
            // una matriz simétrica y no existen bucles
            if( j > i ) {
                printf("\nIngrese para %d a %d: ", i + 1, j + 1);
                scanf("%d", &matriz[i][j]);
                matriz[j][i] = matriz[i][j];
            } else if( j == i ) {
                matriz[i][j] = 0;
            }
        }
    }
    printf("\n");
    int acum = 0; // inicializamos un acumulador para contar los grados
    for (int i = 0; i < nodo; i++) {
        for (int j = 0; j < nodo; j++) {
            printf(" %d ", matriz[i][j]);
            acum = acum + matriz[i][j]; // aquí definimos el grado de cada nodo
        }
        grados[i] = acum; // guardamos el valor de acum en los grados
        acum = 0; // devolvemos el acumulador a 0
        printf("\n");
    }
    printf("\n");
    printf("Los grados de los nodos en orden son: \n");
    int may = grados[0]; // inicializamos el grado mayor con el valor del primer nodos
    int maypos = 0;
    printf("Nodo:  ");
    for (int i = 0; i < nodo; i++) {
        printf(" %d ", i + 1);
    }
    printf("\n");
    printf("Grado: ");
    for (int i = 0; i < nodo; i++) {
        printf(" %d ", grados[i]);
        if (grados[i] > may) {  // buscamos el grado mayor conforme 
            may = grados[i];    // imprimo los grados
            maypos = i + 1;
        }
    }
    // mostramos los resultados
    printf("\nEl grado mayor es: %d, ubicado en el nodo: %d", may, maypos);

    return 0;
}
