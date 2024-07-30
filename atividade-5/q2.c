#include <stdio.h>
#include <string.h>

// Definição da estrutura Pessoa
typedef struct {
    char nome[100];
    char documento[50];
    int idade;
} Pessoa;

// Função para preencher os campos da estrutura Pessoa
void preencherPessoa(Pessoa *p) {
    printf("Digite o nome da pessoa: ");
    scanf(" %[^\n]", p->nome);
    printf("Digite o numero do documento: ");
    scanf(" %[^\n]", p->documento);
    printf("Digite a idade: ");
    scanf("%d", &p->idade);
}

// Função para imprimir os campos da estrutura Pessoa
void imprimirPessoa(const Pessoa *p) {
    printf("Nome: %s\n", p->nome);
    printf("Documento: %s\n", p->documento);
    printf("Idade: %d\n", p->idade);
}

// Função para atualizar a idade da estrutura Pessoa
void atualizarIdade(Pessoa *p, int novaIdade) {
    p->idade = novaIdade;
}

// Função para encontrar e imprimir a pessoa mais velha e mais nova
void imprimirMaisVelhaMaisNova(Pessoa *pessoas, int n) {
    if (n <= 0) return;
    
    Pessoa *maisVelha = &pessoas[0];
    Pessoa *maisNova = &pessoas[0];
    
    for (int i = 1; i < n; i++) {
        if (pessoas[i].idade > maisVelha->idade) {
            maisVelha = &pessoas[i];
        }
        if (pessoas[i].idade < maisNova->idade) {
            maisNova = &pessoas[i];
        }
    }
    
    printf("Pessoa mais velha:\n");
    printf("Nome: %s, Idade: %d\n", maisVelha->nome, maisVelha->idade);
    
    printf("Pessoa mais nova:\n");
    printf("Nome: %s, Idade: %d\n", maisNova->nome, maisNova->idade);
}

int main() {
    int n;
    printf("Digite o numero de pessoas: ");
    scanf("%d", &n);
    
    Pessoa pessoas[n];
    
    // Preencher dados das pessoas
    for (int i = 0; i < n; i++) {
        printf("\nPreenchendo dados da pessoa %d\n", i + 1);
        preencherPessoa(&pessoas[i]);
    }
    
    // Imprimir dados das pessoas
    printf("\nDados das pessoas:\n");
    for (int i = 0; i < n; i++) {
        printf("\nPessoa %d\n", i + 1);
        imprimirPessoa(&pessoas[i]);
    }
    
    // Atualizar idade de uma pessoa específica (exemplo)
    int id;
    int novaIdade;
    printf("\nDigite o indice da pessoa que deseja alterar a idade (0 a %d): ", n - 1);
    scanf("%d", &id);
    printf("Digite a nova idade: ");
    scanf("%d", &novaIdade);
    
    if (id >= 0 && id < n) {
        atualizarIdade(&pessoas[id], novaIdade);
    } else {
        printf("Indice invalido!\n");
    }
    
    // Imprimir pessoa mais velha e mais nova
    imprimirMaisVelhaMaisNova(pessoas, n);
    
    return 0;
}
