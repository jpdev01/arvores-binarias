#include "fila.c"

void percorrerLarguraEmArquivo(No* no, FILE* file, void (callback)(FILE*, int)) {
    Fila* fila = criarFila();
    adicionarFila(fila, no);

    while (!filaVazia(fila)) {
        No* no = removerFila(fila);

        if (no->esquerda != NULL) {
            adicionarFila(fila, no->esquerda);
        }

        if (no->direita != NULL) {
            adicionarFila(fila, no->direita);
        }

        callback(file, no->valor);
    }
}

void percorrerLarguraPrintar(No* no, FILE* file, void (callback)(int)) {
    Fila* fila = criarFila();
    adicionarFila(fila, no);

    while (!filaVazia(fila)) {
        No* no = removerFila(fila);

        if (no->esquerda != NULL) {
            adicionarFila(fila, no->esquerda);
        }

        if (no->direita != NULL) {
            adicionarFila(fila, no->direita);
        }

        callback(no->valor);
    }
}