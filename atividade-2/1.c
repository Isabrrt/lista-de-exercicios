#include <stdio.h>

int main() {
    int N;
    printf("Digite o número de entrevistados: ");
    scanf("%d", &N);

    char sexo[N];
    int opiniao[N];
    int i;
    int fem_gostou = 0, masc_nao_gostou = 0;
    int total_fem = 0, total_masc = 0;

    // Leitura dos dados
    for (i = 0; i < N; i++) {
        printf("Digite o sexo do entrevistado %d (M/F): ", i + 1);
        scanf(" %c", &sexo[i]); // espaço antes de %c para consumir newline

        printf("Digite a opinião do entrevistado %d (1 - Gostou, 0 - Não gostou): ", i + 1);
        scanf("%d", &opiniao[i]);

        if (sexo[i] == 'F' || sexo[i] == 'f') {
            total_fem++;
            if (opiniao[i] == 1) {
                fem_gostou++;
            }
        } else if (sexo[i] == 'M' || sexo[i] == 'm') {
            total_masc++;
            if (opiniao[i] == 0) {
                masc_nao_gostou++;
            }
        }
    }

    // Cálculo das porcentagens
    double porcent_fem_gostou = (total_fem > 0) ? (double)fem_gostou / total_fem * 100 : 0;
    double porcent_masc_nao_gostou = (total_masc > 0) ? (double)masc_nao_gostou / total_masc * 100 : 0;

    // Exibição dos resultados
    printf("Porcentagem de pessoas do sexo feminino que gostaram do produto: %.2f%%\n", porcent_fem_gostou);
    printf("Porcentagem de pessoas do sexo masculino que não gostaram do produto: %.2f%%\n", porcent_masc_nao_gostou);

    return 0;
}
