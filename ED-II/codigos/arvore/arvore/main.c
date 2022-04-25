#include <stdio.h>
#include <stdlib.h>
#include "TAD_Arvore.h"

int main()
{
    Arv *a, *b, *c;
    int vazia, res;
    Arv *dest;

    printf("- Programa arvore binária -\n");

    a = arv_cria(2, arv_criavazia(), arv_criavazia());

    b = arv_cria(5, arv_cria(3, arv_criavazia(), arv_criavazia()),
                 arv_cria(7, arv_criavazia(), arv_criavazia()));

    printf("\n1. Criacao da arvore binaria principal");
    c = arv_cria(10, a, b);

    printf("\n2. Verificacao de conteudo: ");
    vazia = arv_vazia(c);
    if (vazia == 1)
        printf(" Arvore vazia");
    else
        printf(" Arvore nao vazia");

    printf("\n2a. Funcao Pertence: ");

    res = arv_pertence(c, 6);
    if (res == 1)
        printf(" Elemento pertence");
    else
        printf(" Elemento não pertence a arvore");

    printf("\n3. Destruicao da arvore e seu conteudo: ");
    dest = arv_libera(c);
    if (dest == NULL)
        printf("Arvore destruida - memoria liberada");
    else
        printf("Problema na liberacao - retorno nao nulo");

    printf("\n4. Reconstrucao da arvore binaria principal");
    a = arv_cria(2, arv_cria(1, NULL, NULL), arv_cria(4, NULL, NULL));

    b = arv_cria(15, arv_cria(3, arv_cria(1, NULL, NULL), arv_cria(12, NULL, NULL)),
                 arv_cria(17, arv_cria(6, NULL, NULL), NULL));

    c = arv_cria(10, a, b);

    printf("\n5. Busca do elemento 5 na arvore binaria principal");
    res = arv_pertence(c, 5);
    if (res == 0)
        printf(" - Elemento nao encontrado");
    else
        printf(" - Elemento encontrado");

    printf("\n6. Impressao dos elementos Pre-Em-Pos Ordem: \n");
    arv_imprime_pre(c);
    printf("\n");
    arv_imprime_em(c);
    printf("\n");
    arv_imprime_pos(c);
    printf("\n");

    res = altura(c);
    printf("Altura: %d", res);

    //  res = isBaS(c);
    //  printf("\nResultado: %d",res);
    return 0;
}