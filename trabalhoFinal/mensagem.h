/**
 * @file mensagem.h
 * @brief Possui todas as funções referentes as mensagens.
 */

#include "menu.h"
#pragma once
typedef struct msg{
    char texto[150];
    struct cadastro *user;
    struct msg *prev; 
} msg;
/**
 * @brief Essa função manda mensagem para um outro usuário.
 * @param email serve pra mandar para a função ShowFriends,
 * que vai dar display na lista de amigos.
 */
void sendingMsg(cadastro *users, int quantity, char* email);
/**
 * @brief Mostra todas as mensagens disponíveis e depois a apaga.
 * Antes disso, lhe dá a oportunidade de responder a alguém mandando
 * uma mensagem pra essa pessoa.
 */
void showDM(msg **head, char* email, cadastro *users, int quantity);
/**
 * @brief Essa função limpa a caixa de mensagem.
 * @param head é o endereço do ponteiro pra caixa de mensagens.
 */
void freeList(msg **head);