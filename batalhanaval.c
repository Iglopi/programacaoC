#include <stdio.h>
#include <stdbool.h>

// Tamanho do tabuleiro e dos navios
#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3

// Função para exibir o tabuleiro
void exibirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    printf("    A B C D E F G H I J\n");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        printf("%02d. ", i + 1);
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

// Função para verificar se uma posição está dentro dos limites do tabuleiro
bool posicaoValida(int linha, int coluna) {
    return linha >= 0 && linha < TAMANHO_TABULEIRO && coluna >= 0 && coluna < TAMANHO_TABULEIRO;
}

// Função para verificar se há sobreposição de navios
bool sobreposicaoNavio(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna, int direcao) {
    // Direção 0 = horizontal, Direção 1 = vertical, Direção 2 = diagonal principal, Direção 3 = diagonal inversa
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        int novaLinha = linha + (direcao == 1 || direcao == 2 ? i : 0) - (direcao == 3 ? i : 0);
        int novaColuna = coluna + (direcao == 0 || direcao == 2 ? i : 0) + (direcao == 3 ? i : 0);

        if (!posicaoValida(novaLinha, novaColuna) || tabuleiro[novaLinha][novaColuna] == 3) {
            return true; // A posição está fora dos limites ou já ocupada
        }
    }
    return false;
}

// Função para posicionar o navio horizontalmente
void posicionarNavioHorizontal(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linha][coluna + i] = 3;
    }
}

// Função para posicionar o navio verticalmente
void posicionarNavioVertical(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linha + i][coluna] = 3;
    }
}

// Função para posicionar o navio na diagonal principal
void posicionarNavioDiagonalPrincipal(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linha + i][coluna + i] = 3;
    }
}

// Função para posicionar o navio na diagonal inversa
void posicionarNavioDiagonalInversa(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linha + i][coluna - i] = 3;
    }
}

int main() {
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO] = {0};

    // Coordenadas iniciais dos navios
    int linhaHorizontal = 2, colunaHorizontal = 3;
    int linhaVertical = 4, colunaVertical = 6;
    int linhaDiagonal1 = 1, colunaDiagonal1 = 1;
    int linhaDiagonal2 = 5, colunaDiagonal2 = 8;

    // Posicionando os navios no tabuleiro, com verificações de sobreposição
    if (!sobreposicaoNavio(tabuleiro, linhaHorizontal, colunaHorizontal, 0)) {
        posicionarNavioHorizontal(tabuleiro, linhaHorizontal, colunaHorizontal);
    }
    if (!sobreposicaoNavio(tabuleiro, linhaVertical, colunaVertical, 1)) {
        posicionarNavioVertical(tabuleiro, linhaVertical, colunaVertical);
    }
    if (!sobreposicaoNavio(tabuleiro, linhaDiagonal1, colunaDiagonal1, 2)) {
        posicionarNavioDiagonalPrincipal(tabuleiro, linhaDiagonal1, colunaDiagonal1);
    }
    if (!sobreposicaoNavio(tabuleiro, linhaDiagonal2, colunaDiagonal2, 3)) {
        posicionarNavioDiagonalInversa(tabuleiro, linhaDiagonal2, colunaDiagonal2);
    }

    // Exibindo o tabuleiro com os navios
    printf("Tabuleiro de Batalha Naval:\n");
    exibirTabuleiro(tabuleiro);

    return 0;
}
