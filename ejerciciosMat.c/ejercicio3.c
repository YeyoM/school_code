// @autor Diego Emilio Moreno Sanchez, 25/10/21, ID: 264776
//----------------------------------------------------------------
// Escribir un programa que cree una matriz de 4*4 con números 
// enteros y que imprima en pantalla
// a) La matriz
// b) La suma de los elementos por columna.
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
        }
    }
    // recorremos la matriz por columnas para ir obteniendo las sumas
    for ( i = 0; i <= 3; i++ ){
        for ( j = 0; j <= 3; j++ ) {
            acum += mat[j][i];
        }
        sumas[i] = acum;
        acum = 0;
    }
    printf("\n");
    // mostramos la matriz original
    printf("La matriz ingresada es: \n");
    for ( i = 0; i <= 3; i++ ){
        for ( j = 0; j <= 3; j++ ) {
            printf(" %d ", mat[i][j]);
        }
        printf("\n");
    }
    // mostramos las sumas por columnas
    for ( i = 0; i <= 3; i++ ){
        printf("\nLa suma de la columna %d = %d", i, sumas[i]);
    }
    printf("\n");
    return 0;
}