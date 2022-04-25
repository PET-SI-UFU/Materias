#include <stdio.h>
#include <stdlib.h>
#include "TAD_Matriz.h"

/* CRIAÇÃO DO GRAFO
    A função de criação do grafo deve:
    • alocar área para a variável grafo (TipoGrafo)
    • receber a quantidade de vértices do grafo (N) para que possa ser feita a alocação de memória para a matriz (N × N)
    • devolver a posição de memória de início para esta alocação.
*/
TipoGrafo *CriarGrafo(int NVertices)
{
    int i = 0, k = 0;
    TipoGrafo *Grafo;

    //Se o número de vértices é negativo ou 0 não construímos o gráfico
    if (NVertices <= 0)
        return NULL;

    /*  Usamos malloc para alocar dinamicamente a estrutura GRAFO
        Grafo aponta para esse espaço alocado*/
    Grafo = (TipoGrafo *)malloc(sizeof(TipoGrafo));
    //Se a alocação deu errado
    if (Grafo == NULL)
        return NULL;

    //Alocamos um vetor
    Grafo->Mat = (int **)malloc(NVertices * sizeof(int *));
    //Se a alocação deu errado
    if (Grafo->Mat == NULL)
    {
        free(Grafo);
        return NULL;
    }

    for (i = 0; i < NVertices; i++)
    {
        /*  Cada linha do vetor que alocamos terá N colunas
            Usamos calloc para iniciá-las com 0*/
        Grafo->Mat[i] = (int *)calloc(NVertices, sizeof(int));
        //Se a alocação deu errado
        if (Grafo->Mat[i] == NULL)
        {
            //Liberamos cada linha alocada
            for (k = 0; k < i; k++)
                free(Grafo->Mat[k]);
            //Liberamos a estrutura GRAFO
            free(Grafo);
            return NULL;
        }
    }
    //Sabemos o número de vértices
    Grafo->NumVertices = NVertices;
    //Não sabemos as conexões(arestas), por isso inicializamos com 0
    Grafo->NumArestas = 0;

    //Retoranamos um ponteiro para a estrutura GRAFO
    return Grafo;
}

/*INSERE ARESTA
    A função inserirAresta recebe o endereço do GRAFO
    e o vertice1 e vertice2 que serão conectados
*/
int inserirAresta(TipoGrafo *G, int v1, int v2)
{
    if (G == NULL)
        //Grafo não existe
        return -1;

    /*  Se o vértice1 ou 2 for negativo, ele não existe
        Se o vertice1 ou 2 for maior que o número de vértices, ele não existe
    */
    if (v1 < 0 || v1 >= G->NumVertices || v2 < 0 || v2 >= G->NumVertices)
        return 0;

    //A aresta a ser inserida não deve existir: Mat[v1][v2] == 0
    if (G->Mat[v1][v2] == 0)
    {
        G->Mat[v1][v2] = 1;
        G->NumArestas++;
    }
    return 1;
}

/*RETIRAR ARESTA
    A função inserirAresta recebe o endereço do GRAFO
    e o vertice1 e vertice2 que serão desconectados
*/
int retirarAresta(TipoGrafo *G, int v1, int v2)
{

    //Grafo nao existe
    if (G == NULL)
        return -1;

    /*  Se o vértice1 ou 2 for negativo, ele não existe
        Se o vertice1 ou 2 for maior que o número de vértices, ele não existe
    */
    if (v1 < 0 || v1 >= G->NumVertices || v2 < 0 || v2 >= G->NumVertices)
        return -1;

    // Se a aresta a ser removida não existir: Mat[v1][v2] == 0
    if (G->Mat[v1][v2] == 0)
        return 0;

    //Remoção da aresta
    G->Mat[v1][v2] = 0;
    G->NumArestas--;

    return 1;
}

//IMPRIME MATRIZ
void exibirMatriz(TipoGrafo *G)
{
    int v = 0, w = 0;

    printf("\n Grafo - Matriz:\n");
    for (v = 0; v < G->NumVertices; v++)
    {
        printf("%d:", v);
        for (w = 0; w < G->NumVertices; w++)
            printf(" %d", G->Mat[v][w]);
        printf("\n");
    }
    return;
}

//IMPRIME GRAFO
void exibirGrafo(TipoGrafo *G)
{
    int v = 0, w = 0;

    printf("\nGrafo - Resumo:\n");
    for (v = 0; v < G->NumVertices; ++v)
    {
        printf("%d:", v);
        for (w = 0; w < G->NumVertices; ++w)
            if (G->Mat[v][w] == 1)
                printf(" %d", w);
        printf("\n");
    }
    return;
}

//DESTROI GRAFO
TipoGrafo *liberarGrafo(TipoGrafo *G)
{
    int i = 0;

    //Grafo não existe
    if (G == NULL)
        return NULL;

    //Liberar cada linha da matriz
    for (i = 0; i < G->NumVertices; i++)
        free(G->Mat[i]);
    //Liberar matriz
    free(G->Mat);
    //Liberar GRAFO
    free(G);

    //Ponteiro passa a apontar para nada
    G = NULL;

    return G;
}

//VERIFICA ARESTA
int verificaAresta(TipoGrafo *Grafo, int v1, int v2)
{

    //Grafo nao existe
    if (Grafo == NULL)
        return -1;

    /*  Se o vértice1 ou 2 for negativo, ele não existe
        Se o vertice1 ou 2 for maior que o número de vértices, ele não existe
    */
    if (v1 < 0 || v1 >= Grafo->NumVertices || v2 < 0 || v2 >= Grafo->NumVertices)
        return -1;

    // Se a aresta não existir: Mat[v1][v2] == 0
    if (Grafo->Mat[v1][v2] == 0)
        return 0;

    //Se a aresta existir: Mat[v1][v2] == 1
    return 1;
}

int adjacencias(TipoGrafo *Grafo, int v)
{
    //Grafo nao existe
    if (Grafo == NULL)
        return -1;

    /*  Se o vértice1 for negativo, ele não existe
        Se o vertice1 for maior que o número de vértices, ele não existe
    */
    if (v < 0 || v >= Grafo->NumVertices)
        return -1;

    printf("\nAdjacências do vértice %d: ", v);
    for (int i = 0; i < Grafo->NumVertices; i++)
    {
        if (Grafo->Mat[v][i] == 1)
            printf(" %d", i);
    }
    printf("\n");

    return 0;
}

int main(void)
{
    TipoGrafo *g;
    g = CriarGrafo(5);
    inserirAresta(g, 0, 2);
    inserirAresta(g, 0, 1);
    inserirAresta(g, 1, 3);
    inserirAresta(g, 2, 4);
    inserirAresta(g, 2, 1);
    inserirAresta(g, 4, 3);
    exibirMatriz(g);
    exibirGrafo(g);
    retirarAresta(g, 2, 4);
    exibirGrafo(g);

    adjacencias(g, 2);

    g = liberarGrafo(g);

    adjacencias(g, 2);
    return 0;
}