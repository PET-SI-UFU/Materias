#include <stdio.h>
#include "TAD_Grafo.h"

int main(void)
{
    TipoGrafo *g;
    g = CriarGrafo(6);
    inserirAresta(g, 0, 1, 24);
    inserirAresta(g, 0, 2, 5);
    inserirAresta(g, 0, 3, 10);
    inserirAresta(g, 2, 3, 1);
    inserirAresta(g, 2, 5, 10);
    inserirAresta(g, 2, 4, 30);
    inserirAresta(g, 3, 5, 8);
    inserirAresta(g, 5, 4, 20);

    exibirMatriz(g);
    exibirGrafo(g);

    caminhoMaisCurto(g, 5);
    g = liberarGrafo(g);
    return 0;
}
