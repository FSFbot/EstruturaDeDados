#include <printf.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node{
    int data; // Armazena os dados
    struct Node *next; // Ponteiro para o próximo nó
};

struct Node *top = NULL; // Inicializa o topo da pilha como NULL

// Função para verficar se a pilha está vazia
bool isEmpty(){
    return top == NULL;
}

// Função para inserir um elemento na pilha(push)

void push(int data){
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode -> data = data; // Insirir os dados no novo nó
    newNode -> next = top; // Conecta o nó ao topo anterior
    top = newNode;  // O novo nó se torna o topo
}

// Função para remover um elemento da pilha(pop)
int pop(){
    if(isEmpty()){
        printf("A pilha está vazia\n");
        return -1;
    }
    struct Node *temp = top; // Armazena o topo atual
    int data = top -> data; // Armazena os dados do topo
    top = top -> next; // Move o topo para o próximo nó
    free(temp); // Libera a memória do nó removido
    return data; // Retorna os dados do nó removido
}

int peek(){
    if(isEmpty()){
        printf("A pilha está vazia\n");
        return -1;
    }
    return top -> data; // Retorna os dados do topo
}