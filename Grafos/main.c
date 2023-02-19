/**
 @file   main.c
 @brief  Arquivo com a implementação das funções de inicialização do programa.
 @author Gustavo Rangel Bandeira Cauduro
 @date   2021-09-20
*/

/* Inclusões */
#include <stdio.h>
#include "erros.h"
#include "lista.h"
#include "fila.h"
#include "grafo.h"

void mostra_array(int* arr, int n) {

    for (int i = 0; i < n; i++) {
        printf("[%d] %d\n", i, arr[i]);
    }
}

/**
 * Função onde o programa é inicializado.
 * @param argc Número de argumentos passados para o programa pela linha
 * de comando.
 * @param argv Valores dos argumentos.
 * @return SUCESSO caso o programa termine conforme esperado, ou caso
 * contrário, o código do erro ocorrido.
 */
int main(int argc, char** argv) {

    int nv = 6, tets;
    Grafo_t* g = cria_grafo(nv);

    for (int i = 0; i < 5; i++) {
       insere_aresta(g, i, (i + 1) % 5, 10);
    }

    insere_aresta(g, 1, 5, 1);
    insere_aresta(g, 5, 3, 1);

    /*int* dfs = busca_em_profundidade(g, 5);
    mostra_array(dfs, nv);
    (void)printf("\n");

    int* bfs = busca_em_largura(g, 0);
    mostra_array(bfs, nv);
    (void)printf("\n");

    int* caminho = menor_caminho_dijkstra(g, 0);
    mostra_array(caminho, nv);
    (void)printf("\n");*/

    int** matriz = matrix_adj(g);
    printa_matriz(matriz, nv, nv);
    libera_matriz(matriz, nv);

    tets = grau_entrada(g, 3);
    (void)printf("grau de entrada: %d\n", tets);
    tets = grau_saida(g, 3);
    (void)printf("grau de saida: %d\n", tets);

    libera_grafo(g);
    /*free(dfs);
    free(bfs);
    free(caminho);*/

	// Se chegou até aqui é porque correu tudo bem
	return SUCESSO;
}