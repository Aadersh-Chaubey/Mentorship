#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
void printArray(int * arr, int n){
	for(int i = 0; i < n; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
}
void swap(int * arr, int i, int j){
	int t = arr[i];
	arr[i] = arr[j];
	arr[j] = t;
}
void bubbleSort(int* arr, int n){
	for(int i = 0; i < n; i++){
		int j = 0;
		while(j < n - 1 - i){
			if(arr[j] > arr[j + 1])swap(arr, j, j + 1);
			else j++;
		}
	}
}

void selectionSort(int* arr, int n){
	for(int i = 0; i < n - 1; i++){
		int min = arr[i], mini = i;
		for(int j = i + 1; j < n; j++){
			if(arr[j] < min){
				min = arr[j];
				mini = j;
			}
		}
		swap(arr, i, mini);
	}
}

void insertionSort(int* arr, int n){
	for(int i = 1; i < n; i++){
		int t = arr[i], j = i - 1;
		while(j >= 0 && arr[j] > t){
			arr[j + 1] = arr[j];
			j--;
		}
		arr[++j] = t;
	}
}
int main() {
	// Your code goes here;
	
	int arr[] = {4, 3, 5, 2, 5};
	// bubbleSort(arr, 5);
	// selectionSort(arr, 5);
	insertionSort(arr, 5);
	printArray(arr, 5);
}