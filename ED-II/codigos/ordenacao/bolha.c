/*
1. Compara dois elementos adjacentes e troca de posição se estiverem fora de ordem.
2. Quando o maior elemento do vetor for encontrado, ele será trocado até ocupar a última posição.
3. Na segunda passada, o segundo maior será movido para a penúltima posição do vetor, e assim sucessivamente.
*/

#include<stdio.h>
#include<stdbool.h>

void ordBolha (int v[], int n) {
    int i = 0, j = 0;
    int temp = 0;
    bool troca = true;

    //Percorremos o vetor enquanto i >= 1 e troca for verdadeiro
    for(i = n-1; (i >= 1) && troca; i--){
        troca = false;
        for(j = 0; j < i ;j++){
            //Se o elemento seguinte a i é menor do que ele, fazemos a troca
            if(v[j] > v[j+1]){
                temp = v[j];
                v[j] = v[j+1];
                v[j+1] = temp;
                //Houve uma troca
                troca = true;
            }
        }
    }
    //Note que o algoritmo é estável
    return;
}