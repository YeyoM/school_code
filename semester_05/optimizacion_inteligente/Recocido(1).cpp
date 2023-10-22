#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string>
using namespace std;

int x[25] = {5, 7, 5, 4, 3, 4, 2, 1, 1, 3, 6, 7, 6, 4, 1, 1, 4, 7, 9, 8, 10, 11, 10, 13, 12};
int y[25] = {4, 4, 6, 3, 6, 5, 4, 3, 5, 2, 3, 7, 1, 1, 7, 7, 7, 2, 2, 5, 4, 1, 7, 6, 8};

int distancia(int individuo[25])
{
    int distancia = 0;
    for (int i = 0; i < 24; i++)
    {
        distancia += sqrt(pow(x[individuo[i]] - x[individuo[i + 1]], 2) + pow(y[individuo[i]] - y[individuo[i + 1]], 2));
    }
    return distancia;
}

void mutar(int individuo[25],float tk)
{
    int pos1 = rand() % 25;
    int pos2 = rand() % 25;
    int aux[25];
    for (int i = 0; i < 25; i++)
    {
        aux[i] = individuo[i];
    }
    swap(aux[pos1], aux[pos2]);
    if (distancia(aux) < distancia(individuo))
    {
        for (int i = 0; i < 25; i++)
        {
            individuo[i] = aux[i];
        }
    }
    else
    {
        int prob = exp((distancia(individuo) - distancia(aux)) / tk);
        int n = rand() % 1;
        if (prob > n)
        {
            for (int i = 0; i < 25; i++)
            {
                individuo[i] = aux[i];
            }
        }
    }
}

void CrearIndividuo()
{
    int Individuo[25];
    srand(time(NULL));
    int valores_disponibles[25];
    for (int i = 0; i < 25; i++) {
        valores_disponibles[i] = i;
    }
    // Generar el individuo aleatorio sin repetir valores
    for (int i = 0; i < 25; i++) {
        int indice_aleatorio = rand() % (25 - i); // Elegir un Ã­ndice aleatorio entre los valores disponibles
        Individuo[i] = valores_disponibles[indice_aleatorio]; // Agregar el valor al individuo como cadena
        swap(valores_disponibles[indice_aleatorio], valores_disponibles[24 - i]); // Mover el valor usado al final
    }
    for(int i=0;i<25;i++)
    {
        cout<<Individuo[i]<<" ";
    }
    cout<<endl;
    
    //parte enfriamiento 
    float to=1000;
    float control=0.8;
    float tk;
    for(int i=0;i<2000;i++)
    {
        tk=control*(to/i+1);
        mutar(Individuo,tk);
    }
    cout<<"Distancia: "<<distancia(Individuo)<<endl;
}

int main()
{
    int opcion;
    while (true)
    {
        //crear menu 
        cout << "Viajero" << endl;
        cout << "1. Generar Individuo" << endl;
        cout << "2. Salir" << endl;
        cout << "Ingrese una opcion: ";
        cin >> opcion;

        switch (opcion)
        {
            case 1:
                CrearIndividuo();
                break;
            case 2:
                return 0; // Salir del programa
            default:
                cout << "OpciÃ³n invÃ¡lida. Intente de nuevo." << endl;
                break;
        }
    }

    return 0;
}
