#include <stdio.h>
#define max 100
int a[max];

void printArray(int a[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}


int main() {
    int n,i,j,min,temp;
    printf("Enter the no of elements:");
    scanf("%d",&n);
    printf("Enter the Elements:");
    for( i=0; i<n; i++){
        scanf("%d",&a[i]);
    }
    printf("Array Elements:");
    for( i=0; i<n; i++){
        printf("%d ",a[i]);
    }

     for (i = 0; i < n-1; i++) {
        min = i;
        for (j = i+1; j < n; j++) {
            if (a[j] < a[min]) {
                min = j;
            }
        }
        if( min != i ){
        temp = a[min];
        a[min] = a[i];
        a[i] = temp;
        }
    }
    printf("\nSorted array: \n");
    printArray(a, n);
    return 0;
}
