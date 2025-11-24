#include <stdio.h>
#define max 100
int a[max];
int main() {
    int n,i,j,element,found = 0,index;
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

    printf("\nEnter the number to search: ");
    scanf("%d", &element);

    for (int i = 0; i < n; i++) {
        if (a[i] == element) {
            index = i;
            found++; 
            break;
        }
    }

    if (found != 0) {
        printf("Element %d found at index %d\n",element,index);
    } 
    else {
        printf("Element not found.\n");
    }

    return 0;
}
