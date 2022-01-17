/*
 * @file   fila.h
 * @brief  Arquivo com as definições comuns a todos os tipos de fila.
 * @author Gustavo Rangel Bandeira Cauduro
 * @date   2021-07-05
 */

#pragma once

#ifndef __FILA_h__
#define __FILA_h__

typedef struct elementof_s {
    int dado;
    struct elementof_s* proximo;
} elementof_t;

typedef struct fila_s {
    elementof_t* inicio;
    elementof_t* fim;
    int qtd;
} fila_t;

fila_t* cria_fila();
void libera_fila(fila_t* fila);
int consulta_fila(fila_t* fila, int* valor);
int insere_fila(fila_t* fila, int valor);
int remove_fila(fila_t* fila);
int fila_vazia(fila_t* fila);
int tamanho_fila(fila_t* fila);

#endif// __FILA_h__