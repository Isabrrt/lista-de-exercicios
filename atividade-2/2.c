#include <stdio.h>
#define NUM_ALUNOS 10

int main() {
    int N;
    printf("Digite o número de questões: ");
    scanf("%d", &N);

    char gabarito[N];
    printf("Digite o gabarito da prova: ");
    for (int i = 0; i < N; i++) {
        scanf(" %c", &gabarito[i]);
    }

    char respostas[NUM_ALUNOS][N];
    for (int i = 0; i < NUM_ALUNOS; i++) {
        printf("Digite as respostas do aluno %d: ", i + 1);
        for (int j = 0; j < N; j++) {
            scanf(" %c", &respostas[i][j]);
        }
    }

    double nota_por_questao = 10.0 / N;
    double notas[NUM_ALUNOS];
    int aprovados = 0;

    for (int i = 0; i < NUM_ALUNOS; i++) {
        notas[i] = 0;
        for (int j = 0; j < N; j++) {
            if (respostas[i][j] == gabarito[j]) {
                notas[i] += nota_por_questao;
            }
        }
        printf("Nota do aluno %d: %.2f\n", i + 1, notas[i]);
        if (notas[i] >= 6.0) {
            aprovados++;
        }
    }

    double porcentagem_aprovacao = (double)aprovados / NUM_ALUNOS * 100;
    printf("Porcentagem de aprovação: %.2f%%\n", porcentagem_aprovacao);

    return 0;
}
