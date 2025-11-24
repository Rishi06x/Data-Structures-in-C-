#include <stdio.h>
#include <stdlib.h>
#define MAX 100
int arr[MAX];

int getMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

// Counting sort function for Radix sort
void countingSort(int arr[], int n, int exp) {
    int* output = (int*)malloc(n * sizeof(int));
    int count[10] = {0};

    // Count occurrences of each digit
    for (int i = 0; i < n; i++) {
        count[(arr[i] / exp) % 10]++;
    }

    // Change count[i] to contain the actual position of the digits
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    // Build the output array
    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    // Copy the output array to arr[]
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }

    free(output);
}

// Radix sort function
void radixSort(int arr[], int n) {
    int max = getMax(arr, n);

    // Apply counting sort to sort elements based on place value
    for (int exp = 1; max / exp > 0; exp *= 10) {
        countingSort(arr, n, exp);
    }
}

// Utility function to print an array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Main function to test the Radix sort
int main() {
    int i,j,n;
    printf("Enter the no of elements:");
    scanf("%d",&n);
    printf("Enter the Elements:");
    for( i=0; i<n; i++){
        scanf("%d",&arr[i]);
    }
    printf("Array Elements:");
    for( i=0; i<n; i++){
        printf("%d ",arr[i]);
    }
    printf("\nRadix Sorting...\n");
    radixSort(arr, n);
    printArray(arr, n);
    return 0;
}
