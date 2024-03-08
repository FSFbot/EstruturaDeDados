#include <stdbool.h>
#include <printf.h>

#define MAX_SIZE 10 // Tamanho maximo da pilha

int stack[MAX_SIZE]; // Array que representa a pilha
int top = -1;// Ponteiro do topo

// Função para vergicar se a pilha esta cheia
bool isFull() {
    return top == MAX_SIZE - 1; // Checca se o topo ja atingiu o limite do array
}

// Função para verificar se a pilha esta vazia
bool isEmpty(){
    return top == -1; // Checa se o topo esta no valor inicial
}
// Função para adicionar um elemento na pilha(push)

void push(int data){
    if(isFull()){
        printf("A pilha esta cheia\n");
        return;
    }
    top++;  // Aumenta o topo para o proximo elemento
    stack[top] = data; // Adiciona o elemento no topo
}
// Função para remover um elemento da pilha(pop)
int pop(){
    if(isEmpty()){
        printf("A pilha esta vazia\n");
        return -1;
    }
    int data = stack[top]; // Pega o elemento do topo
    top--; // Diminui o topo para o elemento anterior
    return data;
}
// Função para pegar o elemento do topo da pilha(peek)
int peek(){
    if(isEmpty()){
        printf("A pilha esta vazia\n");
        return -1; // Valor invalido como sinal de erro
    }
    return stack[top]; // Retorna o elemento do topo porem sem remove-lo
}
int main(){
    push(1);
    push(2);
    push(3);
    printf("Elemento do topo: %d\n", peek());
    printf("Elemento removido: %d\n", pop());
    printf("Elemento do topo: %d\n", peek());
    return 0;
}