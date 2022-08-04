#include <stdio.h>
#include "game.h"
#include "plays.h"
#include "ui.h"
int main() {
    Game game;
    Play* play = NULL;
    initGame(&game);
    startInterface(&game, &play);
    return 1;
}
