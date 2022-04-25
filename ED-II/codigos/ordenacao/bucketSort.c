#include<stdio.h>
#include<stdlib.h>
#include "metodos.h"

#define TAM 5

typedef struct{
	int qtd;
	int valores[TAM];
}BALDE;

void bucketSort(int *V, int N){
	int i = 0,j = 0;
    int maior = 0,menor = 0,nroBaldes = 0,pos = 0;
	BALDE *bd;

	//Acha maior e menor valor
	maior = menor = V[0];
	for(i = 1; i < N; i++){
		if(V[i] > maior) maior = V[i];
		if(V[i] < menor) menor = V[i];
	}
	
    //Inicializa baldes
	nroBaldes = (maior - menor) / TAM + 1;
	bd = (BALDE *)malloc(nroBaldes * sizeof(BALDE));
	
    for(i = 0; i < nroBaldes; i++)
		bd[i].qtd = 0;
	
	//Distribui os valores nos baldes
	for(i = 0; i < N; i++){
		pos = (V[i] - menor)/TAM;
		bd[pos].valores[bd[pos].qtd] = V[i];
		bd[pos].qtd++;
	}

	//Ordena baldes e coloca no array
	pos = 0;
	for(i = 0; i < nroBaldes; i++){
		ordSelecao(bd[i].valores, bd[i].qtd);
		for(j = 0; j < bd[i].qtd; j++){
			V[pos] =  bd[i].valores[j];
			pos++;
		}
	}
    free(bd);

    return;
}
