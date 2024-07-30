#include <stdio.h>
#include <string.h>

// Definição da estrutura Funcionario
typedef struct {
    char nome[100];
    float salario;
    int identificador;
    char cargo[50];
} Funcionario;

// Função para preencher os campos da estrutura Funcionario
void preencherFuncionario(Funcionario *f) {
    printf("Digite o nome do funcionario: ");
    scanf(" %[^\n]", f->nome);
    printf("Digite o salario do funcionario: ");
    scanf("%f", &f->salario);
    printf("Digite o identificador do funcionario: ");
    scanf("%d", &f->identificador);
    printf("Digite o cargo do funcionario: ");
    scanf(" %[^\n]", f->cargo);
}

// Função para imprimir os campos da estrutura Funcionario
void imprimirFuncionario(const Funcionario *f) {
    printf("Nome: %s\n", f->nome);
    printf("Salario: %.2f\n", f->salario);
    printf("Identificador: %d\n", f->identificador);
    printf("Cargo: %s\n", f->cargo);
}

// Função para alterar o salário da estrutura Funcionario
void alterarSalario(Funcionario *f, float novoSalario) {
    f->salario = novoSalario;
}

// Função para encontrar e imprimir o funcionário com maior e menor salário
void imprimirMaiorMenorSalario(Funcionario *f, int n) {
    if (n <= 0) return;
    
    Funcionario *maior = &f[0];
    Funcionario *menor = &f[0];
    
    for (int i = 1; i < n; i++) {
        if (f[i].salario > maior->salario) {
            maior = &f[i];
        }
        if (f[i].salario < menor->salario) {
            menor = &f[i];
        }
    }
    
    printf("Funcionario com maior salario:\n");
    printf("Cargo: %s, Salario: %.2f\n", maior->cargo, maior->salario);
    
    printf("Funcionario com menor salario:\n");
    printf("Cargo: %s, Salario: %.2f\n", menor->cargo, menor->salario);
}

int main() {
    int n;
    printf("Digite o numero de funcionarios: ");
    scanf("%d", &n);
    
    Funcionario funcionarios[n];
    
    // Preencher dados dos funcionários
    for (int i = 0; i < n; i++) {
        printf("\nPreenchendo dados do funcionario %d\n", i + 1);
        preencherFuncionario(&funcionarios[i]);
    }
    
    // Imprimir dados dos funcionários
    printf("\nDados dos funcionarios:\n");
    for (int i = 0; i < n; i++) {
        printf("\nFuncionario %d\n", i + 1);
        imprimirFuncionario(&funcionarios[i]);
    }
    
    // Alterar salário de um funcionário específico (exemplo)
    int id;
    float novoSalario;
    printf("\nDigite o identificador do funcionario que deseja alterar o salario: ");
    scanf("%d", &id);
    printf("Digite o novo salario: ");
    scanf("%f", &novoSalario);
    
    for (int i = 0; i < n; i++) {
        if (funcionarios[i].identificador == id) {
            alterarSalario(&funcionarios[i], novoSalario);
            break;
        }
    }
    
    // Imprimir funcionário com maior e menor salário
    imprimirMaiorMenorSalario(funcionarios, n);
    
    return 0;
}
