#include<stdio.h>
 
void busquedaProf(int);
int matriz[30][30],visited[30],nodo,cuenta;    //n is no of vertices and graph is sorted in array G[10][10]
int main()
{
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
    //visited is initialized to zero
    for(i = 0; i < nodo; i++) {
        visited[i] = 0;
    } 
    busquedaProf(0);
    
    printf("\n");
    if(cuenta == nodo) {
        printf("El grafo es conexo\n");
    } else {
        printf("El grafo es disconexo\n");
    }
    return 0;
}
void busquedaProf(int i) {
    int j;
    cuenta++;
    visited[i] = 1;
    for(j = 0; j < nodo; j++) {
        if(!visited[j] && matriz[i][j] == 1) {
            busquedaProf(j);
        }
    }
       
}