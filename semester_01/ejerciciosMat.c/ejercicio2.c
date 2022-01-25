// @autor Diego Emilio Moreno Sanchez, 25/10/21, ID: 264776
//----------------------------------------------------------------
// Escribir un programa que cree una matriz de 4*4 con números 
// enteros y que imprima en pantalla
// a) La matriz
// b) La suma de los elementos por fila. 
//----------------------------------------------------------------

int mat[4][4];  // inicializamos la matriz
int sumas[4];   // inicializamos el arreglo de suamas
int i = 0,      // inicializamos las variables de iteracion
    j = 0,
    acum = 0;   // inicializamos el acumulador

int main() {
    // guardamos la matriz
    for ( i = 0; i <= 3; i++ ){
        for ( j = 0; j <= 3; j++ ) {
            printf("\nIngrese el valor para [%d][%d]: ", i, j);
            scanf("%d", &mat[i][j]);
            acum += mat[i][j];  // vamos acumulando por fila
        }
        sumas[i] = acum;        // guardamos en el arreglo
        acum = 0;               // devolvemos a 0, e iniciamos de nuevo
    } 
    printf("\n");
    // mostramos la matriz
    printf("La matriz ingresada es: \n");
    for ( i = 0; i <= 3; i++ ){
        for ( j = 0; j <= 3; j++ ) {
            printf(" %d ", mat[i][j]);
        }
        printf("\tsuma = %d", sumas[i]);    // mostramos la suma de c/ fila
        printf("\n");
    }
    printf("\n");
    return 0;
}