#ifndef ARVBINBUSCA_H
#define ARVBINBUSCA_H

struct arv
{
    int info;
    struct arv *esq;
    struct arv *dir;
};

typedef struct arv Arv;

Arv *arv_insere(int c, Arv *raiz);

void arv_imprime_em(Arv *a);
void arv_imprime_pre(Arv *a);
void arv_imprime_pre(Arv *a);
void arv_imprime_niveis(Arv *a);

int arv_busca(Arv *a, int c);
Arv *arv_maior(Arv *a);
Arv *arv_menor(Arv *a);

Arv *arv_remove(Arv *a, int c);

#endif