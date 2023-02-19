/**
 * @file   TP1lib.h
 * @brief  Arquivo com as definições comuns a todos os tipos do TP-1.
 * @author Gustavo Rangel Bandeira Cauduro
 * @date   2021-07-17
 */

#pragma once

#ifndef __TP1LIB_h__
#define __TP1LIB_h__
#define TAMANHO_MAXIMO_OBSERVACAO (500 + 1)
#define TAMANHO_MAXIMO_NOME        (80 + 1)

/*
*Tipos de dados e funções usados no trabalho
*/

typedef struct data_s {

	int dia;
	int mes;
	int ano;

}data_t;

typedef struct consulta_s {

	data_t Data;
	char Observacao[TAMANHO_MAXIMO_OBSERVACAO];

}consulta_t;

typedef struct elemento_s* Lista;

typedef struct prontuario_s {

	char Nome[TAMANHO_MAXIMO_NOME];
	Lista Consulta;

}prontuario_t;

void imprimemenu();
int Data_valida(data_t data);

/*
*As definições comuns a todos os tipos de arvore
*/

typedef struct no_s
{
    prontuario_t prontuario;
    struct no_s* esq;
    struct no_s* dir;
} no_t;

typedef struct no_s* Arvore;

Arvore* cria_arvore();
void free_arvore(Arvore* arvore);
int arvore_vazia(Arvore* arvore);
int insere_arvore(Arvore* arvore, prontuario_t* prontuario);
int Consulta_paciente(Arvore* arvore);
void preordem_arvbin(Arvore* arvore, data_t data);
int Consulta_data(Arvore* arvore);
int Inserir_consulta(Arvore* arvore);
int Remover_prontuario(Arvore* arvore);

/*
*As definições comuns a todos os tipos de lista
*/

typedef struct elemento_s {

    consulta_t dado;
    struct elemento_s* proximo;

}elemento_t;

typedef struct elemento_s* Lista;

Lista* cria_lista();
void free_lista(Lista* lista);
int Verifica_Lista_vazia(Lista* lista);
int insere_lista_final(Lista* lista, char* observacao, data_t data);
void mostra_lista(Lista* lista);

#endif