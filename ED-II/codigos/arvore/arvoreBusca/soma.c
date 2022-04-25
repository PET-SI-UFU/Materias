#include "TAD_Fila.h"
#include "TAD_Arvore.h"
#include "soma.h"
#include <stdio.h>
#include <stdlib.h>

// Busca por um elemento e, o retorna caso exista, ou retorna -1;
int arv_buscaL(Arv *a, int c)
{
    if (a == NULL)
        return -1;
    else if (c == a->info)
        return a->info;
    else if (c < a->info)
        return arv_buscaL(a->esq, c);
    else
        return arv_buscaL(a->dir, c);
}

// para cada elemento do percurso em níveis, busca pelo complementar da soma
void achaSomaL(Arv *a, int soma)
{
    TipoFila *f;
    int falta, complementar;
    Arv *aux;
    if (a != NULL)
    {
        f = IniciaFila();
        Enfileira(a, f);
        while (!Vazia(f))
        {
            aux = Desenfileira(f);
            falta = soma - aux->info;
            complementar = arv_buscaL(a, falta);
            if (complementar != -1)
                printf("%d + %d = %d\n", aux->info, complementar, soma);
            if (aux->esq != NULL)
                Enfileira(aux->esq, f);
            if (aux->dir != NULL)
                Enfileira(aux->dir, f);
        }
    }
}

Retorna achaSoma(Arv *A, int V)
{
    if (A == NULL)
    {
        struct Retorna r;
        r.valido = 0;
        return r;
    }
    if (A->info < V)
    {
        if (arv_busca(A, V - A->info))
        {
            struct Retorna r;
            r.valido = 1;
            r.a = A->info;
            r.b = V - r.a;
            return r;
        }
    }
    struct Retorna r1 = achaSoma(A->esq, V);
    if (r1.valido)
        return r1;

    struct Retorna r2 = achaSoma(A->dir, V);

    return r2;
}

int achaVal(Arv *a, int b)
{

    if (a == NULL)
        return 0;

    else if (b == a->info)
        return 1;
    else if (b > a->info)
        return achaVal(a->dir, b);
    else
        return achaVal(a->esq, b);
}

// Retorna dois números (valA e valB) que somados dão v
int achaSomaP(Arv *a, int v, int *valA, int *valB)
{

    if (a == NULL)
        return 0;

    int val = v - a->info;
    printf("\n%d", val);
    if (achaVal(a->esq, val) || achaVal(a->dir, val))
    {
        *valA = a->info;
        *valB = val;
        return 1;
    }
    else if (achaSomaP(a->esq, v, valA, valB))
        return 1;
    else
        return achaSomaP(a->dir, v, valA, valB);
}

int consulta_Arv(Arv *raiz, int valor)
{
    if (raiz == NULL)
        return 0;
    Arv *atual = raiz;
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

int *achaSomaX(Arv *arv, int V)
{
    int *vet;
    int i, j;
    for (i = 0; i <= V; i++)
    {
        for (j = i + 1; j <= V; j++)
        {
            if (i + j == V)
            {
                printf("%d %d \n", i, j);
                if (consulta_Arv(arv, i) && consulta_Arv(arv, j))
                {
                    printf("Válido");
                    vet = (int *)malloc(2 * sizeof(int));
                    vet[0] = i;
                    vet[1] = j;

                    return vet;
                }
            }
        }
    }

    return NULL;
}

int arv_pertence(Arv *a, int c)
{
    if (a == NULL)
        return 0; /* árvore vazia: não encontrou */
    else
        return (a->info == c || arv_pertence(a->esq, c) || arv_pertence(a->dir, c));
}

int achaSomaK(Arv *a, int V)
{
    int num1, num2;
    printf("\n%d %d = ", num1, num2);

    if (a == NULL)
        return 0;
    else if (arv_pertence(a, num1) && arv_pertence(a, num2) && num1 + num2 == V)
    {
        printf("\n%d %d = ", num1, num2);
        return 1;
    }
}