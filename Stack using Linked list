#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
void push();
void pop();
void display();
struct node *head=NULL,*temp,*new;
int i;
int main(){
    int choice;
    printf("TO perform operations\n");
    printf("1 -> PUSH.\n");
    printf("2 -> pop.\n");
    printf("3 -> display.\n");
    printf("0 -> Exit.\n");

    do{
    printf("Enter the choice:");
    scanf("%d",&choice);
    switch(choice){
        case 1:
        push();
        break;
        case 2:
        pop();
        break;
        case 3:
        display();
        break;
        default:
        printf("Invalid Choice.\n");
        } 
    }while(choice!=0);
    printf("Exited!");
     
      
}
void push(){
    new = (struct node*)malloc(sizeof(struct node));
    printf("\nEnter the data:");
    scanf("%d",&(new->data));
    temp = head;
    if(head == NULL){
        head = new;
        
        head->next = NULL;
        
    }
    else{

        new->next=head;
        head = new;       
    }
    display();
    
}
void pop(){
    if(head == NULL){
        printf("Stack is UnderFlow");
    }
    else{
        temp = head;
        head = head->next;
        free(temp);
    }
    display();

}
void display(){
    temp = head;
    while(temp !=NULL){
        printf("%d -> ",temp->data);
        temp = temp->next;
    }
    printf("NULL");
    printf("\n");
}
