#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <windows.h>
#include <conio.h>

// Define o tamanho do tabuleiro
#define BOARD_SIZE 8

// Cores do projeto
#define RED 12     // Vermelho brilhante
#define GREEN 10   // Verde brilhante
#define YELLOW 14  // Amarelo brilhante
#define BLUE 9     // Azul claro
#define WHITE 15   // Branco brilhante
#define CYAN 11    // Ciano brilhante
#define MAGENTA 13 // Magenta brilhante

char board[BOARD_SIZE][BOARD_SIZE];

void setColor(int color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}

void initializeBoard() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = '-';
        }
    }
}

void printBoard() {
    system("cls");
    // Cabeçalho das colunas com largura diferenciada
    printf("\n      ");
    printf("  A    "); // Coluna A com 6 caracteres
    for (char c = 'B'; c < 'A' + BOARD_SIZE; c++) {
        printf("  %c    ", c); // Demais colunas com 7 caracteres
    }
    printf("\n     +");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("------+");
    }
    
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("\n  %d  |", i + 1);
        for (int j = 0; j < BOARD_SIZE; j++) {
            int cellColor = ((i + j) % 2) ? BLUE : WHITE;
            setColor(cellColor);
            
            if (board[i][j] == '-') {
                printf("      ");
            } else {
                int pieceColor;
                switch(board[i][j]) {
                    case 'T': pieceColor = RED; break;
                    case 'B': pieceColor = GREEN; break;
                    case 'C': pieceColor = YELLOW; break;
                    case 'X': pieceColor = MAGENTA; break;
                    default: 
                    // Trata números 1-8 como rosa (MAGENTA)
                        if (board[i][j] >= '1' && board[i][j] <= '8') {
                            pieceColor = MAGENTA;
                        } else {
                            pieceColor = WHITE;
                        }
                        break;
                }
                setColor(pieceColor);
                printf("  %c   ", board[i][j]);
                setColor(cellColor);
            }
            setColor(WHITE);
            printf("|");
        }
        
        printf("\n     +");
        for (int k = 0; k < BOARD_SIZE; k++) {
            printf("------+");
        }
    }
    setColor(WHITE);
}

bool isValidPosition(int row, int col) {
    return row >= 0 && row < BOARD_SIZE && col >= 0 && col < BOARD_SIZE;
}

void waitForEnter() {
    printf("\nPressione Enter para continuar...");
    while(getchar() != '\n');
    getchar();
}

void moveRook() {
    int start_row, end_row;
    char start_col, end_col;
    
    initializeBoard();
    printBoard();
    
    printf("\nSelecione a posicao inicial da Torre (ex: 1 A): ");
    scanf("%d %c", &start_row, &start_col);
    
    start_row--;
    start_col = toupper(start_col) - 'A';
    
    if (!isValidPosition(start_row, start_col)) {
        printf("Posicao invalida!\n");
        waitForEnter();
        return;
    }
    
    board[start_row][start_col] = 'T';
    printBoard();
    
    printf("\nMovimentos possiveis da Torre (mesma linha ou coluna):\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (i != start_col) {
            printf("%c%d ", 'A' + i, start_row + 1);
            board[start_row][i] = 'X';
        }
        if (i != start_row) {
            printf("%c%d ", 'A' + start_col, i + 1);
            board[i][start_col] = 'X';
        }
    }
    printBoard();
    
    printf("\nSelecione a posicao final (ex: 1 H): ");
    scanf("%d %c", &end_row, &end_col);
    
    end_row--;
    end_col = toupper(end_col) - 'A';
    
    if (!isValidPosition(end_row, end_col)) {
        printf("Posicao invalida!\n");
        waitForEnter();
        return;
    }
    
    if (start_row != end_row && start_col != end_col) {
        printf("Movimento invalido para a Torre!\n");
        waitForEnter();
        return;
    }
    
    if (start_row == end_row) {
        int step = (end_col > start_col) ? 1 : -1;
        for (int col = start_col; col != end_col + step; col += step) {
            board[start_row][col - step] = '-';
            board[start_row][col] = 'T';
            printBoard();
            Sleep(300);
        }
    } else {
        int step = (end_row > start_row) ? 1 : -1;
        for (int row = start_row; row != end_row + step; row += step) {
            board[row - step][start_col] = '-';
            board[row][start_col] = 'T';
            printBoard();
            Sleep(300);
        }
    }
    
    printf("\nTorre movida com sucesso!\n");
    waitForEnter();
}

