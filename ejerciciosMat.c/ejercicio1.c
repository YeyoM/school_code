// @autor Diego Emilio Moreno Sanchez, 25/10/21, ID: 264776
//----------------------------------------------------------------
// Escribir un programa que cree una matriz de 4*4 con números enteros 
// y que imprima en pantalla:
// a) La matriz
// b) La suma de todos los elementos de la matriz. 
//----------------------------------------------------------------

int mat[4][4];  // inicializamos la matriz
int i = 0,      // inicializamos las variables de iteracion
    j = 0;
int suma = 0;   // variable para guardar la suma

int main() {
    // guardamos la matriz
    for ( i = 0; i <= 3; i++ ){
        for ( j = 0; j <= 3; j++ ) {
            printf("\nIngrese el valor para [%d][%d]: ", i, j);
            scanf("%d", &mat[i][j]);
        }
    }
    printf("\n");
    // mostramos la matriz
    printf("La matriz ingresada es: \n");
    for ( i = 0; i <= 3; i++ ){
        for ( j = 0; j <= 3; j++ ) {
            printf(" %d ", mat[i][j]);
            suma += mat[i][j];
        }
        printf("\n");
    }
    // mostramos la suma
    printf("\nLa suma de todos los elementos es: %d", suma);
    return 0;
}
