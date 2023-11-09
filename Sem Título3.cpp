#include <stdio.h>

int VerificarVitoria(char tabuleiro[3][3], char jogador) {
    // Verificar linhas
    for (int i = 0; i < 3; i++) {
        if (tabuleiro[i][0] == jogador && tabuleiro[i][1] == jogador && tabuleiro[i][2] == jogador)
            return 1;
    }

    // Verificar colunas
    for (int i = 0; i < 3; i++) {
        if (tabuleiro[0][i] == jogador && tabuleiro[1][i] == jogador && tabuleiro[2][i] == jogador)
            return 1;
    }

    // Verificar diagonais
    if (tabuleiro[0][0] == jogador && tabuleiro[1][1] == jogador && tabuleiro[2][2] == jogador)
        return 1;
    if (tabuleiro[0][2] == jogador && tabuleiro[1][1] == jogador && tabuleiro[2][0] == jogador)
        return 1;

    return 0; // Não houve vitória para o jogador
}


int VerificarEmpate(char tabuleiro[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (tabuleiro[i][j] == ' ') {
                return 0; 
            }
        }
    }
    return 1; 
}

void ImprimirTabuleiro(char tabuleiro[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%c ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int JogadaValida(int linha, int coluna, char tabuleiro[3][3]) {
    if (linha < 0 || linha > 2 || coluna < 0 || coluna > 2 || tabuleiro[linha][coluna] != ' ') {
        return 0; 
    }
    return 1; 
}

int main() {
    char tabuleiro[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
    int linha, coluna;

    char jogador = 'X';

    while (1) {
        ImprimirTabuleiro(tabuleiro);

        printf("Jogador %c, digite a linha (0-2) e a coluna (0-2) separadas por um espaço: ", jogador);

        while (1) {
            if (scanf("%d %d", &linha, &coluna) != 2 || !JogadaValida(linha, coluna, tabuleiro)) {
                printf("Jogada inválida. Tente novamente.\n");
                while (getchar() != '\n'); 
            } else {
                break;
            }
        }

        tabuleiro[linha][coluna] = jogador;

        if (VerificarVitoria(tabuleiro, jogador)) {
            ImprimirTabuleiro(tabuleiro);
            printf("Jogador %c venceu!\n", jogador);
            break;
        }

        if (VerificarEmpate(tabuleiro)) {
            ImprimirTabuleiro(tabuleiro);
            printf("Empate!\n");
            break;
        }

        jogador = (jogador == 'X') ? 'O' : 'X';
    }

    return 0;
}
