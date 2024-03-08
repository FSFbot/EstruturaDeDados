#include <stdio.h>
#include <stdlib.h>
#include "math.h"
int main() {
    printf("Olá, seja bem vindo ao programa de média!!\n");
    printf("Informe quantos numero vamos analisar: ");
    int n;
    float number, soma= 0.0, media;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        printf("Informe o %dº número: ", i+1);
        scanf("%f", &number);
        soma += number;

    }
    printf("Resultado: %.2f\n", soma/n);
    printf("Fim do programa!!\n");
}
