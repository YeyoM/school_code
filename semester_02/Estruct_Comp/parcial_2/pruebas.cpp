
/*

REALIZO
    Cesar Donnet Hernandez Gastelum 283189
    Diego Emilio Moreno Sanchez     264776
    Dante Alejandro Alegria Romero  265853

FECHA
    17/03/22

OBJETIVO
    La aplicacion debe almacenar Productos, 
    que contenga la siguiente estructura.

PRODUCTOS
    Nombre 
    Cantidad 
    Precio 

1.  El numero de productos a insertarse en la lista sera
    aleatorio entre 1 y 8 productos. 
2.  El nombre del producto puede ser un identificador basico. 
    (integrarse aleatoriamente o ingresarlo por teclado segun 
    sea su eleccion).
3.  Cada producto al insertarse en la lista contiene una 
    cantidad y un precio (estos dos generados aleatoriamente).
    (El precio ya viene con los impuestos incluidos.)
4.  Calcular el precio total de la lista de productos ingresados
    en la nota (productos entre 1 y 8)
5.  Mostrar una nota o ticket con todo lo vendido y el total a 
    pagar de la nota como se hacen en los supermercados. Mas o 
    menos con este formato, lo importante son los datos, no el 
    estilo.
6.  Una vez que se muestre el ticket con todo lo vendido y el 
    total a pagar, dar la posibilidad de poder borrar un producto1 
    (ingresar el producto a borrar por teclado) y mostrar de nueva
    cuenta la nota como quedo despues de haber ejecutado la 
    operacion de borrado del producto.

CONSIDERACIONES
1. Realizar el ejercicio con el uso de Listas simples o doblemente 
    enlazadas (seg�n consideren, es indistinto ya que cada estructura 
    tiene sus ventajas o desventajas)
2.  Integrar funciones y/o procedimientos para la distribuci�n del c�digo
3.  Realizar las validaciones necesarias en todos los datos solicitados 
    por teclado
4.  Documentar el codigo en procedimientos, variables y/o lineas importantes
*/

#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <stdio.h>

using namespace std;

struct ProductoNodo {
  string nombre;
  float precio;
  int cantidad;
  struct ProductoNodo *siguiente_producto;
};

// PROTOTIPADO DE FUNCIONES ////////////////////////////////////////////////////////////
void mostrarMenu();
void agragarProducto(ProductoNodo *&lista, string nombre, float precio, int cantidad);
void eliminarProducto(ProductoNodo *&lista, string nombre);
void calcularCuenta(ProductoNodo *&lista);
////////////////////////////////////////////////////////////////////////////////////////

// CONTROL DEL MENU ////////////////////////////////////////////////////////////////////
bool salir = false;
int MAX_PRODUCTOS = 8,
    opcion_seleccionada;
////////////////////////////////////////////////////////////////////////////////////////

// CONTROL DE ARTICULOS INGRESADOS /////////////////////////////////////////////////////
string nombre_del_producto;
float precio_del_producto;
int cantidad_del_producto;
////////////////////////////////////////////////////////////////////////////////////////


int main() {

  cout << "<Nombre del negocio aqui>" << endl;

  do {
  
    mostrarMenu();
    cin >> opcion_seleccionada;

    if (opcion_seleccionada == 1) {

    } else if (opcion_seleccionada == 2) {

    } else if (opcion_seleccionada == 3) {
      
    } else if (opcion_seleccionada == 4) {
      salir = true;
      cout << "Que tanga un lino dia :)" << endl;
    } else {
      cout << "Digite una opcion valida!" << endl;
    }

  } while (salir != true)





  return 0; 
}

// FUNCIONES /////////////////////////////////////////////////////////////////
void mostrarMenu() {
  cout << "1. Ingresar un Producto" << endl;
  cout << "2. Eliminar un Producto" << endl;
  cout << "3. Calcular el total a pagar" << endl;
  cout << "4. Salir" << endl;
  cout << "Ingrese una opcion valida: ";
}


/////////////////////////////////////////////////////////////////////////////
