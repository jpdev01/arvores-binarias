#include <stdio.h>

#define fileName "/home/asaas/CLionProjects/arvores-binarias/result.txt";

FILE* abreArquivo() {
    const char* filePath = fileName;
    FILE *file = fopen(filePath, "w+");
    if (file == NULL) {
        printf("Erro na abertura do arquivo.");
        exit(0);
    }

    return file;
}

void escrever(FILE* file, int value) {
    fprintf(file, "%i ", value);
}