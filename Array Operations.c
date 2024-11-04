#include<stdio.h>
int a[10], currentsize=0, size;
int main(){
    int choice;
    printf("Enter the size of the array:");
    scanf("%d",&size);
    for(int i=0;i<size;i++){
        printf("Enter the element %d:",i+1);
        scanf("%d",&a[i]);
        currentsize++;
    }    
    printf("To perform Operations enter any 1 option\n"); 
    printf("1. To display\n"); 
    printf("2. To Insert\n");
    printf("3. To Delete\n");
    printf("4. To Search\n");  
    printf("5. To Sort\n"); 
    printf("0. To exit"); 
    
        do{
        printf("\nEnter choice:");
        scanf("%d",&choice);
        switch(choice){
        case 1:
            display(a);
            break;
        case 2:
            insert(a);
            break;  
        case 3:
            delete(a);
            break; 
        case 4:
            search(a);
            break;
        case 5:
            sort(a);
            break;  
            }
        }while(choice!=0);
        printf("You Exited👍");
        
        
        
        
    }    
        
    /*Checking the array
      is full or empty  */    
      
int fullorempty(){       
    if(currentsize==10){ //Checks the array is full
        return 1;
        }
    else if(currentsize==0){ //Checks the array is empty
        return 2;
        }
    else{
        return 0;
        }   
    }  
    
    //To Insert an element in specific position 
              
int insert(int *a){  
    int element,pos;
    if(fullorempty()==1){
        printf("Array is Full,Cannot Insert!");
        }
    else{  
        
        printf("Enter the element to insert:");
        scanf("%d",&element);
        printf("Enter the position to insert:");
        scanf("%d",&pos);
        if(pos<0||pos>currentsize){
            printf("Invalid Position");
            }
        else{  
        for(int i=currentsize;i>pos-1;i--){
            a[i]=a[i-1];
        
        }
        a[pos-1]=element;
        currentsize++;
        for(int i=0;i<currentsize;i++){
            printf("%d\n",a[i]);
        }
      }
    }   
} 

    //To delete an Element in specific position 
    
int delete(int *a){
    int pos;
    if(fullorempty()==2){
        printf("Array is Empty,You can't delete:");
    }
    else{
    printf("Enter the position to delete:");
    scanf("%d",&pos);
    if(pos<0||pos>currentsize){
            printf("Invalid Position");
            }
    else{        
    for(int i=pos-1;i<currentsize;i++){
        a[i]=a[i+1];
    }
    currentsize--;
    for(int i=0;i<currentsize;i++){
        printf("%d\n",a[i]);
        }
     } 
   } 
}

    //To search an Element in an array
    
int search(int *a){
    if(fullorempty()==1){
        printf("The array in empty.You can't search:");
    }
    else{
        int search,found=0,i;
        printf("Enter the element to search:");
        scanf("%d",&search);
        for(i=0;i<currentsize;i++){
            if(a[i]==search){
                printf("The element is in %d(st/nd/rd/th) position.\n",i+1);
                found++;
                }
            }   
            if(found==0){
                printf("Not found!");
            }
          
        }
    }
    
    // To display the array Elements 
    
int display(int *a){
    printf("The elements are:\n");
    for(int i=0;i<currentsize;i++){
        printf("%d\n",a[i]);
        } 
    } 
    
    //To sort the array elements in ascending order
    
int sort(int *a){
    int i,j,temp;
    if(fullorempty==0){
        printf("The array is empty, Can't sort");
        }
    else{
        for(i=0;i<currentsize;i++){
            for(j=i+1;j<currentsize;j++){
                if(a[i]>a[j]){
                    temp=a[j];
                    a[j]=a[i];
                    a[i]=temp;
                }
              }
                
            }
            printf("Sorted Array:\n");
            for(i=0;i<currentsize;i++){
                printf("%d \t",a[i]);
            }
        }
    }
