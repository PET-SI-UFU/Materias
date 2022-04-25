/*
    1. Procura o n-ésimo menor elemento do vetor.
    2. Troca do n-ésimo menor elemento com o elemento na n-ésima posição.
    3. Repete até ter colocado todos os elementos em suas posições
    4. Elementos são movimentados apenas uma vez
*/

#include<stdio.h>

void ordSelecao(int v[], int tam){
    int minimo = 0, i = 0, j = 0, menor = 0;

    for (i=0;i<tam-1;i++){
        minimo = i;
        //Encontra o menor elemento do vetor
        for (j=i+1;j<tam;j++){
            if (v[j]<v[minimo])
                minimo = j;
            }
        //Realiza a troca dos valores
        menor = v[minimo];
        v[minimo] = v[i];
        v[i] = menor;
    }
    //Note que o número de trocas é O(n)
    return;
}