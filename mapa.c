#include "mapa.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAP_MAX_LINHAS 20
#define MAP_MAX_COLUNAS 40

Mapa *carregarMapa(const char *arquivo){
    if (!arquivo) return NULL; // 
    FILE *f = fopen(arquivo, "r");
    if (!f) { // Mensagem de erro caso o arquivo não possa ser aberto
        fprintf(stderr,"Erro ao abrir o arquivo do mapa. %s\n", arquivo); 
        return NULL;
    }

    char buffer[256]; // buffer temporario para ler cada linha do arquivo
    char *rows[MAP_MAX_LINHAS];
    int linhas = 0;

    while (fgets(buffer, sizeof(buffer), f) && linhas < MAP_MAX_LINHAS) {
        size_t len = strlen(buffer);
        while (len > 0 && (buffer[len - 1] == '\n' || buffer[len - 1] == '\r')) {
            buffer[--len] = '\0'; // Remove nova linha 
        }

        rows[linhas] = malloc(MAP_MAX_COLUNAS + 1);
        if (!rows[linhas]) { // liberar tudo que ja foi alocado
            for (int k = 0; k < linhas; k++) {
                free(rows[k]);
            }
            fclose(f);
            return NULL;
        }
        for (int c = 0; c < MAP_MAX_COLUNAS; c++) {
            if (c < (int)len){
                rows[linhas][c] = buffer[c];}
            else {// Preencher com espaços as linhas
                rows[linhas][c] = ' '; }
        }
        rows[linhas][MAP_MAX_COLUNAS] = '\0'; 
        linhas ++;
    }
    fclose(f);

    if(linhas == 0) {
        return NULL; // erro se o arquivo do mapa estiver vazio ou sem linhas válidas.
    }
    Mapa *m = malloc (sizeof(Mapa)); // alocar estrutura do mapa dinamicamente
    if (!m) { // erro na alocação
        for (int k = 0; k < linhas; k++) {
            free(rows[k]);}
        return NULL;
    }

    m->linhas = linhas; 
    m->colunas = MAP_MAX_COLUNAS;

    m->celulas = malloc(sizeof(char*) * linhas); // alocar dinacamente matriz de celulas
    if (!m -> celulas) {
        for (int k = 0; k < linhas; k++) {
            free(rows[k]);}
        free(m);
        return NULL;
    }



}