/* @autores:    Diego Emilio Moreno Sanchez,
                Hector Alejandro Perez, 
			    Angel David Ortiz.  
    Fecha:      10 de diciembre de 2021      */   

#include<stdio.h>
 
// inicializamos la funcion 
void busquedaProf(int);

int matriz[30][30],
    visitados[30],
    nodo,
    cuenta;

int main() {
    int i,j;
    printf("\nIngrese el numero de nodos del grafo: ");
    scanf("%d", &nodo);
    for (i = 0; i < nodo; i++){
        for (j = 0; j < nodo; j++){
            // guardamos los valores en la matriz, suponiendo que es 
            // una matriz simétrica y no existen bucles
            if (j > i) {
                printf("\nIngrese para %d a %d: ", i + 1, j + 1);
                scanf("%d", &matriz[i][j]);
                matriz[j][i] = matriz[i][j];
            } else if (j == i) {
                matriz[i][j] = 0;
            }
        }
    }
    //el arreglo de visitados lo inicializamos en 0
    for(i = 0; i < nodo; i++) {
        visitados[i] = 0;
    } 

    busquedaProf(0);
    
    printf("\n");
    // evaluamos si se visitaron todos los nodos, en caso de que si, significa que el grafo es conexo
    if(cuenta == nodo) {
        printf("El grafo es conexo\n");
    } else {
        printf("El grafo es disconexo\n");
    }
    return 0;
}
void busquedaProf(int i) {
    int j;
    // vamos añadiendo a la cuenta cada que pasemos por aquí
    cuenta++;
    visitados[i] = 1;
    for(j = 0; j < nodo; j++) {
        // evaluamos la siguiente expresion, en caso de True usaremos recursividad
        // evalua el arreglo de visitados en la posicion j y la matriz en la posicion i, j en caso de que exista conexiones (1)
        if(!visitados[j] && matriz[i][j] == 1) {
            busquedaProf(j);
        }
    }
}