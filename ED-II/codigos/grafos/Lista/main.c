#include<stdio.h>
#include<stdlib.h>
#include "TAD_Lista.h"

int main(void) {
    int rgrau;
    Grafo g;
    g = criarGrafo(6);
    inserirArco(g,0,5);
    inserirArco(g,0,2);  
    inserirArco(g,0,1);
    inserirArco(g,0,5);
    inserirArco(g,1,4);
    inserirArco(g,1,3);
    inserirArco(g,2,5);
    inserirArco(g,5,2);
    inserirArco(g,5,1);

    imprimirListaAdj(g);

    int N = 0;
    rgrau = grauVertice(g,0);
    printf("\nGrau vértice %d: %d",N,rgrau);
    liberarListaAdj(g);

    return 0;

}