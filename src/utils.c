#include "utils.h"
void freeList(Play* plays){
    Play* tmp;
    while(plays != NULL){
        tmp = plays;
        plays = tmp->nextPlay;
        free(tmp);
    }
}

void freeBoard(Game* game){
    for(int i=0; i<game->rows; i++)
        free(game->board[i]);
    free(game->board);
}

void freeAll(Game* game, Play* plays){
    freeList(plays);
    freeBoard(game);
}