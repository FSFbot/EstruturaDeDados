#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct stack {
    int top;
    unsigned capacity;
    int* array;
} Stack;

Stack* createStack(unsigned capacity) {
    Stack* stack = (Stack*) malloc(sizeof(Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int*) malloc(stack->capacity * sizeof(int));
    return stack;
}

int isFull(Stack* stack) {
    return stack->top == stack->capacity - 1;
}

int isEmpty(Stack* stack) {
    return stack->top == -1;
}

void push(Stack* stack, int item) {
    if (isFull(stack)) return;
    stack->array[++stack->top] = item;
}

int pop(Stack* stack) {
    if (isEmpty(stack)) return INT_MIN;
    return stack->array[stack->top--];
}

int peek(Stack* stack) {
    if (isEmpty(stack)) return INT_MIN;
    return stack->array[stack->top];
}

/*int main() {
    int n, i, temp;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    Stack* stackA = createStack(n);
    Stack* stackB = createStack(n);

    printf("Enter the elements: ");
    for(i = 0; i < n; i++) {
        scanf("%d", &temp);
        push(stackA, temp);
    }

    while(!isEmpty(stackA)) {
        temp = pop(stackA);
        while(!isEmpty(stackB) && peek(stackB) > temp) {
            push(stackA, pop(stackB));
        }
        push(stackB, temp);
    }

    printf("Sorted elements: ");
    while(!isEmpty(stackB)) {
        temp = pop(stackB);
        if(temp != peek(stackB)) {
            printf("%d ", temp);
        }
    }

    return 0;
}*/
