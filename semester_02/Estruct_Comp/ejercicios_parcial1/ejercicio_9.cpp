#include <iostream>

using namespace std;

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

union ids {
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
};

int opcion;

int main() {

  union ids usuario[5];

  usuario[1].pasaporte = "fasdf"; 

  /* cout << "Registro de Usuarios" << endl;
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
      cout << "Ingrese los 8 digitos del NIF: ";
      cin >> users[i].NIF.number;
      cout << endl;
      cout << "Ingrese la letra del NIF: ";
      cin >> users[i].NIF.nif_string;
      cout << endl;
    } else if (opcion == 2) {
      cout << "Ingrese la letra del CIF: ";
      cin >> users[i].CIF.cif_string;
      cout << endl;
      cout << "Ingrese los 8 digitos del CIF: ";
      cin >> users[i].CIF.number;
      cout << endl;
    } else if (opcion == 3) {
      cout << "Ingrese la letra inicial del NIE: ";
      cin >> users[i].NIE.prefix;
      cout << endl;
      cout << "Ingrese los 7 digitos del NIE: ";
      cin >> users[i].NIE.number;
      cout << endl;
      cout << "Ingrese la letra final del NIE: ";
      cin >> users[i].NIE.suffix;
      cout << endl;
    } else if (opcion == 4) {
      cout << "Ingrese el pasaporte: ";
      cin >> users[i].pasaporte;
      cout << endl;
    } else if (opcion == 5) {
      cout << "Ingrese el username: ";
      cin >> users[i].username;
      cout << endl;
    }
  }

  cout << endl;
  cout << "No. de Usuario        Identificacion         Dato de Identificaion" << endl;
  cout << endl;
  for(int i = 0; i < 5; i++) {
    cout << i + 1 << "        " << "Identificacion      " << endl; 
  }
  */
  return 0;
}