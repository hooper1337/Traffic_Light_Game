#ifndef SRC_GAME_H
#define SRC_GAME_H
#include <stdbool.h>
#include <string.h>
#include "stdlib.h"
#include "stdio.h"
#include <time.h>
#include <ctype.h>
#include "plays.h"
typedef struct game{
    char** board;
    char player;
    int stonesA;
    int stonesB;
    int expandA;
    int expandB;
    int type;
    int nPlays;
    int win;
    int tie;
    int rows;
    int columns;
}Game;

void initGame(Game* game);
char** createBoard(int rows, int columns);
void initializeBoard(char** board, int rows, int columns);
int addRow(Game* game);
int addColumn(Game* game);
int playGame(Game* game, Play** play);
int placeRock(char** board, int row, int column);
void changePlayer(Game* game);
int placePiece(char** board, int row, int column);
#endif //SRC_GAME_H