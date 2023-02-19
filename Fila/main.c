/**
 @file   main.c
 @brief  Arquivo com a implementa��o das fun��es de inicializa��o do programa.
 @author Gustavo Rangel Bandeira Cauduro
 @date   2021-07-05
*/

/* Inclus�es */
#include <stdio.h>
#include "erros.h"
#include "fila.h"

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
    
    Fila_t* fila = cria_fila();
    
    for (int i = 0; i < 10; i++) {
        insere_fila(fila, 2 * i);
    }

    while (tamanho_fila(fila) > 0) {
        consulta_fila(fila, &valor);
        printf("valor: %d\n", valor);
        remove_fila(fila);
    }
	
	// Se chegou at� aqui � porque correu tudo bem
	return SUCESSO;
}