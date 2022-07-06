#include "Fila.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct No
{
    Dado info;
    struct No *ant;
}Node;


struct FILA
{
    struct No *Begin;
    struct No *End;
    int tamanho;
};

struct FILA* Cria_Fila (void)
{
    struct FILA *Fila = (struct FILA*) malloc(sizeof(struct FILA));

    if(Fila != NULL)
    {
        Fila->Begin = NULL;
        Fila->End = NULL;
        Fila->tamanho = 0;
    }

    return Fila;
}

int Enfilera (Dado dado, struct FILA *Fila)
{
    if(Fila == NULL) return PONTEIRO_INVALIDO;
    

    Node *no = (Node*) malloc (sizeof(Node));

    if(no == NULL) MEMORIA_INSUFICIENTE;

    no->ant = NULL;
    no->info = dado;

    if(Fila->Begin == NULL && Fila->End == NULL)
    {
        Fila->Begin = no;
        Fila->End = no;
    }else{
        no->ant = Fila->End;
        Fila->End = no;
    }

    Fila->tamanho++;
    return SUCESSO;
}

int BuscaPrimeiro(struct FILA *fila, Dado *dado)
{
    if(fila != NULL) 
        return PONTEIRO_INVALIDO;
    else if(fila->Begin == NULL && fila->End == NULL)
        return NAO_ENCONTRADO;

    (*dado) = fila->Begin->info;
    return SUCESSO;
}

void Clear_Fila(struct FILA *Fila)
{
    if(Fila != NULL)
    {
        if(Fila->End != NULL && Fila->End != NULL)
        {
            Node *ant, *atual = Fila->End;
            while (atual != NULL)
            {
                ant = atual;
                atual = atual->ant;
                free(ant);
            }
            Fila->Begin = NULL;
            Fila->End = NULL;
        }
    }
}

int FilaVazia(struct FILA *fila)
{
    if(fila == NULL)
        return PONTEIRO_INVALIDO;
    else if(fila->tamanho == 0 && fila->Begin == NULL && fila->End == NULL)
        return SUCESSO;
    else
        return FALSO;
}

int TamanhoFila (struct FILA *Fila)
{
    if(Fila == NULL)
        return PONTEIRO_INVALIDO;
    else
        return Fila->tamanho;
}


void destrutor (struct FILA *Fila)
{
    if(Fila != NULL)
    {
        Clear_Fila(Fila);
        free(Fila);
    }
}


void exibir_Fila (struct FILA *fila)
{
    if(fila != NULL)
    {
        Node *aux = fila->End;
        while(aux != NULL)
        {
            printf("Nome: %s\tNota1 %.2f\tNota2 %.2f\tNota3 %.2f\n",aux->info.aluno, aux->info.notaP1, aux->info.Notap2, aux->info.Notap3);
            aux = aux->ant;
        }
    }
}