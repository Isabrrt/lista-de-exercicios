//a) Se você tentar compilar o código original, o compilador irá gerar uma mensagem de erro.
//b) O compilador emite a mensagem de erro porque você está tentando atribuir um valor inteiro (o valor de x) a um ponteiro (p). Isso é uma incompatibilidade de tipos e viola as regras da linguagem C.
//c) Não, a execução não será bem sucedida devido ao erro de compilação.
//d) Segue o código abaixo:

#include <stdio.h>
#include <stdlib.h>

int main(){
    int x, *p;

    x = 100;
    p = &x;  // Agora p aponta para o endereço de x

    printf("Valor de p = %p\tValor de *p = %d\n", p, *p);

    return 0;
}
//e) Sim, com a correção, o programa irá compilar e a resposta será: Valor de p = 0x7ffeefbff87c Valor de *p = 100

