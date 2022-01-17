/*
 * @file   arvore.h
 * @brief  Arquivo com as definições comuns a todos os tipos de arvore.
 * @author Gustavo Rangel Bandeira Cauduro
 * @date   2021-07-15
 */

#pragma once

#ifndef __ARVORE_h__
#define __ARVORE_h__

typedef struct no_s {
    int dado;
    struct no* esq;
    struct no* dir;
}no_t;

typedef no_t* Arvore;

Arvore* cria_arvore();
void libera_arvore(Arvore* arvore);
int insere_arvore(Arvore* arvore, int valor);
int remove_arvore(Arvore* arvore, int valor);
int consulta_arvore(Arvore* arvore, int valor);
int altura_arvore(Arvore* arvore);
int arvore_vazia(Arvore* arvore);


#endif