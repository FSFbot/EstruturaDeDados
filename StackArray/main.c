#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

struct Stack {
    int items[MAX_SIZE];
    int top;
};

// Inicializa a pilha
struct Stack* createStack() {
    struct Stack* s = (struct Stack*)malloc(sizeof(struct Stack));
    s->top = -1;
    return s;
}

// Verifica se a pilha está vazia
int isEmpty(struct Stack* s) {
    return s->top == -1;
}

// Verifica se a pilha está cheia
int isFull(struct Stack* s) {
    return s->top == MAX_SIZE - 1;
}

// Adiciona um elemento ao topo da pilha
void push(struct Stack* s, int item) {
    if (isFull(s)) {
        printf("Pilha cheia\n");
        return;
    }
    s->items[++s->top] = item;
    printf("%d empilhado\n", item);
}

// Remove e retorna o elemento do topo da pilha
int pop(struct Stack* s) {
    if (isEmpty(s)) {
        printf("Pilha vazia\n");
        return -1;
    }
    return s->items[s->top--];
}

// Retorna o elemento do topo sem remover
int top(struct Stack* s) {
    if (isEmpty(s)) {
        return -1;
    }
    return s->items[s->top];
}

int main() {
    struct Stack* stack = createStack();

    push(stack, 10);
    push(stack, 20);
    push(stack, 30);

    printf("%d desempilhado da pilha\n", pop(stack));
    printf("Elemento no topo: %d\n", top(stack));

    if (isEmpty(stack)) {
        printf("A pilha está vazia\n");
    } else {
        printf("A pilha não está vazia\n");
    }

    return 0;
}
