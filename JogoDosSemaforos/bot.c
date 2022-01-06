//
// Created by 35191 on 12/06/2021.
//
#include  <stdio.h>
#include  <stdlib.h>
#include "bot.h"
#include "menus.h"
#include "utils.h"

// Função que cria o tabuleiro para o jogo
void criarTabuleiroBot(tabuleiro__ *tabuleiro){
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

// Função que vai incializar a função jogo
void iniciaJogoBot(jogo__ *jogo){
    jogo->jogaatual = 'A';
    jogo->pedraA = 0;
    jogo->linha = 0;
    jogo->coluna = 0;
    jogo->totalA = 0;
}
//--------------------------------------------

// Função que verifica se o jogador ganhar por linhas
int verificaLinhaBot(tabuleiro__ *tabuleiro, jogo__ *jogo){
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
int verificaColunaBot(tabuleiro__ *tabuleiro, jogo__ *jogo){
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
int verificaDiagonalBot(tabuleiro__ *tabuleiro, jogo__ *jogo){
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
// Função que liberta a memoria alocadas para as linhas e colunas
void limpaTabuleiroBot(tabuleiro__ *tabuleiro){
    for(int i=0;i<tabuleiro->linhas;i++){
        free(tabuleiro->tabela[i]);
    }
    free(tabuleiro->tabela);
}
//--------------------------------------------

// Função que guarda o estado atual do jogo num ficheiro binário
void guardarJogoBot(tabuleiro__ *tabuleiro, jogo__ *jogo){
    FILE *gameSaver = fopen("jogoBot","wb");

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
    fwrite(&jogo->linha,sizeof (int),1,gameSaver);
    fwrite(&jogo->coluna, sizeof (int),1,gameSaver);
    fwrite(&jogo->totalA, sizeof (int),1,gameSaver);
    printf("\nJogo guardado com sucesso!\n");

    fclose(gameSaver);
}
//--------------------------------------------
// Função que adiciona colunas
int adicionarColunaBot(tabuleiro__ *tabuleiro, jogo__ *jogo){
    char* aux;
    if((jogo->totalA < 2 && jogo->jogaatual == 'A')){
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
        jogo->totalA++;
    }
    else{
        printf("O jogador A não pode adicionar mais colunas\n\n");
        return -1;
    }
    return 0;
}
//--------------------------------------------

// Função que troca o turno do jogador
char trocajogadorBot(char jogador){
    if(jogador=='A')
        return 'B';
    else
        return 'A';
}
//--------------------------------------------
// Função que adiciona linhas
int adicionarLinhaBot(tabuleiro__ *tabuleiro, jogo__ *jogo){
    char **aux;
    if((jogo->totalA>=2 && jogo->jogaatual == 'A')){
        printf("O jogador A não pode adicionar mais linhas\n\n");
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

    jogo->totalA++;
}
//--------------------------------------------

// Função para os jogadores colocarem as pedras
int colocarPedraBot(tabuleiro__ *tabuleiro, jogo__ *jogo){
    if((jogo->pedraA == 1  && jogo->jogaatual == 'A')){
        printf("\nJogador A não pode colocar mais pedras!\n\n");
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
    else{
        tabuleiro->tabela[jogo->linha][jogo->coluna]='X';
    }
    jogo->pedraA++;
    return 0;
}
//--------------------------------------------
// Função que imprime o tabuleiro de jogo
void imprimeTabuleiroBot(tabuleiro__ *tabuleiro){
    printf("\n----Tabuleiro----\n");
    for(int i=0; i<tabuleiro->linhas; i++){
        putchar('\n');
        for(int j=0; j<tabuleiro->colunas; j++){
            printf("%c",tabuleiro->tabela[i][j]);
        }
    }
}
//--------------------------------------------

// Função que gere as jogadores dos jogadores A e B
int jogarPecaBot(tabuleiro__ *tabuleiro, jogo__ *jogo){
    printf("\nJogador A indique a linha onde deseja jogar: \n");
    scanf("%d",&jogo->linha);
    printf("\nJogador A indique a coluna onde deseja jogar: \n");
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

//Função que controla o jogo entre o bot e o humano
int jogaBot(tabuleiro__ *tabuleiro, jogo__ *jogo){
    int opt;
    int ganhaA = 0;
    int ganhaB = 0;


        do{
            if(jogo->jogaatual == 'A'){
            switch (opt = menu2()){
                case BOT_PECA:
                    if((jogarPecaBot(tabuleiro, jogo)!=-1)){
                        jogo->jogaatual= trocajogadorBot(jogo->jogaatual);
                    }
                    imprimeTabuleiroBot(tabuleiro);
                    break;
                case BOT_PEDRA:
                    if((colocarPedraBot(tabuleiro, jogo)!=-1)){
                        jogo->jogaatual= trocajogadorBot(jogo->jogaatual);
                    }
                    imprimeTabuleiroBot(tabuleiro);
                    break;
                case BOT_LINHA:
                    if((adicionarLinhaBot(tabuleiro, jogo) != -1)){
                        jogo->jogaatual= trocajogadorBot(jogo->jogaatual);
                    }
                    imprimeTabuleiroBot(tabuleiro);
                    break;
                case BOT_COLUNA:
                    if((adicionarColunaBot(tabuleiro, jogo) != -1)){
                        jogo->jogaatual= trocajogadorBot(jogo->jogaatual);
                    }
                    imprimeTabuleiroBot(tabuleiro);
                    break;
                case BOT_GUARDARJOGO:
                    guardarJogoBot(tabuleiro, jogo);
                    return 0;
                case BOT_LEAVE:
                    limpaTabuleiroBot(tabuleiro);
                    return 0;
            }
             if(verificaLinhaBot(tabuleiro,jogo) == 2 || verificaColunaBot(tabuleiro,jogo) == 2 || verificaDiagonalBot(tabuleiro,jogo) == 2){
                printf("\n\nO jogador A ganhou!\n");
                ganhaA = 1;
                exit(0);
            }
            }
            else{
                jogo->linha = intUniformRnd(0,tabuleiro->linhas-1);
                jogo->coluna = intUniformRnd(0,tabuleiro->colunas-1);

                if(tabuleiro->tabela[jogo->linha][jogo->coluna]=='X'){
                    printf("\nNão pode realizar a jogada, pois tem uma pedra!\n\n");
                }
                else if(tabuleiro->tabela[jogo->linha][jogo->coluna]=='_')
                    tabuleiro->tabela[jogo->linha][jogo->coluna]='G';

                else if(tabuleiro->tabela[jogo->linha][jogo->coluna]=='G')
                    tabuleiro->tabela[jogo->linha][jogo->coluna]='A';

                else if(tabuleiro->tabela[jogo->linha][jogo->coluna]=='A')
                    tabuleiro->tabela[jogo->linha][jogo->coluna]='V';
                putchar('\n');
                printf("\nJogada do BOT\n");
                imprimeTabuleiroBot(tabuleiro);
                if(verificaLinhaBot(tabuleiro,jogo) == 1 || verificaColunaBot(tabuleiro,jogo)==1 || verificaDiagonalBot(tabuleiro,jogo) == 1){
                    printf("\n\nO Bot ganhou!\n");
                    ganhaB = 1;
                    exit(0);

                }
                jogo->jogaatual = trocajogadorBot(jogo->jogaatual);
            }
        }
        while(ganhaA < 1 || ganhaB < 1);
        return 0;
    }
//--------------------------------------------
