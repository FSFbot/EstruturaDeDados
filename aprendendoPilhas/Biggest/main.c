#include <stdio.h>

int main() {
    float n1, n2;

    printf("Digite o primeiro número: ");
    scanf("%f", &n1);
    printf("\nDigite o segundo número: ");
    scanf("%f", &n2);
    if(n1 > n2){
        printf("O primeiro número é maior que o segundo");
    } else if(n1 < n2){
        printf("O segundo número é maior que o primeiro");
    } else {
        printf("Os números são iguais");
    }
}
