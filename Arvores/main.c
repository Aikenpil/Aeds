/**
 @file   main.c
 @brief  Arquivo com a implementa��o das fun��es de inicializa��o do programa.
 @author Gustavo Rangel Bandeira Cauduro
 @date   2021-07-15
*/

/* Inclus�es */
#include <stdio.h>
#include "erros.h"
#include "arvore.h"

/**
 * Fun��o onde o programa � inicializado.
 * @param argc N�mero de argumentos passados para o programa pela linha
 * de comando.
 * @param argv Valores dos argumentos.
 * @return SUCESSO caso o programa termine conforme esperado, ou caso
 * contr�rio, o c�digo do erro ocorrido.
 */
int main(int argc, char** argv) {

    Arvore* arv = cria_arvore();

    insere_arvore(arv, 50);
    insere_arvore(arv, 10);
    insere_arvore(arv, 100);

    printf("%d\n", consulta_arvore(arv, 100));

    remove_arvore(arv, 100);

    printf("%d\n", consulta_arvore(arv, 100));
    printf("%d\n", consulta_arvore(arv, 5));

    libera_arvore(arv);

	// Se chegou at� aqui � porque correu tudo bem
	return SUCESSO;
}