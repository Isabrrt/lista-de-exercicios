#include <stdio.h>
#include <stdlib.h>

int main() {
    int linhas, colunas;
    printf("Digite o número de linhas: ");
    scanf("%d", &linhas);
    printf("Digite o número de colunas: ");
    scanf("%d", &colunas);

    // Alocação dinâmica de memória para a matriz
    int **matriz = (int **)malloc(linhas * sizeof(int *));
    for (int i = 0; i < linhas; i++) {
        matriz[i] = (int *)malloc(colunas * sizeof(int));
    }

    // Leitura dos elementos da matriz
    printf("Digite os elementos da matriz:\n");
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            printf("Elemento [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }

    // Impressão da matriz original
    printf("Matriz original:\n");
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    // Impressão da matriz transposta
    printf("Matriz transposta:\n");
    for (int j = 0; j < colunas; j++) {
        for (int i = 0; i < linhas; i++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    // Liberação da memória alocada
    for (int i = 0; i < linhas; i++) {
        free(matriz[i]);
    }
    free(matriz);

    return 0;
}
