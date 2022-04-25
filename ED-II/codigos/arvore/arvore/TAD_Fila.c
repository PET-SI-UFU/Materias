#ifndef FILA_H
#define FILA_H
#include "TAD_Fila.h"
#endif

#include <stdio.h>
#include <stdlib.h>

void IniciaFila(TipoFila *fila)
{
    fila->inicio = NULL;
    fila->fim = NULL;
    fila->tamanho = 0;
}

int Vazia(TipoFila *fila)
{
    return (fila->inicio == NULL);
}

void Enfileira(Arv *x, TipoFila *fila)
{
    TipoNo *aux;
    aux = (TipoNo *)malloc(sizeof(TipoNo));
    aux->valor = x;
    aux->prox = NULL;
    printf("\n enfileira %d", aux->valor->info);
    if (Vazia(fila))
    {
        fila->inicio = aux;
        fila->fim = aux;
    }
    else
    {
        fila->fim->prox = aux;
        fila->fim = aux;
    }
    fila->tamanho++;
}

Arv *Desenfileira(TipoFila *fila)
{
    TipoNo *q;
    Arv *v;
    if (Vazia(fila))
    {
        printf("Fila esta vazia\n");
        return 0;
    }
    q = fila->inicio;
    v = fila->inicio->valor;
    fila->inicio = fila->inicio->prox;
    free(q);
    fila->tamanho--;
    return v;
}

int Tamanho(TipoFila *fila)
{
    return (fila->tamanho);
}

void Imprime(TipoFila *fila)
{
    TipoNo *aux;
    aux = fila->inicio;
    while (aux != NULL)
    {
        printf("%d ", aux->valor->info);
        aux = aux->prox;
    }
}
