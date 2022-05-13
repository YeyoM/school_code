### Arbol binario de busqueda

Un arbol binario de busqueda con raiz R es de búsqueda cuando no está vacío

- Si tiene un subárbol izquierdo, la raiz del subárbol izquierdo es menor a R, y a la vez el subárbol izquierdo es un arbol binario de busqueda
- Si tiene un subárbol derecho, la raiz del subárbol derecho es mayor a R, y a la vez el subárbol derecho es un arbol binario de busqueda

Un arbol de busqueda debe almacenar elementos que cumplan con una relacion de orden. Debe haber una forma de ordenar los elementos de un arbol binario de busqueda, como por ejemplo números enteros de menor a mayor o entre un rango, usando palabras por orden lexicografico, etc.

### Estructura de los nodos de un arbol binario de busqueda

```cpp

struct Nodo {
  int dato;
  struct Nodo *izq;
  struct Nodo *der;
};

```

### Operaciones de un arbol binario de busqueda

- Añadir o insertar elementos a un árbol 
- Recorrido de elementos
- Buscar o localizar elementos dentro de un árbol
- Borrar elementos de un árbol
- Conocer el número de elementos de un árbol
- Obtener la altura de un árbol

#### Buscar un elemento en un árbol 

Localizar elementos a partir de su valor o su identificador/clave. Para de esta forma comprobar si existe un elemento en un árbol u obtener el dato de un elemento que estamos buscando.

Para buscar un elemento de un árbol, se pueden dar varios casos:

1. Verificar si la raiz es el elemento buscado (si n == R)
2. En caso contrario, verificar si el elemento está en el subárbol izquierdo (si n < R)
3. En caso contrario, verificar si el elemento está en el subárbol derecho (si n > R)

```cpp

bool buscar(Nodo *nodo, int dato_a_buscar) {
  if (nodo == NULL) {
    return false;
  }
  // CASO 1: Si la raiz es el elemento buscado
  if (nodo -> dato == dato_a_buscar) {
    return true;
  }
  // CASO 2: Si el elemento está en el subárbol izquierdo
  if (nodo -> dato > dato_a_buscar) {
    return buscar(nodo -> izq, dato_a_buscar);
  }
  // CASO 3: Si el elemento está en el subárbol derecho
  return buscar(nodo -> der, dato_a_buscar);
}

```

#### Añadir un elemento a un árbol

Se hace a partir de la logica de búsqueda, ya que es necesario introducir el elemento de forma ordenada.

Al añadir un elemento a un árbol, se pueden dar varios casos:

1. Si el árbol está vacío, se añade el elemento como raiz
2. Si la raiz del árbol es igual al elemento a añadir, no se hace nada o se manda un error
3. Si la raiz del árbol es mayor al elemento a añadir, se añade el elemento en el subárbol izquierdo
4. Si la raiz del árbol es menor al elemento a añadir, se añade el elemento en el subárbol derecho
   
```cpp

void insertar(Nodo *&raiz, int dato) {
  if (raiz == NULL) {
    Nodo *nuevo_nodo = new Nodo();
    nuevo_nodo -> dato = dato;
    nuevo_nodo -> izq = NULL;
    nuevo_nodo -> der = NULL;
  } else if (raiz -> dato == dato) {
    cout << "Error: el elemento ya existe" << endl;
  } else if (raiz -> dato > dato) {
    insertar(raiz -> izq, dato);
  } else {
    insertar(raiz -> der, dato);
  }
}

```