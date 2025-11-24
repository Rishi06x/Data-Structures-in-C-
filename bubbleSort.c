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
    printf("\nBubble Sorting...\n");
    for( i=0; i<n-1; i++){
        for( j=0; j<n-1-i; j++){
            if(a[j] > a[j+1]){
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
    printf("After sorting:");
    for(int i=0; i<n; i++){
        printf("%d ",a[i]);
    }
}
