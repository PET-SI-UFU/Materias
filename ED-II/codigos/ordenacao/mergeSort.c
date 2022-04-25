/*
1. Divida o vetor em duas metades.
2. Recursivamente ordene cada metade.
*/

#include<stdio.h>
#include<stdlib.h>

//Protótipo de funções
void intercala(int v[], int e, int m, int d);
void mergesort (int v[], int e, int d);

void intercala(int v[], int e, int m, int d){
    int *r;  //vetor auxiliar dinâmico para armazenar a mistura
    int i = 0,j = 0,k = 0;

    r = (int *) malloc (((d+1)-e)*sizeof(int));

    i=e;
    j=m+1;
    k=0;

    /*  intercala enquanto nenhuma das partes do vetor
        foi consumida totalmente
    */
    while ((i<=m)&&(j<=d)){
    if(v[i]<=v[j]){ 
        r[k]=v[i];
        i++;
    }
    else{
        r[k]=v[j];
        j++;
    }
    k++;
    }

    while (i<=m) {r[k]=v[i]; i++; k++;} //termina de intercalar se sobrou à esquerda
    while (j<=d) {r[k]=v[j]; j++; k++;} //termina de intercalar se sobrou à direita

    //Copia do vetor auxiliar (contendo os dados ordenados) sobre o vetor original
    j=0;
    for(i=e;i<=d;i++){
        v[i]=r[j];
        j++;
    }
    free(r);

    return;
}

void mergesort (int v[], int e, int d){
    int m = 0;
    if (e<d){
        m = (e+d)/2;
        mergesort(v,e,m);
        mergesort(v,m+1,d);
        intercala(v,e,m,d);
    }//Note que o algoritmo é estavel
    return;
}