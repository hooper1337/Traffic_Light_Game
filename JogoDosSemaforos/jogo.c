// Hugo Ferreira - 2020128305
#include <stdio.h>
#include <stdlib.h>
#include "jogo.h"
#include "utils.h"
#include "menus.h"


// Função que cria o tabuleiro para o jogo
void criarTabuleiro(tabuleiro_ *tabuleiro){
    initRandom();
    tabuleiro->colunas = tabuleiro->linhas = intUniformRnd(3,5);
    tabuleiro->tabela = malloc(sizeof (char*)*tabuleiro->linhas);
    if(tabuleiro->tabela == NULL){
        printf("Erro ao alocar a memória");
        exit(0);
    }
    for(int i=0;i<tabuleiro->linhas;i++){
        tabuleiro->tabela[i]=malloc(sizeof (char)*tabuleiro->colunas);
        if(tabuleiro->tabela[i] == NULL){
            printf("Erro ao alocar a memória");
            exit(0);
        }
    }
    for(int i=0; i<tabuleiro->linhas;i++)
        for(int j=0;j<tabuleiro->colunas; j++){
            tabuleiro->tabela[i][j]='_';
        }
}
//--------------------------------------------

// Função que imprime o tabuleiro de jogo
void imprimeTabuleiro(tabuleiro_ *tabuleiro){
    printf("\n----Tabuleiro----\n");
    for(int i=0; i<tabuleiro->linhas; i++){
        putchar('\n');
        for(int j=0; j<tabuleiro->colunas; j++){
            printf("%c",tabuleiro->tabela[i][j]);
        }
    }
}
//--------------------------------------------

// Função que imprime as regras de jogo
void imprimeRegras(){
    printf("----Regras----\n");
    printf("\nGanha o jogador que coloque uma peça que permita formar uma linha, coluna ou diagonal completas com peças da mesma cor!\nCada jogador pode adicionar até duas linhas ou colunas\nCada jogador pode pôr uma pedra no tabuleiro!\n");
}
//--------------------------------------------

// Função que liberta a memoria alocadas para as linhas e colunas
void limpaTabuleiro(tabuleiro_ *tabuleiro){
    for(int i=0;i<tabuleiro->linhas;i++){
        free(tabuleiro->tabela[i]);
    }
    free(tabuleiro->tabela);
}
//--------------------------------------------

// Função que vai incializar a função jogo
void iniciaJogo(jogo_ *jogo){
    jogo->jogaatual = 'A';
    jogo->pedraA = 0;
    jogo->pedraB = 0;
    jogo->linha = 0;
    jogo->coluna = 0;
    jogo->totalA = 0;
    jogo->totalB = 0;
}
//--------------------------------------------

// Função que gere as jogadores dos jogadores A e B
int jogarPeca(tabuleiro_ *tabuleiro, jogo_ *jogo){
    printf("\nJogador %c indique a linha onde deseja jogar: \n",jogo->jogaatual);
    scanf("%d",&jogo->linha);
    printf("\nJogador %c indique a coluna onde deseja jogar: \n",jogo->jogaatual);
    scanf("%d",&jogo->coluna);

    if(tabuleiro->tabela[jogo->linha][jogo->coluna]=='X'){
        printf("\nNão pode realizar a jogada, pois tem uma pedra!\n\n");
        return -1;
        }
    else if(tabuleiro->tabela[jogo->linha][jogo->coluna]=='_')
        tabuleiro->tabela[jogo->linha][jogo->coluna]='G';

    else if(tabuleiro->tabela[jogo->linha][jogo->coluna]=='G')
        tabuleiro->tabela[jogo->linha][jogo->coluna]='A';

    else if(tabuleiro->tabela[jogo->linha][jogo->coluna]=='A')
        tabuleiro->tabela[jogo->linha][jogo->coluna]='V';

    return 0;
}
//--------------------------------------------

// Função que adiciona linhas
int adicionarLinha(tabuleiro_ *tabuleiro, jogo_ *jogo){
    char **aux;
    if((jogo->totalA>=2 && jogo->jogaatual == 'A') || (jogo->totalB>=2 && jogo->jogaatual == 'B')){
        printf("O jogador %c não pode adicionar mais linhas\n\n",jogo->jogaatual);
        return -1;
        }
    aux = realloc(tabuleiro->tabela, sizeof(char*)*(tabuleiro->linhas+1));

    if(aux == NULL){
        printf("Erro ao alocar a memória");
        exit(0);
    }

    aux[tabuleiro->linhas] = malloc(sizeof(char) * tabuleiro->colunas);

    if(aux[tabuleiro->linhas] == NULL){
        printf("Erro ao alocar a memória");
        exit(0);
    }

    for(int i=0; i< tabuleiro->colunas; i++){
        aux[tabuleiro->linhas][i] = '_';
    }

    tabuleiro->linhas++;
    tabuleiro->tabela = aux;

    if(jogo->jogaatual=='A')
        jogo->totalA++;
    else if(jogo->jogaatual=='B')
        jogo->totalB++;
    return 0;
}
//--------------------------------------------

