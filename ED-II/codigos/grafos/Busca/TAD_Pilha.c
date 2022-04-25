#include <stdio.h>
#include <stdlib.h>
#include "TAD_Pilha.h"

//INICIA PILHA
void IniciaPilha(TipoPilha *pilha)
{
    pilha->topo = NULL;
    pilha->tamanho = 0;
}

//PILHA VAZIA
int VaziaPilha(TipoPilha *pilha)
{
    //Se a pilha está vazia
    return (pilha->topo == NULL);
}

//TOPO
int Topo(TipoPilha *pilha)
{
    TipoNo *aux;
    if (pilha == NULL)
        return -1;

    //O valor no topo da pilha
    return pilha->topo->valor;
}

//EMPILHA
void Empilha(int x, TipoPilha *pilha)
{
    TipoNo *aux;
    if (pilha == NULL)
        return;

    aux = (TipoNo *)malloc(sizeof(TipoNo));
    //Se a alocação deu errado
    if (aux == NULL)
        return;

    //O novo Nó aponta para o primeriro Nó da pilha
    aux->valor = x;
    aux->prox = pilha->topo;

    //O topo da pilha agora é o primeiro Nó
    pilha->topo = aux;
    pilha->tamanho++;
}

//DESEMPILHA
int Desempilha(TipoPilha *pilha)
{
    int v = 0;
    TipoNo *no;

    if (pilha == NULL)
        return -1;

    no = pilha->topo;
    v = no->valor;

    //O topo passa a ser o próximo Nó
    pilha->topo = no->prox;
    pilha->tamanho--;
    free(no);

    //Retorno o valor desempilhado
    return v;
}