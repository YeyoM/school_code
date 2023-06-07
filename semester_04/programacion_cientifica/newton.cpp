#include <iostream>
using namespace std;

// Función para calcular el valor interpolado utilizando el método de interpolación de Newton
double interpolacionNewton(int n, double x[], double y[], double xint) {
    double f_xint = y[0]; // Valor inicial para f(xint)
    
    // Crear tabla de diferencias
    int m = n - 1;
    double T[m][m];

    for (int i = 0; i <= (m - 1); i++) {
        T[i][0] = (y[i + 1] - y[i]) / (x[i + 1] - x[i]);
    }

    int j = 1;
    for (int i = j; i <= (m - 1); i++) {
        while (i <= (m - 1)) {
            T[i][j] = (T[i][j - 1] - T[i - 1][j - 1]) / (x[i + 1] - x[i - j]);
            i++;
        }
        j++;
    }

    // Calcular el valor interpolado
    for (int i = 0; i <= (n - 1); i++) {
        double p = 1;
        for (int j = 0; j <= i; j++) {
            p *= (xint - x[j]);
        }
        f_xint += T[i][i] * p;
    }

    // print table
    cout << "Tabla de diferencias divididas:" << endl;
    for (int i = 0; i <= (m - 1); i++) {
        for (int j = 0; j <= i; j++) {
            cout << T[i][j] << "\t";
        }
        cout << endl;
    }

    // p3(x) = A0+A1(x−x0)+A2(x−x0)(x−x1)+A3(x−x0)(x−x1)(x−x2)
    // A0, A1, A2, A3 = y0, T[0][0], T[1][1], T[2][2]
    // f(xint) = y0 + T[0][0](xint - x0) + T[1][1](xint - x0)(xint - x1) + T[2][2](xint - x0)(xint - x1)(xint - x2)

    return f_xint;
}

int main() {
    int n;
    cout << "Ingrese el número de coordenadas: ";
    cin >> n;

    double x[n];
    double y[n];

    cout << "Ingrese los datos (x, y):" << endl;
    for (int i = 0; i < n; i++) {
        cout << "x[" << i << "]: ";
        cin >> x[i];
        cout << "y[" << i << "]: ";
        cin >> y[i];
    }

    double xint;
    cout << "Ingrese el valor que desea interpolar (xint): ";
    cin >> xint;

    // Calcular el valor interpolado utilizando el método de interpolación de Newton
    double resultado = interpolacionNewton(n, x, y, xint);

    cout << "f(xint) = " << resultado << endl;

    return 0;
}