#include <stdio.h>
#include <stdlib.h>

int main() {
    int tamanho;
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &tamanho);

    // Alocação dinâmica de memória
    int *vetor = (int *)malloc(tamanho * sizeof(int));
    if (vetor == NULL) {
        printf("Erro de alocação de memória.\n");
        return 1;
    }

    // Leitura dos elementos do vetor
    for (int i = 0; i < tamanho; i++) {
        printf("Digite o elemento %d: ", i + 1);
        scanf("%d", &vetor[i]);
    }

    // Impressão dos elementos na ordem inversa
    printf("Elementos na ordem inversa:\n");
    for (int i = tamanho - 1; i >= 0; i--) {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    // Liberação da memória alocada
    free(vetor);

    return 0;
}
