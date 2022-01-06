// Hugo Ferreira - 2020128305
#include "menus.h"
#include "jogo.h"
#include <stdio.h>
#include <stdlib.h>

// Menu inicial
int menu(){
    int opt;

    do
    {
        printf("\n\nBem vindo ao jogo do semáforo!\n\n");
        printf("0 - Carregar jogo anterior\n");
        printf("1 - Iniciar jogo Humano vs Humano\n");
        printf("2 - Iniciar jogo Humano vs Computador\n");
        printf("3 - Regras\n");
        printf("4 - Sair do jogo\n");
        printf("\nOpcão: ");
        scanf("%d", &opt);
        printf("\n\n");
    }
    while(opt < OPT_CARREGAR_JOGO || opt > OPT_SAIR);
    return opt;
}
//--------------------------------------------

//Menu de jogo
int menu1(char jogador){
    int opt;

    do
    {
        printf("\n\nJogadas disponíveis!\n\n");
        printf("Faça a sua jogada jogador %c \n\n",jogador);
        printf("5 - Colocar peça\n");
        printf("6 - Colocar pedra\n");
        printf("7 - Adicionar Linha\n");
        printf("8 - Adicionar Coluna\n");
        printf("9 - Guardar Jogo\n");
        printf("10 - Sair do Jogo\n");

        printf("\nOpcão: ");
        scanf("%d", &opt);
        printf("\n\n\n");
    }
    while(opt < PECA || opt > OPT_LEAVE);
    return opt;
}
//--------------------------------------------

//Menu de jogo contra o bot
int menu2(){
    int opt;

    do
    {
        printf("\n\nJogadas disponíveis!\n\n");
        printf("Faça a sua jogada jogador A \n\n");
        printf("11 - Colocar peça\n");
        printf("12 - Colocar pedra\n");
        printf("13 - Adicionar Linha\n");
        printf("14 - Adicionar Coluna\n");
        printf("15 - Guardar Jogo\n");
        printf("16 - Sair do Jogo\n");

        printf("\nOpcão: ");
        scanf("%d", &opt);
        printf("\n\n\n");
    }
    while(opt < BOT_PECA || opt > BOT_LEAVE);
    return opt;
}
//--------------------------------------------