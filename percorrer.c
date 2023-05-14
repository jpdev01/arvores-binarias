void percorrerProfundidadeInOrder(No* no, void (callback)(int)) {
    if (no != NULL) {
        percorrerProfundidadeInOrder(no->esquerda,callback);
        callback(no->valor);
        percorrerProfundidadeInOrder(no->direita,callback);
    }
}

void percorrerProfundidadePreOrder(No* no, void (callback)(int)) {
    if (no != NULL) {
        callback(no->valor);
        percorrerProfundidadePreOrder(no->esquerda,callback);
        percorrerProfundidadePreOrder(no->direita,callback);
    }
}

void percorrerProfundidadePosOrder(No* no, void (callback)(int)) {
    if (no != NULL) {
        percorrerProfundidadePosOrder(no->esquerda,callback);
        percorrerProfundidadePosOrder(no->direita,callback);
        callback(no->valor);
    }
}

void exibe(int v) {
    printf("%d ", v);
}