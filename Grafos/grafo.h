/*
 * @file   grafo.h
 * @brief  Arquivo com as definições comuns a todos os tipos de grafo.
 * @author Gustavo Rangel Bandeira Cauduro
 * @date   2021-09-20
 */

#pragma once

#ifndef __GRAFO_h__
#define __GRAFO_h__

typedef struct Grafo_s {
    int vertices;
    Lista* arestas;
} Grafo_t;

Grafo_t* cria_grafo(int num_vertices);
int insere_aresta(Grafo_t* grafo, int origem, int destino, int peso);
void libera_grafo(Grafo_t* grafo);
Lista* adjacencia(Grafo_t* grafo, int vertice);

int* busca_em_profundidade(Grafo_t* grafo, int origem);
int* busca_em_largura(Grafo_t* grafo, int origem);
int* menor_caminho_dijkstra(Grafo_t* grafo, int origem);

int** matrix_adj(Grafo_t* g);

void printa_matriz(int** matriz, int nLinhas, int nColunas);
void libera_matriz(int** matriz, int nLinhas);

int grau_entrada(Grafo_t* g, int vertice);
int grau_saida(Grafo_t* g, int vertice);

#endif // __GRAFO_h__