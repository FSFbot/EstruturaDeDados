#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
    int priority;
    char task[50];
    struct Node* next;
}Node;

typedef struct queque {
    Node* front;
    Node* rear;
}Queue;

void enqueue(Queue* queue, int priority, char* task) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->priority = priority;
    strcpy(newNode->task, task);
    newNode->next = NULL;

    if (queue->rear == NULL) {
        queue->front = queue->rear = newNode;
        return;
    }

    if (priority < queue->front->priority) {
        newNode->next = queue->front;
        queue->front = newNode;
    } else {
        Node* current = queue->rear;
        while (current->next != NULL && current->next->priority <= priority) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;

        if (newNode->next == NULL) {
            queue->rear = newNode;
        }
    }
}

void dequeue(Queue* queque){
    if(queque->front == NULL){
        printf("A fila está vazia.\n");
        return;
    }
    Node* temp = queque->front;
    queque->front = queque->front->next;
    if(queque->front == NULL){
        queque -> rear = NULL;
    }
    printf("Tarefa removida com sucesso: %s\n",temp->task);
    free(temp);
}
int main() {
    Queue taskQueue;
    taskQueue.front = taskQueue.rear = NULL;

    enqueue(&taskQueue, 3, "Tarefa de baixa prioridade");
    enqueue(&taskQueue, 1, "Tarefa de alta prioridade");
    enqueue(&taskQueue, 2, "Tarefa de média prioridade");

    printf("Processando tarefas na ordem de prioridade:\n");
    while (taskQueue.front != NULL) {
        dequeue(&taskQueue);
    }

    return 0;
}


