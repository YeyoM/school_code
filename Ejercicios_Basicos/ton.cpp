#include <iostream>

using namespace std;

float peso = 0;

int main() {
    cout << "Ingrese el peso en kilogramos" << endl;
    cin >> peso;
    if ( peso == 500 ) {
        cout << "El peso exactamente media tonelada";
    } else {
        if ( peso > 500 ) {
            cout << "El peso es mayor a media tonelada";
        } else {
            cout << "El peso es menor a media tonelada";
        }
    }
    return 0;
}