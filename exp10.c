#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to swap two elements

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

// Function to partition the array

int partition_left(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low;
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            swap(&arr[i], &arr[j]);
            i++;
        }
    }

    swap(&arr[i], &arr[high]);
    return i;
}

// Function to perform random partition

int partition_right(int arr[], int low, int high) {
    srand(time(NULL));
    int r = low + rand() % (high - low);
    swap(&arr[r], &arr[high]);
    return partition_left(arr, low, high);
}

// Recursive function for quicksort

void quicksort(int arr[], int low, int high) {
    if (low < high) {
        int p = partition_right(arr, low, high);
        quicksort(arr, low, p - 1);
        quicksort(arr, p + 1, high);
    }

}

// Function to print the array

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Driver code

int main() {

   int n;
   printf("enter no. of array's element: ");
   scanf("%d",&n);
   int arr[n];
   for(int i=0; i<n;i++){
   printf("enter array elements: ");
   scanf("%d",&arr[i]);
   }

    printf("Original array: ");
    printArray(arr, n);
    quicksort(arr, 0, n - 1);
    printf("Sorted array: ");
    printArray(arr, n);
    return 0;

}
