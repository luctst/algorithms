/*
 * Insertion sort algorithms
 * Goal: Sort array
*/ 

#include <stdio.h>

int main() {
  int input[] = {5, 2, 4, 6, 1, 3};
  int length = sizeof(input) / sizeof(input[0]);

  for(int i = 0; i < length; i++) {
    int key = input[i];
    int prevKey = i - 1;
    
    while(i > 0 && input[prevKey] > key) {
      input[prevKey + 1] = input[prevKey];
      prevKey = prevKey - 1;
    }

    input[prevKey + 1] = key;
  }
  

  for(int i = 0; i < length; i++) {
   printf("%d", input[i]);
  }
  
  return 0;
}
