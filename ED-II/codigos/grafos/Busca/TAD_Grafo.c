#include <stdio.h>
#include <stdlib.h>
#include "TAD_Grafo.h"
#include "TAD_Fila.h"
#include "TAD_Pilha.h"

/* CRIAÇÃO DE GRAFO
   Para criar um grafo usamos as funções criarGrafo e inserirVertice
*/
struct noVert *inserirVertice(struct noVert *ini, int num)
{
    struct noVert *novoVertice;

    novoVertice = (struct noVert *)malloc(sizeof(struct noVert));
    //Se a alocação deu erro
    if (novoVertice == NULL)
        return NULL;

    novoVertice->vert = num;
    //O vértice inicial passa a ser o próximo, ou segundo na lista.
    novoVertice->prox = ini;
    //As adjacências ou ligações ainda não serão inicializadas.
    novoVertice->ladj = NULL;

    return novoVertice;
}

Grafo criarGrafo(int nVert)
{
    int v = 0;
    Grafo G;

    G = (Grafo)malloc(sizeof(Grafo));
    //Se a alocação deu erro
    if (G == NULL)
        return NULL;

    G->NumArco = 0;
    G->NumVert = 0;
    G->vertices = NULL;

    /* Inserimos vérices na cabeça.
      Assim o custo é menor, pois evitamos perccorer a lista inteira sempre que inserirmos novos vértices
   */
    for (v = nVert - 1; v >= 0; v--)
    {
        G->vertices = inserirVertice(G->vertices, v);
        G->NumVert++;
    }
    return G;
}
//TERMINA A CRIAÇÃO DE GRAFO

/*
   INSERIR LIGAÇÕES OU ARESTAS
   Para inserir arestas usamos as funções inserirArco e inserirAdjacencia
*/
struct noAdj *inserirAdjacencia(int vdest, struct noAdj *l)
{
    struct noAdj *novo;

    novo = (struct noAdj *)malloc(sizeof(struct noAdj));
    //Se a alocação deu erro
    if (novo == NULL)
        return NULL;

    novo->vert = vdest;
    /* O l que era o primeiro da lista de adjacências passa a ser o segundo
      Sendo o próximo do novo vértice.
   */
    novo->prox = l;

    return novo;
}

void inserirArco(Grafo G, int v1, int v2)
{
    struct noVert *v;
    struct noAdj *z;

    //Se o grafo não existe
    if (G == NULL)
        return;

    for (v = G->vertices; v != NULL; v = v->prox)
    {
        //Achou o vértice para inserir a adjacência
        if (v->vert == v1)
        {
            //Verifica se o arco já existe
            for (z = v->ladj; z != NULL; z = z->prox)
            {
                //O arco já existe, retornar!
                if (z->vert == v2)
                    return;
            }
            //Se o arco não existe inserimos-o.
            v->ladj = inserirAdjacencia(v2, v->ladj);
            G->NumArco++;
            break;
        }
    }
}
//TERMINA A INSERÇÃO DE ARESTAS

//INSERE NOVO VÉRTICE
void inserirNovoVertice(Grafo G, int nv)
{
    G->vertices = inserirVertice(G->vertices, nv);
    G->NumVert++;
}

//IMPRIME LISTA DE ADJACÊNCIAS
void imprimirListaAdj(Grafo G)
{

    struct noVert *nv;
    struct noAdj *na;

    //Grafo não existe
    if (G == NULL)
        return;

    printf("\n\nLista de Adjacencias:");
    for (nv = G->vertices; nv != NULL; nv = nv->prox)
    {
        printf("\nVertice %d:", nv->vert);
        for (na = nv->ladj; na != NULL; na = na->prox)
        {
            printf("(%d)", na->vert);
        }
    }
    return;
}

//LIBERA LISTA DE ADJACÊNCIAS
void liberarListaAdj(Grafo G)
{
    //Grafo não existe
    if (G == NULL)
        return;

    struct noVert *nv, *aux1;
    struct noAdj *na, *aux2;

    printf("\n\nLista de Adjacencias:");
    for (nv = G->vertices; nv != NULL;)
    {
        for (na = nv->ladj; na != NULL;)
        {
            aux2 = na->prox;
            free(na);
            na = aux2;
        }
        aux1 = nv->prox;
        free(nv);
        nv = aux1;
    }
    free(G);

    return;
}

