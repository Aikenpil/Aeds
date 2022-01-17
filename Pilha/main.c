/**
 @file   main.c
 @brief  Arquivo com a implementação das funções de inicialização do programa.
 @author Gustavo Rangel Bandeira Cauduro
 @date   2021-07-05
*/

/* Inclusões */
#include <stdio.h>
#include "erros.h"
#include "pilha.h"

/**
 * Função onde o programa é inicializado.
 * @param argc Número de argumentos passados para o programa pela linha
 * de comando.
 * @param argv Valores dos argumentos.
 * @return SUCESSO caso o programa termine conforme esperado, ou caso
 * contrário, o código do erro ocorrido.
 */
int main(int argc, char** argv) {

    int valor = 0;
    int i;
    Pilha_t* pilha = cria_pilha();
    
    for (i = 0; i < 10; i++) {
        insere_pilha(pilha, i);
    }

    int k = tamanho_pilha(pilha);
    printf("\n+-------------+");
    while (tamanho_pilha(pilha) > 0) {

        k--;
        acessa_topo(pilha, &valor);
        (void)printf("\n|[%d] valor : %d|\n", k, valor);
        printf("+-------------+");
        remove_pilha(pilha);
    }

    // Se chegou até aqui é porque correu tudo bem
    return SUCESSO;
}