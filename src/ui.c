#include "ui.h"

void printBoard(char** board, int rows, int columns){
    printf("\n\nBOARD\n");
    for(int i=0; i<rows; i++){
        putchar('\n');
        for(int j=0; j<columns; j++){
            if(j == 0 ){
                printf("| %c |", board[i][j]);
            }else{
                printf(" %c |", board[i][j]);
            }
        }
    }
}
void startInterface(Game* game, Play** play){
    char option[20] = "";
    bool exit = false;

    printf("\nWelcome to the Traffic Light Game.\n");
    do{
        printf("\nWhat do you want to do?\n1 - Load previous game.\n2 - Play against human.\n3 - Play against computer.\n4 - Exit the game.\n\n>");
        fgets(option, 20, stdin);
        option[strlen(option)-1] = '\0';

        if(strcmp(option, "1\0") == 0){

        }else if(strcmp(option, "2\0") == 0){
            exit = true;
            playMenu(game, play);

        }else if(strcmp(option, "3\0") == 0){
            exit = true;
        }else if(strcmp(option, "4\0") == 0){
            //call function to free memory
            exit = true;
        }
    }while(!exit);
}
char* getRowInput(){
    char* row;
    printf("\nIntroduce the row you wish to play.\n>");
    fgets(row, 256, stdin);
    row[strlen(row)-1] = '\0';
    return row;
}

char* getColumnInput(){
    char* column;
    printf("\nIntroduce the column you wish to play.\n>");
    fgets(column, 256, stdin);
    column[strlen(column)-1] = '\0';
    return column;
}

void playPiece(Game* game, Play** play){
    char* row;
    char* column;
    int r;
    int c;
    row = getRowInput();
    column = getColumnInput();
    if(validatePosition(game, row, column) == 1){
        r = atoi(row);
        c = atoi(column);
        if(placePiece(game->board, r, c) == 1){
            game->nPlays++;
            insertNode(play, r, c, game->player);
            changePlayer(game);
        }else{
            printf("\nYou cant play a piece there.\n");
            return;
        }
    }else{
        printf("\nYou cant play outside of the board.\n");
        return;
    }
}

void playRock(Game* game, Play** play){
    char* row;
    char* column;
    int r;
    int c;
    row = getRowInput();
    column = getColumnInput();
    if(validatePosition(game, row, column) == 1){
        r = atoi(row);
        c = atoi(column);
        if(placeRock(game->board, r, c) == 1){
            game->nPlays++;
            //insert play with a rock
            changePlayer(game);
        }else{
            printf("\nYou cant place a rock there.\n");
            return;
        }
    }else{
        printf("\nYou cant play outside of the board.\n");
        return;
    }
}

void playMenu(Game* game, Play** play){
    char option[20] = "";
    bool exit = false;
    do{
        printBoard(game->board, game->rows, game->columns);
        printf("\n\nYour turn player [%c].\n\n", game->player);
        printf("1 - Place a piece.\n");
        printf("2 - Save the game.\n");
        printf("3 - See 'K' plays.\n");
        printf("4 - Place a rock.\n");
        printf("5 - Add a line.\n");
        printf("6 - Add a column.\n");
        printf("7 - Exit game.\n\n>");
        fgets(option, 20, stdin);
        option[strlen(option)-1] = '\0';
        if(strcmp(option, "1\0") == 0){
            playPiece(game, play);
        }else if(strcmp(option, "4\0") == 0){
            playRock(game, play);
        }else if(strcmp(option, "5\0") == 0)
            addRow(game);
        else if(strcmp(option, "6\0") == 0)
            addColumn(game);
    }while(!exit);
}



