#include <stdio.h>

#define MAX 100  

void reverseQueue(int queue[], int n) {
    int stack[MAX];
    int top = -1;
    for (int i = 0; i < n; i++) {
        stack[++top] = queue[i];
    }
    for (int i = 0; i < n; i++) {
        queue[i] = stack[top--];
    }
}

void printQueue(int queue[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main() {
    int queue[MAX];
    int n;

    printf("Enter the number of elements in the queue: ");
    scanf("%d", &n);

    printf("Enter the elements of the queue: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &queue[i]);
    }

    printf("Original Queue: ");
    printQueue(queue, n);

    reverseQueue(queue, n);

    printf("Reversed Queue: ");
    printQueue(queue, n);

    return 0;
}