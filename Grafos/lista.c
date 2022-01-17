/*
 * @file   lista.c
 * @brief  Arquivo com as definições comuns a todos os tipos de lista.
 * @author Gustavo Rangel Bandeira Cauduro
 * @date   2021-06-28
 */

 /* Inclusões */
#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

/* Funções */
Lista* cria_lista() {

	Lista* lista = malloc(sizeof(Lista));
	if (lista != NULL) {
		*lista = NULL;
	}
	return lista;
}

void free_lista(Lista* lista) {
      
    elementol_t* aux;
     
    if (lista == NULL) return;

    while (*lista != NULL)
    {
        aux = *lista;
        *lista = (*lista)->proximo;
        free(aux);
    }
    free(lista);
}

int Verifica_Lista_vazia(Lista* lista) {

    if (lista == NULL || *lista == NULL) {
        return 1;
    }
    else {
        return 0;
    }
}

int Verifica_Tamanho_lista(Lista* lista) {

    int tam = 0;
    elementol_t* elem = *lista;
    
    if (Verifica_Lista_vazia(lista)) {
        return 0;
    }
    
    while (elem != NULL) {
        tam++;
        elem = elem->proximo;
    }
    return tam;
}

int insere_lista_final(Lista* lista, aresta valor) {

    if (lista == NULL) return 1;
    elementol_t* elem = malloc(sizeof(elementol_t));
    elem->dado = valor;
    elem->proximo = NULL;

    if (*lista == NULL)
    {
        *lista = elem;
        return 0;
    }

    elementol_t* aux = *lista;
    while (aux->proximo != NULL) aux = aux->proximo;
    aux->proximo = elem;
    return 0;
}

int remove_lista_inicio(Lista* lista) {

    aresta a;
    if (Verifica_Lista_vazia(lista)) return 1;

    elementol_t* aux = *lista;
    *lista = (*lista)->proximo;
    free(aux);
    return 0;
}



