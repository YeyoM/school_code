#include <iostream>
using namespace std;

struct Nodo {
  int dato;
  Nodo* der;
  Nodo* izq;
  Nodo* padre;
};

// Creamos el nodo y asignamos los valores
// de los punteros padre, izquierdo y derecho
// para despues insertar el nodo en el arbol
// se crea una funcion aparte ya que se usa 
// en varias partes del codigo
Nodo* crearNodo(int n, Nodo* padre) {
  Nodo* nuevo_nodo = new Nodo();
  nuevo_nodo -> dato = n;
  nuevo_nodo -> der = NULL;
  nuevo_nodo -> izq = NULL;
  nuevo_nodo -> padre = padre;
  return nuevo_nodo;
}

// Inicializamos el arbol
Nodo* arbol = NULL;

// Prototipado de las funciones
void insertarNodo(Nodo*&, int, Nodo*);
void mostrarArbol(Nodo*, int);
void preOrden(Nodo*);
void inOrden(Nodo*);
void postOrden(Nodo*);
bool busqueda(Nodo*, int);
void eliminarArbol(Nodo*, int);
void eliminarNodo(Nodo*);
void destruirNodo(Nodo*);
Nodo* minimo(Nodo*);            // funciones auxiliares
void reemplazar(Nodo*, Nodo*);

// Insertar un nodo en el arbol, si el arbol esta vacio
// se asigna el nodo como raiz, si no, si el valor
// es menor que el valor de la raiz, se inserta en
// el subarbol izquierdo, si no, se inserta en el
// subarbol derecho
void insertarNodo(Nodo*& arbol, int n, Nodo*padre) {
  if (arbol == NULL) {
    Nodo* nuevo_nodo = crearNodo(n, padre);
    arbol = nuevo_nodo;
  }
  else {
    int valorRaiz = arbol -> dato;
    if (n < valorRaiz) {
      insertarNodo(arbol -> izq, n, arbol);
    }
    else {
      insertarNodo(arbol -> der, n, arbol);
    }
  }
}

// Mostrar el arbol en una forma que la raiz esta 
// en el lado izquierdo y las hojas estan en el lado derecho
void mostrarArbol(Nodo* arbol, int cont) {
  if (arbol == NULL) {
    return;
  }
  else {
    mostrarArbol(arbol -> der, cont + 1);
    for (int i = 0; i < cont; i++) {
      cout << "   ";
    }
    cout << arbol -> dato << endl;
    mostrarArbol(arbol -> izq, cont + 1);
  }
}

// Mostrar el recorrido del arbol en preorden
// (raiz, izquierdo, derecho)
void preOrden(Nodo* arbol) {
  if (arbol == NULL) {
    return;
  }
  else {
    cout <<  arbol -> dato << "-";
    preOrden(arbol -> izq);
    preOrden(arbol -> der);
  }
}

// Mostrar el recorrido del arbol en inorden
// (izquierdo, raiz, derecho)
void inOrden(Nodo* arbol) {
  if (arbol == NULL) {
    return;
  }
  else {
    inOrden(arbol -> izq);
    cout << arbol -> dato << "-";
    inOrden(arbol -> der);
  }
}

// Mostrar el recorrido del arbol en postorden
// (izquierdo, derecho, raiz)
void postOrden(Nodo* arbol) {
  if (arbol == NULL) {
    return;
  }
  else {
    postOrden(arbol -> der);
    postOrden(arbol -> izq);
    cout << arbol -> dato << "-";
  }
}

// Este metodo retorna un booleano, en caso que el arbol 
// este vacio retorna false, si el arbol no esta vacio
// y el valor esta en el arbol retorna true, si el valor
// no esta en el arbol y es menor que el valor de la raiz
// se busca en el subarbol izquierdo, si no, se busca
// en el subarbol derecho, asi hasta que se encuentre o 
// no se encuentre el valor (cuando apunte a NULL)
bool busqueda(Nodo* arbol, int n) {
  if (arbol == NULL) {
    return false;
  }
  else if (arbol -> dato == n) {
    return true;
  }
  else if (n < arbol -> dato) {
    return busqueda(arbol -> izq, n);
  }
  else {
    return busqueda(arbol -> der, n);
  }
}

// Eliminar un nodo del arbol, si el arbol esta vacio
// se retorna un valor nulo, si no, si el valor
// es menor que el valor de la raiz, se elimina en
// el subarbol izquierdo, si no, se elimina en el
// subarbol derecho, asi hasta que el valor sea 
// el que estamos buscando y ahi llamamos a eliminarNodo
void eliminar(Nodo*arbol, int n) {
  if (arbol == NULL) {
    return;
  }
  else if (n < arbol -> dato) {
    eliminar(arbol -> izq, n);
  }
  else if (n > arbol -> dato) {
    eliminar(arbol -> der, n);
  }
  else {
    eliminarNodo(arbol);
  }
}

