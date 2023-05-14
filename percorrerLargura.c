#include "fila.c"

void percorrerLargura(No* no, void (callback)(int)) {
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