//IMPRIME LISTA DE ADJACÊNCIAS
void imprimirListaAdjRec(struct noVert *nv)
{
    struct noAdj *na;

    if (nv == NULL)
        return;

    printf("\nVertice %d:", nv->vert);
    for (na = nv->ladj; na != NULL; na = na->prox)
    {
        printf("(%d)", na->vert);
    }
    imprimirListaAdjRec(nv->prox);

    return;
}

/*
   Está programada para grafos direcionados
*/
int grauVertice(Grafo G, int v)
{

    struct noVert *nv;
    struct noAdj *na;
    int cont = 0;

    //Se o grafo não existe
    if (G == NULL)
        return 0;

    for (nv = G->vertices; nv != NULL; nv = nv->prox)
    {
        //Achamos o vértice na lista de vértice
        if (v == nv->vert)
        {
            //Grau de saída
            //Contamos na lista de adjacências
            for (na = nv->ladj; na != NULL; na = na->prox)
            {
                cont = cont + 1;
            }
        }
        else
        {
            //Se não achamos o vértice, procuramos ele na lista de adjacências de alguém
            for (na = nv->ladj; na != NULL; na = na->prox)
            {
                // Grau de entrada
                if (v == na->vert)
                {
                    cont = cont + 1;
                }
            }
        }
    }
    return cont;
}

//BUSCA EM LARGURA

int FoiVisitado(int vert, int *vet, int tam)
{
    int i = 0;
    for (i = 0; i <= tam; i++)
    {
        if (vet[i] == vert)
            return 1;
    }
    return 0;
}

int imprimeVisita(int *vet, int tam)
{
    int i = 0;
    printf("\nOrdem da visita: ");
    for (i = 0; i <= tam; i++)
    {
        printf("(%d) ", vet[i]);
    }
    return 0;
}

void BuscaEmLargura(Grafo G, int v)
{
    struct noVert *nv; //Vértices
    struct noAdj *na;  //Arestas
    int *visitados;
    TipoFila *fila;
    int i = 0, cont = 0, vt = 0;

    //Alocação
    visitados = (int *)malloc(G->NumVert * sizeof(int));
    if (visitados == NULL)
        return;

    //Iniciar o vetor de visitados com -1 para todos os vértices
    for (i = 0; i < G->NumVert; i++)
    {
        visitados[i] = -1;
    }

    //Anotar como visitado o vértice de origem (busca)
    visitados[cont] = v;

    fila = (TipoFila *)malloc(sizeof(TipoFila));
    if (fila == NULL)
        return;

    //Iniciar a fila e inserir o vértice de origem
    IniciaFila(fila);
    Enfileira(v, fila);

    //Enquanto a fila não for vazia
    while (!Vazia(fila))
    {
        vt = Desenfileira(fila);

        //Percorro a lista de vértices
        for (nv = G->vertices; nv != NULL; nv = nv->prox)
        {
            //Se achei o vértice que procuro
            if (vt == nv->vert)
            {
                //Percorro a lista de adjacências
                for (na = nv->ladj; na != NULL; na = na->prox)
                {
                    //Se o vértice não foi visitado
                    if (FoiVisitado(na->vert, visitados, cont) == 0)
                    {
                        //Enfileira o vértice
                        Enfileira(na->vert, fila);
                        cont++;
                        visitados[cont] = na->vert;
                    }
                }
            }
        }
    }
    imprimeVisita(visitados, cont);
    free(fila);
}
//Termina BUSCA EM LARGURA

