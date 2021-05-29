/**
 *  @file settings.h
 *  @brief Tem uma função para dar display no menu de configurações
 *  e possui a função principal do menu de configurações. 
 */
#pragma once
#include "menu.h"

/**
*    @brief Função criada pra dar display no menu de configuracao.
*/
void menuConfig();

/**
*    @brief Função principal que controla as configurações.
*    @param head6. Se alguem deslogar em uma conta e logar em outra, o paramêtro
*    head6 mantem os grupos que foram criados/já existem no ultimo login. 
*    @param user é o endereço do usuário. 
*    @param users é o vetor de struct cadastros.
*    @param lengthUsers é o endereço do tamanho do vetor de struct cadastro.
*    @param quantity é a quantidade de cadastros realmente feitos. 
*/
void setting(int choice, cadastro *user, cadastro *users, int * lengthUsers, int *quantity, group **head6);

