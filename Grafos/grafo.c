/*
 * @file   grafo.c
 * @brief  Arquivo com as implementações de grafo.
 * @author Gustavo Rangel Bandeira Cauduro
 * @date   2021-09-20
 */

 /* Inclusões */
#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include "grafo.h"
#include "fila.h"

/* Funções */

Grafo_t* cria_grafo(int num_vertices) {
    
    Grafo_t* grafo = malloc(sizeof(Grafo_t));
    grafo->vertices = num_vertices;
    grafo->arestas = cria_lista();
    return grafo;
}

void libera_grafo(Grafo_t* grafo) {

    free_lista(grafo->arestas);
    free(grafo);
}

int insere_aresta(Grafo_t* grafo, int origem, int destino, int peso) {

    aresta a;
    a.origem = origem;
    a.destino = destino;
    a.peso = peso;

    return insere_lista_final(grafo->arestas, a);
}

Lista* adjacencia(Grafo_t* grafo, int vertice) {

    Lista* lista = grafo->arestas;
    Lista* resultado = cria_lista();

    if (Verifica_Lista_vazia(lista)) return NULL;

    elementol_t* elem = *lista;


    while (elem != NULL) {

        if (elem->dado.origem == vertice) {
            insere_lista_final(resultado, elem->dado);
        }
        elem = elem->proximo;
    }

    return resultado;
}

int* DFS(Grafo_t* grafo, int origem, int* visitado)
{
    Lista* adj = adjacencia(grafo, origem);
    visitado[origem] = 1;

    elementol_t* elem = *adj;

    while (elem != NULL) {

        if (visitado[elem->dado.destino] == 0) {
            DFS(grafo, elem->dado.destino, visitado);
        }
        elem = elem->proximo;
    }

    free_lista(adj);
    return visitado;
}

int* busca_em_profundidade(Grafo_t* grafo, int origem) {

    int* visitado = malloc(grafo->vertices * sizeof(int));
    for (int i = 0; i < grafo->vertices; i++) visitado[i] = 0;

    return DFS(grafo, origem, visitado);
}

int* busca_em_largura(Grafo_t* grafo, int origem)
{
    int* visitado = malloc(sizeof(int) * grafo->vertices);
    for (int i = 0; i < grafo->vertices; i++) visitado[i] = 0;

    fila_t* F = cria_fila();
    insere_fila(F, origem);

    while (!fila_vazia(F)) {

        int v = F->inicio->dado;
        remove_fila(F);
        if (visitado[v]) continue;

        visitado[v] = 1;

        Lista* adj = adjacencia(grafo, v);

        elementol_t* elem = *adj;
        while (elem != NULL) {

            insere_fila(F, elem->dado.destino);
            elem = elem->proximo;
        }

        free_lista(adj);
    }

    libera_fila(F);
    return visitado;
}

int* menor_caminho_dijkstra(Grafo_t* grafo, int origem)
{
    float* dist = malloc(sizeof(float) * grafo->vertices);
    int* anterior = malloc(sizeof(int) * grafo->vertices);
    int* visitado = malloc(sizeof(int) * grafo->vertices);
    int num_visitados = 0;

    for (int i = 0; i < grafo->vertices; i++) {

        dist[i] = 999999.0;
        anterior[i] = -1;
        visitado[i] = 0;
    }

    dist[origem] = 0;

    while (num_visitados < grafo->vertices) {

        int u = 0;
        for (int k = 1; k < grafo->vertices; k++) {

            if (visitado[u]) u = k;
            else break;
        }

        for (int k = 1; k < grafo->vertices; k++) {

            if (dist[k] < dist[u] && !visitado[k]) u = k;
        }

        printf("menor: %d\n", u);

        visitado[u] = 1;
        num_visitados++;

        Lista* adj = adjacencia(grafo, u);

        elementol_t* elem = *adj;

        while (elem != NULL) {

            int v = elem->dado.destino;
            int w = elem->dado.peso;
            float alt = dist[u] + w;
            printf("\taresta: %d -(%d)-> %d\n", u, w, v);
            if (alt < dist[v]) {

                dist[v] = alt;
                anterior[v] = u;
            }
            elem = elem->proximo;
        }
        free_lista(adj);
    }

    free(visitado);
    free(dist);

    return anterior;
}

int** matrix_adj(Grafo_t* g) {
    
    int** Matrix = (int**)malloc(sizeof(int*) * g->vertices);

    if (Matrix == NULL) { return; }

    for (int i = 0; i < g->vertices; i++) {
        Matrix[i] = (int*)malloc(sizeof(int) * g->vertices);
    }

    for (int j = 0; j< g->vertices; j++) {
        for (int k = 0; k < g->vertices; k++) {
            Matrix[j][k] = 0;
        }
    }

    elementol_t* elem = *(g->arestas);

    if (elem == NULL) { return; }

    while (elem != NULL) {
        Matrix[elem->dado.origem][elem->dado.destino] = 1;
        elem = elem->proximo;
    }

    return Matrix;
}

void printa_matriz(int** matriz, int nLinhas, int nColunas) {

    for (int i = 0; i < nLinhas; i++) {

        for (int j = 0; j < nColunas; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

void libera_matriz(int** matriz, int nLinhas) {

    for (int i = 0; i < nLinhas; i++) {
        free(matriz[i]);
    }
    free(matriz);
}

int grau_entrada(Grafo_t* g, int vertice) {

    int E = 0;

    elementol_t* elem = *(g->arestas);
    
    if (elem == NULL) { return; }
    
    while (elem != NULL) {
        if (vertice == (elem->dado.destino)) { E++; }
        elem = (elem->proximo);
    }

    return E;
}

int grau_saida(Grafo_t* g, int vertice) {

    int E = 0;

    elementol_t* elem = *(g->arestas);

    if (elem == NULL) { return; }

    while (elem != NULL) {
        if (vertice == (elem->dado.origem)) { E++; }
        elem = (elem->proximo);
    }

    return E;
}