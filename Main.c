#include <stdio.h>
// making connect 4
// r = red, b = blue


int wincheck(char board[6][7]) {

    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 7 - 3; j++) {
            char c = board[i][j];
            if (c != ' ' &&
                c == board[i][j+1] &&
                c == board[i][j+2] &&
                c == board[i][j+3]) {
                return 1;
            }
        }
    }


    for (int j = 0; j < 7; j++) {
        for (int i = 0; i < 6 - 3; i++) {
            char c = board[i][j];
            if (c != ' ' &&
                c == board[i+1][j] &&
                c == board[i+2][j] &&
                c == board[i+3][j]) {
                return 1;
            }
        }
    }


    for (int i = 0; i < 6 - 3; i++) {
        for (int j = 0; j < 7 - 3; j++) {
            char c = board[i][j];
            if (c != ' ' &&
                c == board[i+1][j+1] &&
                c == board[i+2][j+2] &&
                c == board[i+3][j+3]) {
                return 1;
            }
        }
    }


    for (int i = 3; i < 6; i++) {
        for (int j = 0; j < 7 - 3; j++) {
            char c = board[i][j];
            if (c != ' ' &&
                c == board[i-1][j+1] &&
                c == board[i-2][j+2] &&
                c == board[i-3][j+3]) {
                return 1;
            }
        }
    }

    return 0;
}


int main() {
    char board[6][7] = {
        {' ',' ',' ',' ',' ',' ',' '},
        {' ',' ',' ',' ',' ',' ',' '},
        {' ',' ',' ',' ',' ',' ',' '},
        {' ',' ',' ',' ',' ',' ',' '},
        {' ',' ',' ',' ',' ',' ',' '},
        {' ',' ',' ',' ',' ',' ',' '}
    };

    int move_no = 0;
    int running = 1;
    char moves[2] = {'b', 'r'};
    int won = 0;

    while (running) {
        move_no++;

        if (move_no % 2 == 1) {
                printf("Red's Move \n");
        } else {
            printf("Blue's Move \n");
        }

        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 7; j++) {
                printf("|%c", board[i][j]);
            }
            printf("|\n");
        }

        printf("---------------\n");

        int move;
        printf("Which column? 1-7 (if game over then put 99) \n");
        scanf("%d", &move);

        if (move == 99) {
            printf("GAME OVER DETECTED. GGS");
            running = 0;
            break;
        }

        for (int i = 5; i >= 0; i--) {
            if (board[i][move - 1] == ' ') {
                board[i][move - 1] = moves[move_no % 2];
                break;
            } else {
                if (i == 0) {
                    printf("\n Invalid move try again \n");
                    move_no--;
                }
            }
        }

        won = wincheck(board);
        if (won != 0) {
            if (move_no % 2 == 1) {
                printf("Red Has Won The Game");
                running = 0;
            } else {
                printf("Blue Has Won The Game");
                running = 0;
            }
        }

    }

    return 0;
}
