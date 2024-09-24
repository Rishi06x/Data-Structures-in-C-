#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next,*prev;
};
void sort();
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
    sort();  
}

void sort(){
    int d;
    struct node *curr = head;
    while(curr != NULL){
        temp = curr->next;
        while(temp != NULL){
            if(curr->data > temp->data){
                d = curr->data;
                curr->data = temp->data;
                temp->data = d;
            }
            temp = temp->next;
        }
        curr = curr->next;
    }
    temp = head;
    while(temp != NULL){
        printf("%d\t",temp->data);
        temp = temp->next;
    }
    printf("\n");
}
