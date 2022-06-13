// Diego Emilio Moreno Sanchez ID: 264776

#include <iostream>
using namespace std;

// write a function that given an array of integers, returns
// the array sorted in ascending order using the bubble sort algorithm
void bubbleSort(int arr[], int n) {
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n - 1; j++) {
      if(arr[j] > arr[j + 1]) {
        int temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }
}

int main() {
  
  int arr[] = {5, 4, 3, 2, 1};
  int n = sizeof(arr) / sizeof(arr[0]);

  for(int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }

  cout << endl;

  bubbleSort(arr, n);

  for(int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
  
  return 0;
}