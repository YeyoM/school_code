#include <iostream>
using namespace std;

struct Nodo {
  int dato;
  struct Nodo *anterior;
  struct Nodo *siguiente;
};

void insertarNodo(Nodo *&lista, int n);
void mostrarLista(Nodo *lista);

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

  mostrarLista(lista);

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
  //   cout << "Anterior: " <<anterior_nuevo -> dato << endl;\
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
    cout << actual -> dato << endl;
    actual = actual -> siguiente;     // cambiamos al siguiente nodo
  }
  cout << actual -> dato << endl;

  cout << "cambio" << endl;

  // nos detenemos ahi para que el nodo acutual no
  // sea null y poder recorrer de atras para delante
  while(actual != NULL) {
    cout << actual -> dato << endl;
    actual = actual -> anterior; 
  }

}