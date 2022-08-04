#ifndef SRC_PLAYS_H
#define SRC_PLAYS_H
typedef struct play Play;
struct play{
    int row;
    int column;
    char player;
    char piece;
    Play* nextPlay;
};

void insertNode(Play** play, int row, int column, char player, char piece);
void showPlays(Play* play);
#endif //SRC_PLAYS_H
