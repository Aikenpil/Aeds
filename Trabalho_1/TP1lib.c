/**
 * @file   TP1lib.c
 * @brief  Arquivo com a implementação comum a todos os tipos do TP-1.
 * @author Gustavo Rangel Bandeira Cauduro
 * @date   2021-07-17
 */

/* inclusões */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TP1lib.h"

/*
Outras funções do programa
*/

void imprimemenu(){

    // funcao para imprimir o menu no terminal

    (void)printf("+-----------------------------------------+\n"
                 "| Bem-vindo a Prova / Trabalho Trimestral |\n"
                 "+-----------------------------------------+\n");

    (void)printf("\n");
    (void)printf("\n");

    (void)printf("Escolha o que vai a ser executado :\n");

    (void)printf("+-------------------------------------------+\n"
                 "| 1) Consultar paciente                     |\n"
                 "| 2) Consultar data                         |\n"
                 "| 3) Inserir consulta                       |\n"
                 "| 4) Remover prontuario                     |\n"
                 "| 0) Sair                                   |\n"
                 "+-------------------------------------------+\n");
}

int Data_valida(data_t data) {
    // verificar se o ano eh maior que 1900 e os meses estao entre [1,12]
    // retorna 0 se nao for valido e retorna 1 se for
    if ((data.ano > 1900) && (data.mes >= 1 && data.mes <= 12)) {
        if (data.mes == 1 || data.mes == 3 || data.mes == 5 || data.mes == 7 || data.mes == 8 || data.mes == 10 || data.mes == 12) {
            // para meses com 31 dias
            if (data.dia >= 1 && data.dia <= 31) return 1;
            else return 0;
        }
        if (data.mes == 4 || data.mes == 6 || data.mes == 9 || data.mes == 11) {
            // para meses com 30 dias
            if (data.dia >= 1 && data.dia <= 30) return 1;
            else return 0;
        }
        else {
            // fevereiro
            if (data.dia >= 1 && data.dia <= 28) return 1;
            else return 0; 
        }
    }
    else return 0;
}

/*
Implementação das funções que manipulam uma árvore
*/

Arvore* cria_arvore() {
    
    Arvore* raiz = malloc(sizeof(Arvore));
    if (raiz != NULL) *raiz = NULL;
    return raiz;
}

void libera_no(no_t* no) {
   
    if (no == NULL) return;
    libera_no(no->esq);
    libera_no(no->dir);
    free_lista(no->prontuario.Consulta);
    free(no);
    no = NULL;
}

void free_arvore(Arvore* arvore) {
    
    if (arvore == NULL) return;
    libera_no((*arvore));
    free(arvore);
}

int insere_arvore(Arvore* arvore, prontuario_t* prontuario) {
    
    //retorna 1 caso sucesso
    //retorna 0 caso erro

    if (arvore == NULL) return 0;
    no_t* novo = malloc(sizeof(no_t));
    if (novo == NULL) return 0;

    novo->prontuario.Consulta = prontuario->Consulta;
    strcpy(novo->prontuario.Nome, prontuario->Nome);
    novo->dir = NULL;
    novo->esq = NULL;

    if (*arvore == NULL) {
        *arvore = novo;
        return 0;
    }

    no_t* atual = *arvore;
    no_t* pai = NULL;

    while (atual != NULL) {

        pai = atual;
        if (prontuario->Nome == atual->prontuario.Nome) {
            free(novo);
            return 1;
        }

        if (strcmp(prontuario->Nome, atual->prontuario.Nome) > 0) atual = atual->dir;
        else atual = atual->esq;
    }

    if (strcmp(prontuario->Nome, pai->prontuario.Nome) > 0) pai->dir = novo;
    else pai->esq = novo;

    return 1;
}

no_t* remove_no(no_t* no) {
 
    no_t* n1, * n2;
    if (no->esq == NULL) {
        n2 = no->dir;
        free(no);
        return n2;
    }
    n1 = no;
    n2 = no->esq;
    while (n2->dir != NULL) {
        n1 = n2;
        n2 = n2->dir;
    }
    if (n1 != no)
    {
        n1->dir = n2->esq;
        n2->esq = no->esq;
    }
    n2->dir = no->dir;
    free_lista(no->prontuario.Consulta);
    free(no);
    return n2;
}

