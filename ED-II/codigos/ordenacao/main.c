/*
        COMANDOS DE COMPILAÇÃO
        gcc -c main.c 
        gcc -c bolha.c bucketSort.c countingSort.c heapSort.c insercao.c mergeSort.c quickSort.c shellSort.c selecao.c preencher.c 
        gcc -o main main.o countingSort.o bolha.o bucketSort.o heapSort.o insercao.o mergeSort.o preencher.o quickSort.o selecao.o shellSort.o
        ./main
*/
#include<stdio.h>
#include<stdlib.h>
#include "metodos.h"


int main(void){
    int t = 0, *a;
    int op = 0;

    // Menu com opcoes de algoritmos de ordenacao
    op = menuPreencheOp();

    do{
        a=menuCriaInsere(&t);
        printf("\nVetor Inicial: ");
        imprime(a,t);
        switch(op){
            case 1: ordBolha(a,t);
                    printf("\nVetor Ordenado por Bolha: ");
                    break;

            case 2: ordSelecao(a,t);
                    printf("\nVetor Ordenado por Selecao: ");
                    break;

            case 3: ordInsercao(a,t);
                    printf("\nVetor Ordenado por Insercao: ");
                    break;

            case 4: quicksort(a,0,t-1);
                    printf("\nVetor Ordenado por Quicksort: ");
                    break;

            case 5: mergesort(a,0,t-1);
                    printf("\nVetor Ordenado por Mergesort: ");
                    break;

            case 6: heapsort(a,t-1);
                    printf("\nVetor Ordenado por Heapsort: ");
                    break;

            case 7: shellsort(a,t);
                    printf("\nVetor Ordenado por Shellsort: ");
                    break;

            case 8: countingSort(a,t);
                    printf("\nVetor Ordenado por Countingsort: ");
                    break;
            case 9: bucketSort(a,t);
                    printf("\nVetor Ordenado por Bucketsort: ");
                    break;

            default: printf("\nOpcao incorreta!");
        }
        imprime(a,t);
        free(a);
        op = menuPreencheOp();
    }while(op!=10);

    return 0;
}