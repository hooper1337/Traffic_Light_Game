#ifndef SRC_UTILS_H
#define SRC_UTILS_H
#include "plays.h"
#include "game.h"
#include <stdlib.h>
void freeList(Play* plays);
void freeBoard(Game* game);
void freeAll(Game* game, Play* plays);
#endif //SRC_UTILS_H
