#include <iostream>
using namespace std;

void shellSort(int array[], int size) {
  int gap, j, k;
   for(gap = size / 2; gap > 0; gap = gap / 2) {       
      //initially gap = n/2, decreasing by gap /2
      for(j = gap; j < size; j++) {
         for(k = j-gap; k>=0; k -= gap) {
            if(array[k+gap] >= array[k])
               break;
            else
               swap(array[k+gap], array[k]);
         }
      }
   }
}

// Print an array
void printArray(int array[], int size) {
  int i;
  for (i = 0; i < size; i++)
    cout << array[i] << " ";
  cout << endl;
}

// Driver code
int main() {
  int data[] = {9, 8, 3, 7, 5, 6};
  int size = sizeof(data) / sizeof(data[0]);
  shellSort(data, size);
  cout << "Sorted array: \n";
  printArray(data, size);
}