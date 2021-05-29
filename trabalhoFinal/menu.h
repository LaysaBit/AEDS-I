/**
 * @file menu.h
 * @brief Possui todos os cabeçalhos pro funcionamento do programa e as funções
 * de login e menu.
 */
#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "profile.h"
#include "grupos.h"
#include "amigos.h"
#include "mural.h"
#include "basicfunc.h"
#include "mensagem.h"
#include "settings.h"

/**
 * @brief Responsável por fazer a verificação de email, senha e a função de cadastro de usuários.
 */
void loginArea(cadastro* users, int * lengthUsers, int *quantity, struct group ** head6);
/**
 *  @brief Responsável pela camada de decisões mais externas como saber o que o 
 *  usuário quer fazer na página principal da rede social: acessar perfil, mensagens, mural, grupos ou configurações.
 *  @param users é o vetor de struct cadastros.
 *  @param email é o email do usuário.
 *  @param quantity é a quantidade de cadastros realmente feitos.  
 *  @param lengthUsers é o endereço do tamanho do vetor de struct cadastro.
 *  @param head6. Se alguem deslogar em uma conta e logar em outra, o paramêtro
 *   head6 mantem os grupos que foram criados/já existem no ultimo login. 
 */
void menu(cadastro *users, char* email, int *quantity, int * lengthUsers, struct group ** head6);
