#include<stdio.h>

#define K 100

void countingSort(int *V, int N){
	int i = 0, j = 0, k = 0;
	int baldes[K];
	
    for(i = 0; i< K; i++)
		baldes[i] = 0;
	
    for(i = 0; i < N; i++)
		baldes[V[i]]++;
	
    for(i = 0, j = 0; j<K; j++){
		for(k = baldes[j]; k>0; k--){
			V[i++] = j;
        }
	}
    return;
} 