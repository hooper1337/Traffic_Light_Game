#ifndef SRC_UI_H
#define SRC_UI_H
#include "game.h"
#include "plays.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void printBoard(char** board, int rows, int columns);
void startInterface(Game* game, Play** play);
void playMenu(Game* game, Play** play);
#endif //SRC_UI_H