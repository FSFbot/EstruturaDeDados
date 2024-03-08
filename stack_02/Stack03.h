#ifndef STACK_02_STACK03_H
#define STACK_02_STACK03_H

#include <limits.h>

typedef struct stack {
    int top;
    unsigned capacity;
    int* array;
} Stack;

Stack* createStack(unsigned capacity);
int isFull(Stack* stack);
int isEmpty(Stack* stack);
void push(Stack* stack, int item);
int pop(Stack* stack);
int peek(Stack* stack);

#endif //STACK_02_STACK03_H