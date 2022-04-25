#include <stdio.h>
#include <stdlib.h>
#include "TAD_Fila.h"

Arv *arv_criavazia(void)
{
    return NULL;
}

// CRIA
Arv *arv_cria(int c, Arv *esq, Arv *dir)
{
    // Alocamos estrutura para a árvore
    Arv *p = (Arv *)malloc(sizeof(Arv));
    if (p != NULL)
    {
        p->info = c;
        p->esq = esq;
        p->dir = dir;
    }

    return p;
}

int arv_vazia(Arv *a)
{
    return a == NULL;
}

// LIBERA RECURSIVA
Arv *arv_libera(Arv *a)
{
    if (!arv_vazia(a))
    {
        arv_libera(a->esq); /* libera esq */
        arv_libera(a->dir); /* libera dir */
        free(a);            /* libera raiz */
    }
    return NULL;
}

// PERTENCE RECURSIVA
int arv_pertence(Arv *a, int c)
{
    if (arv_vazia(a))
        return 0; /* árvore vazia: não encontrou */
    else
        return (a->info == c || arv_pertence(a->esq, c) || arv_pertence(a->dir, c));
}

// PRE ORDEM
void arv_imprime_pre(Arv *a)
{
    if (!arv_vazia(a))
    {
        printf("%d ", a->info);  /* mostra raiz */
        arv_imprime_pre(a->esq); /* mostra sae */
        arv_imprime_pre(a->dir); /* mostra sad */
    }
}

// POS ORDEM
void arv_imprime_pos(Arv *a)
{
    if (!arv_vazia(a))
    {
        arv_imprime_pos(a->esq); /* mostra sae */
        arv_imprime_pos(a->dir); /* mostra sad */
        printf("%d ", a->info);  /* mostra raiz */
    }
}

// EM ORDEM
void arv_imprime_em(Arv *a)
{
    if (!arv_vazia(a))
    {
        arv_imprime_em(a->esq); /* mostra sae */
        printf("%d ", a->info); /* mostra raiz */
        arv_imprime_em(a->dir); /* mostra sad */
    }
}

int max(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}

// FUNÇÃO ALTURA
int altura(Arv *a)
{
    if (arv_vazia(a))
        return -1; // raiz está no nível 0
    else
        return 1 + max(altura(a->esq), altura(a->dir));
}

int isBaS(Arv *a)
{
    TipoFila *f;
    Arv *aux = a;
    int x;
    if (!arv_vazia(a))
    {
        f = (TipoFila *)malloc(sizeof(TipoFila));
        IniciaFila(f);
        Enfileira(a, f);
        while (!Vazia(f))
        {
            aux = Desenfileira(f);
            printf("\nSai %d", aux->info);
            if ((aux->esq != NULL && aux->esq->info > aux->info) ||
                (aux->dir != NULL && aux->dir->info < aux->info))
                return 0;
            if (!arv_vazia(aux->esq))
                Enfileira(aux->esq, f);
            if (!arv_vazia(aux->dir))
                Enfileira(aux->dir, f);
        }
    }
    return 1;
}
