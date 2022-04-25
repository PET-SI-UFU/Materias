#include "TAD_Grafo.h"
#include <stdlib.h>
#include <stdio.h>

TipoGrafo *CriarGrafo(int NVertices)
{
    int i, k;
    TipoGrafo *Grafo;
    if (NVertices <= 0)
        return NULL;
    Grafo = (TipoGrafo *)malloc(sizeof(TipoGrafo));
    if (Grafo == NULL)
        return NULL;

    Grafo->Mat = (int **)malloc(NVertices * sizeof(int *));
    if (Grafo->Mat == NULL)
    {
        free(Grafo);
        return NULL;
    }
    for (i = 0; i < NVertices; i++)
    {
        Grafo->Mat[i] = (int *)calloc(NVertices, sizeof(int));
        if (Grafo->Mat[i] == NULL)
        {
            for (k = 0; k < i; k++)
                free(Grafo->Mat[k]);
            free(Grafo);
            return NULL;
        }
    }
    Grafo->NumVertices = NVertices;
    Grafo->NumArestas = 0;
    return Grafo;
}

int inserirAresta(TipoGrafo *G, int v1, int v2, int peso)
{
    if (G == NULL)
        return -1;
    if (v1 < 0 || v1 >= G->NumVertices || v2 < 0 || v2 >= G->NumVertices)
        return -1; // nao eh possivel criar aresta: intervalo
    if (G->Mat[v1][v2] == 0)
    {
        G->Mat[v1][v2] = peso;
        G->NumArestas++;
    }
    return 1;
}

int retirarAresta(TipoGrafo *G, int v1, int v2)
{
    if (G == NULL)
        return -1; // grafo nao existe
    if (v1 < 0 || v1 >= G->NumVertices || v2 < 0 || v2 >= G->NumVertices)
        return -1; // nao eh possivel retirar aresta: intervalo
    if (G->Mat[v1][v2] == 0)
        return 0;       // aresta nao existe
    G->Mat[v1][v2] = 0; //remove aresta
    G->NumArestas--;
    return 1;
}

void exibirGrafo(TipoGrafo *G)
{
    int v, w;
    printf("\nGrafo - Resumo:\n");
    for (v = 0; v < G->NumVertices; ++v)
    {
        printf("%d:", v);
        for (w = 0; w < G->NumVertices; ++w)
            if (G->Mat[v][w] != 0)
                printf(" %d", w);
        printf("\n");
    }
}

void exibirMatriz(TipoGrafo *G)
{
    int v, w;
    printf("\nGrafo - Matriz:\n");
    for (v = 0; v < G->NumVertices; ++v)
    {
        printf("%d:", v);
        for (w = 0; w < G->NumVertices; ++w)
            printf(" %d", G->Mat[v][w]);
        printf("\n");
    }
}

TipoGrafo *liberarGrafo(TipoGrafo *G)
{
    int i;
    if (G == NULL)
        return NULL;

    for (i = 0; i < G->NumVertices; i++)
        free(G->Mat[i]);
    free(G->Mat);
    free(G);
    G = NULL;
    return G;
}

void caminhoMaisCurto(TipoGrafo *G, int origem)
{
    int i, v, w, minimo, posmin, S;
    int *M, *L;
    M = (int *)malloc(G->NumVertices * sizeof(int));
    L = (int *)malloc(G->NumVertices * sizeof(int));

    // preenchimento preliminar dos vetores
    for (i = 0; i < G->NumVertices; i++)
    {
        M[i] = 0;      // falso, vértice não visitado
        L[i] = 999999; // valor inicial para os custos
    }

    M[origem] = 1;
    for (v = 0; v < G->NumVertices; v++)
    {
        if (G->Mat[origem][v] != 0)
        {
            L[v] = G->Mat[origem][v];
        }
    }

    for (i = 0; i < G->NumVertices; i++)
    {
        w = 0;
        minimo = 999999;
        for (v = 0; v < G->NumVertices; v++)
        {
            if (L[v] < minimo && M[v] == 0)
            {
                minimo = L[v];
                posmin = v;
                w = 1;
            }
        }
        if (w == 0)
            break;
        M[posmin] = 1;
        for (v = 0; v < G->NumVertices; v++)
        {
            if (G->Mat[posmin][v] != 0 && M[v] == 0)
            {
                S = L[posmin] + G->Mat[posmin][v];
                if (S < L[v])
                    L[v] = S;
            }
        }
    }

    printf("\nMenor caminho partindo de %d: \n", origem);
    for (v = 0; v < G->NumVertices; v++)
    {
        if (L[v] == 999999)
            printf("%d: - \n", v);
        else
            printf("%d: %d\n", v, L[v]);
    }
}