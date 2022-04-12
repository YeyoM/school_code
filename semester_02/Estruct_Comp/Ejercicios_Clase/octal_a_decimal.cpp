#include <stdio.h>
#include <math.h>

int octal(int n, int i);

int main(){
  int k = octal(114, 0);
  printf("En octal es %d",k);
  return 0;
}
int octal(int n, int i){
  int coc, residuo, res;
  coc = n / 8;
  residuo = n % 8;
  if (coc != 0){
    res = residuo * pow(10, i) + octal(coc, i + 1);
  }
  else {
    res = residuo * pow(10, i);
  }
  return res;
}