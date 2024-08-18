#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "ponto.h"
#include "circulo.h"

typedef struct circulo_{
    PONTO *p; // Ponteiro para um ponto
    float raio; // Raio do circulo
} CIRCULO;

// Função para criar um círculo 
CIRCULO *circulo_criar (PONTO *p, float raio){
    if (p == NULL) {
        printf("Erro: ponteiro PONTO é NULL em circulo_criar!\n");
        return NULL; 
    }
    if (raio <= 0) {
        printf("Erro: raio deve ser maior que zero!\n");
        return NULL;
    }

    CIRCULO *c = malloc(sizeof(CIRCULO));

    if (c) {
        c->p = p;
        c->raio = raio;
    } else {
        printf("Erro: falha ao alocar memória para circulo!\n");
    }
    return c;
}

// Função para definir as coordenadas do ponto do círculo
bool circulo_set_ponto (CIRCULO *c, PONTO *p){
    if(c){
        if(p){
            c->p = p;
            return(true);
        } else {
            printf("Erro: ponto NULL em circulo_set_ponto!\n");
        }
    }
    return(false);
}

// Função para definir o raio
bool circulo_set_raio (CIRCULO *c, float raio){
    if (c) {
        if (raio > 0) {
            c->raio = raio;
            return(true);
        } else {
            printf("Erro: raio deve ser maior que zero!\n");
        }
    }
    return(false);
}

// Função para obter a coordenada do ponto
PONTO *circulo_get_ponto (CIRCULO *c){
    if(c){
        return(c->p);
    }
    printf("Erro: ponto NULL em circulo_get_ponto!\n");
    return(NULL);
}

// Função para obter o raio
float circulo_get_raio (CIRCULO *c){
    if(c){
        return(c->raio);
    }
    printf("Erro: ponto NULL em circulo_get_raio!\n");
    return -1;
}

// Função para apagar um circulo
void circulo_apagar (CIRCULO **circulo){
    if(*circulo && circulo){
        free(*circulo);
        *circulo = NULL;
    }
}