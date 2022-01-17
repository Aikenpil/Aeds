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
      
    elemento_t* aux;
     
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
    elemento_t* elem = *lista;
    
    if (Verifica_Lista_vazia(lista)) {
        return 0;
    }
    
    while (elem != NULL) {
        tam++;
        elem = elem->proximo;
    }
    return tam;
}

int insere_lista_inicio(Lista* lista, int valor) {
    
    if (lista == NULL) {
        return 1;
    }
    
    elemento_t* elem = malloc(sizeof(elemento_t));
    elem->dado = valor;
    elem->proximo = *lista;
    *lista = elem;
    return 0;
}

int insere_lista_final(Lista* lista, int valor) {

    if (lista == NULL) {
        return 1;
    }
    
    elemento_t* elem = malloc(sizeof(elemento_t));
    elem->dado = valor;
    elem->proximo = NULL;

    if (*lista == NULL) {
        *lista = elem;
    }
    else {
        elemento_t* aux = *lista;
        while (aux->proximo != NULL) {
            aux = aux->proximo;
        }
        aux->proximo = elem;
    }
    return 0;
}

int remove_lista_inicio(Lista* lista) {
    
    elemento_t* aux = *lista;
   
    if (Verifica_Lista_vazia(lista)) {
        return 1;
    }
    *lista = (*lista)->proximo;
    free(aux);
    return 0;
}

int remove_lista_final(Lista* lista) {
 
    elemento_t* anterior = NULL;
    elemento_t* elem = *lista;
    
    if (Verifica_Lista_vazia(lista)) {
        return 1;
    }
    
    while (elem->proximo != NULL) {
        anterior = elem;
        elem = elem->proximo;
    }

    if (elem == *lista) {
        *lista = NULL;
    }
    else {
        anterior->proximo = NULL;
        free(elem);
    }
    return 0;
}

void mostra_lista(Lista* lista) {
    
    elemento_t* elem = *lista;
    int posicao = 0;
    
    if (Verifica_Lista_vazia(lista)) {
        return;
    }
    printf("-------\n");
    while (elem != NULL)
    {
        printf("[%d]: %d\n", posicao, elem->dado);
        elem = elem->proximo;
        posicao++;
    }
    printf("-------\n");
}

int Mostra_nesimo_elemento(Lista* lista, int valor) {

    elemento_t* elem = *lista;
    int posicao = 0;

    if (Verifica_Lista_vazia(lista)) {
        (void)fprintf(stderr, "Lista vazia");
    }

    while (elem != NULL && posicao != valor) {
        elem = elem->proximo;
        posicao++;
    }  

    return elem->dado;
}