#include "Stack03.h"
#include <limits.h>
#include <stdio.h>
int main() {
    int n, i, temp;
    printf("Digite o número de elementos: ");
    scanf("%d", &n);

    Stack* stackA = createStack(n);
    Stack* stackC = createStack(n);

    printf("Digite os elementos: ");
    for(i = 0; i < n; i++) {
        scanf("%d", &temp);
        push(stackA, temp);
    }

    while(!isEmpty(stackA)) {
        temp = pop(stackA);
        while(!isEmpty(stackC) && peek(stackC) < temp) {
            push(stackA, pop(stackC));
        }
        if(isEmpty(stackC) || peek(stackC) != temp) {
            push(stackC, temp);
        }
    }

    printf("Elementos ordenados em ordem decrescente: ");
    while(!isEmpty(stackC)) {
        printf("%d ", pop(stackC));
    }

    return 0;
}