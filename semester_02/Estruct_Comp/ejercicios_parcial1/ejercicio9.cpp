// autores: Cesar Donnet Hernandez Gastelum, Diego Emilio Moreno Sanchez
// 24/02/22 Estructuras Computacionales

/*
  Ejercicio UNION DE ESTRUCTURAS Escribir un programa donde supongamos que una
  aplicación puede identificar a los usuarios mediante uno de los siguientes 
  posibles cinco datos:
  • NIF: ocho dígitos seguidos de una letra. (Normas de información financiera)
  • CIF: letra seguida de 8 dígitos. (Cédula de identificación fiscal)
  • Pasaporte: ocho letras y/o números.
  • NIE: letra seguida de 7 dígitos y una segunda letra. (Número de Identidad de 
    Extranjero)
  • Nombre de usuario: cadena de texto de hasta 16 letras. 

  De acuerdo con la estructura anterior generar un programa que guarde la información 
  de 5 usuarios, donde aparezca un menú y muestre cual opción de identificación desea 
  elegir para cada usuario (elegir solo una manera).
  Por ejemplo, un usuario podrá elegir entre NIF, CIF, Pasaporte, NIE, ó username.
  Obviamente solo se capturará una identificación para cada usuario y también puede 
  ser diferente para cada uno de los 5 usuarios. Por último, imprimir todos los usuarios 
  en forma organizada de acuerdo con el tipo de identificación que comparten y el 
  subíndice que se les asigno en el arreglo
*/

#include <iostream>

using namespace std;

union ids {
  char NIF[9];
  char CIF[9];
  char NIE[9];
  char pasaporte[8];
  char username[16];
} users[5];

int opcion;
int opciones[5];

int main() {

  cout << "Registro de Usuarios" << endl;
  cout << "1) NIF" << endl;
  cout << "2) CIF" << endl;
  cout << "3) NIE" << endl;
  cout << "4) Pasaporte" << endl;
  cout << "5) Username" << endl;


  for (int i = 0; i < 5; i++) {
    cout << "Ingrese la opcion de identificacion para el usuario " << i + 1 << ": ";
    cin >> opcion;
    cout << endl;
    if (opcion == 1) {
      cout << "Ingrese los 9 digitos del NIF: ";
      cin >> users[i].NIF;
      cout << endl;
      opciones[i] = 1;
    } else if (opcion == 2) {
      cout << "Ingrese los 9 digitos del CIF: ";
      cin >> users[i].CIF;
      cout << endl;
      opciones[i] = 2;
    } else if (opcion == 3) {
      cout << "Ingrese los 9 digitos del NIE: ";
      cin >> users[i].NIE;
      cout << endl;
      opciones[i] = 3;
    } else if (opcion == 4) {
      cout << "Ingrese el pasaporte: ";
      cin >> users[i].pasaporte;
      cout << endl;
      opciones[i] = 4;
    } else if (opcion == 5) {
      cout << "Ingrese el username: ";
      cin >> users[i].username;
      cout << endl;
      opciones[i] = 5;
    }
  }

  cout << endl;
  cout << "No. de Usuario        Identificacion         Dato de Identificaion" << endl;
  cout << endl;
  for(int i = 0; i < 5; i++) {
    cout << i + 1 << "                        ";
    if (opciones[i] == 1) {
      cout << "NIF                   " << users[i].NIF;
    } else if (opciones[i] == 2) {
      cout << "CIF                   " << users[i].CIF;
    } else if (opciones[i] == 3) {
      cout << "NIE                   " << users[i].NIE;
    } else if (opciones[i] == 4) {
      cout << "Pasaporte             " << users[i].pasaporte;
    } else if (opciones[i] == 5) {
      cout << "Username             " << users[i].username;
    }
    cout << endl;
  }
  
  return 0;
}
