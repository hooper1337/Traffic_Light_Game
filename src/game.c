#include "game.h"

void initGame(Game* game){
    srand(time(NULL));
    game->player = 'A';
    game->stonesA = 0;
    game->stonesB = 0;
    game->expandA = 0;
    game->expandB = 0;
    game->type = 0;
    game->win = 0;
    game->tie = 0;
    game->rows = game->columns = rand() % (5 + 1 - 3) + 3;
    game->board = createBoard(game->rows, game->columns);
    initializeBoard(game->board, game->rows, game->columns);
}

void changePlayer(Game* game){
    if(game->player == 'A')
        game->player = 'B';
    else
        game->player = 'A';
}

char** createBoard(int rows, int columns){
    char** board = NULL;

    board = malloc(sizeof (char*)* rows);
    if(board == NULL){
        printf("\nError in memory alocation for the board.\n");
        return NULL;
    }
    for(int i=0; i<rows; i++){
        board[i] = malloc(sizeof(char)* columns);
        if(board[i] == NULL){
            for(int j=0; j<i; j++)
                free(board[j]);
            free(board);
            printf("\nError in memory alocation for the columns of the board.\n");
            return NULL;
        }
    }
    return board;
}

char placePiece(char** board, int row, int column){
    char piece;
    if(board[row][column] == '_') {
        piece = 'G';
        board[row][column] = piece;
    }else if(board[row][column] == 'G'){
        piece = 'Y';
        board[row][column] = piece;
    }else if(board[row][column] == 'Y'){
        piece = 'R';
        board[row][column] = piece;
    }
    else
        return '.';
    return piece;
}

void initializeBoard(char** board, int rows, int columns){
    for(int i=0; i<rows; i++)
        for(int j=0; j<columns; j++)
            board[i][j] = '_';
}

int addRow(Game* game){
    char** aux;
    if((game->player == 'A' && game->expandA == 2) ||
        (game->player == 'B' && game->expandB == 2)){
        printf("\nPlayer %c you cant expand the board more.\n", game->player);
        return -1;
    }
    aux = realloc(game->board, sizeof(char*)*(game->rows+1));
    if(aux == NULL){
        printf("\nError allocating memory for the new row.\n");
        return -1;
    }
    aux[game->rows] = malloc(sizeof(char)*game->columns);
    if(aux[game->rows] == NULL){
        printf("\nError allocating memory for the new row.\n");
        return -1;
    }
    for(int i=0; i<game->columns; i++)
        aux[game->rows][i] = '_';
    game->rows++;
    game->board = aux;
    if(game->player == 'A')
        game->expandA++;
    else
        game->expandB++;
    return 1;
}

int addColumn(Game* game){
    char* aux;
    if((game->player == 'A' && game->expandA == 2) ||
       (game->player == 'B' && game->expandB == 2)){
        printf("\nPlayer %c you cant expand the board more.\n", game->player);
        return -1;
    }
    for(int i=0; i<game->rows; i++){
        aux = realloc(game->board[i], sizeof(char)*(game->columns+1));
        if(aux == NULL){
            printf("\nError allocating memory for the new column.\n");
            return -1;
        }
        aux[game->columns] = '_';
        game->board[i] = aux;
    }
    game->columns++;
    if(game->player == 'A')
        game->expandA++;
    else
        game->expandB++;
    return 1;
}

int validatePosition(Game* game, char* row, char* column){
    int r;
    int c;
    if(strlen(row) == 1 && strlen(column) == 1)
        if(isdigit(row[0]) == 1 && isdigit(column[0])){
            r = atoi(row);
            c = atoi(column);
            if((r < game->rows && r >= 0) || (c < game->columns && c  >=0))
                return 1;
        }
    return 0;
}



char placeRock(char** board, int row, int column){
    char piece;
    if(board[row][column] == '_'){
        piece = 'X';
        board[row][column] = piece;
        return piece;
    }
    return '.';
}


