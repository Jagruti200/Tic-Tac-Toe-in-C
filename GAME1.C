#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <dos.h>

char square[10] = {'o', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

int checkWin();
void drawBoard();

int main() {
    int player = 1, i, choice;
    char mark; // X, O

    // Set background color and text color
    textbackground(BLUE);  // Background Color
    clrscr();
    textcolor(WHITE);  // Text Color

    do {
        drawBoard();
        player = (player % 2) ? 1 : 2;
        textcolor(YELLOW);
        printf("Player %d, enter the choice: ", player);
        scanf("%d", &choice);
        mark = (player == 1) ? 'X' : 'O';

        if (choice >= 1 && choice <= 9 && square[choice] == ('0' + choice)) {
            square[choice] = mark;
        } else {
            textcolor(RED);
            printf("Invalid option! Try again.\n");
            player--;
            getch();
        }

        i = checkWin();
        player++;

    } while (i == -1);

    drawBoard();

    if (i == 1) {
        textcolor(GREEN);
        printf("==> Player %d won!\n", --player);
        sound(1000);
        delay(500);
        nosound();
    } else {
        textcolor(CYAN);
        printf("==> Game Draw!\n");
    }

    getch();
    return 0;
}

int checkWin() {
    int winConditions[8][3] = {
        {1, 2, 3}, {4, 5, 6}, {7, 8, 9}, // Rows
        {1, 4, 7}, {2, 5, 8}, {3, 6, 9}, // Columns
        {1, 5, 9}, {3, 5, 7}  // Diagonals
    };

    int j;
    for (j = 0; j < 8; j++) {  
        if (square[winConditions[j][0]] == square[winConditions[j][1]] &&
            square[winConditions[j][1]] == square[winConditions[j][2]]) {
            return 1;
        }
    }

    for (j = 1; j <= 9; j++) {
        if (square[j] != 'X' && square[j] != 'O') {
            return -1;  
        }
    }

    return 0;  
}

void drawBoard() {
    clrscr();
    textcolor(WHITE);
    printf("\n\n\t");
    textcolor(LIGHTGREEN);
    printf(" Tic Tac Toe ");
    textcolor(WHITE);
    printf("\n\n");
    
    textcolor(LIGHTRED);
    printf("Player 1 (X) - Player 2 (O)\n\n\n");

    textcolor(WHITE);
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c  \n", square[1], square[2], square[3]);
    printf("_____|_____|_____\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c  \n", square[4], square[5], square[6]);
    printf("_____|_____|_____\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c  \n", square[7], square[8], square[9]);
    printf("     |     |     \n");
}
