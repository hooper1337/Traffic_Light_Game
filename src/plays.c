#include <stdio.h>
#include <stdlib.h>
#include "plays.h"

void insertNode(Play** play, int row, int column, char player, char piece){
    Play* newPlay;
    newPlay = malloc(sizeof( Play));
    if(newPlay == NULL){
        printf("\nError allocating memory for the new play.\n");
        return;
    }
    newPlay->row = row;
    newPlay->column = column;
    newPlay->player = player;
    newPlay->piece = piece;
    newPlay->nextPlay = (*play);
    (*play) = newPlay;
}

void showPlays(Play* play){
    Play* aux = play;
    while(aux != NULL){
        printf("\nPlayer: %c", aux->player);
        printf("\nRow: %d", aux->row);
        printf("\nColumn: %d", aux->column);
        printf("\nPiece: %c", aux->piece);
        aux = aux->nextPlay;
    }
}
