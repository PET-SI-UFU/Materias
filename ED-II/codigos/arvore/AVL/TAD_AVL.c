#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "TAD_AVL.h"

//CRIA ARVORE
ArvAVL *cria_ArvAVL()
{
    ArvAVL *raiz = (ArvAVL *)malloc(sizeof(ArvAVL));
    if (raiz != NULL)
        *raiz = NULL;
    return raiz;
}

//LIBERA NO
void libera_NO(struct NO *no)
{
    if (no == NULL)
        return;
    libera_NO(no->esq);
    libera_NO(no->dir);
    free(no);
    no = NULL;
}

//LIBERA ARVORE
void libera_ArvAVL(ArvAVL *raiz)
{
    if (raiz == NULL)
        return;
    libera_NO(*raiz); // libera cada nó
    free(raiz);       // libera a raiz
}

//ALTURA DO NO
int altura_NO(struct NO *no)
{
    if (no == NULL)
        return -1;
    else
        return no->altura;
}

//FATOR DE BALANCEAMENTO
int fatorBalanceamento_NO(struct NO *no)
{
    return labs(altura_NO(no->esq) - altura_NO(no->dir));
}

//SE VAZIA
int estaVazia_ArvAVL(ArvAVL *raiz)
{
    if (raiz == NULL)
        return 1;
    if (*raiz == NULL)
        return 1;
    return 0;
}

//TOTAL NO
int totalNO_ArvAVL(ArvAVL *raiz)
{
    if (raiz == NULL)
        return 0;
    if (*raiz == NULL)
        return 0;
    int alt_esq = totalNO_ArvAVL(&((*raiz)->esq));
    int alt_dir = totalNO_ArvAVL(&((*raiz)->dir));
    return (alt_esq + alt_dir + 1);
}

//ALTURA DA ARVORE AVL
int altura_ArvAVL(ArvAVL *raiz)
{
    if (raiz == NULL)
        return 0;
    if (*raiz == NULL)
        return 0;
    int alt_esq = altura_ArvAVL(&((*raiz)->esq));
    int alt_dir = altura_ArvAVL(&((*raiz)->dir));
    if (alt_esq > alt_dir)
        return (alt_esq + 1);
    else
        return (alt_dir + 1);
}

//EM ORDEM
void emOrdem_ArvAVL(ArvAVL *raiz)
{
    if (raiz == NULL)
        return;
    if (*raiz != NULL)
    {
        emOrdem_ArvAVL(&((*raiz)->esq));
        printf("No %d: H(%d) fb(%d)\n", (*raiz)->info, altura_NO(*raiz), fatorBalanceamento_NO(*raiz));
        emOrdem_ArvAVL(&((*raiz)->dir));
    }
}

//CONSULTA
int consulta_ArvAVL(ArvAVL *raiz, int valor)
{
    if (raiz == NULL)
        return 0;
    struct NO *atual = *raiz;
    while (atual != NULL)
    {
        if (valor == atual->info)
        {
            return 1;
        }
        if (valor > atual->info)
            atual = atual->dir;
        else
            atual = atual->esq;
    }
    return 0;
}

//=================================
int maior(int x, int y)
{
    if (x > y)
        return x;
    else
        return y;
}

void RotacaoDireita(ArvAVL *A)
{ // LL
    printf("\nRotacao Direita");
    struct NO *B;
    B = (*A)->esq;
    (*A)->esq = B->dir;
    B->dir = *A;
    (*A)->altura = maior(altura_NO((*A)->esq), altura_NO((*A)->dir)) + 1;
    B->altura = maior(altura_NO(B->esq), (*A)->altura) + 1;
    *A = B;
}

void RotacaoEsquerda(ArvAVL *A)
{ // RR
    printf("\nRotacao Esquerda");
    struct NO *B;
    B = (*A)->dir;
    (*A)->dir = B->esq;
    B->esq = (*A);
    (*A)->altura = maior(altura_NO((*A)->esq), altura_NO((*A)->dir)) + 1;
    B->altura = maior(altura_NO(B->dir), (*A)->altura) + 1;
    (*A) = B;
}

void RotacaoDuplaDireita(ArvAVL *A)
{ // LR
    printf("\nRotacao Dupla Direita");
    RotacaoEsquerda(&(*A)->esq);
    RotacaoDireita(A);
}

void RotacaoDuplaEsquerda(ArvAVL *A)
{ // RL
    printf("\nRotacao Dupla Esquerda");
    RotacaoDireita(&(*A)->dir);
    RotacaoEsquerda(A);
}

