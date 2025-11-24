#include<stdio.h>
#define size 100
int a[size];

int main(){
    int n,i,j,temp;
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
    printf("\nInsertion Sort...\n");
    for(i=1; i<n; i++){
        temp = a[i];
        for(j=i-1; j>=0 && a[j]>temp; j--){
            a[j+1] = a[j];
        }
         a[j+1] = temp;
    }
    printf("After Sorting: ");
    for( j=0; j<n; j++){
        printf("%d ",a[j]);
    }
}