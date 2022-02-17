#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

void copia(char *, char *);

int main()
{
  char uno[20];
  char dos[20];

  cout << "Dame una cadena:" << endl;
  gets(uno);

  // prototipo
  copia(uno, dos);

  cout << endl
       << endl
       << "La copia es: " << dos;

  return 0;
}

void copia(char *primera, char *segunda)
{
  int cont = 0;

  while (*primera != '\0')
  {
    cont = cont + 1;
    cout << cont << endl;
    cout << *primera << endl;
    *segunda++ = *primera++;
  }
  *segunda = '\0';
}

/*
#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

void copia (char [], char []);

int main()
{
char uno[20];
char dos[20];

cout<<"Dame una cadena#1:"<<endl;
gets(uno);




//prototipo
copia(uno, dos);



cout<<endl<<endl<<"contenido de las cadena copiada es: "<<dos<<endl;



return 0;
}



void copia (char cadena1[], char cadena2[])
{
strcpy (cadena2,cadena1);
}
*/