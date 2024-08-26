#include<stdio.h>
#include<stdlib.h>

struct node {
    int coeff, pow;
    struct node *next;
};

struct node *first = NULL, *second = NULL, *result = NULL;

void create(struct node **poly);
void display(struct node *poly);
void addPolynomials(struct node *first, struct node *second, struct node **result);

int main() {
    printf("First Equation:\n");
    create(&first);
    printf("Second Equation:\n");
    create(&second);
    printf("First Polynomial: ");
    display(first);
    printf("Second Polynomial: ");
    display(second);
    addPolynomials(first, second, &result);
    printf("Resultant Polynomial: ");
    display(result);
    return 0;
}

void create(struct node **poly) {
    int n;
    struct node *temp = NULL;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        struct node *new = (struct node*)malloc(sizeof(struct node));
        printf("Enter the coefficient and exponential value: ");
        scanf("%d %d", &(new->coeff), &(new->pow));
        new->next = NULL;
        if (*poly == NULL) {
            *poly = new;
        } else {
            temp->next = new;
        }
        temp = new;
    }
}

void display(struct node *poly) {
    struct node *temp = poly;
    while (temp != NULL) {
        printf("%dx^%d", temp->coeff, temp->pow);
        if (temp->next != NULL) {
            printf(" + ");
        }
        temp = temp->next;
    }
    printf("\n");
}

void addPolynomials(struct node *first, struct node *second, struct node **result) {
    struct node *temp = NULL, *new = NULL;
    while (first != NULL && second != NULL) {
        new = (struct node*)malloc(sizeof(struct node));
        if (first->pow == second->pow) {
            new->pow = first->pow;
            new->coeff = first->coeff + second->coeff;
            first = first->next;
            second = second->next;
        } else if (first->pow > second->pow) {
            new->pow = first->pow;
            new->coeff = first->coeff;
            first = first->next;
        } else {
            new->pow = second->pow;
            new->coeff = second->coeff;
            second = second->next;
        }
        new->next = NULL;
        if (*result == NULL) {
            *result = new;
        } else {
            temp->next = new;
        }
        temp = new;
    }

    while (first != NULL) {
        new = (struct node*)malloc(sizeof(struct node));
        new->pow = first->pow;
        new->coeff = first->coeff;
        new->next = NULL;
        if (*result == NULL) {
            *result = new;
        } else {
            temp->next = new;
        }
        temp = new;
        first = first->next;
    }

    while (second != NULL) {
        new = (struct node*)malloc(sizeof(struct node));
        new->pow = second->pow;
        new->coeff = second->coeff;
        new->next = NULL;
        if (*result == NULL) {
            *result = new;
        } else {
            temp->next = new;
        }
        temp = new;
        second = second->next;
    }
}
