// Diego Emilio Moreno Sanchez @YeyoM
// 11/03/2022

#include <iostream>
using namespace std;

struct Nodo {
  int dato;
  struct Nodo *anterior;
  struct Nodo *siguiente;
};

void insertarNodo(Nodo *&lista, int n);
void mostrarLista(Nodo *lista);
void borrarNodo(Nodo *&lista, int n);
void buscarDato(Nodo *lista, int n);

int main(){

  Nodo *lista;
  lista = NULL;

  int dato;

  cout << "Ingrese un dato: ";
  cin >> dato;
  insertarNodo(lista, dato);

  cout << "Ingrese un dato: ";
  cin >> dato;
  insertarNodo(lista, dato);

  cout << "Ingrese un dato: ";
  cin >> dato;
  insertarNodo(lista, dato);
  
  cout << "Ingrese un dato: ";
  cin >> dato;
  insertarNodo(lista, dato);

  cout << endl;
  cout << "La lista es la siguiente: " << endl;
  mostrarLista(lista);

  cout << endl;
  cout << "Digite un numero para eliminar de la lista: ";
  cin >> dato;
  borrarNodo(lista, dato);

  cout << endl;
  cout << "La lista es la siguiente: " << endl;
  mostrarLista(lista);

  cout << endl;
  cout << "Digite un numero para buscar en la lista: ";
  cin >> dato;
  buscarDato(lista, dato);

  return 0;
}

void insertarNodo(Nodo *&lista, int n) {
  Nodo *nuevo_nodo = new Nodo();
  nuevo_nodo -> dato = n;

  Nodo *aux1 = lista;
  Nodo *aux2 = NULL;  // este siempre va anerior a aux1
  Nodo *aux3 = NULL;  // este lo usaremos para que cuando insertemos
                      // un nodo, el que le sigue apunte a ese nuevo nodo
                      // para cuando sea el primer elemento

  // recorremos la lista mientras aux1 (iterador) sea diferente de null
  // y que el doto del nodo iterador sea menor al dato, esto nos deja
  // exactamente en la posicion donde hay que insertar el nodo
  while((aux1 != NULL) && (aux1 -> dato < n)){
    aux2 = aux1;
    aux1 = aux1 -> siguiente;
  }

  if(lista == aux1){
    // este procedimiento para cuando se inserte al inicio de la lista
    lista = nuevo_nodo;             // lista apunta al nuevo nodo    
    if(lista -> siguiente != 0) {   // si no es el unico elemento
      aux3 = lista -> siguiente;    // llamamos a una variable auxiliar que 
      aux3 -> anterior = lista;     // guarda a la posicion siguiente, para 
    }                               // que ese siguiente apunte al primero
  } else {
    // en caso contrario que sea en medio o al final
    aux2 -> siguiente = nuevo_nodo; // el nodo anterior al que vamos a ingresar apunta en siguiente al nuevo
    nuevo_nodo -> anterior = aux2;  // el nuevo nodo, su anterior apunta al aux2, el nodo menor que el
  }

  nuevo_nodo -> siguiente = aux1; // el nuevo nodo apunta en siguiente a aux1, el nodo mayor que el
  
  // en caso de que el que insertemos no sea el ultimo elemento
  if(aux1 != 0) {
    aux1 -> anterior = nuevo_nodo;  // ese elemento mayor al nuevo nodo
  }                                 // su anterior sera el nuevo nodo


  cout << "Elemento " << n << " ingresado correctamente" << endl;


  // Pruebasssssss
  // Nodo *anterior_nuevo = nuevo_nodo -> anterior;
  // Nodo *siguiente_nuevo = nuevo_nodo -> siguiente;
  // 
  // if(anterior_nuevo != 0) {
  //   cout << "Anterior: " <<anterior_nuevo -> dato << endl;
  // }
  // if(siguiente_nuevo != 0) {
  //   cout << "Siguiente: " << siguiente_nuevo -> dato << endl;
  // }
}

void mostrarLista(Nodo *lista) {
  Nodo *actual = new Nodo();
  actual = lista;

  // nos detendremos una vez que el apuntador
  // del nodo n(siguiente) apunte a -> NULL
  while(actual -> siguiente != NULL) {
    cout << actual -> dato << " ";
    actual = actual -> siguiente;     // cambiamos al siguiente nodo
  }
  cout << actual -> dato << endl;
  cout << endl;

  cout << "Ahora al reves: " << endl;

  // nos detenemos ahi para que el nodo acutual no
  // sea null y poder recorrer de atras para delante
  while(actual != NULL) {
    cout << actual -> dato << " ";
    actual = actual -> anterior; 
  }
}

void borrarNodo(Nodo *&lista, int n) {
  
  if(lista != NULL) {
    Nodo *aux_borrar;
    Nodo *anterior = NULL;
    Nodo *siguiente = NULL;
    aux_borrar = lista;

    while((aux_borrar != NULL) && (aux_borrar -> dato != n)) {
      // recorremos todos a una posicion, anterior avanza una posicion
      anterior = aux_borrar;
      // y a su vez aux_borrar se va a la posicion siguiente
      aux_borrar = aux_borrar -> siguiente;
      // ojo que lista se queda igual
    }

    // CASO 1
    // recorrio toda la lista pero el dato no se encontro
    // y al final termino apuntando a NULL, por lo tanto
    if(aux_borrar == NULL) {
      cout << "El elemento no existe";
    }

    // CASO 2
    // en caso de que sea el primer elemento (no entra al while)
    else if((aux_borrar -> dato == n) && (anterior == NULL)) {
      // lista ya no va a apuntar al primer elemento
      // sino al siguiente (aux_borrar -> siguiente)
      lista = aux_borrar -> siguiente;
      lista -> anterior = NULL;
      // eliminamos aux_borrar
      delete aux_borrar;
    }

    // CASO 3
    // en caso de que el elemento a borrar no sea el primero
    // pero si exista
    else {
      if (aux_borrar -> siguiente != 0) {
        siguiente = aux_borrar -> siguiente;
        siguiente -> anterior = aux_borrar -> anterior;
      }
      anterior -> siguiente = aux_borrar -> siguiente;
      delete aux_borrar;
    }
  }

}

void buscarDato(Nodo *lista, int n) {
  bool encontrado = false;
  Nodo *actual = new Nodo();
  actual = lista;

  while(actual != NULL) {
    if (actual -> dato == n){ 
      encontrado = true;
      cout << "Encontrado!!!" << endl;
      break;
    };
    actual = actual -> siguiente;
  }

  if(encontrado == false) {
    cout << "El elemento no ha sido encontrado" << endl;
  }

}