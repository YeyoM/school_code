#include <iostream>
using namespace std;

/**
 * It returns the number of ways to choose k elements from a set of n elements
 * 
 * @param n number of elements
 * @param k the number of elements to choose from the set
 * 
 * @return The number of combinations of n elements taken k at a time.
 */
int misterio(int n, int k) {
  int y1, y2, aux;
  if (k == 0 || n == k) {
    aux = 1;
  } else {
    y1 = misterio(n - 1, k);
    y2 = misterio(n - 1, k - 1);
    aux = y1 + y2;
  }
  return aux;
}

int misterio2(int a, int b) {
  cout << "a: " << a << endl;
  int aux;
  if(a == 1) {
    aux = b;
  } else {
    if(a % 2 == 0) {
      aux = misterio2(a/2, b*2);
    } else {
      aux = misterio2(a/2, b*2) + b;
    }
  }
  return aux;
}

int main() {
  int n = 5, k = 4;
  cout << "El resultado es: " << misterio2(n, k) << endl;
  return 0;
}