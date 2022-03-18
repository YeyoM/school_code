
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
4.  Documentar el c�digo en procedimientos, variables y/o l�neas importantes
*/

#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <stdio.h>

using namespace std;

struct name {
  string nombre;
  name* sig;
};

struct cant {
  int cantidad;
  cant* sigui;
};
struct presio {
  float precio;
  presio* siguiente;
};

void Insertargeneral(name*&, string);
void insertarderivado112(cant*&, int);
void insertarderivado2(presio*&, float);

name* list = NULL;
cant* lis = NULL;
presio* li = NULL;
string a;
int n;
float n2;

int main() {
  int f;
  cout << "Cuantos productos deseas registrar?\n";
  cin >> f;
  for (int i = 0; i < f; i++) {
    cout << "Digite el nombre de su producto: ";
    cin >> a;
    cout << "\nDigite la cantidad de productos: ";
    cin >> n;
    cout << "\nDigite el precio: ";
    cin >> n2;
    Insertargeneral(list, a);
    insertarderivado112(lis, n);
    insertarderivado2(li, n2);	
	}  
}
void Insertargeneral(name*& list, string nombre2) {
    name* nuevo = new name();
    nuevo->nombre = nombre2;
    name* aux1 = list;
    name* aux2;
    while ((aux1 != NULL)) {
        aux2 = aux1;
        aux1 = aux1->sig;
   }
    if (list == aux1) {
        list = nuevo;
    }
    else {
        aux2->sig = nuevo;
    }
    nuevo->sig = aux1;
    cout << "Se inserto el nombre de " << nombre2 << endl;
    

}
void insertarderivado112(cant*& lis, int canti) {
    cant* nuevecito = new cant();
    nuevecito->cantidad = canti;
    cant* au = lis;
    cant* aux;
    while ((au != NULL)) {
        aux = au;
        au = au->sigui;
    }
    if (lis == au) {
        lis = nuevecito;
    }
    else {
        aux->sigui = nuevecito;
    }
    nuevecito->sigui = au;
    cout << "Se inserto el valor de " << canti << endl;
}
void insertarderivado2(presio*& li, float precio) {
    presio* nuez = new presio();
    nuez->precio = precio;
    presio* aux3 = li;
    presio* aux4;
    while ((aux3 != NULL)) {
        aux4 = aux3;
        aux3 = aux3->siguiente;
    }
    if (li == aux3) {
        li = nuez;
    }
    else {
        aux4->siguiente = nuez;
    }
    nuez->siguiente = aux3;
    cout << "Se inserto el valor de " << precio << endl;
}