int arvore_vazia(Arvore* arvore) {
  
    //retorna 1 caso esteja vazia
    //retorna 0 caso não esteja vazia

    if (arvore == NULL) return 1;
    if (*arvore == NULL) return 1;
    return 0;
}

int Consulta_paciente(Arvore* arvore) {

    //retorna 1 caso sucesso
    //retorna 0 caso erro

    if (arvore_vazia(arvore)) {
        (void)fprintf(stderr, "Arvore vazia");
        return 0;
    }

    char nome[TAMANHO_MAXIMO_NOME];

    (void)printf("Digite o nome do paciente: ");
    fgets(nome, TAMANHO_MAXIMO_NOME, stdin);
    //Usei isso para remover o /n que o fgets pega
    int len = strlen(nome);
    if (nome[len - 1] == '\n') nome[--len] = 0;

    no_t* atual = *arvore;
    no_t* pai = NULL;

    while (atual != NULL) {
        if (strcmp(atual->prontuario.Nome, nome) == 0) {
            if (atual == *arvore) mostra_lista(&(atual->prontuario.Consulta));
            else {
                if (pai->dir == atual) mostra_lista(&(pai->dir->prontuario.Consulta));
                else mostra_lista(&(pai->esq->prontuario.Consulta));
            }
            return 1;
        }
        pai = atual;
        if (strcmp(nome, atual->prontuario.Nome) > 0) atual = atual->dir;
        else atual = atual->esq;
    }
    (void)fprintf(stderr, "\nNome nao encontrado\n");
    return 0;
}

void preordem_arvbin(Arvore* arvore, data_t data) {

    if (arvore_vazia(arvore)) return;
    
    Lista lista = ((*arvore)->prontuario.Consulta);

    if (*arvore != NULL) {

        while (lista != NULL) {
            if (lista->dado.Data.dia == data.dia && lista->dado.Data.mes == data.mes && lista->dado.Data.ano == data.ano) {
                puts((*arvore)->prontuario.Nome);
            }
            lista = lista->proximo;
        }
            preordem_arvbin(&((*arvore)->esq), data);
            preordem_arvbin(&((*arvore)->dir), data);
    }
}

int Consulta_data(Arvore* arvore) {

    //retorna 1 caso sucesso
    //retorna 0 caso erro

    if (arvore_vazia(arvore)) {
        (void)fprintf(stderr, "Arvore vazia");
        return 0;
    }

    data_t data;
    char lixo;

    (void)printf("Entre a data (DD/MM/AAAA): ");
    (void)scanf("%d/%d/%d%c", &data.dia, &data.mes, &data.ano, &lixo);
    // lixo para pegar o \n
    if (Data_valida(data) == 0) {
        (void)printf("Data invalida");
        return 0;
    }

    (void)printf("Consultas no dia (%d/%d/%d) : ", data.dia, data.mes, data.ano);
    // funcao para percorrer a arvore em pre ordem, sendo 1.raiz, 2.filho esquerdo, 3.filho direito
    preordem_arvbin(arvore, data);

    return 1;
}

int Inserir_consulta(Arvore* arvore) {
    
    //retorna 1 caso sucesso
    //retorna 0 caso erro

    data_t data;
    char nome[TAMANHO_MAXIMO_NOME];
    char observacao[TAMANHO_MAXIMO_OBSERVACAO];
    char lixo;

    (void)printf("Entre a data (DD/MM/AAAA): ");
    (void)scanf("%d/%d/%d%c", &data.dia, &data.mes, &data.ano, &lixo);
    if (Data_valida(data) == 0) {
        (void)fprintf(stderr, "Data invalida");
        return 0;
    }

    (void)printf("Entre com o nome do paciente: ");
    fgets(nome, TAMANHO_MAXIMO_NOME, stdin);
    //Usei isso para remover o /n que o fgets pega
    int len = strlen(nome);
    if (nome[len - 1] == '\n') nome[--len] = 0;

    (void)printf("Entre com a observacao: ");
    fgets(observacao, TAMANHO_MAXIMO_OBSERVACAO, stdin);
    //Usei isso para remover o /n que o fgets pega
    len = strlen(observacao);
    if (observacao[len - 1] == '\n') observacao[--len] = 0;

    no_t* atual = *arvore;

    while (atual != NULL) {

        if (strcmp(atual->prontuario.Nome, nome) == 0) {
            insere_lista_final(&(atual->prontuario.Consulta), observacao, data);
            return 1;
        }
        if (strcmp(atual->prontuario.Nome, nome) > 0) atual = atual->dir;
        else atual = atual->esq;
    }

    //se não há um prontuario, é criado um
    prontuario_t* novoprontuario = malloc(sizeof(prontuario_t));
    
    if (novoprontuario == NULL){
        (void)fprintf(stderr, "Falha ao criar prontuario");
        return 0;
    }

    Lista* lista = cria_lista();

    if (lista == NULL) {
        (void)fprintf(stderr, "Falha ao criar prontuario, lista de consultas nao criada");
        return 0;
    }
    
    strcpy(novoprontuario->Nome, nome);
    insere_lista_final(lista, observacao, data);
    novoprontuario->Consulta = *lista;
    insere_arvore(arvore, novoprontuario);

    return 1;
}

