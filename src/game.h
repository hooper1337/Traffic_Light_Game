#ifndef SRC_GAME_H
#define SRC_GAME_H
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
void printBoard(char** board, int rows, int columns);
void initializeBoard(char** board, int rows, int columns);
#endif //SRC_GAME_H
