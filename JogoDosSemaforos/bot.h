//
// Created by 35191 on 12/06/2021.
//

#ifndef JOGODOSSEMAFOROS_BOT_H
#define JOGODOSSEMAFOROS_BOT_H

// Estrutura do tabuleiro
typedef struct tabuleiro1{
    char **tabela;
    int linhas;
    int colunas;
    struct tabuleiro *tabprox;
}tabuleiro__;
//--------------------------------------------

// Estrutura de opções de jogo
typedef struct jogo1{
    char jogaatual;
    int pedraA;
    int linha;
    int coluna;
    int totalA;
}jogo__;
//--------------------------------------------

int adicionarLinhaBot(tabuleiro__ *tabuleiro, jogo__ *jogo);
char trocajogadorBot(char jogador);
int jogaBot(tabuleiro__ *tabuleiro, jogo__ *jogo);
int jogarPecaBot(tabuleiro__ *tabuleiro, jogo__ *jogo);
void imprimeTabuleiroBot(tabuleiro__ *tabuleiro);
int colocarPedraBot(tabuleiro__ *tabuleiro, jogo__ *jogo);
int adicionarColunaBot(tabuleiro__ *tabuleiro, jogo__ *jogo);
void guardarJogoBot(tabuleiro__ *tabuleiro, jogo__ *jogo);
void limpaTabuleiroBot(tabuleiro__ *tabuleiro);
int verificaColunaBot(tabuleiro__ *tabuleiro, jogo__ *jogo);
int verificaDiagonalBot(tabuleiro__ *tabuleiro, jogo__ *jogo);
int verificaLinhaBot(tabuleiro__ *tabuleiro, jogo__ *jogo);
void iniciaJogoBot(jogo__ *jogo);
void criarTabuleiroBot(tabuleiro__ *tabuleiro);
#endif //JOGODOSSEMAFOROS_BOT_H
