#pragma once

#ifndef __LISTA_h__
#define __LISTA_h__

typedef struct elemento_s {

	int dado;
	struct elemento_s *proximo;

}elemento_t;

typedef struct elemento_s* Lista;

Lista* cria_lista();
void free_lista(Lista* lista);

int Verifica_Lista_vazia(Lista* lista);
int Verifica_Tamanho_lista(Lista* lista);

int insere_lista_inicio(Lista* lista, int valor);
int insere_lista_final(Lista* lista, int valor);
int remove_lista_inicio(Lista* lista);
int remove_lista_final(Lista* lista);

void mostra_lista(Lista* lista);

int Mostra_nesimo_elemento(Lista* lista, int valor);

#endif // __LISTA_h__