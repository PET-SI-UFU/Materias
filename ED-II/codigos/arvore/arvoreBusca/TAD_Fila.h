#ifndef FILA_H
#define FILA_H

#include "TAD_Arvore.h"

typedef struct No
{
    Arv *valor;
    struct No *prox;
} TipoNo;

typedef struct Fila
{
    TipoNo *inicio, *fim;
    int tamanho;
} TipoFila;

TipoFila *IniciaFila();
int Vazia(TipoFila *fila);
void Enfileira(Arv *x, TipoFila *fila);
Arv *Desenfileira(TipoFila *fila);

#endif