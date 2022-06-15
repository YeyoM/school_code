#include <iostream>

using namespace std;

// Imprimir el vector
void imprimirVector(int arr[], int tam) {
    for (int x = 0; x < tam; x++)
        cout << arr[x] << " ";

    cout << "\n";
}

void heapify(int vector[], int tam, int indice) {
    // Encontrar el mayor (nodo padre), nodo hijo y nodo derecho.
    int mayor = indice; // Padre
    int izq = 2 * indice + 1; // Nodo izq
    int der = 2 * indice + 2; // Nodo der

    // En los ifs se hacen 2 validaciones:
    //  1. Si los hijos del subarbol existen (izq < tam)
    //      Si el index del nodo izq o derecho sobrepasan el tamaño actual, entonces no existen ó ya fueron ordenados del vector.
    //  2. Si el valor de los hijos es mayor al padre
    //      Si ese es el caso, entonces el mayor se vuelve el index de alguno de los hijos.

    if (izq < tam && vector[izq] > vector[mayor])
        mayor = izq;

    if (der < tam && vector[der] > vector[mayor])
        mayor = der;

    // El mayor cambió y ahora no es igual que el indice? (linea 17)
        // Cambia los valores ahora con el nuevo index mayor del vector.
        // Vuelve a aplicar la propiedad de heap.
    if (mayor != indice) {
        swap(vector[indice], vector[mayor]);
        heapify(vector, tam, mayor);
    }
}

// Funcion principal para heapsort
void heapSort(int arr[], int tam) {

    // Crear max-heap (heapify)
    for (int i = tam / 2 - 1; i >= 0; i--)
        heapify(arr, tam, i);

    // Heapsort! (Ordenamiento)
    for (int i = tam - 1; i >= 0; i--) {

        // Cambia el valor del nodo que está hasta abajo con la raiz
        swap(arr[0], arr[i]);
        imprimirVector(arr, tam);

    // Vuelve a aplicar la propiedad para ajustar el vector.
        heapify(arr, i, 0);
    }
}

// Funcion Principal
int main() {
    int vector[] = {1, 12, 9, 5, 6, 10};
    int n = sizeof(vector) / sizeof(vector[0]);
    cout << "Vector desordenado:\n";
    imprimirVector(vector, n);
    cout<<"\n";

    heapSort(vector, n);

    cout << "\nVector ordenado: \n";
    imprimirVector(vector, n);
}