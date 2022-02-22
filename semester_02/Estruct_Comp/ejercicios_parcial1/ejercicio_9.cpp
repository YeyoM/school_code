#include <iostream>

using namespace std;

/*union user_id {
  struct NIF {
    unsigned int number;
    char ch;
  } nif;
  struct CIF {
    char ch;
    unsigned int number;
  } cif;
  char passport[8];
  struct NIE {
    char prefix;
    unsigned int number;
    char suffix;
  } nie;
  char username[16];
};*/


/*union ids 
{
  struct nif {
    int nif_number;
    string nif_string;
  } nif;
  struct cif {
    int cif_number;
    string cif_string;
  } cif;
  struct nie {
    char prefix;
    int nie_number;
    char suffix;
  } nie;
  //char pasaporte[8];
  //char username[10];
};*/

/*union ids {
  struct Nif {
    int nif_number;
    string nif_string;
  };
  struct Cif {
    int cif_number;
    string cif_string;
  };
  struct nie {
    char prefix;
    int nie_number;
    char suffix;
  };
  char pasaporte[8];
  char username[10];
};*/

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