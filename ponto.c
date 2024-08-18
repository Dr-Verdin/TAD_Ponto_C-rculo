#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "ponto.h"

typedef struct ponto_ {
    float x; // Valor do eixo x do ponto
    float y; // Valor do eixo y do ponto
} PONTO;

// Função para criar um ponto
PONTO *ponto_criar (float x, float y){
    PONTO *p = malloc(sizeof(PONTO));

    if (p == NULL) {
        printf("Erro: ponteiro NULL em ponto_criar!\n");
        return NULL;
    }

    if (p) {
        p->x = x;
        p->y = y;
    } else {
        printf("Erro: falha ao alocar memoria para ponto!\n");
    }
    return p;
}

// Função para apagar um ponto
void ponto_apagar (PONTO **p){
    if(*p && p){
        free(*p);
        *p = NULL;
    }
}

// Função para definir as coordenadas de um ponto
bool ponto_set (PONTO *p, float x, float y){
    if(p){
        p->x = x;
        p->y = y;
        return(true);
    }
    return(false);
}

// Função para obter a coordenada x de um ponto
float ponto_get_x (PONTO *p){
    if(p){
        return(p->x);
    }
    printf("Erro: ponteiro NULL em ponto_get_x!\n");
    return -1;
}

// Função para obter a coordenada y de um ponto
float ponto_get_y (PONTO *p){
    if(p){
        return(p->y);
    }
    printf("Erro: ponteiro NULL em ponto_get_y!\n");
    return -1;
}

// Função para imprimir as coordenadas de um ponto
void ponto_print (PONTO *p){
    if(p)
        printf("Ponto: (%.1f, %.1f)\n", p->x, p->y);
    else
        printf("Erro: ponteiro NULL em ponto_print!\n");
}