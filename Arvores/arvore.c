/*
 * @file   arvore.c
 * @brief  Arquivo com as implementações de arvore.
 * @author Gustavo Rangel Bandeira Cauduro
 * @date   2021-07-15
 */

/* inclusões */
#include<stdlib.h>
#include"arvore.h"

Arvore* cria_arvore() {
    Arvore* raiz = malloc(sizeof(Arvore));
    if (raiz != NULL) *raiz = NULL;
    return raiz;
}

void libera_no(no_t* no) {
    if (no == NULL) return;
    libera_no(no->esq);
    libera_no(no->dir);
    free(no);
    no = NULL;
}

void libera_arvore(Arvore* arvore) {
    if (arvore == NULL) return;
    libera_no((*arvore));
    free(arvore);
}

// insere em árvore binária de busca
int insere_arvore(Arvore* arvore, int valor) {
    if (arvore == NULL) return 1;
    no_t* novo = malloc(sizeof(no_t));
    if (novo == NULL) return 1;

    novo->dado = valor;
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
        if (valor == atual->dado) {
            free(novo);
            return 1; // elemento já existe
        }

        if (valor > atual->dado) atual = atual->dir;
        else atual = atual->esq;
    }

    if (valor > pai->dado) pai->dir = novo;
    else pai->esq = novo;
    return 0;
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
    if (n1 != no) {
        n1->dir = n2->esq;
        n2->esq = no->esq;
    }
    n2->dir = no->dir;
    free(no);
    return n2;
}

int remove_arvore(Arvore* arvore, int valor) {
    if (arvore == NULL) return 1;
    no_t* pai = NULL, * atual = *arvore;

    while (atual != NULL) {
        if (valor == atual->dado) {
            if (atual == *arvore) *arvore = remove_no(atual);
            else {
                if (pai->dir == atual) pai->dir = remove_no(atual);
                else pai->esq = remove_no(atual);
            }
            return 0;
        }
        pai = atual;
        if (valor > atual->dado) atual = atual->dir;
        else atual = atual->esq;
    }
    return 1;
}

int consulta_arvore(Arvore* arvore, int valor) {
    if (arvore_vazia(arvore)) return 0;
    no_t* atual = *arvore;

    while (atual != NULL) {
        if (valor == atual->dado) return 1;
        if (valor > atual->dado) atual = atual->dir;
        else atual = atual->esq;
    }
    return 0;
}

int altura_arvore(Arvore* arvore) {
    if (arvore_vazia(arvore)) return 0;
    int alt_esq = altura_arvore(&((*arvore)->esq));
    int alt_dir = altura_arvore(&((*arvore)->dir));

    return (alt_esq > alt_dir ? alt_esq : alt_dir) + 1;
}

int arvore_vazia(Arvore* arvore) {
    if (arvore == NULL) return 1;
    if (*arvore == NULL) return 1;
    return 0;
}