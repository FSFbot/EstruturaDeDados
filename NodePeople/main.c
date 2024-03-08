#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Pessoa {
    char nome[50];
    char dataNascimento[11];
    struct Pessoa *proximo;
} Pessoa;

void cadastrarPessoa(Pessoa **lista);
int contarPessoas(Pessoa *lista);
Pessoa* buscarPessoaPorNome(Pessoa *lista, char *nome);
Pessoa* buscarPessoaPorData(Pessoa *lista, char *data);

int main() {
    Pessoa *lista = NULL; // Lista inicialmente vazia

    // Cadastro de algumas pessoas
    int n;
    printf("Digite o número de pessoas a cadastrar: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        cadastrarPessoa(&lista);
    }

    // Mostra o número de pessoas cadastradas
    int totalPessoas = contarPessoas(lista);
    printf("Total de pessoas cadastradas: %d\n", totalPessoas);

    // Consulta por nome
    char nomePesquisado[50];
    printf("Digite o nome da pessoa a ser consultada: ");
    scanf("%s", nomePesquisado);

    Pessoa *pessoaEncontrada = buscarPessoaPorNome(lista, nomePesquisado);

    if (pessoaEncontrada != NULL) {
        printf("Pessoa encontrada:\n");
        printf("Nome: %s\n", pessoaEncontrada->nome);
        printf("Data de nascimento: %s\n", pessoaEncontrada->dataNascimento);
    } else {
        printf("Pessoa não encontrada!\n");
    }

    // Consulta por data de nascimento
    char dataPesquisada[11];
    printf("Digite a data de nascimento da pessoa a ser consultada (DD/MM/AAAA): ");
    scanf("%s", dataPesquisada);

    pessoaEncontrada = buscarPessoaPorData(lista, dataPesquisada);

    if (pessoaEncontrada != NULL) {
        printf("Pessoa encontrada:\n");
        printf("Nome: %s\n", pessoaEncontrada->nome);
        printf("Data de nascimento: %s\n", pessoaEncontrada->dataNascimento);
    } else {
        printf("Pessoa não encontrada!\n");
    }

    return 0;
}

void cadastrarPessoa(Pessoa **lista) {
    // Aloca um novo elo
    Pessoa *novo = (Pessoa*)malloc(sizeof(Pessoa));

    // Leitura do nome
    printf("Digite o nome: ");
    scanf("%s", novo->nome);

    // Leitura da data de nascimento
    printf("Digite a data de nascimento (DD/MM/AAAA): ");
    scanf("%s", novo->dataNascimento);

    // Insere o novo elo no início da lista
    novo->proximo = *lista;
    *lista = novo;
}

int contarPessoas(Pessoa *lista) {
    int count = 0;
    Pessoa *aux = lista;

    // Percorre a lista até o final (aux == NULL)
    while (aux != NULL) {
        count++;
        aux = aux->proximo;
    }

    return count;
}

Pessoa* buscarPessoaPorNome(Pessoa *lista, char *nome) {
    Pessoa *aux = lista;

    // Percorre a lista enquanto `aux` não for NULL e o nome não for encontrado
    while (aux != NULL && strcmp(aux->nome, nome) != 0) {
        aux = aux->proximo;
    }

    return aux;
}

Pessoa* buscarPessoaPorData(Pessoa *lista, char *data) {
    Pessoa *aux = lista;

    // Percorre a lista enquanto `aux` não for NULL e a data não for encontrada
    while (aux != NULL && strcmp(aux->dataNascimento, data) != 0) {
        aux = aux->proximo;
    }

    return aux;
}
