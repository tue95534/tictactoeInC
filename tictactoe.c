#include <stdio.h>

void printBoard(char *ptr) {
    printf(" 1 2 3 \n");
    printf("1 %c %c %c \n", *ptr, *(ptr+1),*(ptr+2));
    printf("2 %c %c %c \n", *(ptr+3), *(ptr+4),*(ptr+5));
    printf("3 %c %c %c \n", *(ptr+6), *(ptr+7),*(ptr+8));
}

void computerTurn(char *ptr) {
    for (int i = 0; i < 9; i++) {
        if (*(ptr+i) == '_') {
            *(ptr+i) = 'O';
            return;
        }
    }
}

int tieBoard(char *ptr) {
    int count = 0;
    for (int i = 0; i < 9; i++) {
        if (*(ptr + i) == '_') {
            count++;
        }
    }
    if (count == 0) {
        return 0;
    }
    else {
        return 1;
    }
}

int winLose(char *ptr, char letter) {
    int winCombos[8][3] = {  
       {0, 1, 2} ,   
       {3, 4, 5} ,
       {6, 7, 8} ,
       {0, 3, 6} ,
       {1, 4, 7} ,
       {2, 5, 8} ,
       {0, 4, 8} ,
       {2, 4, 6}};
    for (int i = 0; i < 8; i++) {
        if (*(ptr+winCombos[i][0]) == letter && *(ptr+winCombos[i][1]) == letter && *(ptr+winCombos[i][2]) == letter) {
            return 0;
        }
    }
    return 1;
}

int main()
{
    char board[10] = {'_','_','_','_','_','_','_','_','_','\0'};
    char *ptr = &board;
    printBoard(ptr);
    do {
        int location;
        printf("Play: ");
        
        if (scanf("%i", &location) == 1) {
            if (board[location] == '_') {
                board[location] = 'X';
                if (winLose(ptr, 'X') == 0) {
                    printBoard(ptr);
                    printf("\nYou Won!");
                    break;
                }
                if (tieBoard(ptr) == 0) {
                    printBoard(ptr);
                    printf("\nYou Tied!");
                    break;
                }
                computerTurn(ptr);
                printBoard(ptr);
                if (winLose(ptr, 'O') == 0) {
                    printBoard(ptr);
                    printf("\nYou Lost!");
                    break;
                }
                if (tieBoard(ptr) == 0) {
                    printBoard(ptr);
                    printf("\nYou Tied!");
                    break;
                }
            }
            else {
                printf("Invalid Location. Try Again \n");
            }
        }
        else {
            printf("Invalid Location. Please type a number between 0-8. \n");
            while(getchar() != '\n');
        }
    }
    while(5 == 5);
    printf("\n");
    return 0;
}




