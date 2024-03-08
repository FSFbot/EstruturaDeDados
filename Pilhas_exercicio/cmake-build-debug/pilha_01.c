#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void push(Node** top, int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    if (!newNode) {
        printf("Heap overflow\n");
        exit(0);
    }
    newNode->data = data;
    newNode->next = *top;
    *top = newNode;
}

int isEmpty(Node* top) {
    return top == NULL;
}

int peek(Node* top) {
    if (!isEmpty(top)) {
        return top->data;
    } else {
        exit(1);
    }
}

void pop(Node** top) {
    Node* temp;
    if (*top == NULL) {
        printf("Stack underflow\n");
        exit(1);
    } else {
        temp = *top;
        *top = (*top)->next;
        temp->next = NULL;
        free(temp);
    }
}

void display(Node* top) {
    Node* temp;
    if (top == NULL) {
        printf("Stack underflow\n");
        exit(1);
    } else {
        temp = top;
        while (temp != NULL) {
            printf("%d->", temp->data);
            temp = temp->next;
        }
    }
}

int main() {
    Node *A = NULL, *B = NULL;
    int n, num;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &num);
        push(&A, num);
    }
    while (!isEmpty(A)) {
        int temp = peek(A);
        pop(&A);
        while (!isEmpty(B) && peek(B) > temp) {
            push(&A, peek(B));
            pop(&B);
        }
        push(&B, temp);
    }
    printf("Sorted elements are: ");
    display(B);
    return 0;
}