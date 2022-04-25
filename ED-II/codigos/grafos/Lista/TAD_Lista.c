#include <stdio.h>
#include <stdlib.h>
#include "TAD_Lista.h"

/* CRIAÇÃO DE GRAFO
   Para criar um grafo usamos as funções criarGrafo e inserirVertice
*/
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
//TERMINA A CRIAÇÃO DE GRAFO

/*
   INSERIR LIGAÇÕES OU ARESTAS
   Para inserir arestas usamos as funções inserirArco e inserirAdjacencia
*/
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

    if (G->vertices == NULL)
        return;

    struct noVert *nv, *aux;
    struct noAdj *na, *aux2;

    for (nv = G->vertices; nv != NULL;)
    {
        for (na = nv->ladj; na != NULL;)
        {
            aux2 = na->prox;
            free(na);
            na = aux2;
        }
        aux = nv->prox;
        free(nv);
        nv = aux;
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
