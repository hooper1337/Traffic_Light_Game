cmake_minimum_required(VERSION 3.17)
project(JogoDosSemaforos C)

set(CMAKE_C_STANDARD 99)

add_executable(JogoDosSemaforos main.c menus.c menus.h jogo.c jogo.h bot.c bot.h utils.c utils.h)