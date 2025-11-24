#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next,*prev;
};
void reverse();
struct node *head=NULL,*temp=NULL,*new,*tail;
void reverse(){
    struct node *curr = head,*temp;
    while(curr != NULL){
        temp = curr->next;
        curr->next = curr->prev;
        curr->prev = temp;
        curr = curr->prev;
    }
    temp = head;
    head = tail;
    tail = temp;

    temp = head;
    while(temp != NULL){
        printf("%d\t",temp->data);
        temp = temp->next;
    }
    printf("\n");
}
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
    reverse();  
}
