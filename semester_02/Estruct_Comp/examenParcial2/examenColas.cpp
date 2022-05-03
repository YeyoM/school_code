// Alumno -> Diego Emilio Moreno Sanchez
// ID -> 264776
// Fecha ->02/05/2022
// Ejercicio 2 Examen Parcial 2

/*
  Explicacion del ejercicio (Programa de Colas):

  - Realizar un programa que utilice el algoritmo de COLAS CIRCULARES.
  - La Lista para la cola será de tipo string
  - Simular la lista para 10 para que te da la posibilidad de capturar 
    hasta 10 elementos
  - Ingresar a la cola circular 6 palabras que pueden ser FOTO1, 
    FOTO2, FOTO3 … FOTO6 o CANCION1, CANCION2, CANCION3 … CANCION6 o 
    VIDEO1, VIDEO2, VIDEO3 … VIDEO6, o DIAPOSITIVA1, DIAPOSITIVA2, 
    DIAPOSITIVA3 … DIAPOSITIVA6, pensando por ejemplo en un álbum de 
    fotos, un reproductor de música o de video, una presentación de 
    power point respectivamente. Este primer procedimiento de ingresar 
    6 palabras es automático, es decir, programa desde el código hará 
    las primeras inserciones respetando el algoritmo de la cola circular.
  - El programa se controla con un menú con las opciones 
    1. Siguiente 
    2. Anterior 
    3. Ingresar dato 
    4. Salir
  - El programa empieza imprimiendo la primera palabra de la cola, 
    si ingresas 1 imprime la palabra que sigue, si ingresas 2 imprime la 
    palabra anterior. Importante si llegas al elemento de la 
    lista(recordar que solo 10) donde está la última palabra e ingresan 1 
    entonces imprimir la primera palabra de la cola, si estas en la primera
    palabra e ingresan un 0 debes imprimir la última palabra de la 
    cola(que no necesariamente es la que está en la última casilla, porque 
    recuerda que la cola empieza con solo 6 palabras aunque la capacidad de 
    la lista es de 10 palabras).
  - Ingresar un 3 debe permitir agregar una nueva palabra a la cola, 
    considerar el mensaje de “cola llena” cuando así sea.
  - Este problema de cola circular no incluye eliminaciones.
*/

/*
  PLANTEAMIENTO DE LA SOLUCION:
  
  - La idea con la que resuelvo el problema es implementar la cola circular
    con una lista doblemente enlazada, de esta forma es mas sencillo implementar
    la funcionalidad de ir hacia atras o hacia delante usando los apuntadores 
    siguiente y anterior.
  - Para ir agregando elementos a la cola, antes que nada se hace el algoritmo 
    de la cola circular, es decir, si la cola esta llena, no se puede agregar 
    mas elementos con las restricciones correspondientes.
  - Una vez que revisemos que se pueda agregar un elemento a la cola, se procede
    a agregarlo, esto se hace con una lista doblemente enlazada, el elemento
    que se agregue se agrega al final de la lista, y el apuntador siguiente apunta
    al primer elemento de la lista y su apuntador a anterior apunta al ultimo 
    elemento de la lista. 
  - Esto con la finalidad de hacer muy sencillas las funcionalidades de ir 
    al siguiente elemento e ir al elemento anterior.
*/

// Librerias ===================================================================
#include <iostream>
#include <stdbool.h>
using namespace std;

// Nodo ========================================================================
struct Nodo {
  string dato;
  struct Nodo *siguiente;
  struct Nodo *anterior;
};

// Prototipos ==================================================================
void menu();
void insertarDato(Nodo *&inicio, Nodo *&fin, string dato, int &MAX, int &contadorFin, int &contadorInicio);
void mostrarActual(Nodo *actual);
void moverSiguiente(Nodo *&actual);
void moverAnterior(Nodo *&actual);

// Variables Globales ==========================================================
int MAX = 10;
int opcion;
bool salir = false;
int contadorFin = -1;
int contadorInicio = -1;
string dato;

