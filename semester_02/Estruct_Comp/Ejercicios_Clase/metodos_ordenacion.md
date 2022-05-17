### Ordenación de las estructuras de datos

La ordenación interna es aquella en la que los elementos a componentes del arreglo se encuentran en la memoria principal de la computadora.

La ordenación externa es aquella en al que los elementos se encuentran en archivos que están almacenados en dispositivos de almacenamiento secundario como discos.

- Pueden ser clasificados en metodos directos(cortos y de facil elaboración y compresión) y logaritmicos(son más complejos pero requeren menos comparaciones y movimientos para ordenar elementos)

- Clasificación de los algoritmos de Ordenamiento
  
1. Algoritmos de Inserción
2. Algoritmos de Intercambio
3. Algoritmos de Selección
4. Algoritmos de Enumeración

#### Método de ordenación de burbuja

Se basa en una serie de intercambios entre elementos adyacentes. Estos intercambios dan la impresión de que cada elemento va moviéndose a través del arreglo hasta llegar a su posición final.

El algoritmo se analiza de la siguiente forma:

- Supongamos que tenemos el siguiente arreglo: [4, 5, 2, 1, 3]
  
1. Empezamos comparando el elemento de la posición 0 con el elemento de la posición 1: 4 vs 5, como están en orden continuamos -> [4, 5, 2, 1, 3]
2. Comparamos el elemento de la posición 1 con el elemento de la posición 2: 5 vs 2, como no están en orden, intercambiamos los elementos -> [4, 2, 5, 1, 3]
3. Comparamos el elemento de la posición 2 con el elemento de la posición 3: 5 vs 1, como no están en orden, intercambiamos los elementos -> [4, 2, 1, 5, 3]
4. Comparamos el elemento de la posición 3 con el elemento de la posición 4: 5 vs 3, como no están en orden, intercambiamos los elementos -> [4, 2, 1, 3, 5]
   - Aqui el elemento en la posicion 4 ya está en su posición final. Continuamos con los demas elementos.
5. Comparamos el elemento de la posicion 0 con el elemento de la posicion 1: 4 vs 2, como no están en orden, intercambiamos los elementos -> [2, 4, 1, 3, 5]
6. Comparamos el elemento de la posicion 1 con el elemento de la posicion 2: 4 vs 1, como no están en orden, intercambiamos los elementos -> [2, 1, 4, 3, 5]
7. Comparamos el elemento de la posicion 2 con el elemento de la posicion 3: 4 vs 3, como no están en orden, intercambiamos los elementos -> [2, 1, 3, 4, 5]
   - Aqui el elemento en la posicion 3 ya está en su posición final. Continuamos con los demas elementos.
8. Comparamos el elemento de la posicion 0 con el elemento de la posicion 1: 2 vs 1, como no están en orden, intercambiamos los elementos -> [1, 2, 4, 3, 5]
9. Comparamos el elemento de la posicion 1 con el elemento de la posicion 2: 2 vs 4, como están en orden, continuamos -> [1, 2, 4, 3, 5]
10. Comparamos el elemento de la posicion 2 con el elemento de la posicion 3: 4 vs 3, como no están en orden, intercambiamos los elementos -> [1, 2, 3, 4, 5]
    - Aquí el arreglo ya está ordenado.

El código se ve de la siguiente manera:
```cpp
void bubbleSort(int arr[], int num_elementos) { 
  for (int i = 0; i < num_elementos - 1; i++) {
    for (int j = 0; j < num_elementos - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        swap(&arr[j], &arr[j + 1]);
      }
    }
  }
}
```


