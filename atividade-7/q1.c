#include <stdio.h>
#include <string.h>

// Definição do enum para o gênero
typedef enum {
    MASCULINO,
    FEMININO
} Genero;

// Definição da struct Pessoa
typedef struct {
    char nome[81];
    int idade;
    Genero genero;
} Pessoa;

// Função para ler os dados de uma pessoa
void lerPessoa(Pessoa *p) {
    printf("Digite o nome: ");
    scanf(" %80[^\n]", p->nome);
    printf("Digite a idade: ");
    scanf("%d", &p->idade);
    printf("Digite o genero (0 para MASCULINO, 1 para FEMININO): ");
    int genero;
    scanf("%d", &genero);
    p->genero = (Genero)genero;
}

// Função para imprimir os dados de uma pessoa
void imprimirPessoa(const Pessoa *p) {
    printf("Nome: %s\n", p->nome);
    printf("Idade: %d\n", p->idade);
    printf("Genero: %s\n", p->genero == MASCULINO ? "MASCULINO" : "FEMININO");
}

int main() {
    Pessoa p;

    // Ler os dados da pessoa
    lerPessoa(&p);

    // Imprimir os dados da pessoa
    imprimirPessoa(&p);

    return 0;
}