// Programa Principal ==========================================================
int main() {

  /* Inicializamos los apuntadores de los nodos, tanto el inicio como el final */
  Nodo *inicio;
  inicio = NULL;

  Nodo *fin;
  fin = NULL;

  /* Ingresamos los primeros 6 elementos */
  insertarDato(inicio, fin, "FOTO1", MAX, contadorFin, contadorInicio);
  insertarDato(inicio, fin, "FOTO2", MAX, contadorFin, contadorInicio);
  insertarDato(inicio, fin, "FOTO3", MAX, contadorFin, contadorInicio);
  insertarDato(inicio, fin, "FOTO4", MAX, contadorFin, contadorInicio);
  insertarDato(inicio, fin, "FOTO5", MAX, contadorFin, contadorInicio);
  insertarDato(inicio, fin, "FOTO6", MAX, contadorFin, contadorInicio);

  /* Creamos un apuntador a un nodo con nombre de actual */
  /* Este sera el que usemos para recorrer toda la cola  */
  /* Inicialmente apuntara al inicio de la cola          */
  Nodo *actual;
  actual = inicio;

  do {
    system("cls");
    /* Mostramos el nodo actual */
    mostrarActual(actual); 
    /* Mostramos el menu */
    menu();
    cout << "Ingrese una opcion: ";
    cin >> opcion;
    if (opcion == 1) {
      /* Movemos el nodo actual una posicion hacia delante */
      moverSiguiente(actual);
    } else if (opcion == 2) {
      /* Movemos el nodo actual una posicion hacia atras */
      moverAnterior(actual);
    } else if (opcion == 3) {
      /* Ingresamos un nuevo dato */
      cout << "Ingrese un dato: ";
      cin >> dato;
      insertarDato(inicio, fin, dato, MAX, contadorFin, contadorInicio);
    } else if (opcion == 4) {
      salir = true;
    } else {
      cout << "Opcion no valida" << endl;
    }
    mostrarActual(actual);
  } while (!salir);
  return 0;
}

// Funciones ===================================================================
void menu() {
  cout << "1. Siguiente" << endl;
  cout << "2. Anterior" << endl;
  cout << "3. Ingresar dato" << endl;
  cout << "4. Salir" << endl;
}

void insertarDato(Nodo *&inicio, Nodo *&fin, string dato, int &MAX, int &contadorFin, int &contadorInicio) {
  /* Hacemos la verificacion para saber si podemos agregar elementos */
  if(((contadorFin == (MAX - 1)) && (contadorInicio == 0)) || ((contadorFin + 1) == contadorInicio)) {
    cout << "Cola llena" << endl;
    system("pause");
  } else {
    if (contadorFin == (MAX - 1)) {
      contadorFin = 0;
    } else {
      contadorFin++;
    }
    /* verificamos si el nodo a ingresar es el primero */
    if (inicio == NULL || fin == NULL) {
      /* Creamos un nuevo nodo */
      Nodo *nuevo_nodo = new Nodo;
      nuevo_nodo -> dato = dato;
      /* Asignamos los apuntadores */
      nuevo_nodo -> siguiente = NULL;
      nuevo_nodo -> anterior = NULL;
      /* Ponemos que inicio y fin apuntan al mismo nodo */
      inicio = nuevo_nodo;
      fin = nuevo_nodo;
    } else {
      /* Creamos un nuevo nodo */
      Nodo *nuevo_nodo = new Nodo;
      nuevo_nodo -> dato = dato;
      /* Asignamos los apuntadores */
      fin -> siguiente = nuevo_nodo;    /* apuntamos al nuevo nodo */
      nuevo_nodo -> anterior = fin;     /* apuntamos al nodo final */
      nuevo_nodo -> siguiente = inicio; /* apuntamos al nodo inicial */
      inicio -> anterior = nuevo_nodo;  /* apuntamos al nodo anterior */
      fin = nuevo_nodo;                 /* hacemos que ahora el final sea el nuevo */
    }
    if ((contadorFin == 0) && (contadorInicio == -1)) {
      contadorInicio = 0;
    }
  }
}

void mostrarActual(Nodo *actual) {
  /* Mostramos el dato del nodo actual */
  cout << "Actual: " << actual -> dato << endl;
}

void moverSiguiente(Nodo *&actual) {
  /* Movemos el nodo a siguiente */
  if (actual == NULL) {
    cout << "Cola vacia" << endl;
  } else {
    actual = actual -> siguiente;
  }
}

void moverAnterior(Nodo *&actual) {
  /* Movemos el nodo a anterior */
  if (actual == NULL) {
    cout << "Cola vacia" << endl;
  } else {
    actual = actual -> anterior;
  }
}


