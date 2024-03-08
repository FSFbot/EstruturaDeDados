#include <stdio.h>
void convertToBinary(int n){
    if(n / 2 != 0 ){
        convertToBinary(n / 2);
    }
    printf("%d", n % 2);
}
int main() {
    int num;
    printf("Digite um numero inteiro: ");
    scanf("%d", &num);
    printf("O binario de %d é: ", num);
    convertToBinary(num);
    return 0;
}
