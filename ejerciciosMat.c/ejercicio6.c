// @autor Diego Emilio Moreno Sanchez, 25/10/21, ID: 264776
//----------------------------------------------------------------
// Ordenar una matriz de menor a mayor y mostrar en pantalla:
// a) La matriz original
// b) La matriz ordenada de menor a mayor
//----------------------------------------------------------------

int n,      // n definira el tamaño de la matriz 
    j,      // variables de iteracion
    i,
    k = 0,
    res,    // tamaño de n*n
    temp;   // variable temporal para acomodar los numeros

int main() {
    // generamos las matrices
    printf("Ingrese el num de filas y columnas de la matriz: ");
    scanf("%d", &n);
    int mat1[n][n];
    int mat2[n][n];
    res = n * n;
    // generamos un arreglo para guardar la matriz y asi acomodar
    int arr[res];
    // guardamos la mirmera matriz
    printf("\nPrimera matriz: ");
    for ( i = 0; i < n; i++ ) {
        for ( j = 0; j < n; j++ ) {
            printf("\nIngrese el valor para [%d][%d]: ", i, j);
            scanf("%d", &mat1[i][j]);
        }
    }
    // convertimos a arreglo
    for ( i = 0; i < n; i++ ) {
        for ( j = 0; j < n; j++ ) {
            arr[k] = mat1[i][j];
            k++;
        }
    }
    // acomodamos
    for (int i = 0; i <= res; i++){
        for (int j = i + 1; j <= res; j++) {  
            if(arr[i] > arr[j]) {   
                temp = arr[i];  
                arr[i] = arr[j];    
                arr[j] = temp;    
            } 
        }
    }
    k = 0;
    // volvemos a convertir a matriz
    for ( i = 0; i < n; i++ ) {
        for ( j = 0; j < n; j++ ) {
            mat1[i][j] = arr[k];
            k++;
        }
    }
    // mostramos la matriz resultante
    printf("\nLa matriz resultante es: \n");
    for ( i = 0; i < n; i++ ) {
        for ( j = 0; j < n; j++ ) {
            printf(" %d ", mat1[i][j]);
        }
        printf("\n");
    }
    return 0;
}