#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }

    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }

    return root;
}


struct Node* minValueNode(struct Node* node) {
    struct Node* current = node;
    // Loop down to find the leftmost leaf
    while (current && current->left != NULL)
        current = current->left;

    return current;
}

// Function to delete a node in the BST
struct Node* deleteNode(struct Node* root, int key) {
    // Base case: If the tree is empty
    if (root == NULL) return root;

    // Otherwise, recur down the tree
    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else {
        // Node with only one child or no child
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }
        printf("Root of right: %d", root->right->data);
        // Node with two children: Get the inorder successor (smallest in the right subtree)
        struct Node* temp = minValueNode(root->right);

        // Copy the inorder successor's content to this node
        root->data = temp->data;

        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

void inorder(struct Node* root) {
    if (root == NULL) {
        return;
    }

    inorder(root->left);     
    printf("%d ", root->data); 
    inorder(root->right);  
}

int main() {
    struct Node* root = NULL;
    char choice;
    int data,element;
    do{
       printf("Enter the data:");
       scanf("%d",&data);
       root = insert(root,data);
       printf("Wanna add node (Y or y):");
       scanf(" %c",&choice);
       choice = tolower(choice);
    }while(choice == 'y');
    printf("In-order traversal of the binary tree: \n");
    inorder(root);
    printf("\nEnter the element to delete:\n");
    scanf("%d",&element);
    root = deleteNode(root,element);
    printf("In-order traversal of the binary tree: \n");
    inorder(root);

    return 0;
}