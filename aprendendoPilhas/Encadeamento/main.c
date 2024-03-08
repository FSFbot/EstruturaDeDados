#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Cria um novo nó
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Verifica se a pilha (lista encadeada) está vazia
int isEmpty(struct Node* root) {
    return !root;
}

// Adiciona um elemento ao topo da pilha
void push(struct Node** root, int data) {
    struct Node* node = newNode(data);
    node->next = *root;
    *root = node;
    printf("%d empilhado\n", data);
}

// Remove o elemento do topo da pilha
int pop(struct Node** root) {
    if (isEmpty(*root)) {
        return -1;
    }
    struct Node* temp = *root;
    *root = (*root)->next;
    int popped = temp->data;
    free(temp);

    return popped;
}

// Retorna o elemento do topo sem remover
int top(struct Node* root) {
    if (isEmpty(root)) {
        return -1;
    }
    return root->data;
}

int main() {
    struct Node* root = NULL;

    push(&root, 10);
    push(&root, 20);
    push(&root, 30);

    printf("%d desempilhado da pilha\n", pop(&root));
    printf("Elemento no topo: %d\n", top(root));

    if (isEmpty(root)) {
        printf("A pilha está vazia\n");
    } else {
        printf("A pilha não está vazia\n");
    }

    return 0;
}
