#include <stdio.h>

int main() {
    int tabuleiro[10][10];
    int i, j;

    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // ===== Navios horizontais e verticais =====
    int linhaH = 2, colunaH = 4;
    for (i = 0; i < 3; i++) {
        tabuleiro[linhaH][colunaH + i] = 3;
    }

    int linhaV = 5, colunaV = 7;
    for (i = 0; i < 3; i++) {
        tabuleiro[linhaV + i][colunaV] = 3;
    }

    // ===== Navios diagonais =====
    // Diagonal descendente (linha+coluna)
    int linhaD1 = 0, colunaD1 = 0;
    for (i = 0; i < 3; i++) {
        if(tabuleiro[linhaD1 + i][colunaD1 + i] != 3) {
            tabuleiro[linhaD1 + i][colunaD1 + i] = 3;
        }
    }

    // Diagonal ascendente (linha decrescente, coluna crescente)
    int linhaD2 = 6, colunaD2 = 0;
    for (i = 0; i < 3; i++) {
        if(tabuleiro[linhaD2 - i][colunaD2 + i] != 3) {
            tabuleiro[linhaD2 - i][colunaD2 + i] = 3;
        }
    }

    // ===== Exibe coordenadas de cada navio =====
    printf("Coordenadas do navio horizontal:\n");
    for (i = 0; i < 3; i++) printf("(%d, %d)\n", linhaH, colunaH + i);

    printf("\nCoordenadas do navio vertical:\n");
    for (i = 0; i < 3; i++) printf("(%d, %d)\n", linhaV + i, colunaV);

    printf("\nCoordenadas do navio diagonal descendente:\n");
    for (i = 0; i < 3; i++) printf("(%d, %d)\n", linhaD1 + i, colunaD1 + i);

    printf("\nCoordenadas do navio diagonal ascendente:\n");
    for (i = 0; i < 3; i++) printf("(%d, %d)\n", linhaD2 - i, colunaD2 + i);

    printf("\n=== TABULEIRO 10x10 ===\n");
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
