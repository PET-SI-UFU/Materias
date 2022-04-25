#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include "hash.h"

/* Criação de uma nova tabela hash. */
TabelaHs *criar (int tam) {

	TabelaHs *tabelaHash = NULL;
	int i;

	if(tam < 1) return NULL;

	/* Alocação de memória para a tabela (estrutura). */
	if((tabelaHash = malloc(sizeof(TabelaHs))) == NULL ) {
		return NULL;
	}
	/* Alocação de memória para o vetor associado à tabela. */
	if((tabelaHash->tab = malloc(sizeof(Termo *) * tam)) == NULL) {
		return NULL;
	}

	for(i = 0; i < tam; i++ ) {
		tabelaHash->tab[i] = NULL;
	}

	tabelaHash->tamanho = tam;
	return tabelaHash;	
}



/* Espalhamento para a chave (termo portugues) */
int ht_hash(TabelaHs *tabTermos, char *pt) {
	unsigned long int hashval = 0; // ULONG_MAX -> valor máximo possível 
  int i = 0;

	while(hashval < ULONG_MAX && i < strlen(pt) ) {
		hashval = hashval << 8;  // deslocamento de oito bits à direita
		hashval += pt[i];
    printf("\n%lu -> %c (%d)", hashval, pt[i], pt[i]);
		i++;
	}
	return hashval % tabTermos->tamanho;
}

/* Criação do par (chave/valor) -> Termo (pt/en) */
Termo *criarNovoTermo( char *pt, char *en ) {
	Termo *nTermo;

	if( ( nTermo = malloc( sizeof( Termo ) ) ) == NULL ) {
		return NULL;
	}

  strcpy(nTermo->port,pt);   // copiar termo chave
  strcpy(nTermo->engl,en);   // copiar valor
	nTermo->prox = NULL;

	return nTermo;
}

/* Inserir par chave/valor (pt/en) numa tabela hash. */
void inserirTermoTh(TabelaHs *tabTermos, char *ptChave, char *enValor) {
	int bin = 0;
	Termo *novoT = NULL;
	Termo *pos = NULL;
	Termo *ult = NULL;

	bin = ht_hash(tabTermos,ptChave);
  //printf("\n Bin Gerado: %d", bin);

	pos = tabTermos->tab[bin];

	while(pos != NULL  && strcmp(ptChave, pos->port ) > 0 ) {
		ult = pos;
		pos = pos->prox;
	}

	/* Se a chave já existe, substituir o valor. */
	if(pos != NULL && strcmp(ptChave, pos->port ) == 0 ) {
		strcpy(pos->engl,enValor);

	} else {
    /* Se chave não existe, inserir novo par (termo) */
		novoT = criarNovoTermo(ptChave, enValor);
    //printf("\nNovo termo: %s %s", novoT->port, novoT->engl);

		/* Inserção no início da lista. */
		if(pos == tabTermos->tab[bin]) {
			novoT->prox = pos;
			tabTermos->tab[bin] = novoT;
	
		/* Inserção ao final da lista. */
		} else if (pos == NULL) {
			ult->prox = novoT;
	
		/* Inserção ordenada */
		} else  {
			novoT->prox = pos;
			ult->prox = novoT;
		}
	}
}


/* Buscar um par chave/valor (termo pt/en) em uma tabela hash. */
char *buscarTermoTh(TabelaHs *tabTermos, char *chv ) {
	int bin = 0;
	Termo *par;

	bin = ht_hash(tabTermos, chv);
  //printf("\nPosição na tabela: %d",bin);
	
  /* Alcança a posição bin para buscar o valor da chave. */
	par = tabTermos->tab[bin];
	while( par != NULL && strcmp( chv, par->port ) > 0 ) {
		par = par->prox;
	}

	if( par == NULL || strcmp( chv, par->port ) != 0 ) {
		return NULL;

	} else {
		return par->engl;
	}
	
}


void percursoTh(TabelaHs *tabTermos){
   int i,tam;
   Termo *t;

   tam = tabTermos->tamanho;
   for (i=0;i<tam;i++){
     t = tabTermos->tab[i];
     printf("%d:",i);
     while (t != NULL){
       printf("(%s, %s) ",t->port,t->engl);
       t = t->prox;
     }
     printf("\n");
   }
}