/*
 * @file   lista.h
 * @brief  Arquivo com as definições comuns a todos os tipos de lista.
 * @author Gustavo Rangel Bandeira Cauduro
 * @date   2021-06-28
 */

#pragma once

#ifndef __LISTA_h__
#define __LISTA_h__

typedef struct aresta
{
    int origem;
    int destino;
    int peso;
} aresta;

typedef struct elementol_s {

    aresta dado;
    struct elementol_s* proximo;

}elementol_t;

typedef struct elementol_s* Lista;

typedef struct Lista2
{
    elementol_t* inicio;
} Lista2;

Lista* cria_lista();
void free_lista(Lista* lista);

int Verifica_Lista_vazia(Lista* lista);
int Verifica_Tamanho_lista(Lista* lista);

int insere_lista_final(Lista* lista, aresta valor);
int remove_lista_inicio(Lista* lista);

#endif// __LISTA_h__