/*
 * @file   fila.c
 * @brief  Arquivo com as implementações de fila.
 * @author Gustavo Rangel Bandeira Cauduro
 * @date   2021-07-05
 */

 /* Inclusões */
#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

/* Funções */

fila_t* cria_fila() {

	fila_t* fila = malloc(sizeof(fila_t));
	if (fila != NULL) {
		fila->inicio = NULL;
		fila->fim = NULL;
		fila->qtd = 0;
	}
	return fila;
}

void libera_fila(fila_t* fila) {

	if (fila != NULL) {
		elementof_t* aux;
		while (fila->inicio != NULL) {

			aux = fila->inicio;
			fila->inicio = fila->inicio->proximo;
			free(aux);
		}
		free(fila);
	}
}

int consulta_fila(fila_t* fila, int* valor) {

	if (fila_vazia(fila)) {
		return 1;
	}
	*valor = fila->inicio->dado;
	return 0;
}

int insere_fila(fila_t* fila, int valor) {

	if (fila == NULL) {
		return 1;
	}
	elementof_t* elem = malloc(sizeof(elementof_t));
	if (elem != NULL) {
		elem->dado = valor;
		elem->proximo = NULL;
	}
	
	if (fila->fim == NULL) {
		fila->inicio = elem;
	}
	else {
		fila->fim->proximo = elem;
	}
	fila->fim = elem;
	fila->qtd++;

	return 0;
}

int remove_fila(fila_t* fila) {

	if (fila_vazia(fila)) {
		return 1;
	}
	elementof_t* aux = fila->inicio;
	fila->inicio = fila->inicio->proximo;
	free(aux);

	if (fila->inicio == NULL) {
		fila->fim = NULL;
	}
	fila->qtd--;
	return 0;
}

int fila_vazia(fila_t* fila) {

	if (fila == NULL) {
		return 1;
	}
	if (fila->qtd == 0) {
		return 1;
	}
	return 0;
}

int tamanho_fila(fila_t* fila) {

	if (fila == NULL){
		return 0;
	}
	else {
		return fila->qtd;
	}
}