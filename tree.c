#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *left,*right;
};
void inorder(struct node *root);
void preorder(struct node *root);
struct node *create(){
    struct node *new = (struct node*)malloc(sizeof(struct node));
    printf("\nEnter the data(-1 for no node):");
    scanf("%d",&(new->data));
    if(new->data == -1){
        return 0;
    }
    printf("Enter left child of %d:",new->data);
    new->left = create();
    printf("Enter right child of %d:",new->data);
    new->right = create();
    return new;
}

void main(){
    struct node *root = NULL;
    root = create();
    printf("Pre order is:");
    preorder(root);
    printf("\n Inorder is:");
    inorder(root);
}

void preorder(struct node *root){
    if(root == NULL){
        return;
    }
    printf("%d\t",root->data);
    preorder(root->left);
    preorder(root->right);
}
void inorder(struct node *root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    printf("%d\t",root->data);
    inorder(root->right);
}