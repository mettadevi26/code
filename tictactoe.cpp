#include <stdio.h>

char board[3][3];

// fungsi untuk inisialisasi papan
void initBoard() {
    char num = '1';
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = num++;
        }
    }
}

// fungsi tampil papan
void displayBoard() {
    printf("\n");
    for (int i = 0; i < 3; i++) {
        printf(" %c | %c | %c ", board[i][0], board[i][1], board[i][2]);
        if (i < 2) printf("\n---|---|---\n");
    }
    printf("\n\n");
}

// cek menang
int checkWin() {
    // baris & kolom
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
            return 1;
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
            return 1;
    }

    // diagonal
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
        return 1;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
        return 1;

    return 0;
}

// cek seri
int checkDraw() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != 'X' && board[i][j] != 'O')
                return 0;
        }
    }
    return 1;
}

// isi posisi
void makeMove(int pos, char player) {
    int row = (pos - 1) / 3;
    int col = (pos - 1) % 3;
    board[row][col] = player;
}

// validasi langkah
int isValidMove(int pos) {
    if (pos < 1 || pos > 9)
        return 0;

    int row = (pos - 1) / 3;
    int col = (pos - 1) % 3;

    if (board[row][col] == 'X' || board[row][col] == 'O')
        return 0;

    return 1;
}

int main() {
    int pos;
    char player = 'X';

    initBoard();

    while (1) {
        displayBoard();

        printf("Player %c, pilih posisi (1-9): ", player);
        scanf("%d", &pos);

        if (!isValidMove(pos)) {
            printf("Input tidak valid! Coba lagi.\n");
            continue;
        }

        makeMove(pos, player);

        if (checkWin()) {
            displayBoard();
            printf("Player %c MENANG!\n", player);
            break;
        }

        if (checkDraw()) {
            displayBoard();
            printf("Game SERI!\n");
            break;
        }

        // ganti player
        player = (player == 'X') ? 'O' : 'X';
    }

    return 0;
}