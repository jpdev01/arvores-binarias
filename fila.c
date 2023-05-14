#include <stdlib.h>
#include <string.h>

typedef struct fila {
    struct elemento* cabeca;
    struct elemento* cauda;
} Fila;

typedef struct elemento {
    struct elemento* proximo;
    struct elemento* anterior;
    struct no* valor;
} Elemento;


Fila* criarFila() {
    Fila *fila = malloc(sizeof(Fila));
    fila->cabeca = NULL;
    fila->cauda = NULL;

    return fila;
}

void adicionarFila(Fila* fila, No* valor) {
    Elemento* elemento = malloc(sizeof(Elemento));

    elemento->valor = valor;
    elemento->proximo = NULL;

    if (fila->cauda != NULL) {
        fila->cauda->proximo = elemento;
        fila->cauda = elemento;
    } else {
        fila->cabeca = elemento;
        fila->cauda = elemento;
    }
}

int filaVazia(Fila* fila) {
    return fila->cabeca == NULL;
}

No* removerFila(Fila* fila) {
    Elemento* cabeca = fila->cabeca;
    No* valor = cabeca->valor;

    fila->cabeca = cabeca->proximo;

    if (fila->cabeca == NULL) {
        fila->cauda = NULL;
    }

    free(cabeca);

    return valor;
}
