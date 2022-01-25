// @autor Diego Emilio Moreno Sanchez, 25/10/21, ID: 264776
//----------------------------------------------------------------
// Suma de dos matrices cuadradas, dejando el resultado en una tercera 
// matriz y que imprima en pantalla las 3 matrices
//----------------------------------------------------------------

int n,      // n definira el tamaño de la matriz 
    j, 
    i;      // variables de iteracion

int main() {
    // generamos las matrices
    printf("Ingrese el num de filas y columnas de la matriz: ");
    scanf("%d", &n);
    int mat1[n][n]; 
    int mat2[n][n];
    int mat3[n][n];     // aqui se guardara el resultado
    // guardamos la primera matriz
    printf("\nPrimera matriz: ");
    for ( i = 0; i < n; i++ ) {
        for ( j = 0; j < n; j++ ) {
            printf("\nIngrese el valor para [%d][%d]: ", i, j);
            scanf("%d", &mat1[i][j]);
        }
    }
    // guardamos la segunda matriz
    printf("\nSegunda matriz: ");
    for ( i = 0; i < n; i++ ) {
        for ( j = 0; j < n; j++ ) {
            printf("\nIngrese el valor para [%d][%d]: ", i, j);
            scanf("%d", &mat2[i][j]);
            // sumamos las matrices
            mat3[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
    // mostramos la matriz resultante
    printf("\nMatriz resultante: ");
    printf("\n");
    for ( i = 0; i < n; i++ ) {
        for ( j = 0; j < n; j++ ) {
            printf(" %d ", mat3[i][j]);
        }
        printf("\n");
    }
    return 0;
}