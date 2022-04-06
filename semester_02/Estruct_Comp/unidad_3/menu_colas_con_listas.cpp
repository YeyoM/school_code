#include<iostream>
using namespace std;

struct Nodo {
  int dato;
  Nodo *siguiente;
};

void cola_circular(int n){

  /////////////////////////////////////
  Nodo *start;
  start = NULL;
  Nodo *end;
  end = NULL;

  int inicio = -1;
  int fin = -1;

  int dato;
  int opcion;
  /////////////////////////////////////

  do{
      cout << "1. Insertar" << endl;
      cout << "2. Eliminar" << endl;
      cout << "3. Mostrar"  << endl;
      cout << "4. Salir"    << endl;
      cout << "Digite una opcion: ";
      cin >> opcion;
      switch(opcion){
          case 1:
              if(fin==n){
                  cout<<"Cola llena"<<endl;
              }else{
                  cout<<"Digite un numero: ";
                  cin>>dato;
                  cola[fin]=dato;
                  fin++;
              }
              break;
          case 2:
              if(frente==fin){
                  cout<<"Cola vacia"<<endl;
              }else{
                  cout<<"El dato eliminado es: "<<cola[frente]<<endl;
                  frente++;
              }
              break;
          case 3:
              if(frente==fin){
                  cout<<"Cola vacia"<<endl;
              }else{
                  for(i=frente;i<fin;i++){
                      cout<<cola[i]<<" ";
                  }
                  cout<<endl;
              }
              break;
          case 4:
              break;
          default:
              cout<<"Opcion no valida"<<endl;
      }
  }while(opcion!=4);
}

int main(){
    int n;
    cout<<"Digite el tamaño de la cola: ";
    cin>>n;
    cola_circular(n);
    return 0;
}


/*
Nodo *start;
start = NULL;
Nodo *end;
end = NULL;

int inicio = -1;
int fin = -1;

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
}

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

*/