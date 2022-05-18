#include <iostream>
#include <bits/stdc++.h>
using namespace std;



int main() {
  int vector[5] = {4, 5, 1, 2, 3};

  for (int i = 0; i < 5; i++) {
    int min = i;
    for (int j = i + 1; j < 5; j++) {
      if (vector[j] < vector[min]) {
        min = j;
      }
    }
    swap(vector[min], vector[i]);
  }

  for (int i = 0; i < 5; i++) {
    cout << vector[i] << " ";
  }

  return 0;
}