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
            playGame(game, play);
            showPlays(*play);
        }
    }while(!exit);
}
