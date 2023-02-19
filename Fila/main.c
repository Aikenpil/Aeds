/**
 @file   main.c
 @brief  Arquivo com a implementação das funções de inicialização do programa.
 @author Gustavo Rangel Bandeira Cauduro
 @date   2021-07-05
*/

/* Inclusões */
#include <stdio.h>
#include "erros.h"
#include "fila.h"

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
    
    Fila_t* fila = cria_fila();
    
    for (int i = 0; i < 10; i++) {
        insere_fila(fila, 2 * i);
    }

    while (tamanho_fila(fila) > 0) {
        consulta_fila(fila, &valor);
        printf("valor: %d\n", valor);
        remove_fila(fila);
    }
	
	// Se chegou até aqui é porque correu tudo bem
	return SUCESSO;
}