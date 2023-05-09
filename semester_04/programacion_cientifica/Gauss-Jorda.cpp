/*
Universidad Autonoma de Aguascalientes
Centro de Ciencias Básicas
Departamento de Ciencias de la computación
Programación cientifica
Diego Emilio Moreno Sanchéz
Diego Emanuel Saucedo Ortega
Carlos Daniel Torres Macías

Se va a crear un programa que ejecute la evaluación 
del método Gaussiano para el siguiente sistema
 de ecuaciones lineales.  
 
 -x1 + x2 - x3 = -1
4x1 - 2x2 + 2x3 = 0
-3x1 - 2x2 = -133

Se debe desplegar un menú para ejecutar el método y una opción 
para salir del sistema. 

Al seleccionar ejecutar el método el usuario debe proporcionar : 
la dimensión del sistema y los coeficientes necesarios del sistema 
Una vez realizada cualquier operación  debe regresar al menú principal. 
Al salir debe detener el programa y luego regresar el control al sistema inicial. 
*/

#include <iostream>
#include <cmath>

using namespace std;
void menu();
void menu(){
    cout << "1. Ejecutar metodo" << endl;
    cout << "2. Salir" << endl;
    cout << "Ingrese una opcion: ";
}

int main(){
    int opcion;
    do{
    menu();
    cin >> opcion;
    if (opcion == 1){
        int n;
        float a[n][n+1], x[n], pivot, factor;
        int i, j, k;

        // Entrada de dimension del sistema
        cout << "Ingrese la dimension del sistema: ";
        cin >> n;

        // Entrada de coeficientes de las ecuaciones
        cout << "Ingrese los coeficientes de las ecuaciones:" << endl;
        for (i = 0; i < n; i++)
        {
                cout << "Ingrese ecuacion " << i+1 << ": " << endl;
            
            for (j = 0; j < (n+1); j++)
            {
                if (j == n)
                {
                    cout << "Ingrese el resultado: ";
                }
                else
                {
                    cout << "Ingrese el coeficiente de x" << j + 1 << ": ";
                }
                cin >> a[i][j];

            }
        }
        // Eliminacion Gaussiana
        for (k = 0; k < 3; k++)
        {
            pivot = a[k][k];
            for (j = k; j < 4; j++)
            {
                a[k][j] /= pivot;
            }
            for (i = k + 1; i < 3; i++)
            {
                factor = a[i][k];
                for (j = k; j < 4; j++)
                {
                    a[i][j] -= factor * a[k][j];
                }
            }
        }

        // Sustitucion hacia atros
        for (i = 2; i >= 0; i--)
        {
            x[i] = a[i][3];
            for (j = i + 1; j < 3; j++)
            {
                x[i] -= a[i][j] * x[j];
            }
        }

        // Imprimir solucion
        if (a[2][2] != 0) // sistema tiene solucion unica
        {
            cout << "La solucion del sistema es: (" << x[0] << ", " << x[1] << ", " << x[2] << ")" << endl;
        }
        else
        {
            if (a[2][3] == 0) // sistema tiene soluciones infinitas
            {
                cout << "El sistema tiene soluciones infinitas" << endl;
            }
            else // sistema no tiene solucion
            {
                cout << "El sistema no tiene solucion" << endl;
            }
        }
        system("pause");
        system("cls");
        }
        else if(opcion==2){
            cout << "Gracias por usar el programa" << endl;
        }
        else{
            cout << "Opcion invalida" << endl;
        }
        system("pause");
        system("cls");

    }while(opcion!=2);

    return 0;
}

