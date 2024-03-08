#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct Node{
    int data;
    struct Node* next;
} Node;

Node* newNode(int data){
    Node* node = (Node*) malloc(sizeof(Node));
    if (node == NULL){
        printf("Erro ao Alocar Memoria\n");
        exit(0);
    }
    node -> data =data;
    node -> next = NULL;
    return node;
}

int isEmpty(Node* root){
    return !root;
}

void push(Node** root, int data){
    Node* node = newNode(data);
    node -> next = *root;
    *root = node;
    printf("%d pushed to stack\n", data);
}
int pop(Node** root){
    if (isEmpty(*root))
        return INT_MIN;

    Node* temp = *root;
    *root = (*root) -> next;
    int popped = temp -> data;
    free(temp);
    return popped;
    }
int peek(Node* root){
    if (isEmpty(root))
        return INT_MIN;
    return root -> data;
}

int main(){
    Node* root = NULL;
    push(&root, 10);
    push(&root, 20);
    push(&root, 30);
    printf("%d popped from stack\n", pop(&root));
    printf("Top element is %d\n", peek(root));
    return 0;
}
