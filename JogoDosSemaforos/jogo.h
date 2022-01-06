// Hugo Ferreira - 2020128305
#ifndef JOGODOSSEMAFOROS_JOGO_H
#define JOGODOSSEMAFOROS_JOGO_H

// Estrutura do tabuleiro
typedef struct tabuleiro{
    char **tabela;
    int linhas;
    int colunas;
    struct tabuleiro *tabprox;
}tabuleiro_;
//--------------------------------------------

// Estrutura de opções de jogo
typedef struct jogo{
    char jogaatual;
    int pedraA;
    int pedraB;
    int linha;
    int coluna;
    int totalA;
    int totalB;
}jogo_;
//--------------------------------------------

void criarTabuleiro(tabuleiro_ *tabuleiro);
void imprimeTabuleiro(tabuleiro_ *tabuleiro);
int jogarPeca(tabuleiro_ *tabuleiro, jogo_ *jogo);
void iniciaJogo(jogo_ *jogo);
void imprimeRegras();
void limpaTabuleiro(tabuleiro_ *tabuleiro);
int adicionarLinha(tabuleiro_ *tabuleiro, jogo_ *jogo);
int adicionarColuna(tabuleiro_ *tabuleiro, jogo_ *jogo);
char trocajogador(char jogador);
int colocarPedra(tabuleiro_ *tabuleiro, jogo_ *jogo);
void guardarJogo(tabuleiro_ *tabuleiro, jogo_ *jogo);
void carregarJogo(tabuleiro_ *tabuleiro, jogo_ *jogo);
int verificaLinha(tabuleiro_ *tabuleiro, jogo_ *jogo);
int verificaColuna(tabuleiro_ *tabuleiro, jogo_ *jogo);
int verificaDiagonal(tabuleiro_ *tabuleiro, jogo_ *jogo);
void guardarTurno(tabuleiro_ *tabuleiro);
#endif //JOGODOSSEMAFOROS_JOGO_H
