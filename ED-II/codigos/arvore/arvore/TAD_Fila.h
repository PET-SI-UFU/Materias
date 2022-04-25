#ifndef ARVORE_H
#define ARVORE_H
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

void IniciaFila(TipoFila *fila);
int Vazia(TipoFila *fila);
void Enfileira(Arv *x, TipoFila *fila);
Arv *Desenfileira(TipoFila *fila);
int Tamanho(TipoFila *fila);
void Imprime(TipoFila *fila);
void excluirNegativos(TipoFila *fila);

//...

#endif