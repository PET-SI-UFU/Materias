#include <stdlib.h>
#include <stdio.h>
#include "TAD_Arvore.h"
#include "TAD_Fila.h"

int arv_vazia(Arv *a)
{
    return a == NULL;
}

int max(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}

int altura(Arv *a)
{
    if (arv_vazia(a))
        return -1; // raiz está no nível 0
    else
        return 1 + max(altura(a->esq), altura(a->dir));
}

int fatorbalanc(Arv *a)
{
    return (altura(a->esq) - altura(a->dir));
}

Arv *arv_insere(int c, Arv *raiz)
{
    Arv *p;
    if (arv_vazia(raiz))
    {
        p = (Arv *)malloc(sizeof(Arv));
        p->info = c;
        p->esq = NULL;
        p->dir = NULL;
        return p;
    }
    else
    {
        if (c < raiz->info)
            raiz->esq = arv_insere(c, raiz->esq);
        else
            raiz->dir = arv_insere(c, raiz->dir);
    }
    return raiz;
}

void arv_imprime_em(Arv *a)
{
    if (!arv_vazia(a))
    {
        arv_imprime_em(a->esq); /* mostra sae */
        printf("%d ", a->info); /* mostra raiz */
        arv_imprime_em(a->dir); /* mostra sad */
    }
}

void arv_imprime_pre(Arv *a)
{
    if (!arv_vazia(a))
    {
        printf("%d ", a->info);  /* mostra raiz */
        arv_imprime_pre(a->esq); /* mostra sae */
        arv_imprime_pre(a->dir); /* mostra sad */
    }
}

void arv_imprime_pos(Arv *a)
{
    if (!arv_vazia(a))
    {
        arv_imprime_pos(a->esq); /* mostra sae */
        arv_imprime_pos(a->dir); /* mostra sad */
        printf("%d ", a->info);  /* mostra raiz */
    }
}

void arv_imprime_niveis(Arv *a)
{
    TipoFila *f;
    int fb;
    Arv *aux;
    if (!arv_vazia(a))
    {
        f = IniciaFila();
        Enfileira(a, f);
        while (!Vazia(f))
        {
            aux = Desenfileira(f);
            fb = fatorbalanc(aux);
            printf("%d (%d) ", aux->info, fb);
            if (!arv_vazia(aux->esq))
                Enfileira(aux->esq, f);
            if (!arv_vazia(aux->dir))
                Enfileira(aux->dir, f);
        }
    }
}

int arv_busca(Arv *a, int c)
{
    if (arv_vazia(a))
        return -1;
    else if (c == a->info)
        return 1;
    else if (c < a->info)
        return arv_busca(a->esq, c);
    else
        return arv_busca(a->dir, c);
}

// Função para encontrar o maior valor numa árvore
Arv *arv_maior(Arv *a)
{
    Arv *aux;
    if (arv_vazia(a))
        return NULL;
    else
    {
        aux = a;
        while (!arv_vazia(aux->dir))
            aux = aux->dir;
    }
    return aux;
}

// Função para encontrar o menor valor numa árvore
Arv *arv_menor(Arv *a)
{
    Arv *aux;
    if (arv_vazia(a))
        return NULL;
    else if (arv_vazia(a->esq))
        return a;
    else
        return arv_menor(a->esq);
}

// Função para remover um dado elemento
Arv *arv_remove(Arv *r, int c)
{
    Arv *p;

    if (arv_vazia(r))
    {
        return NULL;
    }
    else
    {

        if (c == r->info)
        { // achou elemento a ser removido
            // remoção em folha
            if (arv_vazia(r->esq) && arv_vazia(r->dir))
            {
                free(r);
                return NULL;
            }
            else
            { // remoção em nó interno (esquerda vazia)
                if (arv_vazia(r->esq))
                {
                    p = r;
                    r = r->dir;
                    free(p);
                }
                else // remoção em nó interno (direita vazia)
                    if (arv_vazia(r->dir))
                    {
                        p = r;
                        r = r->esq;
                        free(p);
                    }
                    else
                    {
                        // remoção em nó interno (dir/esq não vazias)
                        p = arv_menor(r->dir);
                        r->info = p->info;
                        r->dir = arv_remove(r->dir, p->info);
                    }
            }
        }
        else // continuar procurando o elemento
            if (c < r->info)
                r->esq = arv_remove(r->esq, c);
            else
                r->dir = arv_remove(r->dir, c);
    }
    return r;
}