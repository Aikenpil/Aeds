/**
 @file   main.c
 @brief  Arquivo com a implementa��o das fun��es de inicializa��o do programa.
 @author Gustavo Rangel Bandeira Cauduro
 @date   2021-06-28
*/

/* Inclus�es */
#include <stdio.h>
#include "erros.h"
#include "lista.h"

/**
 * Fun��o onde o programa � inicializado.
 * @param argc N�mero de argumentos passados para o programa pela linha
 * de comando.
 * @param argv Valores dos argumentos.
 * @return SUCESSO caso o programa termine conforme esperado, ou caso
 * contr�rio, o c�digo do erro ocorrido.
 */
int main(int argc, char** argv) {

	int valor, x, j = 0;
	
	Lista* lista = cria_lista();
	
	for (size_t i = 0; i < 50; i++) {
		insere_lista_final(lista, j);
		j += 10;
	}
	
	printf("\nTamanho da lista:%d", Verifica_Tamanho_lista(lista));
	mostra_lista(lista);

	printf("\nVai retornar o n-esimo valor da lista: \n");
	scanf("%d", &valor);

	x = Mostra_nesimo_elemento(lista, valor);

	printf("\n%d\n", x);

	// Se chegou at� aqui � porque correu tudo bem
	return SUCESSO;
}