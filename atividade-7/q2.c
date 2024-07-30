#include <stdio.h>
#include <string.h>

// Definição do enum para o tipo de produto
typedef enum {
    ALIMENTO,
    BEBIDA,
    ELETRONICO
} TipoProduto;

// Definição da union para armazenar o tipo do produto
typedef union {
    char alimento[50];
    char bebida[50];
    char eletronico[50];
} Tipo;

// Definição da struct Produto
typedef struct {
    char nome[81];
    float preco;
    TipoProduto tipo;
    Tipo descricao;
} Produto;

// Função para ler os dados de um produto
void lerProduto(Produto *p) {
    printf("Digite o nome do produto: ");
    scanf(" %80[^\n]", p->nome);
    printf("Digite o preço do produto: ");
    scanf("%f", &p->preco);
    printf("Digite o tipo do produto (0 para ALIMENTO, 1 para BEBIDA, 2 para ELETRONICO): ");
    int tipo;
    scanf("%d", &tipo);
    p->tipo = (TipoProduto)tipo;
    
    switch (p->tipo) {
        case ALIMENTO:
            printf("Digite a descrição do alimento: ");
            scanf(" %49[^\n]", p->descricao.alimento);
            break;
        case BEBIDA:
            printf("Digite a descrição da bebida: ");
            scanf(" %49[^\n]", p->descricao.bebida);
            break;
        case ELETRONICO:
            printf("Digite a descrição do eletrônico: ");
            scanf(" %49[^\n]", p->descricao.eletronico);
            break;
        default:
            printf("Tipo inválido!\n");
            break;
    }
}

// Função para imprimir os dados de um produto
void imprimirProduto(const Produto *p) {
    printf("Nome: %s\n", p->nome);
    printf("Preço: %.2f\n", p->preco);
    
    switch (p->tipo) {
        case ALIMENTO:
            printf("Tipo: ALIMENTO\n");
            printf("Descrição: %s\n", p->descricao.alimento);
            break;
        case BEBIDA:
            printf("Tipo: BEBIDA\n");
            printf("Descrição: %s\n", p->descricao.bebida);
            break;
        case ELETRONICO:
            printf("Tipo: ELETRONICO\n");
            printf("Descrição: %s\n", p->descricao.eletronico);
            break;
        default:
            printf("Tipo inválido!\n");
            break;
    }
}

int main() {
    Produto p;

    // Ler os dados do produto
    lerProduto(&p);

    // Imprimir os dados do produto
    imprimirProduto(&p);

    return 0;
}