void moveBishop() {
    int start_row, end_row;
    char start_col, end_col;
    
    initializeBoard();
    printBoard();
    
    printf("\nSelecione a posicao inicial do Bispo (ex: 1 A): ");
    scanf("%d %c", &start_row, &start_col);
    
    start_row--;
    start_col = toupper(start_col) - 'A';
    
    if (!isValidPosition(start_row, start_col)) {
        printf("Posicao invalida!\n");
        waitForEnter();
        return;
    }
    
    board[start_row][start_col] = 'B';
    printBoard();
    
    printf("\nMovimentos possiveis do Bispo (diagonais):\n");
    for (int i = 1; i < BOARD_SIZE; i++) {
        int directions[4][2] = {{i,i}, {i,-i}, {-i,i}, {-i,-i}};
        for (int d = 0; d < 4; d++) {
            int new_row = start_row + directions[d][0];
            int new_col = start_col + directions[d][1];
            if (isValidPosition(new_row, new_col)) {
                printf("%c%d ", 'A' + new_col, new_row + 1);
                board[new_row][new_col] = 'X';
            }
        }
    }
    printBoard();
    
    printf("\nSelecione a posicao final (ex: 8 H): ");
    scanf("%d %c", &end_row, &end_col);
    
    end_row--;
    end_col = toupper(end_col) - 'A';
    
    if (!isValidPosition(end_row, end_col)) {
        printf("Posicao invalida!\n");
        waitForEnter();
        return;
    }
    
    int row_diff = abs(start_row - end_row);
    int col_diff = abs(start_col - end_col);
    
    if (row_diff != col_diff) {
        printf("Movimento invalido para o Bispo!\n");
        waitForEnter();
        return;
    }
    
    int row_dir = (end_row > start_row) ? 1 : -1;
    int col_dir = (end_col > start_col) ? 1 : -1;
    
    int current_row = start_row;
    int current_col = start_col;
    
    while (current_row != end_row && current_col != end_col) {
        board[current_row][current_col] = '-';
        current_row += row_dir;
        current_col += col_dir;
        board[current_row][current_col] = 'B';
        printBoard();
        Sleep(300);
    }
    
    printf("\nBispo movido com sucesso!\n");
    waitForEnter();
}

void showKnightMoves() {
    int start_row;
    char start_col;
    
    initializeBoard();
    printBoard();
    
    printf("\nSelecione a posicao do Cavalo (ex: 4 D): ");
    scanf("%d %c", &start_row, &start_col);
    
    start_row--;
    start_col = toupper(start_col) - 'A';
    
    if (!isValidPosition(start_row, start_col)) {
        printf("Posicao invalida!\n");
        waitForEnter();
        return;
    }
    
    board[start_row][start_col] = 'C';
    printBoard();
    
    int dr[] = {-2, -2, -1, -1, 1, 1, 2, 2};
    int dc[] = {-1, 1, -2, 2, -2, 2, -1, 1};
    
    printf("\nMovimentos possiveis do Cavalo (em L):\n");
    for (int i = 0; i < 8; i++) {
        int new_row = start_row + dr[i];
        int new_col = start_col + dc[i];
        
        if (isValidPosition(new_row, new_col)) {
            printf("%d. %c%d\n", i+1, 'A' + new_col, new_row + 1);
            board[new_row][new_col] = '0' + (i+1);
        }
    }
    printBoard();
    
    printf("\nSelecione um movimento (1-8) ou 0 para cancelar: ");
    int choice;
    scanf("%d", &choice);
    
    if (choice > 0 && choice <= 8) {
        int new_row = start_row + dr[choice-1];
        int new_col = start_col + dc[choice-1];
        
        if (isValidPosition(new_row, new_col)) {
            // Limpa todos os números de movimento
            for (int i = 0; i < 8; i++) {
                int clear_row = start_row + dr[i];
                int clear_col = start_col + dc[i];
                if (isValidPosition(clear_row, clear_col)) {
                    board[clear_row][clear_col] = '-';
                }
            }
            
            board[start_row][start_col] = '-';
            board[new_row][new_col] = 'C';
            printBoard();
            printf("\nCavalo movido para %c%d!\n", 'A' + new_col, new_row + 1);
        }
    }
    
    waitForEnter();
}

void showMenu() {
    printBoard();
    setColor(YELLOW);
    printf("\n  === XADREZ INTERATIVO ===\n");
    setColor(WHITE);
    printf("\n  1. Mover Torre");
    printf("\n  2. Mover Bispo");
    printf("\n  3. Mover Cavalo");
    printf("\n  4. Sair");
    setColor(GREEN);
    printf("\n\nEscolha uma opcao: ");
    setColor(WHITE);
}

int main() {
    system("color");
    initializeBoard();
    
    int choice;
    do {
        showMenu();
        scanf("%d", &choice);
        
        switch(choice) {
            case 1: moveRook(); break;
            case 2: moveBishop(); break;
            case 3: showKnightMoves(); break;
            case 4: printf("\nSaindo...\n"); break;
            default: printf("\nOpcao invalida!\n"); waitForEnter();
        }
    } while(choice != 4);
    
    return 0;
}