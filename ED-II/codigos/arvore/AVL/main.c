#include <stdio.h>
#include <stdlib.h>

#include "TAD_AVL.h"

int main()
{
    ArvAVL *avl, *avlc;
    int res, i;
    int N1 = 10, dados1[] = {50, 25, 10, 5, 7, 3, 30, 20, 8, 15};
    int N = 10, dados[] = {50, 25, 10, 5, 7, 3, 30, 20, 8, 15};
    // int N = 11, dados[11] = {50,25,10,5,5,7,3,30,20,8,15};
    // int N = 10, dados[10] = {1,2,3,10,4,5,9,7,8,6};

    avl = cria_ArvAVL();
    avlc = cria_ArvAVL();

    for (i = 0; i < N; i++)
    {
        res = insere_ArvAVL(avl, dados[i]);
    }
    //
    for (i = 0; i < N1; i++)
    {
        res = insere_ArvAVL(avlc, dados1[i]);
    }

    printf("\nÁrvore AVL :\n");
    emOrdem_ArvAVL(avl);

    printf("\nÁrvore AVLc :\n");
    emOrdem_ArvAVL(avlc);

    res = iguais_ArvAVL(avl, avlc);
    printf("\nResultado iguais = %d\n\n", res);

    printf("\nRemoção em AVL :\n");
    emOrdem_ArvAVL(avl);
    remove_ArvAVL(avl, 10);
    remove_Menores_ArvAVL(avl, 45);
    printf("\nApós remoção: \n");
    emOrdem_ArvAVL(avl);

    printf("\n\n");
    libera_ArvAVL(avl);

    return 0;
}

/*
        50
      /    \
     5      82
    / \    / \
   2  10  70  84




  */