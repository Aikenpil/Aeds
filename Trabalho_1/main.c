/**
 * @file   main.c
 * @brief  Arquivo com a implementa��o das fun��es de inicializa��o do programa.
 * @author Gustavo Rangel Bandeira Cauduro
 * @date   2021-07-16
*/

/* Inclus�es */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "erros.h"
#include "TP1lib.h"

/**
 * Fun��o onde o programa � inicializado.
 * @param argc N�mero de argumentos passados para o programa pela linha
 * de comando.
 * @param argv Valores dos argumentos.
 * @return SUCESSO caso o programa termine conforme esperado, ou caso
 * contr�rio, o c�digo do erro ocorrido.
 */
int main(int argc, char** argv) {

	Arvore* arvore = cria_arvore();
	int opcao = NULL;
	char lixo;

	do {

		setbuf(stdin, NULL);

		imprimemenu();
		(void)scanf("%u%c", &opcao, &lixo);
		
		switch (opcao) {
		case 1:
			system("cls");
			Consulta_paciente(arvore);
			(void)printf("\n\n\n");
			system("pause");
			break;

		case 2:
			system("cls");
			Consulta_data(arvore);
			(void)printf("\n\n\n");
			system("pause");
			break;

		case 3:
			system("cls");
			Inserir_consulta(arvore);
			(void)printf("\n\n\n");
			system("pause");
			break;

		case 4:
			system("cls");
			Remover_prontuario(arvore);
			(void)printf("\n\n\n");
			system("pause");
			break;

		case 0:
			break;

		default:
			system("cls");
			(void)printf("Digite uma opcao valida\n");
			(void)printf("\n\n\n");
			system("pause");
			break;
		}
	} while (opcao != 0);
	
	free(arvore);
	// Se chegou at� aqui � porque correu tudo bem
	return SUCESSO;
}