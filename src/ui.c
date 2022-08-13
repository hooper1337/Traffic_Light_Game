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
    initGame(game);
    printf("\nWelcome to the Traffic Light Game.\n");
    do{
        printf("\n\nWhat do you want to do?\n1 - Load previous game.\n2 - Play against human.\n3 - Play against computer.\n4 - Exit the game.\n\n>");
        fgets(option, 20, stdin);
        option[strlen(option)-1] = '\0';

        if(strcmp(option, "1\0") == 0){
            loadGame(game, play);
        }else if(strcmp(option, "2\0") == 0){
            exit = true;
            game->type = 1;
            playMenu(game, play);
        }else if(strcmp(option, "3\0") == 0){
            exit = true;
            game->type = 2;
            playMenu(game, play);
        }else if(strcmp(option, "4\0") == 0){
            //call function to free memory
            exit = true;
        }else
            printf("\nThats not a valid option.\n");
    }while(!exit);
}
char* getRowInput(){
    char *row = malloc(sizeof(char)* 256);
    printf("\nIntroduce the row you wish to play.\n>");
    fgets(row, 256, stdin);
    row[strlen(row)-1] = '\0';
    return row;
}

char* getColumnInput(){
    char *column = malloc(sizeof(char)* 256);
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
    char piece;
    row = getRowInput();
    column = getColumnInput();
    if(validatePosition(game, row, column) == 1){
        r = atoi(row);
        c = atoi(column);
        piece = placePiece(game->board, r, c);
        if(piece != '.'){
            game->nPlays++;
            insertNode(play, r, c, game->player, piece);
            verifyWinner(game);
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
    char piece;
    row = getRowInput();
    column = getColumnInput();
    if((game->player == 'A' && game->stonesA < 1) ||
        game->player == 'B' && game->stonesB < 1){
        if(validatePosition(game, row, column) == 1){
            r = atoi(row);
            c = atoi(column);
            piece = placeRock(game->board, r, c);
            if(piece != '.'){
                if(game->player == 'A')
                    game->stonesA++;
                else
                    game->stonesB++;
                game->nPlays++;
                insertNode(play,r, c, game->player, piece);
                changePlayer(game);
            }else{
                printf("\nYou cant place a rock there.\n");
                return;
            }
        }else{
            printf("\nYou cant play outside of the board.\n");
            return;
        }
    }else{
        printf("\nPlayer %c you cant place more rocks.\n", game->player);
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
        }else if(strcmp(option, "2\0") == 0){
            saveGame(game, *play);
            //call function to free memory
            exit = true;
        }else if(strcmp(option, "3\0") == 0){
            showPlays(*play, game->nPlays);
        }else if(strcmp(option, "4\0") == 0){
            playRock(game, play);
        }else if(strcmp(option, "5\0") == 0){
            addRow(game);
            insertNode(play, 0, 0, game->player, '0');
        }
        else if(strcmp(option, "6\0") == 0){
            addColumn(game);
            insertNode(play, 0, 0, game->player, '0');
        }
        if(game->type == 2)
            playBot(game, play);
        if(game->win == 1){
            //call function to free memory
            printBoard(game->board, game->rows, game->columns);
            resumeGame(*play);
            exit = true;
        }
    }while(!exit);
}