int Remover_prontuario(Arvore* arvore) {

    //retorna 1 caso sucesso
    //retorna 0 caso erro

    if (arvore_vazia(arvore)) {
        (void)fprintf(stderr, "Arvore vazia");
        return 0;
    }

    char nome[TAMANHO_MAXIMO_NOME];

    (void)printf("Entre com o nome do paciente: ");
    fgets(nome, TAMANHO_MAXIMO_NOME, stdin);
    //Usei isso para remover o /n que o fgets pega
    int len = strlen(nome);
    if (nome[len - 1] == '\n') nome[--len] = 0;

    no_t* atual = *arvore;
    no_t* pai = NULL;

    while (atual != NULL) {
        if (strcmp(atual->prontuario.Nome, nome) == 0) {
            if (atual == *arvore) *arvore = remove_no(atual);
            else {
                if (pai->dir == atual) pai->dir = remove_no(atual);
                else pai->esq = remove_no(atual);
            }
            (void)fprintf(stdout, "Prontuario apagado com sucesso");
            return 1;
        }
        pai = atual;
        if (strcmp(atual->prontuario.Nome, nome) > 0) atual = atual->dir;
        else atual = atual->esq;
    }
    fprintf(stderr, "\nNome nao encontrado\n");
    return 0;
}

/*
Implementação das funções que manipulam uma lista
*/

Lista* cria_lista() {

    Lista* lista = malloc(sizeof(Lista));
    if (lista != NULL) {
        *lista = NULL;
    }
    return lista;
}

void free_lista(Lista* lista) {

    elemento_t* aux;

    if (lista == NULL) return;

    while (*lista != NULL) {
        aux = *lista;
        *lista = (*lista)->proximo;
        free(aux);
    }
    free(lista);
}

int Verifica_Lista_vazia(Lista* lista) {

    //retorna 1 caso sucesso
    //retorna 0 caso nao tiver vazia

    if (lista == NULL || *lista == NULL) {
        return 1;
    }
    else {
        return 0;
    }
}

int insere_lista_final(Lista* lista, char* observacao, data_t data) {

    //retorna 1 caso sucesso
    //retorna 0 caso erro

    if (lista == NULL) {
        return 0;
    }

    elemento_t* elem = malloc(sizeof(elemento_t));
    if (elem == NULL) return 0;

    strcpy(elem->dado.Observacao, observacao);

    elem->dado.Data.dia = data.dia;
    elem->dado.Data.mes = data.mes;
    elem->dado.Data.ano = data.ano;

    elem->proximo = NULL;

    if (*lista == NULL) {
        *lista = elem;
    }
    else {
        elemento_t* aux = *lista;
        while (aux->proximo != NULL) {
            aux = aux->proximo;
        }
        aux->proximo = elem;
    }

    return 1;
}

void mostra_lista(Lista* lista) {

    if (Verifica_Lista_vazia(lista)) return;

    elemento_t* elem = *lista;
    int posicao = 1;

    (void)printf("$~~~~~~~~~~~~~~~~~\n");
    while (elem != NULL) {
        (void)printf("Consulta[%d]: [%d/%d/%d], %s\n", posicao, elem->dado.Data.dia, elem->dado.Data.mes, elem->dado.Data.ano, elem->dado.Observacao);
        elem = elem->proximo;
        posicao++;
    }
    (void)printf("$~~~~~~~~~~~~~~~~~\n");
}