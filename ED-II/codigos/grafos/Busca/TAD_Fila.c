#include <stdio.h>
#include <stdlib.h>
#include "TAD_Fila.h"

//INICIA FILA
void IniciaFila(TipoFila *fila)
{
    fila->inicio = NULL;
    fila->fim = NULL;
    fila->tamanho = 0;
}

//VAZIA
int Vazia(TipoFila *fila)
{
    //Verifica se a fila está vazia
    return (fila->inicio == NULL);
}

//ENFILEIRA
void Enfileira(int x, TipoFila *fila)
{
    TipoNo *aux;
    aux = (TipoNo *)malloc(sizeof(TipoNo));
    if (aux == NULL)
        return;

    //Inicializamos o novo Nó
    aux->valor = x;
    aux->prox = NULL;

    //Se a fila estiver vazia adicionamos o Nó no início
    if (Vazia(fila))
    {
        fila->inicio = aux;
        fila->fim = aux;
    }
    //Caso não buscamos a última posição da fila
    else
    {
        fila->fim->prox = aux;
        fila->fim = aux;
    }
    //O tamanho da fila aumenta
    fila->tamanho++;
}

//DESENFILEIRA
int Desenfileira(TipoFila *fila)
{
    TipoNo *q;
    int v = 0;

    //Se a fila está vazia
    if (Vazia(fila))
    {
        printf("Fila esta vazia\n");
        return 0;
    }

    //q aponta para o início da fila
    q = fila->inicio;
    v = fila->inicio->valor;

    //Início da fila passa a ser o próximo Nó
    fila->inicio = fila->inicio->prox;
    free(q);
    fila->tamanho--;

    //Retornamos o valor excluído da fila
    return v;
}