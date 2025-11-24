#include<stdio.h>
#define size 100
int a[size];

int main(){
    int n,i,low=0, high,result=-1,key;
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

    printf("\nEnter the element to search:");
    scanf("%d",&key);
    high = n-1;
    printf("%d ",high);
    while(low <= high){
        int mid = (low + high)/2;
        if(a[mid] == key){
            result = mid;
            break;
        }
        if(a[mid] < key){
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }
    if(result != -1){
        printf("Element %d Found at index %d",key,result+1);
    }
    else {   
        printf("Not found");
    }
    return 0;
}