#include "files.h"
void saveGame(Game* game, Play* play){
    FILE* f;
    Play* aux = play;
    f = fopen("game.bin", "wb");
    if(f == NULL){
        printf("\nError opening the desired file.\n");
        return;
    }
    fwrite(&game->nPlays, sizeof(int), 1, f);
    fwrite(&game->stonesA, sizeof(int), 1, f);
    fwrite(&game->stonesB, sizeof(int), 1,f);
    fwrite(&game->expandA, sizeof(int), 1, f);
    fwrite(&game->expandB, sizeof(int), 1, f);
    fwrite(&game->rows, sizeof(int), 1, f);
    fwrite(&game->columns, sizeof(int), 1, f);
    while(aux != NULL){
        fwrite(&aux->row, sizeof(int), 1,f);
        fwrite(&aux->column, sizeof(int), 1,f);
        fwrite(&aux->player, sizeof(char), 1,f);
        fwrite(&aux->piece, sizeof(char), 1, f);
        aux = aux->nextPlay;
    }

    fclose(f);
}

void loadGame(Game* game, Play** play){
    FILE* f;
    int counter = 0;
    int row;
    int column;
    char player;
    char piece;
    f = fopen("game.bin", "rb");
    if(f == NULL){
        printf("\nError opening the desired file.\n");
        return;
    }
    fread(&game->nPlays, sizeof(int), 1, f);
    fread(&game->stonesA, sizeof(int), 1, f);
    fread(&game->stonesB, sizeof(int), 1,f);
    fread(&game->expandA, sizeof(int), 1, f);
    fread(&game->expandB, sizeof(int), 1, f);
    fread(&game->rows, sizeof(int), 1, f);
    fread(&game->columns, sizeof(int), 1, f);
    game->board = createBoard(game->rows, game->columns);
    initializeBoard(game->board, game->rows, game->columns);
    while(counter < game->nPlays){
        fread(&row, sizeof(int),1, f);
        fread(&column, sizeof(int), 1, f);
        fread(&player, sizeof(char), 1, f);
        fread(&piece, sizeof(char), 1,f);
        insertNode(play, row, column,player,piece);
        if(piece == 'X')
            placeRock(game->board, row, column);
        else
            placePiece(game->board, row, column);
        counter++;
    }
    fclose(f);

}