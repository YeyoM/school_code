#include <iostream>
#include <time.h>
using namespace std;

//* 3. Cruzar los bits de las cadenas 
  /**
   * a. Se compara la cadena i con la cadena n - i (n = 10 en este ejercicio)
   * b. Se divide la cadena i en dos partes (iguales o no)
   * c. Se divide la cadena n - i en dos partes (iguales o no)
   * d. Se intercambian las partes de las cadenas, ej.
   *   i     = 1010101010 -> a. 10101 b. 01010
   *   n - i = 0101010101 -> c. 01010 d. 10101
   *   nuevaCadena1 = a + d = 1010110101
   *   nuevaCadena2 = c + b = 0101001010
   * e. Se comparan las cadenas nuevaCadena1, nuevaCadena2, i, n - i
   * f. La que tenga el menor número de 1's es la mejor
   * g. Se repite el bucle para las demas cadenas usando a i como iterador 
  */
string cruzamientoBits(string first, string second){
  // Esta es la cadena que se va a retornar
  string mejorCadena = "";
  // cout << "Cadena 1: " << first << endl;
  // cout << "Cadena 2: " << second << endl;

  // Dividimos los strings en 4 partes
  // string a = first.substr(0, 5);
  // string b = first.substr(5, 5);
  // string c = second.substr(0, 5);
  // string d = second.substr(5, 5);

  // Para evitar que pasen las cosas raras de que
  // las mejores cadenas son las mismas que la generación anterior
  // lo que podemos hacer es generar de manera aleatoria los
  // rangos en que dividimos las cadenas
  // podria ser 5 y 5, 4 y 6, 3 y 7
  // Queda algo de la siguiente manera:
  
  // Obtener un numero aleatorio entre 5, 6 y 7
  int rango = rand() % 3 + 5;
  // Dividimos las cadenas en 2 partes
  string a = first.substr(0, rango);
  string b = first.substr(rango, 10 - rango);
  string c = second.substr(0, rango);
  string d = second.substr(rango, 10 - rango);

  // Se hace el cruzamiento de bits
  string nuevaCadena1 = a + d;
  string nuevaCadena2 = c + b;

  // Se hace el conteo de 1's con array
  // Solo hijos
  int conteo1s[2] = {0, 0};
  // Con padres
  // int conteo1s[4] = {0, 0, 0, 0};

  for(int i = 0; i < nuevaCadena1.length(); i++){
    if(nuevaCadena1[i] == '1'){
      conteo1s[0]++;
    } else if(nuevaCadena2[i] == '1'){
      conteo1s[1]++;
    } /*else if(first[i] == '1'){
      conteo1s[2]++;
    } else if(second[i] == '1'){
      conteo1s[3]++;
    } */
  }

  // Se compara el numero de 1's
  int menor = conteo1s[0];
  for(int i = 0; i < 2; i++){
    if(conteo1s[i] < menor){
      menor = conteo1s[i];
    }
  }

  // Con padres
  // int menor = conteo1s[0];
  // for(int i = 0; i < 4; i++){
  //   if(conteo1s[i] < menor){
  //     menor = conteo1s[i];
  //   }
  // }

  // Se retorna la cadena con el menor numero de 1's
  if(menor == conteo1s[0]){
    mejorCadena = nuevaCadena1;
  } else if(menor == conteo1s[1]){
    mejorCadena = nuevaCadena2;
  } /*else if(menor == conteo1s[2]){
    mejorCadena = first;
  } else if(menor == conteo1s[3]){
    mejorCadena = second;
  } */

  // cout << "Padre 1:      " << first << endl;
  // cout << "Padre 2:      " << second << endl;
  // cout << "Hijo 1:       " << nuevaCadena1 << endl;
  // cout << "Hijo 2:       " << nuevaCadena2 << endl;
  // cout << "Mejor cadena: " << mejorCadena << endl;

  return mejorCadena;

}

int main() {

  // Se inicializa el generador de numeros aleatorios
  srand(time(NULL));

  //*Secuencia del algoritmo

  //* 1. Generar las cadenas de 10 bits aleatorios
  // Generar 10 cadenas de 10 bits aleatorios
  // string cadenas[10];
  // for(int i = 0; i < 10; i++){
  //   string cadena = "";
  //   for(int j = 0; j < 10; j++){
  //     // Generar un numero aleatorio entre 0 y 1
  //     int numero = rand() % 2;
  //     // Convertir el numero a string
  //     string numeroString = to_string(numero);
  //     // Concatenar el numero a la cadena
  //     cadena += numeroString;
  //   }
  //   // Agregar la cadena al array de cadenas
  //   cadenas[i] = cadena;
  // }
  // // mostrar las cadenas
  // for(int i = 0; i < 10; i++){
  //   cout << "Cadena " << i + 1 << ": " << cadenas[i] << endl;
  // }

  // Para prueba usamos 10 cadenas ya definidas para un mejor control
  string cadenas[10] = {
    "0110000101", 
    "1000001010", 
    "1011011000", 
    "0010100111", 
    "1001010011", 
    "0001001101", 
    "0110101100", 
    "1100010001", 
    "1000111010", 
    "0101001101"
  };

  // Usar una matrix de 10x10 para guardar las siguientes generaciones
  string matriz[10][10] {};

  //* 4. Se repite el algoritmo 10 vecessss
  for(int i = 0; i < 10; i++){
    for(int j = 0; j < 10; j++){
      if (i == 0) {
        // Se hace el cruzamiento de bits con la primer generacion
        matriz[i][j] = cruzamientoBits(cadenas[j], cadenas[9 - j]);
      } else {
        // Se hace el cruzamiento de bits con la generation anterior
        matriz[i][j] = cruzamientoBits(matriz[i - 1][j], matriz[i - 1][9 - j]);
      }
    }
  }

  //* Mostrar la matriz
  for(int i = 0; i < 10; i++){
    for(int j = 0; j < 10; j++){
      cout << matriz[i][j] << " ";
    }
    cout << endl;
  }

  return 0;
}