#include <iostream>
#include <stdio.h>
#include <locale.h>

using namespace std;

int edad = 0;
bool ver = false;

int main(){
    setlocale(LC_ALL,"");
    do {
        cout << "Ingrese su edad" << endl;
        cin >> edad;
        if (edad <= 0 || edad > 150) {
            cout << "Edad no valida" << endl;
        } else if (edad <= 10) {
            cout << "ni" << "\u00D1" << "o" << endl;
            ver = true;
        } else if (edad > 65) {
            cout << "jubilado" << endl;
            ver = true;
        }
    } while (ver == false);
    
    return 0;
}