// Eliminar un nodo del arbol, si el nodo a eliminar
// tiene 2 hijos, se reemplaza con el nodo sucesor
// en caso contrario, se reemplaza con unico hijo
void eliminarNodo(Nodo* nodoEliminar) {
  if (nodoEliminar -> izq && nodoEliminar -> der) {
    Nodo* menor = minimo(nodoEliminar -> der);
    nodoEliminar -> dato = menor -> dato;
    eliminarNodo(menor);
  }
  else if (nodoEliminar -> izq) {
    reemplazar(nodoEliminar, nodoEliminar -> izq);
    destruirNodo(nodoEliminar);
  }
  else if (nodoEliminar -> der) {
    reemplazar(nodoEliminar, nodoEliminar -> der);
    destruirNodo(nodoEliminar);
  }
  else {
    reemplazar(nodoEliminar, NULL);
    destruirNodo(nodoEliminar);
  }
}

// Aqui eliminamos el nodo 
void destruirNodo(Nodo* nodo) {
  nodo -> izq = NULL;
  nodo -> der = NULL;
  delete nodo;
}

Nodo* minimo(Nodo* arbol) {
  if (arbol == NULL) {
    return NULL;
  }
  if (arbol -> izq) {
    return minimo(arbol -> izq);
  }
  else {
    return arbol;
  }
}

// Si el nodo que tiene que ser eliminado es el hijo izquierdo de su padre,
// el padre del hijo izquierdo se reemplaza con el hijo derecho
// Si el nodo que tiene que ser eliminado es el hijo derecho de su padre,
// el padre del hijo derecho se reemplaza con el hijo derecho
void reemplazar(Nodo* arbol, Nodo* nuevoNodo) {
  if (arbol -> padre) {
    if (arbol -> dato == arbol -> padre -> izq -> dato) {
      arbol -> padre -> izq = nuevoNodo;
    }
    else if (arbol -> dato == arbol -> padre -> der -> dato) {
      arbol -> padre -> der = nuevoNodo;
    }
  }
  if (nuevoNodo) {
    nuevoNodo -> padre = arbol -> padre;
  }
}

int main() {
  int opc, dato, contador = 0;
  do {
    cout << "\t" << "MENU";
    cout << endl << "1. Insertar Nodo";
    cout << endl << "2. Mostrar Arbol completo";
    cout << endl << "3. Recorrer en Preorden";
    cout << endl << "4. Recorrer en Inorden";
    cout << endl << "5. Recorrer en Postorden";
    cout << endl << "6. Buscar Nodo";
    cout << endl << "7. Eliminar un nodo del arbol";
    cout << endl << "8. Salir";
    cout << endl << "Opcion: "; 
    cin >> opc;

    if (opc == 1) {
      cout << endl << "Digite un nuevo numero: ";
      cin >> dato;
      insertarNodo(arbol, dato, NULL);
      cout << endl;
      system("pause");
      system("cls");
    }
    else if (opc == 2) {
      cout << endl << "Mostrendo el arbol completo:" << endl << endl;
      mostrarArbol(arbol, contador);
      cout << endl;
      system("pause");
      system("cls");
    }
    else if (opc == 3) {
      cout << endl << "Realizando el recorrido PreOrden: " << endl;
      preOrden(arbol);
      cout << endl;
      system("pause");
      system("cls");
    }
    else if (opc == 4) {
      cout << endl << "Realizando el recorrido InOrden: " << endl;
      inOrden(arbol);
      cout << endl;
      system("pause");
      system("cls");
    }
    else if (opc == 5) {
      cout << endl << "Realizando el recorrido PostOrden: " << endl;
      postOrden(arbol);
      cout << endl;
      system("pause");
      system("cls");
    }
    else if (opc == 6) {
      cout << endl << "Que elemento quieres buscar: "; cin >> dato;
      if (busqueda(arbol,dato) == true){
        cout << "El elemento " << dato << " se encuentra en el arbol" << endl;
      }
      else {
        cout << "El elemento " << dato << " no se encuntra en el arbol" << endl;
      }
      cout << endl;
      system("pause");
      system("cls");
    }
    else if (opc == 7) {
      cout << endl << "Escriba el nodo que quieres eliminar: "; cin >> dato;
      eliminar(arbol, dato);
      cout << endl;
      system("pause");
      system("cls");
    }
    else if (opc == 8) {
      cout << endl << "Saliendo del programa..." << endl;
      system("pause");
    }
    else {
      cout << endl << "Opcion invalida, intente de nuevo" << endl;
      system("pause");
    }
  } while (opc != 8);
  system("cls");
  return 0;
}