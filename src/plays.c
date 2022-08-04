#include <stdio.h>
#include <stdlib.h>
#include "plays.h"

void insertNode(Play** play, int row, int column, char player){
    Play* newPlay;
    newPlay = malloc(sizeof( Play));
    if(newPlay == NULL){
        printf("\nError allocating memory for the new play.\n");
        return;
    }
    newPlay->row = row;
    newPlay->column = column;
    newPlay->player = player;
    newPlay->nextPlay = (*play);
    (*play) = newPlay;
}
