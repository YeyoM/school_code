//palabras palindromas a partir de un archivo.txt
#include <iostream>
#include <string>
#include <fstream>  //Libreria especifica para archivos
#include<string.h>
using namespace std;

string texto;
 int  igual = 0, x = 0;
 //edita la copia de la variable texto y la revierte
void reverseStr(string& str) {
    int n = str.length();
 
    for (int i = 0; i < n / 2; i++)
        swap(str[i], str[n - i - 1]);
}
 //comparacion de cada palabra.
void evaluar(string texto){
	string reverse;
	reverse=texto;
	reverseStr(reverse);
    for(int i = 0; i < texto.length(); i++) {
        if(texto[i] == reverse[i]) {//evalua si cada letra es igual, la variable texto que es la que leyo del archivo y la variable reverse que es la copia de texto pero invertida
            igual++;
        }
    }
    if(texto.length() == igual) { //si el contador de las veces que fue igual es indentico al tama�o de letras de la palabra entonces si es palindroma
        x= 1;
    } else {
    x= 0;
	}
	igual=0;  //reinciamos el contador;
 }

//lectura de archivos
void lectura() {
	
    string  nombreArchivo;
    ifstream archivo; // ifstream es para la lectura
    cout << "Que archivo desea abrir: (escriba el nombre del archivo seguido con .txt)"; getline(cin, nombreArchivo);
    archivo.open(nombreArchivo.c_str(), ios::in);
    if (archivo.fail()) {
        cout << "No se pudo abrir el archivo\n";
        exit(1);
    }
    cout<<"\t\tEl contenido del archivo txt es este:\n\n";
    while (!archivo.eof()) { //eof recorre todo el archivo
		getline(archivo, texto);
	    evaluar(texto);
	    
        if(x==1){
        	cout<<texto<<" es palindroma\n";
		}else{
			cout<<texto<<" no es palindroma\n";
		}
		x=0;
	
    }
    archivo.close();
}
 
int main() {
   lectura();
    return 0;
}
