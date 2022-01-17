#pragma once

#ifndef __PILHA_h__
#define __PILHA_h__

typedef struct elemento_s
{
    int dado;
    struct elemento_s* proximo;
} elemento_t;

typedef elemento_t* Pilha_t;

Pilha_t* cria_pilha();
void libera_pilha(Pilha_t* pilha);
int acessa_topo(Pilha_t* pilha, int* valor);
int insere_pilha(Pilha_t* pilha, int valor);
int remove_pilha(Pilha_t* pilha);
int tamanho_pilha(Pilha_t* pilha);
int pilha_vazia(Pilha_t* pilha);

#endif // __PILHA_h__