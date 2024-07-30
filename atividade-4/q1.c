#include <stdio.h>

#define MAX_SIZE 1000

int is_coast(char map[][MAX_SIZE], int i, int j, int m, int n) {
    if (map[i][j] != '#') return 0; // Não é terra
    if (i > 0 && map[i-1][j] == '.') return 1; // Tem água acima
    if (i < m-1 && map[i+1][j] == '.') return 1; // Tem água abaixo
    if (j > 0 && map[i][j-1] == '.') return 1; // Tem água à esquerda
    if (j < n-1 && map[i][j+1] == '.') return 1; // Tem água à direita
    return 0;
}

int main() {
    int m, n, i, j, count = 0;
    char map[MAX_SIZE][MAX_SIZE];

    scanf("%d %d", &m, &n);
    for (i = 0; i < m; i++) {
        scanf("%s", map[i]);
    }

    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            if (is_coast(map, i, j, m, n)) {
                count++;
            }
        }
    }

    printf("%d\n", count);

    return 0;
}
