// @autor Diego Emilio Moreno Sanchez, 25/10/21, ID: 264776
//----------------------------------------------------------------
// Multiplicación de una matriz de n * n por un escalar, dejando el 
// resultado en otra matriz. Al final imprima en pantalla las 2 matrices y el escalar
//----------------------------------------------------------------

int n,      // n definira el tamaño de la matriz 
    esc,    // producto escalar
    i = 0,  // variables de iteracion
    j = 0;

int main() {
    // generamos las matrices
    printf("Ingrese el num de filas y columnas de la matriz: ");
    scanf("%d", &n);
    int mat[n][n];      // matriz original
    int mat2[n][n];     // matriz nueva
    printf("\n");
    // guardamos el producto escalar
    printf("Ingrese el producto escalar: ");
    scanf("%d", &esc);
    printf("\n");
    // guardamos la matriz n*n
    for ( i = 0; i < n; i++ ) {
        for ( j = 0; j < n; j++ ) {
            printf("\nIngrese el valor para [%d][%d]: ", i, j);
            // vamos generando la nueva matriz
            scanf("%d", &mat[i][j]);        
            mat2[i][j] = mat[i][j] * esc;
        }
    }
    printf("\n");
    // mostramos las matrices
    for ( i = 0; i < n; i++ ) {
        for ( j = 0; j < n; j++ ) {
            printf(" %d ", mat[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    for ( i = 0; i < n; i++ ) {
        for ( j = 0; j < n; j++ ) {
            printf(" %d ", mat2[i][j]);
        }
        printf("\n");
    }

    return 0;
}