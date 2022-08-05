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

void showPlays(Play* play, int nPlays){
    char plays[20];
    int counter = 0;
    int playsCounter;
    printf("\nHow many plays do you want to see?\n>");
    fgets(plays, 20, stdin);
    plays[strlen(plays)-1] = '\0';

    if(validateNumberOfPlays(plays, nPlays) == 1){
        playsCounter = atoi(plays);
        printf("\nPlays:\n");
        while (counter < playsCounter) {
            printf("\nPlayer: %c", play->player);
            printf("\nRow: %d", play->row);
            printf("\nColumn: %d", play->column);
            printf("\nPiece: %c\n", play->piece);
            play = play->nextPlay;
            counter++;
        }
        printf("\n");
    }else
        return;
}

int validateNumberOfPlays(char* plays, int nPlays){
    int number=0;
    if(strlen(plays) == 1){
        if (isdigit(plays[0]) == 1)
            number = atoi(plays);
    }else if(strlen(plays) == 2){
        if(strcmp(plays, "10\0") == 0)
            number = atoi(plays);
    }else{
        printf("\nThats not a valid number of plays.\n");
        return 0;
    }if(number == 0){
        printf("\nYou cant see 0 plays.\n");
        return 0;
    }if(number > nPlays){
        printf("\nGame only has %d plays yet.\n", nPlays);
        return 0;
    }
    return 1;
}
