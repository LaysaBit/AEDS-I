/**
 * @file grupos.h
 * @brief Possui funções de mural, funções dos integrantes dos grupos, de criação
 * de grupos, ser adicionado a um grupo existente e etc.
 */
#include "menu.h"
#pragma once

typedef struct integrantes{
    struct cadastro *user;
    struct integrantes *next;
} integrantes;

typedef struct group{
    char name[51];
    char about[301];
    struct cadastro *adm;
    struct integrantes *head4;
    struct board *head5;
    struct group *next;
} group;
/**
 * @brief Apenas cria um novo nó struct group e insere o user que criou
 * como administrador e o insere como integrante também.
 * @param user vai servir para criar um novo nó de struct integrantes.
*/
group * nodeGroups(cadastro *user);

/**
 * @brief dá printf de todos os nomes de todos os integrantes de um grupo.
 */
void showIntegrantes(integrantes *head);
/**
 * @brief Cria um novo nó de struct integrante e insere o user no parâmetro
 * struct cadastro e iguala a zero um ponteiro que deve apontar pro próximo
 * integrante.
 */ 
integrantes * criarIntegrantes(cadastro *user);

/**
 * @brief É uma função de ordenação que põe o integrante no primeiro valor
 * da lista de integrantes.
 */
void initialInsertUser(integrantes ** head, cadastro *user);
/**
 * @brief Uma função de ordenação que insere o integrante em qualquer lugar
 * da lista de integrantes que não seja a primeira posição.
 */
void insertUser(integrantes **prev, integrantes ** temp, cadastro *user);
/**
 * @brief Função principal para adicionar usuários em um grupo.
 * Com a função strcmp analisa toda a lista de integrantes.
 * Se o nome do integrante que queremos inserir é menor o nome do elemento analisado,
 * botamos o novo usuario antes desse integrantr que possui um nome maior lexicograficamente.
 */
void addUserToGroup(group ** grupo, cadastro *user);
/**
 * @brief Recebe um nome e procura na lista de grupos cadastrados se existe um grupo
 * com esse nome. Retornando o grupo, se for achado.
 */
group * findGroupByName(group *head6, char *name);
/**
 * @brief Dá printf nos grupos podendo ser os cadastrados ou os grupos de um
 * usuário em específico.
 */
void showGroups(group *head6);
/**
 * @brief Se não possuir nenhum grupo cadastrado, ele cria o primeiro grupo e o insere
 * seu endereço no head6 e no ponteiro de grupos do usuário que criou o grupo.
 * @param head6 é o endereço do ponteiro que aponta pro primeiro grupo da lista
 * de grupos cadastrados.
 */
void noGroups(group **head6, group **grupo, cadastro *user);
/**
 * @brief Função de ordenação. Insere o grupo na primeira posição da lista
 * de grupos, seja na lista de grupos cadastrados ou na lista de um usuário.
 */
void initialGroups(group **head6, group ** newnode);
/**
 * @brief Função de ordenação. Insere o grupo em qualquer posição menos na primeira
 *  posição da lista de grupos, seja na lista de grupos cadastrados ou na lista de um usuário.
 */
void orderGroups(group **prev, group **temp, group** newnode);
/**
 * @brief Função principal das listas de grupos.
 * Com a função strcmp analisa toda a lista encadeada de grupos.
 * Se o grupo que queremos inserir tiver um nome lexicograficamente menor do que
 * o nome do grupo analisado. Botamos esse grupo uma posição antes do grupo que está sendo analisado
 * como maior lexicograficamente.
 */
void newGroup(group **head, group **newnode);



