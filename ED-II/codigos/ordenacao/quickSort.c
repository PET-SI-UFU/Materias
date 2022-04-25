/*
 **Estratégia para ordenação**
    - Definição de um pivô.
        - Primeiro elemento do vetor
        - Posicionar o pivô ao final dos menores.
    - Colocam-se os elementos menores que o pivô à esquerda.
    - Os elementos maiores que o pivô são acomodados à direita.
    - O pivô é colocado na sua posição correta (ordenada).
    - Os lados esquerdo e o direito são em seguida ordenados independentemente.
*/

#include<stdio.h>

//Protótipo das funções
void quicksort(int v[], int esq, int dir);
int particao(int v[],int esq,int dir);
void troca(int v[], int i, int j);

void troca(int v[], int i,int j){
  int temp;
  temp=v[i];
  v[i]=v[j];
  v[j]=temp;
}

/*  Parte o vetor em duas metadas, de preferência equilibradas e 
*   volta a posição onde o pivô se encontra.*/
int particao(int v[],int esq,int dir){
    int i = 0, fim = 0;

    fim = esq;
    for(i=esq+1;i<=dir;i++){
        if(v[i]<v[esq]) {
            fim=fim+1;
            troca(v,fim,i);
        }
    }
    troca(v,esq,fim);
    return fim;
}

void quicksort(int v[], int esq, int dir){
    int i = 0;

    //Já está ordenado
    if(esq>=dir) return;

    //Devolve a posição onde cai o pivô
    i = particao(v,esq,dir); 
    
    //Lista dos menores
    quicksort(v,esq,i-1); 
    
    //Lista dos maiores
    quicksort(v,i+1,dir);
}