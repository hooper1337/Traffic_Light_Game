// Hugo Ferreira - 2020128305
#ifndef JOGODOSSEMAFOROS_MENUS_H
#define JOGODOSSEMAFOROS_MENUS_H


//Menu inicial
#define OPT_CARREGAR_JOGO 0
#define OPT_INCIAR_JOGO 1
#define OPT_HUMANO_PC 2
#define REGRAS 3
#define OPT_SAIR 4
//--------------------------------------------

//Menu de jogo
#define PECA 5
#define PEDRA 6
#define LINHA 7
#define COLUNA 8
#define GUARDARJOGO 9
#define OPT_LEAVE 10
//--------------------------------------------
//Menu de jogo para jogar contra o bot
#define BOT_PECA 11
#define BOT_PEDRA 12
#define BOT_LINHA 13
#define BOT_COLUNA 14
#define BOT_GUARDARJOGO 15
#define BOT_LEAVE 16
//--------------------------------------------
int menu();
int menu1(char jogador);
int menu2();
#endif //JOGODOSSEMAFOROS_MENUS_H
