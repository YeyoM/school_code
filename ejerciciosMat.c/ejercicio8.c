// @autor Diego Emilio Moreno Sanchez, 25/10/21, ID: 264776
//----------------------------------------------------------------
// Crear una matriz identidad (debe ser cuadrada) y mostrarla en pantalla.
//----------------------------------------------------------------

int n,      // n definira el tamaño de la matriz 
    j,      // variables de iteracion
    i;

int main() {
    // generamos la matriz
    printf("Ingrese el num de filas y columnas de la matriz: ");
    scanf("%d", &n);
    int mat1[n][n];
    for ( i = 0; i < n; i++ ) {
        for ( j = 0; j < n; j++ ) {
            if (i == j) {
                mat1[i][j] = 1;
            } else {
                mat1[i][j] = 0;
            }
        }
    }
    // mostramos la matriz
    printf("\nLa matriz resultante: \n");
    for ( i = 0; i < n; i++ ) {
        for ( j = 0; j < n; j++ ) {
            printf(" %d ", mat1[i][j]);
        }
        printf("\n");
    }
    return 0;
}