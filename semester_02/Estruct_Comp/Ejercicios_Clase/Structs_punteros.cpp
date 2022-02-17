// @utor Diego Emilio Moreno
/*
  Realizar lo siguiente

  - Obtener el tamaño que ocupa en 
    bytes la estructura

  - Asignar la estructura a un 
    apuntador
 
  - Obtener el tamaño de la dirección 
    de memoria a la que apunta la 
    estructura
 
  - Capturar por teclado los datos 
    de la estructura a través de 
    un apuntador

  - Imprimir si el nombre e 
    identificador del cliente si
    el saldo actual es mayor de 
    1000, de lo contrario solo
    imprimir el nombre del cliente 
    (hacer la manipulación e 
    impresión a través del apuntador 
    de la estructura).
*/

#include <iostream>
using namespace std;

struct informacion_cliente { 
  int   identificador;    /* Número identificador */     
  char  nombre[100];      /* Nombre de la celda */ 
  float saldo_actual;     /* Saldo actual del cliente */ 
};

int main() {

  struct informacion_cliente cliente1;
  struct informacion_cliente *apuntador_cliente1;

  apuntador_cliente1 = &cliente1;

  cout << "Ingrese el ID del cliente: ";
  cin >> (*apuntador_cliente1).identificador;
  cout << endl;

  fflush(stdin);

  cout << "Ingrese el nombre del cliente: ";
  gets((*apuntador_cliente1).nombre);
  cout << endl;

  fflush(stdin);

  cout << "Ingrese el saldo actual del cliente: ";
  cin >> (*apuntador_cliente1).saldo_actual;
  cout << endl;

  cout << "Tam de la estructura: ";
  cout << sizeof(informacion_cliente) << endl;

  cout << "Tam de la direccion: ";
  cout << sizeof(&cliente1) << endl;

  if ((*apuntador_cliente1).saldo_actual > 1000){
    cout << "Nombre del cliente: ";
    cout << (*apuntador_cliente1).nombre << endl;
    cout << "ID del cliente: ";
    cout << (*apuntador_cliente1).identificador << endl;
  } else {
    cout << "Nombre del cliente: ";
    cout << (*apuntador_cliente1).nombre << endl;
  }

  return 0;
}
