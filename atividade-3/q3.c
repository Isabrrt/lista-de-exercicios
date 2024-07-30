#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int n, i, j;

    // Solicita o tamanho da matriz
    printf("Digite a ordem da matriz: ");
    scanf("%d", &n);

    // Aloca memória dinamicamente para a matriz
    int **matriz = (int**)malloc(n * sizeof(int*));
    for (i = 0; i < n; i++) {
        matriz[i] = (int*)malloc(n * sizeof(int));
    }

    // Inicializa a semente para gerar números aleatórios
    srand(time(NULL));

    // Preenche a matriz com números aleatórios
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            matriz[i][j] = rand() % 100 + 1; // Números aleatórios entre 1 e 100
        }
    }

    // Imprime a matriz
    printf("Matriz:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%4d ", matriz[i][j]);
        }
        printf("\n");
    }

    // Libera a memória alocada
    for (i = 0; i < n; i++) {
        free(matriz[i]);
    }
    free(matriz);

    return 0;
}
