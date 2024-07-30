#include <stdio.h>

// Definição do enum para os meses do ano
typedef enum {
    JANEIRO = 1, FEVEREIRO, MARCO, ABRIL, MAIO, JUNHO,
    JULHO, AGOSTO, SETEMBRO, OUTUBRO, NOVEMBRO, DEZEMBRO
} Mes;

// Definição da struct Data
typedef struct {
    int dia;
    Mes mes;
    int ano;
} Data;

// Função para ler a data
void lerData(Data *d) {
    printf("Digite o dia: ");
    scanf("%d", &d->dia);
    
    printf("Digite o mes (1 para JANEIRO, 2 para FEVEREIRO, ..., 12 para DEZEMBRO): ");
    int mes;
    scanf("%d", &mes);
    d->mes = (Mes)mes;
    
    printf("Digite o ano: ");
    scanf("%d", &d->ano);
}

// Função para imprimir a data no formato dd/mm/aaaa
void imprimirData(const Data *d) {
    printf("%02d/%02d/%04d\n", d->dia, d->mes, d->ano);
}

int main() {
    Data data;

    // Ler a data
    lerData(&data);

    // Imprimir a data
    imprimirData(&data);

    return 0;
}
