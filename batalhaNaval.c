#include <stdio.h>

int main() {
    int tabuleiro[10][10];
    int i, j;

    // ===== Inicializa o tabuleiro com 0 (água) =====
    for (i = 0; i < 10; i++)
        for (j = 0; j < 10; j++)
            tabuleiro[i][j] = 0;

    // ======== NAVIOS ========

    // Navio horizontal (3 posições)
    int linhaH = 1, colunaH = 6;
    for (i = 0; i < 3; i++)
        tabuleiro[linhaH][colunaH + i] = 3;

    // Navio vertical (3 posições)
    int linhaV = 3, colunaV = 0;
    for (i = 0; i < 3; i++)
        tabuleiro[linhaV + i][colunaV] = 3;

    // Navio diagonal descendente (3 posições)
    int linhaD1 = 4, colunaD1 = 2;
    for (i = 0; i < 3; i++)
        tabuleiro[linhaD1 + i][colunaD1 + i] = 3;

    // Navio diagonal ascendente (3 posições)
    int linhaD2 = 9, colunaD2 = 7;
    for (i = 0; i < 3; i++)
        tabuleiro[linhaD2 - i][colunaD2 + i] = 3;

    // ======== MATRIZES DE HABILIDADE ========

    int cone[5][5] = {0};
    for (i = 0; i < 5; i++)
        for (j = 0; j < 5; j++)
            if (j >= 2 - i && j <= 2 + i)
                cone[i][j] = 1;

    int cruz[5][5] = {0};
    for (i = 0; i < 5; i++)
        for (j = 0; j < 5; j++)
            if (i == 2 || j == 2)
                cruz[i][j] = 1;

    int octaedro[5][5] = {0};
    for (i = 0; i < 5; i++)
        for (j = 0; j < 5; j++)
            if (i + j >= 2 && i + j <= 6 && j - i <= 2 && i - j <= 2)
                octaedro[i][j] = 1;

    // ======== PONTOS DE ORIGEM ========
    int origemCruzLinha = 0, origemCruzColuna = 3;
    int origemConeLinha = 5, origemConeColuna = 2;
    int origemOctaedroLinha = 5, origemOctaedroColuna = 7;

    // ======== SOBREPOSIÇÃO DAS HABILIDADES ========
    for (i = 0; i < 5; i++)
        for (j = 0; j < 5; j++)
            if (cruz[i][j] == 1) {
                int linhaTab = origemCruzLinha + i;
                int colTab = origemCruzColuna + j - 2;
                if (linhaTab >= 0 && linhaTab < 10 && colTab >= 0 && colTab < 10)
                    if (tabuleiro[linhaTab][colTab] == 0)
                        tabuleiro[linhaTab][colTab] = 5;
            }

    for (i = 0; i < 5; i++)
        for (j = 0; j < 5; j++)
            if (cone[i][j] == 1) {
                int linhaTab = origemConeLinha + i;
                int colTab = origemConeColuna + j - 2;
                if (linhaTab >= 0 && linhaTab < 8 && colTab >= 0 && colTab < 8)
                    if (tabuleiro[linhaTab][colTab] == 0)
                        tabuleiro[linhaTab][colTab] = 5;
            }

    for (i = 0; i < 5; i++)
        for (j = 0; j < 5; j++)
            if (octaedro[i][j] == 1) {
                int linhaTab = origemOctaedroLinha + i - 2;
                int colTab = origemOctaedroColuna + j - 2;
                if (linhaTab >= 0 && linhaTab < 10 && colTab >= 0 && colTab < 10)
                    if (tabuleiro[linhaTab][colTab] == 0)
                        tabuleiro[linhaTab][colTab] = 5;
            }

    // ======== EXIBE O TABULEIRO FINAL ========

    printf("\n=== LEGENDA ===\n");
    printf("~ = Água (0)\n");
    printf("N = Navio (3)\n");
    printf("* = Área afetada por habilidade (5)\n\n");

    printf("   ");
    for (j = 0; j < 10; j++)
        printf("%2d ", j);
    printf("\n");

    for (i = 0; i < 10; i++) {
        printf("%2d ", i);
        for (j = 0; j < 10; j++) {
            if (tabuleiro[i][j] == 0)
                printf("~  ");
            else if (tabuleiro[i][j] == 3)
                printf("N  ");
            else if (tabuleiro[i][j] == 5)
                printf("*  ");
        }
        printf("\n");
    }

    return 0;
}
