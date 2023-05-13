#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no {
    struct no* pai;
    struct no* esquerda;
    struct no* direita;
    int valor;
} No;

typedef struct arvore {
    struct no* raiz;
    int tamanho;
} Arvore;

Arvore* cria() {
    Arvore *arvore;
    arvore = malloc(sizeof(Arvore));
    arvore->raiz = NULL;

    return arvore;
}

int vazia(Arvore* arvore) {
    return (arvore->raiz == NULL);
}

No* adicionar(Arvore* arvore, No* pai, int valor) {
    No *no = malloc(sizeof(No));

    no->pai = pai;
    no->esquerda = NULL;
    no->direita = NULL;
    no->valor = valor;

    if (pai == NULL) {
        arvore->raiz = no;
    }

    return no;
}

void removeNo(Arvore* arvore, No* no) {
    if (no->esquerda != NULL)
        removeNo(arvore, no->esquerda);

    if (no->direita != NULL)
        removeNo(arvore, no->direita);

    if (no->pai == NULL) {
        arvore->raiz = NULL;
    } else {
        if (no->pai->esquerda == no)
            no->pai->esquerda = NULL;
        else
            no->pai->direita = NULL;
    }
    free(no);
}

//void percorrer(No* no) {
//    if (no != NULL) {
//        printf("%f", no->valor);
//        percorrer(no->esquerda);
//        percorrer(no->direita);
//    }
//}
//
//void percorrerComCallback(No* no, void (callback)(int)) {
//    if (no != NULL) {
//        callback(no->valor);
//        percorrerComCallback(no->esquerda, callback);
//        percorrerComCallback(no->direita, callback);
//    }
//}

