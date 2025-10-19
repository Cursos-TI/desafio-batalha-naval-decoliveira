#include <stdio.h>

int main() {
    int tabuleiro[10][10];
    int i, j;

    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    int linhaH = 2;
    int colunaH = 4;
    for (i = 0; i < 3; i++) {
        tabuleiro[linhaH][colunaH + i] = 3;
    }

    int linhaV = 5;
    int colunaV = 7;
    for (i = 0; i < 3; i++) {
        tabuleiro[linhaV + i][colunaV] = 3;
    }

    printf("Coordenadas do navio horizontal:\n");
    for (i = 0; i < 3; i++) {
        printf("(%d, %d)\n", linhaH, colunaH + i);
    }

    printf("\nCoordenadas do navio vertical:\n");
    for (i = 0; i < 3; i++) {
        printf("(%d, %d)\n", linhaV + i, colunaV);
    }

    printf("\n=== TABULEIRO ===\n");
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
