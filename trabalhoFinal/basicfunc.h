/**
 * @file basicfunc.h
 * @brief Funções para pegar inteiro e vetor de caracteres. 
*/
#pragma once
#include "menu.h"
/**
 * @brief Função para pegar como input um número inteiro.
 */
int getInt();
/**
 * @brief Função para pegar como input um vetor de caracteres.
 * @param to é para onde o vetor de caracteres vai ser inserido
 * @param max limite máximo de caracteres possíveis nesse vetor de caracteres
 * de destino.
 */
int getString(char* to, int max);