// Função que adiciona colunas
int adicionarColuna(tabuleiro_ *tabuleiro, jogo_ *jogo){
    char* aux;
    if((jogo->totalA < 2 && jogo->jogaatual == 'A') || (jogo->totalB < 2 && jogo->jogaatual == 'B')){
    for(int i=0; i < tabuleiro->linhas; i++){
        aux = realloc(tabuleiro->tabela[i], sizeof(char) * (tabuleiro->colunas+1));
        if(aux == NULL){
            printf("Erro ao alocar a memória");
            exit(0);
        }
        aux[tabuleiro->colunas]='_';

        tabuleiro->tabela[i] = aux;

        aux = NULL;
    }
    tabuleiro->colunas++;
    if(jogo->jogaatual == 'A')
        jogo->totalA++;
    else if(jogo->jogaatual == 'B')
        jogo->totalB++;
}
    else{
        printf("O jogador %c não pode adicionar mais colunas\n\n",jogo->jogaatual);
        return -1;
    }
    return 0;
}
//--------------------------------------------
// Função que troca o turno do jogador
char trocajogador(char jogador){
    if(jogador=='A')
        return 'B';
    else
        return 'A';
}
//--------------------------------------------

// Função para os jogadores colocarem as pedras
int colocarPedra(tabuleiro_ *tabuleiro, jogo_ *jogo){
    if((jogo->pedraA == 1  && jogo->jogaatual == 'A') || (jogo->pedraB == 1 && jogo->jogaatual == 'B')){
        printf("\nJogador %c não pode colocar mais pedras!\n\n", jogo->jogaatual);
        return -1;
    }
    printf("\nJogador %c indique a linha onde deseja jogar: \n",jogo->jogaatual);
    scanf("%d",&jogo->linha);
    printf("\nJogador %c indique a coluna onde deseja jogar: \n",jogo->jogaatual);
    scanf("%d",&jogo->coluna);

    if(tabuleiro->tabela[jogo->linha][jogo->coluna] != '_'){
        printf("\nNão pode colocar a pedra aqui\n");
        return -1;
    }
    else
        tabuleiro->tabela[jogo->linha][jogo->coluna]='X';

    if(jogo->jogaatual == 'A')
        jogo->pedraA++;
    else
        jogo->pedraB++;
    return 0;
}
//--------------------------------------------

// Função que guarda o estado atual do jogo num ficheiro binário
void guardarJogo(tabuleiro_ *tabuleiro, jogo_ *jogo){
    FILE *gameSaver = fopen("jogo","wb");

    if(gameSaver == NULL){
        printf("Não foi possivel guardar o ficheiro");
        return;
    }
    fwrite(&tabuleiro->linhas, sizeof (int),1,gameSaver);
    fwrite(&tabuleiro->colunas,sizeof (int),1,gameSaver);

    for(int i=0; i< tabuleiro->linhas;i++){
        for(int j=0; j<tabuleiro->colunas;j++){
            fwrite(&tabuleiro->tabela[i][j],sizeof(char),1,gameSaver);
        }
    }
    fwrite(&jogo->jogaatual, sizeof (char),1,gameSaver);
    fwrite(&jogo->pedraA, sizeof (int),1,gameSaver);
    fwrite(&jogo->pedraB, sizeof (int ),1,gameSaver);
    fwrite(&jogo->linha,sizeof (int),1,gameSaver);
    fwrite(&jogo->coluna, sizeof (int),1,gameSaver);
    fwrite(&jogo->totalA, sizeof (int),1,gameSaver);
    fwrite(&jogo->totalB,sizeof (int),1,gameSaver);

    printf("\nA guardar jogo...\n");

    printf("\nJogo guardado com sucesso!\n");

    fclose(gameSaver);
}
//--------------------------------------------

// Função que carrega o jogo
void carregarJogo(tabuleiro_ *tabuleiro, jogo_ *jogo){

    FILE* savefile = fopen("jogo","rb");

    if(savefile == NULL){
        printf("Não foi possivel guardar o ficheiro");
        return;
    }

    fread(&tabuleiro->linhas,sizeof(int),1,savefile);
    fread(&tabuleiro->colunas,sizeof(int),1,savefile);

    tabuleiro->tabela = malloc(sizeof (char*)*tabuleiro->linhas);

    for(int i=0;i<tabuleiro->linhas;i++){
        tabuleiro->tabela[i]=malloc(sizeof (char)*tabuleiro->colunas);
        if(tabuleiro->tabela[i] == NULL){
            printf("Erro ao alocar a memória");
        }
    }

    for(int i=0; i<tabuleiro->linhas;i++){
        for(int j=0; j<tabuleiro->colunas;j++){
            fread(&tabuleiro->tabela[i][j],sizeof(char),1,savefile);
        }
    }
    fread(&jogo->jogaatual, sizeof (char),1,savefile);
    fread(&jogo->pedraA, sizeof (int),1,savefile);
    fread(&jogo->pedraB, sizeof (int ),1,savefile);
    fread(&jogo->linha,sizeof (int),1,savefile);
    fread(&jogo->coluna, sizeof (int),1,savefile);
    fread(&jogo->totalA, sizeof (int),1,savefile);
    fread(&jogo->totalB,sizeof (int),1,savefile);

    fclose(savefile);
}
//--------------------------------------------

