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
1.  Realizar el ejercicio con el uso de Listas simples o doblemente 
    enlazadas (seg�n consideren, es indistinto ya que cada estructura 
    tiene sus ventajas o desventajas)
2.  Integrar funciones y/o procedimientos para la distribuci�n del c�digo
3.  Realizar las validaciones necesarias en todos los datos solicitados 
    por teclado
4.  Documentar el codigo en procedimientos, variables y/o lineas importantes

*/

#include  <iostream>
#include  <stdlib.h>
#include  <string.h>
#include  <conio.h>
#include  <stdio.h>
#include  <time.h>

using namespace std;

// ESTRUCTURA DEL PRODUCTO ///////////////////////////////////////////
struct Producto {
  string nombre;
	int cantidad;
	float precio;
  Producto* siguiente_producto;
};

// ELIMINAR UN PRODUCTO DE LA LISTA /////////////////////////////////
void eliminarProducto(Producto *&lista_productos, string nombre) {

  // VERIFICAMOS QUE LA LISTA NO ESTE VACIA
	if (lista_productos != NULL) {
		Producto* aux_borrar;
		Producto* anterior = NULL;
		aux_borrar = lista_productos;
    // RECORREMOS LA LISTA HASTA QUE ENCONTREMOS EL NOMBRE DEL PRODUCTO
		while ((aux_borrar != NULL) && (aux_borrar -> nombre != nombre)) {
			anterior = aux_borrar;
			aux_borrar = aux_borrar -> siguiente_producto;
		}
    // CASO EN QUE NO LO ENCONTREMOS
		if (aux_borrar == NULL) {
			cout << "El nombre escrito no ha sido encontrado\n";
		}
    // EN CASO DE QUE ESTE AL INICIO DE LA LISTA
		else if (anterior == NULL) {
			lista_productos = lista_productos -> siguiente_producto;
			delete aux_borrar;
		}
    // EN CASO CONTRARIOO, ESTE EN MEDIO O AL FINAL
		else {
			anterior -> siguiente_producto = aux_borrar -> siguiente_producto;
			delete aux_borrar;
		}
	}
}

// INSERTAR UN PRODUCTO A LA LISTA /////////////////////////////////////
void insertarProducto(Producto *&lista, string _nombre, float _precio, int _cantidad) {

  // GENERAMOS EL PRODUCTO
  Producto* nuevo   = new Producto();
	nuevo -> nombre   = _nombre;
	nuevo -> cantidad = _precio;
	nuevo -> precio   = _cantidad;

	Producto* aux = lista;
	Producto* aux2 = 0;

  // RECORREMOS LA LISTA
	while (aux != NULL) {
		aux2 = aux;
		aux = aux -> siguiente_producto;
	}
  // ASIGNAMOS EL PRODUCTO A LA LISTA
	if (lista == aux) {
		lista = nuevo;
	}
	else {
		aux2 -> siguiente_producto = nuevo;
	}
	nuevo -> siguiente_producto = aux;
}

// MOSTRAR LA LISTA ACTUAL DE PRODUCTOS //////////////////////////////////
void mostrarLista(Producto* lista) {

  // GENERAMOS EL PRODUCTO QUE VA A RECORRER LA LISTA
	Producto* producto_actual = new Producto();
	producto_actual = lista;

  // AQUI GUARDAREMOS CANTIDADES IMPORTANTES PARA EL TOTAL
	int suma_total = 0, 
      aux = 0;

  // MIENTRAS RECORREMOS VAMOS IMPRIMIENDO LA LISTA
	while (producto_actual != NULL) {
		aux = (producto_actual -> cantidad * producto_actual -> precio);
		suma_total += aux;
		cout << producto_actual -> nombre << " \t " << producto_actual -> cantidad << "\t\t " << producto_actual -> precio << "\t" << aux << "\n";
		producto_actual = producto_actual -> siguiente_producto;
	}

  // MOSTRAMOS EL TOTAL 
	cout << "\n\t\t\t" << "Total general: " << suma_total << "\n\n";
}

// MAIN ///////////////////////////////////////////////////////////////////
int main() {

  // INICIALIZACION DE LA LISTA 
	Producto* lista = NULL;

  // VARIABLES PARA INGRESAR, ELIMINAR O MOSTRAR PRODUCTOS 
	string nombre_producto;

	int cantidad_producto,
      total_cantidad_productos,
      opcion = 1;

	float precio_producto;

  // PARA GENERAR NUMEROS ALEATORIOS 
  srand(time(NULL));

	while (opcion >= 1 && opcion <= 3) {

    // MOSTRAMOS EL MENU
		system("cls");
		cout << ">>>>>>>>>>>>>>>MENU<<<<<<<<<<<<<<\n\n";
		cout << "1.Ingresar Productos\n2.Mostrar ticket de compra\n3.Eliminar un producto de la compra\n4.Salir\nRespuesta: ";
		cin >> opcion;
		system("cls");

		switch (opcion) {

    // GENERAMOS TODOS LOS PRODUCTOS  
		case 1:
			cout << "Digite cuantos productos deseas registrar: ";
			cin >> total_cantidad_productos;
      // ITERAREMOS HASTA INGRESAR TODOS LOS PRODUCTOS
			for (int i = 0; i < total_cantidad_productos; i++) {
				system("cls");
				cout << "Digite el nombre del producto: " << i + 1 << ": ";
				cin >> nombre_producto;

        // LA CANTIDAD DE CADA PRODUCTO Y SU PRECIO SON GENERADOS ALEATORIAMENTE
				cantidad_producto = 1 + rand() % 10;
				precio_producto   = 1 + rand() % 1000;

        // LLAMAMOS A LA FUNCIO PARA INSERTAR CADA PRODUCTO
				insertarProducto(lista, nombre_producto, precio_producto, cantidad_producto);
			}
			break;

    // MOSTRAMOS TODA LA LISTA DE PRODUCTOS
		case 2:
			cout << "Nombre\t\tCantidad\t\Precio\tTotal\n\n";
			mostrarLista(lista);
			system("pause");
			break;

    // CASO PARA ELIMINAR UN PRODUCTO
		case 3:
		  cout << "Digita el nombre del producto a eliminar: ";
			cin >> nombre_producto;
		  eliminarProducto(lista, nombre_producto);
			break;

    // SALIR...
		case 4:
			cout << "Saliendo....\n";
			break;

    // OPCIONES INVALIDAS
		default:
			cout << "Esta opcion no existe...saliendo...\n";
			break;

		}
	}
  system("pause");
  return 0;
}