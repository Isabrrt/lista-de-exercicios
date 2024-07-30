#include <stdio.h>

int main() {
    int x, y, *p;

    y = 0;
    p = &y; // p agora aponta para o endereço de y

    x = *p; // x recebe o valor de y (que é 0)
    x = 4; // x agora vale 4
    (*p)++; // O valor que p aponta (y) é incrementado em 1, então y agora vale 1
    --x; // x é decrementado em 1, então x agora vale 3
    (*p) += x; // O valor que p aponta (y) é incrementado em x, então y agora vale 1 + 3 = 4

    printf("Valor final de x: %d\n", x);
    printf("Valor final de y: %d\n", y);

    return 0;
}
