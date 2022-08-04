#include <stdio.h>
#include "game.h"
#include "plays.h"
int main() {
    Game game;
    Play* play = NULL;
    initGame(&game);
    printBoard(game.board, game.rows, game.columns);
    return 1;
}
