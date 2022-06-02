#include <iostream>
#include <stdlib.h>

using namespace std;

int main() {
	const int n = 9;
	int i, inf, sup, mitad, dato;
	bool encontrado = false;
	int numeros[n] = {2,3,4,6,7,12,22,45,100};

	cout << "Vector: ";
	for (i = 0; i < n; i++) {
		cout << numeros[i] << " ";
	}

	cout << "Introduzca el numero a buscar: ";
	cin >> dato;
	
	inf = 0;
	sup = n - 1;
	while (inf <= sup && !encontrado) {
		mitad = (inf + sup) / 2;
		if (dato == numeros[mitad]) {
			encontrado = true;
		} else if {
			if (dato < numeros[mitad]) {
				sup = mitad - 1;
			} else {
				inf = mitad + 1;
			}
		} else {
			cout << "El numero no se encuentra en el vector" << endl;
			break;
		}
	}
	
	cout << "El numero " << dato << " se encuentra en la posicion " << mitad << endl;

}

