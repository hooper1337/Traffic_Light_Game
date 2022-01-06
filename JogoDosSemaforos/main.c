// Hugo Ferreira - 2020128305
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menus.h"
#include "jogo.h"
#include "utils.h"
#include "bot.h"


int main()
{
    int opt;
    int opt1;
    tabuleiro_ t;
    jogo_ j;
    tabuleiro__ t1;
    jogo__ j1;

    int ganhaA=0;
    int ganhaB=0;

    do
    {
        switch(opt = menu()){
            case OPT_CARREGAR_JOGO:
                carregarJogo(&t,&j);
                imprimeTabuleiro(&t);
                do{
                    switch (opt1 = menu1(j.jogaatual)){
                        case PECA:
                            if((jogarPeca(&t, &j)!=-1)){
                                j.jogaatual= trocajogador(j.jogaatual);
                            }
                            imprimeTabuleiro(&t);
                            break;
                        case PEDRA:
                            if((colocarPedra(&t, &j)!=-1)){
                                j.jogaatual= trocajogador(j.jogaatual);
                            }
                            imprimeTabuleiro(&t);
                            break;
                        case LINHA:
                            if((adicionarLinha(&t, &j) != -1)){
                                j.jogaatual= trocajogador(j.jogaatual);
                            }
                            imprimeTabuleiro(&t);
                            break;
                        case COLUNA:
                            if((adicionarColuna(&t, &j) != -1)){
                                j.jogaatual= trocajogador(j.jogaatual);
                            }
                            imprimeTabuleiro(&t);
                            break;
                        case GUARDARJOGO:
                            guardarJogo(&t, &j);
                        case OPT_CARREGAR_JOGO:
                            carregarJogo(&t,&j);
                            imprimeTabuleiro(&t);
                            break;
                        case OPT_LEAVE:
                            limpaTabuleiro(&t);
                            return 0;
                    }
                    if(verificaLinha(&t,&j) == 1 || verificaColuna(&t,&j)==1 || verificaDiagonal(&t,&j) == 1){
                        printf("\n\nO jogador B ganhou!\n");
                        exit(0);
                    }
                    else if(verificaLinha(&t,&j) == 2 || verificaColuna(&t,&j) == 2 || verificaDiagonal(&t,&j) == 2){
                        printf("\n\nO jogador A ganhou!\n");
                        exit(0);
                    }
                }
                while(ganhaA < 1 || ganhaB < 1);
                break;
            case OPT_INCIAR_JOGO:
                criarTabuleiro(&t);
                imprimeTabuleiro(&t);
                iniciaJogo(&j);
                do{
                switch (opt1 = menu1(j.jogaatual)){
                    case PECA:
                    if((jogarPeca(&t, &j)!=-1)){
                    j.jogaatual= trocajogador(j.jogaatual);
                    }
                    imprimeTabuleiro(&t);
                    break;
                    case PEDRA:
                    if((colocarPedra(&t, &j)!=-1)){
                    j.jogaatual= trocajogador(j.jogaatual);
                    }
                    imprimeTabuleiro(&t);
                    break;
                    case LINHA:
                    if((adicionarLinha(&t, &j) != -1)){
                    j.jogaatual= trocajogador(j.jogaatual);
                    }
                    imprimeTabuleiro(&t);
                    break;
                    case COLUNA:
                    if((adicionarColuna(&t, &j) != -1)){
                    j.jogaatual= trocajogador(j.jogaatual);
                    }
                    imprimeTabuleiro(&t);
                    break;
                    case GUARDARJOGO:
                    guardarJogo(&t, &j);
                    case OPT_LEAVE:
                    limpaTabuleiro(&t);
                        return 0;
                }
                if(verificaLinha(&t,&j) == 1 || verificaColuna(&t,&j)==1 || verificaDiagonal(&t,&j) == 1){
                    printf("\n\nO jogador B ganhou!\n");
                    exit(0);
                }
                else if(verificaLinha(&t,&j) == 2 || verificaColuna(&t,&j) == 2 || verificaDiagonal(&t,&j) == 2){
                    printf("\n\nO jogador A ganhou!\n");
                    exit(0);
                }
                }
                while(ganhaA < 1 || ganhaB < 1);
                break;
            case OPT_HUMANO_PC:
            criarTabuleiroBot(&t1);
            imprimeTabuleiroBot(&t1);
            iniciaJogoBot(&j1);
            jogaBot(&t1,&j1);
            case REGRAS:
                imprimeRegras();
                break;
            case OPT_SAIR:
                return 0;
        }
    }
    while(opt != OPT_SAIR);
    return 0;
}





