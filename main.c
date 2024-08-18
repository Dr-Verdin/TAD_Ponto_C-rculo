#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "ponto.h"
#include "circulo.h"

int main (void){
    // Definindo um ponto
    float xP, yP;
    scanf(" %f %f", &xP, &yP);

    PONTO *ponto = ponto_criar (xP, yP);

    // Definindo um circulo
    float xC, yC, raio;
    scanf(" %f %f %f", &xC, &yC, &raio);

    PONTO *centro = ponto_criar(xC, yC);
    CIRCULO *circulo = circulo_criar (centro, raio);

    // Imprimir as coordenadas do ponto
    ponto_print(ponto);

    // Imprimir coordenadas do centro círculo e do seu raio
    raio = circulo_get_raio (circulo);
    xC = ponto_get_x (centro);
    yC = ponto_get_y (centro);
    printf("Circulo: Centro (%.1f, %.1f), Raio = %.1f\n", xC, yC, raio);

    // Apagar o ponto e apagar o círculo
    ponto_apagar (&ponto);
    circulo_apagar (&circulo);

    return 0;
}