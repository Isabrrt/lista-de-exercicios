#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TURMAS 10
#define MAX_VAGAS 40

struct aluno {
    int mat;
    char nome[81];
    float notas[3];
    float media;
};

typedef struct aluno Aluno;

struct turma {
    char id; 
    int vagas; 
    Aluno* alunos[MAX_VAGAS];
};

typedef struct turma Turma;

Turma* turmas[MAX_TURMAS];

Turma* cria_turma(char id) {
    Turma* t = (Turma*)malloc(sizeof(Turma));
    if (t != NULL) {
        t->id = id;
        t->vagas = MAX_VAGAS;
        for (int i = 0; i < MAX_VAGAS; i++) {
            t->alunos[i] = NULL;
        }
    }
    return t;
}

void matricula_aluno(Turma* turma, int mat, char* nome) {
    if (turma->vagas == 0) {
        printf("Não há vagas disponíveis na turma %c.\n", turma->id);
        return;
    }

    for (int i = 0; i < MAX_VAGAS; i++) {
        if (turma->alunos[i] == NULL) {
            Aluno* a = (Aluno*)malloc(sizeof(Aluno));
            a->mat = mat;
            strncpy(a->nome, nome, 81);
            for (int j = 0; j < 3; j++) {
                a->notas[j] = 0.0;
            }
            a->media = 0.0;
            turma->alunos[i] = a;
            turma->vagas--;
            printf("Aluno matriculado na turma %c.\n", turma->id);
            return;
        }
    }
}

void lanca_notas(Turma* turma) {
    for (int i = 0; i < MAX_VAGAS; i++) {
        if (turma->alunos[i] != NULL) {
            printf("Lançar notas para o aluno %s (matrícula %d):\n", turma->alunos[i]->nome, turma->alunos[i]->mat);
            float soma = 0.0;
            for (int j = 0; j < 3; j++) {
                printf("Nota %d: ", j + 1);
                scanf("%f", &(turma->alunos[i]->notas[j]));
                soma += turma->alunos[i]->notas[j];
            }
            turma->alunos[i]->media = soma / 3.0;
        }
    }
}

void imprime_alunos(Turma* turma) {
    printf("Alunos da turma %c:\n", turma->id);
    for (int i = 0; i < MAX_VAGAS; i++) {
        if (turma->alunos[i] != NULL) {
            printf("Matrícula: %d, Nome: %s, Média: %.2f\n", turma->alunos[i]->mat, turma->alunos[i]->nome, turma->alunos[i]->media);
        }
    }
}

void imprime_turmas(Turma** turmas, int n) {
    for (int i = 0; i < n; i++) {
        if (turmas[i] != NULL) {
            printf("Turma %c:\n", turmas[i]->id);
            imprime_alunos(turmas[i]);
        }
    }
}

Turma* procura_turma(Turma** turmas, int n, char id) {
    for (int i = 0; i < n; i++) {
        if (turmas[i] != NULL && turmas[i]->id == id) {
            return turmas[i];
        }
    }
    return NULL;
}

int main() {
    int n = 0;
    char option;
    while (1) {
        printf("Menu:\n");
        printf("1. Criar turma\n");
        printf("2. Matricular aluno\n");
        printf("3. Lançar notas\n");
        printf("4. Imprimir alunos de uma turma\n");
        printf("5. Imprimir todas as turmas\n");
        printf("6. Sair\n");
        printf("Escolha uma opção: ");
        scanf(" %c", &option);

        if (option == '1') {
            if (n >= MAX_TURMAS) {
                printf("Número máximo de turmas atingido.\n");
                continue;
            }
            char id;
            printf("Digite o identificador da turma: ");
            scanf(" %c", &id);
            turmas[n] = cria_turma(id);
            n++;
        } else if (option == '2') {
            char id;
            int mat;
            char nome[81];
            printf("Digite o identificador da turma: ");
            scanf(" %c", &id);
            Turma* turma = procura_turma(turmas, n, id);
            if (turma == NULL) {
                printf("Turma não encontrada.\n");
                continue;
            }
            printf("Digite a matrícula do aluno: ");
            scanf("%d", &mat);
            printf("Digite o nome do aluno: ");
            scanf(" %80[^\n]", nome);
            matricula_aluno(turma, mat, nome);
        } else if (option == '3') {
            char id;
            printf("Digite o identificador da turma: ");
            scanf(" %c", &id);
            Turma* turma = procura_turma(turmas, n, id);
            if (turma == NULL) {
                printf("Turma não encontrada.\n");
                continue;
            }
            lanca_notas(turma);
        } else if (option == '4') {
            char id;
            printf("Digite o identificador da turma: ");
            scanf(" %c", &id);
            Turma* turma = procura_turma(turmas, n, id);
            if (turma == NULL) {
                printf("Turma não encontrada.\n");
                continue;
            }
            imprime_alunos(turma);
        } else if (option == '5') {
            imprime_turmas(turmas, n);
        } else if (option == '6') {
            break;
        } else {
            printf("Opção inválida.\n");
        }
    }

    // Liberar memória alocada
    for (int i = 0; i < n; i++) {
        if (turmas[i] != NULL) {
            for (int j = 0; j < MAX_VAGAS; j++) {
                if (turmas[i]->alunos[j] != NULL) {
                    free(turmas[i]->alunos[j]);
                }
            }
            free(turmas[i]);
        }
    }

    return 0;
}
