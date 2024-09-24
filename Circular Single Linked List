#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};
void display();
void insert();
void delete();
void search();
struct node *head=NULL,*temp=NULL,*new,*tail=NULL,*prev;
int n;
int main(){
    int i,choice;
    printf("Enter the no. of node:");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        new = (struct node*)malloc(sizeof(struct node));
        printf("Enter the data %d:",i+1);
        scanf("%d",&(new->data));
        if(head == NULL){
            head = new;
            head->next=NULL;
        }
        else{
            tail->next = new;
            new->next=NULL;

        }
        tail = new;
    }
    tail->next = head;

    printf("To perform Operations.\n");
    printf("1 -> Insert\n");
    printf("2 -> delete\n");
    printf("3 -> search\n");
    printf("4 -> display\n");
    printf("0 -> Exit.\n");
    do{
        printf("Enter the choice:");
        scanf("%d",&choice);
        switch(choice){
            case 1:
            insert();
            break;
            case 2:
            delete();
            break;
            case 3:
            search();
            break;
            case 4:
            display();
            break;
        }
    }while(choice!=0);
    printf("Exited!");  
}
void display(){
    temp = head;
     do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("%d ",head->data);
    printf("\n");
}
void insert(){
    int pos;
    new = (struct node*)malloc(sizeof(struct node));
    printf("Enter the position to insert:");
    scanf("%d",&pos);
    printf("Enter the data :");
    scanf("%d",&(new->data));
    temp = head;
    if(pos==1){
        new->next=head;
        head = new;

    }
    else if(pos >1 && pos<=n){
        for(int i=1;i<pos-1;i++){
            temp = temp->next;
        }
        new->next=temp->next;
        temp->next = new;
    }
    else{
        tail->next = new;
        new->next = NULL;
        tail = new;
    }
    tail->next = head;
}
void delete(){
    if(head==NULL){
        printf("List is Empty! ");
    }
    else{
        int pos;
        printf("Enter the position:");
        scanf("%d",&pos);
        temp=head;
        if(pos ==1){
            head = temp->next; 
        }
        else{
      
        for(int i=1;i<pos;i++){
            prev = temp;
            if(temp==NULL){
                printf("%d",temp->data);
            }
            temp = temp->next;   
            }
        prev->next = temp->next;
        }
        free(temp);
    }
}
void search(){
    int element,flag=0;
    printf("Enter the element to search:");
    scanf("%d",&element);
    temp = head;
    do
    {
      if(temp->data == element){
            found;
        }
        temp = temp->next;
    }while (temp != head);
    if(flag == 1){
        printf("%d is Found.\n",element);
    }
    else{
        printf("%d is not Found",element);
    }  
}
