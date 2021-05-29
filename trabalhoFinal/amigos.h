/**
 * @file amigos.h
 * @brief Contém todas as funções referentes a seção de amigos do sistema.
 */
#pragma once
#include "menu.h"

typedef struct friends{
    cadastro *user;
    struct friends *next;
} friends;
/**
 * @brief Apenas cria um nó de struct friends com o nome de um usuário e
 * iguala a null o seu ponteiro de struct friends next.
 */ 
friends * createFriends(cadastro *users);
/**
 * @brief Se a pessoa nao tiver nenhum amigo, recebe um nó de struct friends e o
 * insere na primeira posição da sua lista de amigos.
 */
void noFriends(cadastro *user, friends** head);
/**
 * @brief É uma função de ordenação que põe o struct friends recebido no primeiro valor
 * da lista de integrantes.
 */
void initialInsert(friends **head, cadastro *users);
/**
 * @brief Uma função de ordenação que insere o integrante em qualquer lugar
 * da lista de struct friends que não seja a primeira posição.
 */
void middleOrEnd(friends **prev, friends** temp, cadastro *users);
/**
 * @brief Função principal das listas de amigos.
 * Com a função strcmp analisa toda a lista encadeada de amigos se for preciso.
 * Se o amigo que queremos inserir tiver um nome lexicograficamente menor do que
 * o nome do amigo analisado. Botamos esse amigo uma posição antes do amigo que está
 *  sendo analisado como maior lexicograficamente.
 */
void insertAndOrder(cadastro *user, friends** head, char* name);
/**
 * @brief Função que dá printf em todos os nomes das pessoas que estão na lista
 * de amigos de um usuário.
 */
void showFriends(cadastro *users, int quantity, friends** head, char *email);
/**
 * @brief Mostra todos os usuarios cadastrados no sistema.
 */
void showUsers(cadastro *users, int quantity);
/**
 * @brief Depois de mostrar as pessoas disponiveis pra adicionar, perguntar 
 * o nome da pessoa que o usuario quer adicionar, a função faz uma busca 
 * para achar o nome da pessoa no sistema e adiciona-la como amiga.
 * Depois disso, vai no sistema da pessoa que foi adicionada e faz ela adicionar
 * o outro usuário também. É um processo mútuo entre dois usuários. 
 */
void addFriends(cadastro *users, int quantity, friends** head, char *email);
/**
 * @brief Verifica se duas pessoas cadastradas já são amigas analisando a 
 * lista de amigos de um usuário.
 */ 
int areTheyFriends(char* name, friends* head, cadastro *users, char *email, int quantity);
/**
 * @brief Uma função de busca por meio do nome do usuário.
 */
int findUserByName(cadastro *users, int quantity, char* name);
/**
 * @brief Função para calcular quantas pessoas existem na lista de amigos de um usuário.
 */
int quantityFriends(friends *head);
/**
 * @brief transforma um vetor de char que pode ter letras maiusculas em minúsculas.
 */
char* toLower(char* s);
