#include <iostream>
using namespace std;

struct Nodo {
  int dato;
  Nodo* der;
  Nodo* izq;
  Nodo* padre;
};

Nodo* crearNodo(int n, Nodo* padre) {
  Nodo* nuevo_nodo = new Nodo();
  nuevo_nodo -> dato = n;
  nuevo_nodo -> der = NULL;
  nuevo_nodo -> izq = NULL;
  nuevo_nodo -> padre = padre;
  return nuevo_nodo;
}

Nodo* arbol = NULL;
void insertarNodo(Nodo*&, int, Nodo*);
void mostrarArbol(Nodo*, int);
void preOrden(Nodo*);
void inOrden(Nodo*);
void postOrden(Nodo*);
bool busqueda(Nodo*, int);
void eliminarArbol(Nodo*, int);
void eliminarNodo(Nodo*);
void destruirNodo(Nodo*);

Nodo* minimo(Nodo*);
void reemplazar(Nodo*, Nodo*);

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

void eliminarArbol(Nodo*arbol, int n) {
  if (arbol == NULL) {
    return;
  }
  else if (n < arbol -> dato) {
    eliminarArbol(arbol -> izq, n);
  }
  else if (n > arbol -> dato) {
    eliminarArbol(arbol -> der, n);
  }
  else {
    eliminarNodo(arbol);
  }
}

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
      eliminarArbol(arbol, dato);
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