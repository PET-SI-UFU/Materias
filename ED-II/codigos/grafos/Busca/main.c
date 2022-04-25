/*
    COMANDOS DE COMPILAÇÃO
    gcc -c main.c 
    gcc -c TAD_Fila.c TAD_Pilha.c TAD_Grafo.c
    gcc -o main main.o TAD_Fila.o TAD_Pilha.o TAD_Grafo.o
    ./main
*/
#include <stdio.h>
#include <stdlib.h>
#include "TAD_Grafo.h"

int main(void)
{
    int rgrau;
    Grafo g;
    g = criarGrafo(7);
    inserirArco(g, 0, 2);
    inserirArco(g, 0, 1);
    inserirArco(g, 1, 3);
    inserirArco(g, 1, 4);
    inserirArco(g, 2, 0);
    inserirArco(g, 2, 3);
    inserirArco(g, 2, 5);
    inserirArco(g, 3, 2);
    inserirArco(g, 3, 4);
    inserirArco(g, 3, 5);
    inserirArco(g, 3, 6);
    inserirArco(g, 4, 6);
    inserirArco(g, 5, 6);
    inserirArco(g, 6, 4);
    inserirArco(g, 6, 5);

    imprimirListaAdj(g);
    rgrau = grauVertice(g, 1);
    printf("\nGrau Vertice 1: %d", rgrau);
    printf("\nBusca em Largura");
    BuscaEmLargura(g, 0);
    printf("\nBusca em Profundidade");
    BuscaEmProfundidade(g, 0);
    printf("\n");
    PercursoProfundidadeTempo(g, 0);
    printf("\n");

    return 0;
}