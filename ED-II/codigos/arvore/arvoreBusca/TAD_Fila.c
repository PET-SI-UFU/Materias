#include <stdio.h>
#include <stdlib.h>
#include "TAD_Fila.h"

TipoFila *IniciaFila()
{
    TipoFila *fila;
    fila = (TipoFila *)malloc(sizeof(TipoFila));
    fila->inicio = NULL;
    fila->fim = NULL;
    fila->tamanho = 0;
    return fila;
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