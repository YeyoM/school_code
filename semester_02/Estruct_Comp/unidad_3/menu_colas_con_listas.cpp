// Cesar Donet Hernandez Gastelum
// Diego Emilio Moreno Sanchez @YeyoM
// 8 de abril de 2022

#include <iostream>
using namespace std;

// ESTRUCTURA DE LOS NODOS DE LA PILA ////////////////
struct Nodo {
  int dato;
  Nodo *siguiente;
};

// PROTOTIPOS DE LAS FUNCIONES ////////////////////////
void buscarDato(Nodo *lista, int dato);
void insertarDato(Nodo *&start, Nodo *&end, int dato);
void eliminarDato(Nodo *&start, Nodo *&end);


int main(){

  // AQUI DEFINIMOS LA LONGITUD DE LA COLA ////////////
  int tam_cola;
  cout << "Digite el tamaño de la cola: ";
  cin >> tam_cola;
    
  // AQUI DEFINIMOS ESTRUCTURAS PARA LLEVAR EL CONTROL 
  // DE LA COLA
  Nodo *start;
  start = NULL;
  Nodo *end;
  end = NULL;

  int inicio = -1;
  int fin = -1;

  int dato;
  int opcion;


  // MOSTRAMOS EL MENU ////////////////////////////////
  do{
    cout << "1. Insertar"         << endl;
    cout << "2. Mostrar/Eliminar" << endl;
    cout << "3. Buscar"           << endl;
    cout << "4. Salir"            << endl;
    cout << "Digite una opcion: ";
    cin  >> opcion;
    switch(opcion){
      // CASO 1 PARA INSERTAR UN ELEMENTO A LA COLA ///
      case 1:
        if(fin == tam_cola){
          cout << "Cola llena" << endl;
        } else{
          cout << "Digite un numero: ";
          cin >> dato;
          insertarDato(start, end, dato);
          fin++;
        }
        break;
      // CASO 2 PARA ELIMINAR UN ELEMENTO A LA COLA ///
      case 2:
        if(inicio == fin){
          cout << "Cola vacia" << endl;
        } else{
          eliminarDato(start, end);
          inicio++;
        }
        break;
      // CASO 3 PARA BUSCAR UN ELEMENTO A LA COLA /////
      case 3:
        if(inicio == fin){
          cout << "Cola vacia" << endl;
        } else{
          cout << "Digite un numero: ";
          cin >> dato;
          buscarDato(start, dato);
          cout << endl;
        }
        break;
      /////////////////////////////////
      case 4:
        break;
      /////////////////////////////////
      default:
        cout << "Opcion no valida" << endl;
    }
  } while(opcion != 4);
    return 0;
}

///////////////////////////////////////
void buscarDato(Nodo *pila, int dato) {
  bool encontrado = false;
  Nodo *actual = new Nodo();
  actual = pila;
  while(actual != NULL) {
    if (actual -> dato == dato){ 
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

///////////////////////////////////////
void insertarDato(Nodo *&start, Nodo *&end, int dato) {
  Nodo *nuevo_nodo = new Nodo;
  nuevo_nodo -> dato = dato;
  nuevo_nodo -> siguiente = NULL;

  if (start == NULL) {
    start = nuevo_nodo;
    end = nuevo_nodo;
  } else {
    end -> siguiente = nuevo_nodo;
    end = nuevo_nodo;
  }
  cout << "El numero: " << nuevo_nodo -> dato << " ha sido insertado" << endl;
}

///////////////////////////////////////
void eliminarDato(Nodo *&start, Nodo *&end) {
  if (start == NULL) {
    cout << "La cola esta vacia" << endl;
  } else {
    Nodo *aux = start;
    cout << "Eliminando..." << aux -> dato << endl;
    start = start -> siguiente;
    delete aux;
  }
}