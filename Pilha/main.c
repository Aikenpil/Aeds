/**
 @file   main.c
 @brief  Arquivo com a implementa��o das fun��es de inicializa��o do programa.
 @author Gustavo Rangel Bandeira Cauduro
 @date   2021-07-05
*/

/* Inclus�es */
#include <stdio.h>
#include "erros.h"
#include "pilha.h"

/**
 * Fun��o onde o programa � inicializado.
 * @param argc N�mero de argumentos passados para o programa pela linha
 * de comando.
 * @param argv Valores dos argumentos.
 * @return SUCESSO caso o programa termine conforme esperado, ou caso
 * contr�rio, o c�digo do erro ocorrido.
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

    // Se chegou at� aqui � porque correu tudo bem
    return SUCESSO;
}