#include "mapa.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAP_LINHAS 20
#define MAP_COLUNAS 40

Mapa *carregarMapa(const char *arquivo){
    FILE *file = fopen(arquivo, "r");
    if (!file) { // Mensagem de erro caso o arquivo não possa ser aberto
        fprintf(stderr,"Erro ao abrir o arquivo do mapa. %s\n", arquivo); 
        return NULL;
    }

    Mapa *mapa = malloc(sizeof(Mapa));
    if (!mapa) { // mensagem de erro caso a alocação falhe
        fprintf(stderr, "Erro ao alocar memoria para o mapa.\n");
        fclose(file);
        return NULL;
    }

    mapa->linhas = MAP_LINHAS;
    mapa->colunas = MAP_COLUNAS;

    mapa->celulas = malloc(m->linhas * sizeof(char *));
    if (!mapa->celulas) { // mensagem de erro caso a alocação fal
        fprintf(stderr, "Erro ao alocar memoria para o mapa.\n");
        free(mapa);
        fclose(file);
        return NULL;
    }
    char buffer[256]; // buffer temporario para ler cada linha do arquivo
    for (int i = 0; i < mapa->colunas; )
}