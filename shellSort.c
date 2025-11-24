#include<stdio.h>
#define size 100
int a[size];

int main(){
    int n,i,j,gap,temp;
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
     for(gap = n/2; gap>0; gap = gap/2){
        for(i=gap; i<n; i++){
            for(j=i-gap; j>=0; j=j-gap){
                if(a[j] > a[j+gap]){
                    temp = a[j];
                    a[j] = a[j+gap];
                    a[j+gap] = temp;
                }
                else{
                    break;
                }
            }      
        }
    }
    printf("\nShell Sorting...\n");
    for( i=0; i<n; i++){
        printf("%d ",a[i]);
    }
    printf("\n");
    return 0;
}
