#include <stdio.h>
#include "core.c"
#include "percorrer.c"
#include "percorrerLargura.c"
#include "fileUtils.c"

Arvore* build() {
    Arvore* arvore = cria();
    No* no4 = adicionar(arvore, NULL, 4);

    No* no2 = adicionar(arvore, no4, 2);
    no4->esquerda = no2;

    No* no8 = adicionar(arvore, no4, 8);
    no4->direita = no8;

    No* no1 = adicionar(arvore, no2, 1);
    no2->esquerda = no1;

    No* no3 = adicionar(arvore, no2, 3);
    no2->direita = no3;

    No* no6 = adicionar(arvore, no8, 6);
    no8->esquerda = no6;

    No* no9 = adicionar(arvore, no8, 9);
    no8->direita = no9;

    No* no5 = adicionar(arvore, no6, 5);
    no6->esquerda = no5;

    No* no7 = adicionar(arvore, no6, 7);
    no6->direita = no7;

    return arvore;
}

void q1(Arvore* arvore) {
    printf("In-order: ");
    percorrerProfundidadeInOrder(arvore->raiz,exibe);
    printf("\nPre-order: ");
    percorrerProfundidadePreOrder(arvore->raiz,exibe);
    printf("\nPos-order: ");
    percorrerProfundidadePosOrder(arvore->raiz,exibe);
    printf("\n");
}

void q2(Arvore* arvore) {
    printf("Percorrer pela largura: ");

    FILE* file = abreArquivo();
    percorrerLarguraPrintar(arvore->raiz, file, exibe);
    percorrerLarguraEmArquivo(arvore->raiz, file, escrever);
}

void main(int argc, char *argv[]){
    Arvore *arvore = build();

    printf("--- Questão 1 ---- \n");
    q1(arvore);
    printf("--- Questão 2 ---- \n");
    q2(arvore);
}