//BUSCA EM PROFUNDIDADE
void BuscaEmProfundidade(Grafo G, int v)
{
    struct noVert *nv;
    struct noAdj *na;
    int *visitados;
    TipoPilha *pilha;
    int i = 0, cont = 0, vt = 0;

    visitados = (int *)malloc(G->NumVert * sizeof(int));
    if (visitados == NULL)
        return;

    //Iniciar o vetor de visitados com -1 para todos os vértices
    for (i = 0; i < G->NumVert; i++)
    {
        visitados[i] = -1;
    }
    //Iniciar a pilha e inserir o vértice de origem
    pilha = (TipoPilha *)malloc(sizeof(TipoPilha));
    if (pilha == NULL)
        return;
    IniciaPilha(pilha);
    Empilha(v, pilha);

    //Enquanto a pilha não estiver vazia
    while (!VaziaPilha(pilha))
    {
        vt = Desempilha(pilha);

        //Se o vértice não foi visitado
        if (FoiVisitado(vt, visitados, cont) == 0)
        {
            visitados[cont] = vt;
            cont++;

            //Percorro a lista de vértices
            for (nv = G->vertices; nv != NULL; nv = nv->prox)
            {
                //Achei o vértice
                if (vt == nv->vert)
                {
                    //Percorro a lista de arestas
                    for (na = nv->ladj; na != NULL; na = na->prox)
                    {
                        //Se não foi visitado
                        if (FoiVisitado(na->vert, visitados, cont) == 0)
                        {
                            Empilha(na->vert, pilha);
                        }
                    }
                }
            }
        }
    }
    imprimeVisita(visitados, cont - 1);
    free(pilha);
}

//BUSCA EM PROFUNDIDADE COM TEMPO

int MarcaVisitaTempo(int vt, int pos, char tipo, struct visitaTempo *vet, int tam)
{
    int i = 0;
    for (i = 0; i < tam; i++)
    {
        if (vet[i].vert == vt)
        {
            if (tipo == 'D')
            {
                vet[i].tempoDescoberta = pos;
                return 1;
            }
            else
            {
                if (vet[i].tempoFinalizacao == -1)
                {
                    vet[i].tempoFinalizacao = pos;
                    return 1;
                }
                else
                    return 0;
            }
        }
    }
    return 0;
}

int FoiVisitadoTempo(int vert, struct visitaTempo *vet, int tam)
{
    int i = 0;
    for (i = 0; i < tam; i++)
    {
        if ((vet[i].vert == vert) && (vet[i].tempoDescoberta != -1))
            return 1;
    }
    return 0;
}

int imprimeVisitaTempo(struct visitaTempo *vet, int tam)
{
    int i;
    for (i = 0; i < tam; i++)
    {
        printf("\n(%d) Descoberta: %d, Finalizacao: %d",
               vet[i].vert, vet[i].tempoDescoberta, vet[i].tempoFinalizacao);
    }
    return 0;
}

void PercursoProfundidadeTempo(Grafo G, int v)
{
    struct noVert *nv;
    struct noAdj *na;
    struct visitaTempo *visitados;
    TipoPilha *pilha;
    int tam = 0, cont = 0, vt, finaliza, r;

    //Iniciar o vetor de visitados com -1 para todos os vértices
    visitados = (struct visitaTempo *)malloc(G->NumVert * sizeof(struct visitaTempo));
    for (nv = G->vertices; nv != NULL; nv = nv->prox)
    {
        visitados[tam].vert = nv->vert;
        visitados[tam].tempoDescoberta = -1;
        visitados[tam].tempoFinalizacao = -1;
        tam++;
    }
    //Iniciar a fila e inserir o vértice de origem
    pilha = (TipoPilha *)malloc(sizeof(TipoPilha));
    IniciaPilha(pilha);
    Empilha(v, pilha);

    while (!VaziaPilha(pilha))
    {
        vt = Topo(pilha);
        if (FoiVisitadoTempo(vt, visitados, tam) == 0)
        {
            MarcaVisitaTempo(vt, cont++, 'D', visitados, tam);
            //cont++;
            for (nv = G->vertices; nv != NULL; nv = nv->prox)
                if (vt == nv->vert)
                {
                    finaliza = 1;
                    for (na = nv->ladj; na != NULL; na = na->prox)
                        if (FoiVisitadoTempo(na->vert, visitados, tam) == 0)
                        {
                            Empilha(na->vert, pilha);
                            finaliza = 0;
                        }
                    if (finaliza == 1)
                    {
                        r = MarcaVisitaTempo(vt, cont, 'F', visitados, tam);
                        if (r == 1)
                            cont++;
                        vt = Desempilha(pilha);
                    }
                }
        }
        else
        {
            r = MarcaVisitaTempo(vt, cont, 'F', visitados, tam);
            if (r == 1)
                cont++;
            vt = Desempilha(pilha);
        }
    }
    imprimeVisitaTempo(visitados, tam);
    free(pilha);
}