#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int menuPreencheOp(){
    int op;
    printf("\n1. Ordenar por Bolha");
    printf("\n2. Ordenar por Selecao");
    printf("\n3. Ordenar por Insercao");
    printf("\n4. Ordenar por Quicksort");
    printf("\n5. Ordenar por Mergesort");
    printf("\n6. Ordenar por Heapsort");
    printf("\n7. Ordenar por Shellsort");
    printf("\n8. Ordenar por Countingsort");
    printf("\n9. Ordenar por Bucketsort");
    printf("\n10. Encerrar");
    printf("\n==> Opcao: ");
    scanf("%d",&op);
    return op;
}


void preenche_aleatorio(int *a, int N){
    int i;
    srand(time(NULL));
    for(i=0; i<N; i++) a[i]=rand()%10001;
}

void preenche_sequencia_asc(int *a, int N, int vinicio){
    int i;
    for(i=0; i<N; i++) {
        a[i]=vinicio;
        vinicio++;
    }
    return;
}

void preenche_sequencia_desc(int *a, int N, int vinicio){
    int i;
    for(i=0; i<N; i++) {
        a[i]=vinicio;
        vinicio--;
    }
    return;
}

void preenche_poucas_chaves(int *a, int N, int nchaves){
    int i;
    srand(time(NULL));
    for(i=0; i<N; i++) a[i]=rand()%nchaves;
    return;
}


int* menuCriaInsere(int *N){
    int *a;
    int op,t,ini;
    printf("\n\tInforme o tamanho do vetor: ");
    scanf("%d",&t);
    a = (int *) malloc (t*sizeof(int));
    printf("\n\n\t ----- Formas de Preenchimento -----");
    printf("\n\t1.Preencher Vetor com valores aleatorios");
    printf("\n\t2.Preencher Vetor com valores em ordem ascendente");
    printf("\n\t3.Preencher Vetor com valores em ordem descendente");
    printf("\n\t4.Preencher Vetor com poucas chaves");
    printf("\n\tOpcao: ");
    scanf("%d",&op);

    switch(op){
        case 1: preenche_aleatorio(a,t);
                break;

        case 2: printf("\n\tValor inicial da sequencia ascendente: ");
                scanf("%d",&ini);
                preenche_sequencia_asc(a,t,ini);
                break;

        case 3: printf("\n\tValor inicial da sequencia descendente: ");
                scanf("%d",&ini);
                preenche_sequencia_desc(a,t,ini);
                break;

        case 4: printf("\n\tInforme o numero de chaves: ");
                scanf("%d",&ini);
                preenche_poucas_chaves(a,t,ini);
                break;
    }
    (*N) = t;
    return a;
}


void imprime(int *a, int N){
    int i;
    printf("\n Elementos: ");
    for (i=0;i<N;i++) printf("%d ",a[i]);
    printf("\n");

    return;
}