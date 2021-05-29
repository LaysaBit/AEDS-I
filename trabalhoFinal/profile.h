/**
*   @file profile.h
*   @brief Esse arquivo lida com todas as funções referentes a parte de perfil da rede social.
*/
#pragma once
#include "menu.h"

typedef struct cadastro{
    char name[151];
    char email[257];
    char password[11];
    char occupation[31];
    char adress[151];
    char bio[301];
    struct board *head;
    struct friends *head2;
    struct msg *head3;
    struct group *head4;
} cadastro;

/**
*    @brief Função pra inicializar alguns cadastros para teste.
*/
void initUsers(cadastro *users);

/**
*    @brief Função que cadastra usuários. A variavel quantity guarda quantos cadastros
*    existem no sistema. Se a quantidade se igualar ao tamanho de espaço disponível para
*    os cadastros, é feito um realloc no vetor de cadastros.
*/
void createAccount(cadastro * users, int * lengthUsers, int* quantity);

/**
*    @brief Função que acha um usuário pelo email procurando-o pelo vetor de struct cadastro.
*/
int findUser(cadastro *users, int quantity, char* email);

/**
*   @brief Função que verifica a conta através do email. Se tiver um email igual ao que 
*   a pessoa botou no sistema, então o email é verificado como verdadeiro.
*/
int verifyAccount(cadastro * users, int quantity, char* email);

/**
*   @brief Função para verificar a senha. Se a senha que foi dada estiver no sistema, então é
*   verificado como verdadeiro.
*/
int verifyPassword(cadastro * users, int quantity, char* password, char*email);

/**
*   @brief Função para mostrar o perfil do usuario, publicamente, logo
*   só mostra o nome, ocupação e a bio.
*/
void showProfile(cadastro *users, int quantity, char *email);

/**
*   @brief Função para modificar os elementos do perfil que ficam expostos
*   publicamente, ou seja, nome, ocupação e bio.
*/
void modifyProfile(cadastro *users, int quantity, char* email);
