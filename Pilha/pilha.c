/*
 * @file   pilha.c
 * @brief  Arquivo com as definições comuns a todos os tipos de pilha.
 * @author Gustavo Rangel Bandeira Cauduro
 * @date   2021-07-05
 */

 /* Inclusões */
#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

/* Funções */

Pilha_t* cria_pilha() {
    
    Pilha_t* pilha = malloc(sizeof(Pilha_t));
    if (pilha != NULL) {
        *pilha = NULL;
    }
    return pilha;
}

void libera_pilha(Pilha_t* pilha) {
    
    if (pilha == NULL) {
        return;
    }
    elemento_t* aux;
    while ((*pilha) != NULL) {
        aux = *pilha;
        *pilha = (*pilha)->proximo;
        free(aux);
    }
    free(pilha);
}

int acessa_topo(Pilha_t* pilha, int* valor) {
    
    if (pilha_vazia(pilha)) {
        return 1;
    }
    *valor = (*pilha)->dado;
    return 0;
}

int insere_pilha(Pilha_t* pilha, int valor) {
    
    if (pilha == NULL) {
        return 1;
    }
    elemento_t* elem = malloc(sizeof(elemento_t));
    if (elem == NULL) {
        return 1;
    }
    elem->dado = valor;
    elem->proximo = *pilha;
    *pilha = elem;
    return 0;
}

int remove_pilha(Pilha_t* pilha) {
    
    if (pilha_vazia(pilha)) {
        return 1;
    }
    elemento_t* aux = *pilha;
    *pilha = aux->proximo;
    free(aux);
    return 0;
}

int tamanho_pilha(Pilha_t* pilha) {
    
    if (pilha == NULL) {
        return 0;
    }
    int contador = 0;
    elemento_t* elem = *pilha;
    while (elem != NULL) {
        contador++;
        elem = elem->proximo;
    }
    return contador;
}

int pilha_vazia(Pilha_t* pilha) {
    if (pilha == NULL) {
        return 1;
    }
    if (*pilha == NULL) {
        return 1;
    }
    return 0;
}