#include <stdio.h>
#include <stdlib.h>
int main() {
  int n, i;
  float num, soma = 0.0, media;

  printf("Digite a quantidade de numeros: ");
  scanf("%d", &n);

  for (i = 0; i < n; i++){
    printf("Digite o numero %d: ", i+1);
    scanf("%f", &num);
    soma += num;
  }
  media = soma / n;
  printf("Media = %.2f", media);

return 0;
}
