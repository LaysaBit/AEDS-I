/**
*   @file mural.h
*   @brief Tem todas as funções referentes a publicações de um usuário ou grupo.
*/
#pragma once
#include "menu.h"

typedef struct board{
    char publi[300];
    struct board *prevpost; //ele aponta para um post mais antigo, n um post mais novo.
} board;
/**
 *  @brief faz display na tela de todas as publicações que o(s) usuario(s) fez.
 */
void printaBoard(board **mural);
/**
 * @brief cria um novo mural através de uma nova struct board e o conecta com uma
 * uma antiga postagem, se ela existir.
*/
board * createBoard(board **mural);
/**
 * @brief createStory é responsavel por pedir o que o usuário quer escrever na publicação.
 */
void createStory(board **mural);
