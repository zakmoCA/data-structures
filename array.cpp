#include <iostream>
using namespace std;


void populateArray(int arr[], int size, int start, int end) {
  if (end - start + 1 > size) {
    cout << "Error: range is greater than array size.";
    return;
  }

  for (int i = 0;  i < size && start <= end; ++i, ++start) {
    arr[i] = start;
  }
}

int main() {
  int myArr[10];
  int myArrSize = 10;
  
  populateArray(myArr, 10, 1, 10);
  for (int i = 0; i < myArrSize; ++i) {
    cout << myArr[i] << " ";
  }
  return 0;
}