/*
 * @file   fila.h
 * @brief  Arquivo com as definições comuns a todos os tipos de fila.
 * @author Gustavo Rangel Bandeira Cauduro
 * @date   2021-07-05
 */

#pragma once

#ifndef __FILA_h__
#define __FILA_h__

typedef struct elemento_s {
    int dado;
    struct elemento_s* proximo;
} elemento_t;

typedef struct fila_s {
    elemento_t* inicio;
    elemento_t* fim;
    int qtd;
} Fila_t;

Fila_t* cria_fila();
void libera_fila(Fila_t* fila);
int consulta_fila(Fila_t* fila, int* valor);
int insere_fila(Fila_t* fila, int valor);
int remove_fila(Fila_t* fila);
int fila_vazia(Fila_t* fila);
int tamanho_fila(Fila_t* fila);

#endif// __FILA_h__