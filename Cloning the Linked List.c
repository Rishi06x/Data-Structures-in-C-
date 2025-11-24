#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next,*prev;
};
void clone();
struct node *head=NULL,*temp=NULL,*new,*tail;
int main(){
    int n;
    printf("Enter the no of element:");
    scanf("%d",&n);
    for(int i=0; i<n; i++){
        new = (struct node*)malloc(sizeof(struct node));
        printf("Enter the data %d:",i+1);
        scanf("%d",&(new->data));
        temp = head;
        if(head == NULL){
            head =tail = new;
            head->prev = NULL;
            head->next = NULL;
        }
        else{
            tail->next = new;
            new->prev = tail;
            new->next = NULL;
            tail = new;
        }
    }
    temp = head;
    while(temp != NULL){
        printf("%d\t",temp->data);
        temp = temp->next;
    }
    printf("\n");
    clone(); 
}

void clone(){
    struct node *temp1;
   
    temp1 = head;
    temp = tail;
    while(temp1 != temp){
        new = (struct node*)malloc(sizeof(struct node));
        new->data = temp1->data;
        tail->next = new;
        new->prev = tail;
        new->next = NULL;
        tail = new;
        temp1 = temp1->next;
    }
    temp = head;
    while(temp != NULL){
        printf("%d\t",temp->data);
        temp = temp->next;
    }
    printf("%d",tail->data);
    printf("\n");
}
