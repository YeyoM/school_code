#include <stdio.h>
#include <math.h>
#include <string.h>

int hexDec(char cad[], int indice, int i);

int main() {
  char cad[]="8F3";
  int k = hexDec(cad, strlen(cad) - 1,0);
  printf("%s - %d", cad, k);
  return 0;
}

int hexDec(char cad[], int indice, int i){
  char hex[]="0123456789ABCDEF";
  int res, num;
  if (indice>=0){
    for (int j = 0; j < strlen(hex); j++){
      if (cad[indice] == hex[j]){
        num = j; break;
      }
    }
    res = num * pow(16, i) + hexDec(cad, indice - 1, i + 1);
  }
  else {
    res = 0;
  } 
  return res;
}
