#include <stdio.h>
#define MAX 100
int arr[MAX];

void merge(int arr[], int left, int mid, int right) {
    int i = 0, j = 0, k = left;
    int l1 = mid - left + 1;
    int l2 = right - mid;
    int L[l1], R[l2];

    for (int i = 0; i < l1; i++)
        L[i] = arr[left + i];
    for (int i = 0; i < l2; i++)
        R[i] = arr[mid + 1 + i];

    while (i < l1 && j < l2) {
        if (L[i] <= R[j]){
            arr[k] = L[i];
            i++;
        } else{
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < l1){
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < l2){
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int i,j,n;
    printf("Enter the no of elements:");
    scanf("%d",&n);
    printf("Enter the Elements:");
    for( i=0; i<n; i++){
        scanf("%d",&arr[i]);
    }

    printf("Given array is \n");
    printArray(arr, n);
    mergeSort(arr, 0, n - 1);
    printf("Sorted array is \n");
    printArray(arr, n);
    return 0;
}