// Função que verifica se o jogador ganhar por linhas
int verificaLinha(tabuleiro_ *tabuleiro, jogo_ *jogo){
    int g = 0;
    int y = 0;
    int v = 0;
    for(int i=0; i<tabuleiro->linhas;i++){
        for(int j=0; j<tabuleiro->colunas;j++){
            if(tabuleiro->tabela[i][j] == 'G'){
                g++;
            }
            else if(tabuleiro->tabela[i][j] == 'Y'){
                y++;
            }
            else if(tabuleiro->tabela[i][j] == 'V'){
                v++;
            }

    }
        if(g == tabuleiro->colunas || y == tabuleiro->colunas || v == tabuleiro->colunas){
            if(jogo->jogaatual == 'A'){
                return 1;
            }
            else{
                return 2;
            }
        }
        g = 0;
        y = 0;
        v = 0;
}
    return 0;
}
//--------------------------------------------

// Função que verifica se o jogador ganha por colunas
int verificaColuna(tabuleiro_ *tabuleiro, jogo_ *jogo){
    int g = 0;
    int y = 0;
    int v = 0;
    for(int i=0; i<tabuleiro->colunas;i++){
        for(int j=0; j<tabuleiro->linhas;j++){
            if(tabuleiro->tabela[j][i] == 'G'){
                g++;
            }
            else if(tabuleiro->tabela[j][i] == 'Y'){
                y++;
            }
            else if(tabuleiro->tabela[j][i] == 'V'){
                v++;
            }
    }
        if(g == tabuleiro->linhas || y == tabuleiro->linhas || v == tabuleiro->linhas){
            if(jogo->jogaatual == 'A'){
                return 1;
            }
            else{
                return 2;
            }
        }
        g = 0;
        y = 0;
        v = 0;
}
    return 0;
}
//--------------------------------------------

// Função que verifica se o jogador ganha por diagonais
int verificaDiagonal(tabuleiro_ *tabuleiro, jogo_ *jogo){
    int g=0;
    int y=0;
    int v=0;
    int j=tabuleiro->linhas;
    if(tabuleiro->linhas == tabuleiro->colunas){
        for(int i=0; i<tabuleiro->linhas;i++){
            if(tabuleiro->tabela[i][i] == 'G'){
                g++;
            }
            else if(tabuleiro->tabela[i][i] == 'Y'){
                y++;
            }
            else if(tabuleiro->tabela[i][i] == 'V'){
                v++;
            }
        }
        if(g == tabuleiro->linhas || y == tabuleiro->linhas || v == tabuleiro->linhas){
            if(jogo->jogaatual == 'A'){
                return 1;
            }
            else
                return 2;
        }
        else{
            v = 0;
            y = 0;
            g = 0;
            for(int i=0; i<tabuleiro->linhas;i++){
                if(tabuleiro->tabela[i][j] == 'G'){
                    g++;
                }
                else if(tabuleiro->tabela[i][j] == 'Y'){
                    y++;
                }
                else if(tabuleiro->tabela[i][j] == 'V'){
                    v++;
                }
                j--;
            }
            if(g == tabuleiro->linhas || y == tabuleiro->linhas || v == tabuleiro->linhas){
                if(jogo->jogaatual == 'A'){
                    return 1;
                }
                else{
                    return 2;
            }
        }
    }
}
    return 0;
}
//--------------------------------------------


void guardarTurno(tabuleiro_ *tabuleiro){
    tabuleiro_ *aux;

    aux = tabuleiro;
    while(aux->tabprox != NULL){
        aux = aux->tabprox;
    }
    aux->tabprox = malloc(sizeof (tabuleiro_));

    aux->colunas = tabuleiro->colunas;
    aux->linhas = tabuleiro->linhas;
    aux->tabela = tabuleiro->tabela;


   //criarTabuleiro(aux);
    for(int i=0; i<aux->linhas;i++){
        for(int j=0;j<aux->colunas;j++){
            aux->tabela[i][j]=tabuleiro->tabela[i][j];
        }
    }
    imprimeTabuleiro(aux->tabprox);
    aux->tabprox = NULL;
}

void mostrarJogadas(tabuleiro_ *tabuleiro){
    while(tabuleiro != NULL){
        imprimeTabuleiro(tabuleiro);
        tabuleiro = tabuleiro->tabprox;
    }
}

