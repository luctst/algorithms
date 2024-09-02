/*
 * Merge sort algorithm
 * Goal: Sort Array
 * Approach:
 *  1. Divide the n-elements sequence to be sorted into two subsequences of n/2 elements each.
 *  2. Sort the two sorted subsequences recursively using merge sort until two sequences of length n/2 are merged.
 *  3. Merge the two sorted subsequences to produce the sorted answer
*/

#include <stdio.h>

void printMotherFuckingArray(int A[], int size) {
	for(int i = 0; i < size; i++) {
		printf("%d ", A[i]);
	}
	printf("\n");
}

void merge(int* left, int leftSize, int* right, int rightSize, int* resultArray) {
	int leftIndex = 0;
	int rightIndex = 0;
	int resultIndex = 0;

	while (leftIndex < leftSize && rightIndex < rightSize) {
		if (left[leftIndex] < right[rightIndex]) {
				resultArray[resultIndex++] = left[leftIndex++];
		} else {
				resultArray[resultIndex++] = right[rightIndex++];
		}
	}

	while (leftIndex < leftSize) {
			resultArray[resultIndex++] = left[leftIndex++];
	}
	while (rightIndex < rightSize) {
			resultArray[resultIndex++] = right[rightIndex++];
	}
}

void mergeSort(int* arr, int size) {
	if (size <= 1) {
		return;
	}
  
  int middle = size / 2;
	int left[middle];
	int right[size - middle];

	for(int i = 0; i < middle; i++) {
		left[i] = arr[i];
	}
	
	for(int j = middle; j < size; j++) {
		right[j - middle] = arr[j];
	}

	mergeSort(left, middle);
	mergeSort(right, size - middle);

	int resultArray[size];
	merge(left, middle, right, size - middle, resultArray);

	for(int i = 0; i < size; i++) {
		arr[i] = resultArray[i];
	};
}

int main() {
	int arr[] = {38, 27, 43, 3, 9, 82, 10};
	int size = sizeof(arr) / sizeof(arr[0]);

	mergeSort(arr, size);

  printMotherFuckingArray(arr, size);
	return 0;
}
