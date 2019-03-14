#include <iostream>

void insertion_sort(int arr[], int length) {
  int i, j;
  for (i=1; i<length; i++) {
    int tmp = arr[i];
    for (j=i; j>=1 && arr[j-1]>tmp; j--) {
      arr[j] = arr[j-1];
    }
    arr[j] = tmp;
  }
}

void shell_sort(int arr[], int length) {
  int i,j;
  for (int gap = length/2; gap > 0; gap /= 2) {
    for (i=gap; i<length; i++) {
      int tmp = arr[i];
      for (j=i; j>=gap && arr[j-gap]>tmp; j-=gap) 
        arr[j] = arr[j-gap];
      arr[j] = tmp;
    }
    //test
    //for (int i_=0; i_<10; i_++) std::cout << arr[i_];
    //std::cout << std::endl;
  }
}

int main() {
  int arr[10] = {1,3,2,4,9,8,7,6,0,5};
  shell_sort(arr, 10);
  for (int i=0; i<10; i++) std::cout << arr[i];
}