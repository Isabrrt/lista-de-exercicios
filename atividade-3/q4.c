#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NOME 100 // Tamanho máximo de um nome
#define MAX_PESSOAS 100 // Número máximo de pessoas

int main() {
    int num_pessoas, i;
    char **nomes;
    int *idades;

    // Lê o número de pessoas
    printf("Digite o número de pessoas: ");
    scanf("%d", &num_pessoas);

    // Aloca memória para os nomes e idades
    nomes = (char**)malloc(num_pessoas * sizeof(char*));
    idades = (int*)malloc(num_pessoas * sizeof(int));

    // Lê os nomes e idades
    for (i = 0; i < num_pessoas; i++) {
        nomes[i] = (char*)malloc((MAX_NOME + 1) * sizeof(char)); // +1 para o caractere nulo
        printf("Digite o nome da pessoa %d: ", i + 1);
        scanf(" %[^\n]", nomes[i]); // Lê uma linha inteira até o '\n'
        printf("Digite a idade da pessoa %d: ", i + 1);
        scanf("%d", &idades[i]);
    }

    // Imprime os nomes
    printf("\nNomes cadastrados:\n");
    for (i = 0; i < num_pessoas; i++) {
        printf("%s\n", nomes[i]);
    }

    // Libera a memória alocada
    for (i = 0; i < num_pessoas; i++) {
        free(nomes[i]);
    }
    free(nomes);
    free(idades);

    return 0;
}
