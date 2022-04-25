#include<stdio.h>

//Protótipo de funções
void trocah(int *A, int p, int m);
int esq(int pos);
int dir(int pos);
void heap_maximo_pos(int *A, int pos, int tam_heap);
void construir_heap_max(int *A,  int fim);
void heapsort(int *A, int fim);

void trocah(int *A, int p, int m){
    int temp = 0;
    temp = A[p];
    A[p] = A[m];
    A[m] = temp;
}

int esq(int pos){
   return (pos*2)+1;
}

int dir(int pos){
   return (pos*2)+2;
}

/* FUNÇÃO max-heapify
* A função max-heapify deixa que o valor A[i] “flutue para
* baixo”, de maneira que a subárvore com raiz no índice i se
* torne um heap
*/
void heap_maximo_pos(int *A, int pos, int tam_heap){
    int e = 0,d = 0,maior = 0;
    e = esq(pos);
    d = dir(pos);

    if((e <= tam_heap) && (A[e] > A[pos]))
        maior = e;
    else maior = pos;
    if((d <= tam_heap) && (A[d] > A[maior]))
        maior = d;
    if(maior != pos){
        trocah(A,pos,maior);
        heap_maximo_pos(A,maior,tam_heap);
    }
    return;
}

/*FUNÇÃO build-max-heap
*O procedimento build-max-heap percorre os nós restantes
*da árvore e executa max-hepify sobre cada um
*/
void construir_heap_max(int *A,  int fim){
    int i;
    for(i=(fim-1)/2; i>=0; i--){
        heap_maximo_pos(A,i,fim);
    }
    return;
}

/* FUNÇÃO heapsort
* 1) Construir um heap, usando a função build-max-heap
* 2) Trocar o elemento A[1] com A[n], e atualiza o tamanho do heap para n − 1
* 3) Corrigir o heap com a função max-heapify e repetir o processo
*/
void heapsort(int *A, int fim){
    int i = 0,j = 0,tam_heap = 0;
    tam_heap = fim;

    construir_heap_max(A,fim);
    
    for (i = fim; i>=0; i--){
        trocah(A,0,i);
        tam_heap--;
        heap_maximo_pos(A,0,tam_heap);
    }
    return;
}