int insere_ArvAVL(ArvAVL *raiz, int valor)
{
    int r;
    if (*raiz == NULL)
    { //árvore vazia ou nó folha
        struct NO *novo;
        novo = (struct NO *)malloc(sizeof(struct NO));
        if (novo == NULL)
            return 0;

        novo->info = valor;
        novo->altura = 0;
        novo->esq = NULL;
        novo->dir = NULL;
        *raiz = novo;
        return 1;
    }

    struct NO *atual = *raiz;
    if (valor < atual->info)
    {
        r = insere_ArvAVL(&(atual->esq), valor);
        if (r == 1)
        {
            if (fatorBalanceamento_NO(atual) >= 2)
            {
                if (valor < (*raiz)->esq->info)
                {
                    RotacaoDireita(raiz);
                }
                else
                {
                    RotacaoDuplaDireita(raiz);
                }
            }
        }
    }
    else
    {
        if (valor > atual->info)
        {
            r = insere_ArvAVL(&(atual->dir), valor);
            if (r == 1)
            {
                if (fatorBalanceamento_NO(atual) >= 2)
                {
                    if ((*raiz)->dir->info < valor)
                    {
                        RotacaoEsquerda(raiz);
                    }
                    else
                    {
                        RotacaoDuplaEsquerda(raiz);
                    }
                }
            }
        }
        else
        {
            printf("Valor duplicado!!\n");
            return 0;
        }
    }

    atual->altura = maior(altura_NO(atual->esq), altura_NO(atual->dir)) + 1;

    return r;
}

struct NO *procuraMenor(struct NO *raiz)
{
    struct NO *atual, *prox;
    if (estaVazia_ArvAVL(&raiz))
        return NULL;
    atual = raiz;
    prox = raiz->esq;
    while (prox != NULL)
    {
        atual = prox;
        prox = prox->esq;
    }
    return atual;
}

int remove_ArvAVL(ArvAVL *raiz, int valor)
{

    int r;

    if (*raiz == NULL)
    { // valor não existe
        printf("valor não encontrado!!\n");
        return 0;
    }

    if (valor < (*raiz)->info)
    {
        r = remove_ArvAVL(&(*raiz)->esq, valor);
        if (r == 1)
        {
            if (fatorBalanceamento_NO(*raiz) >= 2)
            {
                if (altura_NO((*raiz)->dir->esq) <= altura_NO((*raiz)->dir->dir))
                    RotacaoEsquerda(raiz);
                else
                    RotacaoDuplaEsquerda(raiz);
            }
        }
    }

    if ((*raiz)->info < valor)
    {
        r = remove_ArvAVL(&(*raiz)->dir, valor);
        if (r == 1)
        {
            if (fatorBalanceamento_NO(*raiz) >= 2)
            {
                if (altura_NO((*raiz)->esq->dir) <= altura_NO((*raiz)->esq->esq))
                    RotacaoDireita(raiz);
                else
                    RotacaoDuplaDireita(raiz);
            }
        }
    }

    if ((*raiz)->info == valor)
    {
        if (((*raiz)->esq == NULL || (*raiz)->dir == NULL))
        { // nó tem 1 filho ou nenhum
            struct NO *raizAntiga = (*raiz);
            if ((*raiz)->esq != NULL)
                *raiz = (*raiz)->esq;
            else
                *raiz = (*raiz)->dir;
            free(raizAntiga);
        }
        else
        { // nó tem 2 filhos
            struct NO *temp = procuraMenor((*raiz)->dir);
            (*raiz)->info = temp->info;
            remove_ArvAVL(&(*raiz)->dir, (*raiz)->info);
            if (fatorBalanceamento_NO(*raiz) >= 2)
            {
                if (altura_NO((*raiz)->esq->dir) <= altura_NO((*raiz)->esq->esq))
                    RotacaoDireita(raiz);
                else
                    RotacaoDuplaDireita(raiz);
            }
        }
        if (*raiz != NULL)
            (*raiz)->altura = maior(altura_NO((*raiz)->esq), altura_NO((*raiz)->dir)) + 1;
        return 1;
    }

    (*raiz)->altura = maior(altura_NO((*raiz)->esq), altura_NO((*raiz)->dir)) + 1;
    return r;
}

int remove_Menores_ArvAVL(ArvAVL *raiz, int valor)
{
    struct NO *elem;
    elem = procuraMenor(*raiz);
    while (elem != NULL && elem->info < valor)
    {
        printf("\n -> Remoção do %d ", elem->info);
        remove_ArvAVL(&(*raiz), elem->info);
        elem = procuraMenor(*raiz);
    }
}

// Correção nas linhas 301/302, conforme apontamento em aula!!
int iguais_ArvAVL(ArvAVL *r1, ArvAVL *r2)
{
    struct NO *elem;
    if (*r1 == NULL && *r2 == NULL)
        return 1;
    else
    {
        if (*r1 == NULL || *r2 == NULL)
            return 0;
        if ((*r1)->info == (*r2)->info)
        {
            return ((iguais_ArvAVL(&(*r1)->esq, &(*r2)->esq)) &&
                    (iguais_ArvAVL(&(*r1)->dir, &(*r2)->dir)));
        }
        else
            return 0;
    }
}
