### Ordenamiento por seleccion

Es un algoritmo que consiste en el intercambio de posición de los elementos, una vez estos sean encontrados o seleccionados (de ahí su nombre) como aquel que cumple con el criterio establecido. 

- El código se ve de la siguiente manera: 

```cpp
for(int i = 0; i < n; i++){
  int min = i;
  for(int j = i; j < n; j++){
    if(arr[j] < arr[min]){
      min = j;
    }
  }
  swap(arr[i], arr[min]);
}
```

- Ventajas
  ~~~
  - Fácil implementación
  - No requiere memoria adicional
  - Rendimiento constante (poca diferencia  entre mejor y peor caso.
  - Realiza pocos intercambios 
  es apto para una lista de pocos elementos que estén en orden aleatorio
  ~~~
- Desventajas
  ~~~
  - Deficiente y lento en grandes o medianos grupos de datos.
  - Numerosas comparaciones.
  - Rendimiento es fácilmente influenciado  por el orden inicial de los elementos  antes del proceso de ordenamiento
  ~~~