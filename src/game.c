#include "game.h"
#include "stdlib.h"
#include "stdio.h"
#include <time.h>
void initGame(Game* game){
    srand(time(NULL));
    game->player = 'A';
    game->stonesA = 0;
    game->stonesB = 0;
    game->expandA = 0;
    game->expandB = 0;
    game->type = 0;
    game->nPlays = 0;
    game->win = 0;
    game->tie = 0;
    game->rows = game->columns = rand() % (5 + 1 - 3) + 3;
    game->board = createBoard(game->rows, game->columns);
    initializeBoard(game->board, game->rows, game->columns);
}

char** createBoard(int rows, int columns){
    char** board = NULL;

    board = malloc(sizeof (char*)* rows);
    if(board == NULL){
        printf("\nError in memory alocation for the board.\n");
        return NULL;
    }
    for(int i=0; i<rows; i++){
        board[i] = malloc(sizeof(char)* columns);
        if(board[i] == NULL){
            for(int j=0; j<i; j++)
                free(board[j]);
            free(board);
            printf("\nError in memory alocation for the columns of the board.\n");
            return NULL;
        }
    }
    return board;
}

void initializeBoard(char** board, int rows, int columns){
    for(int i=0; i<rows; i++)
        for(int j=0; j<columns; j++)
            board[i][j] = '_';
}

void printBoard(char** board, int rows, int columns){
    if(columns == 4)
        printf("\n\t      BOARD\n");
    else if(columns == 3)
        printf("\n\t    BOARD\n");
    else if(columns == 5)
        printf("\n\t        BOARD\n");
    for(int i=0; i<rows; i++){
        putchar('\n');
        for(int j=0; j<columns; j++){
            if(j == 0 ){
                printf("\t| %c |", board[i][j]);
            }else{
                printf(" %c |", board[i][j]);
            }
        }
    }
}