#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include "hash.h"

int colisao = 0;
int iguais = 0;

int getIguais(){
  return iguais;
}
int getColisao(){
  return colisao;
}

/* Criação de uma nova tabela hash. */
TabelaHs *criar (int tam) {

	TabelaHs *tabelaHash; 
  int i;
 
	if((tabelaHash = (TabelaHs *) malloc(sizeof(TabelaHs))) == NULL ) {
		return NULL;
	}
	if((tabelaHash->tab = malloc(sizeof(Termo *) * tam)) == NULL) {
		return NULL;
	}

	for(i = 0; i < tam; i++ ) {
		tabelaHash->tab[i] = NULL;
	}

	tabelaHash->tamanho = tam;
  tabelaHash->qtde = 0;
	return tabelaHash;	
}



/* Espalhamento para a chave (termo portugues) */
int ht_hash(TabelaHs *tabTermos, char *pt) {
	unsigned long int hashval = 0; // ULONG_MAX -> valor máximo possível 
  int i = 0;

	while(hashval < ULONG_MAX && i < strlen(pt) ) {
		hashval = hashval << 8;  // deslocamento de oito bits à direita
		hashval += pt[i];
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
	return nTermo;
}

/* Inserir par chave/valor (pt/en) numa tabela hash. */
void inserirTermoTh(TabelaHs *tabTermos, char *ptChave, char *enValor) {
	int bin = 0, i, fim = 0;
	Termo *novoT = NULL;
	Termo *pos = NULL;


	bin = ht_hash(tabTermos,ptChave);
  //printf("\n Pos Gerada: %d", bin);

	pos = tabTermos->tab[bin]; // pos é ponteiro da posição de base

  if(pos == NULL){
     novoT = criarNovoTermo(ptChave, enValor);
     tabTermos->tab[bin] = novoT;
     tabTermos->qtde++;
  }
  else {
    	/* Se a chave já existe, substituir o valor. */
	    if(strcmp(ptChave, pos->port ) == 0 ) {
          iguais++;
		      strcpy(pos->engl,enValor);
      }
	    else {
      /* Se chave não está na posição hash, e posição ocupada, continuar busca */
          colisao++;
          i = bin+1;
          if (i >= tabTermos->tamanho) i = 0; // reiniciar - percurso circular
          while(tabTermos->tab[i] != NULL){
              /* Próxima posição não é vazia */
              /* Chave encontrada em posição estendida, substituir*/
              if(strcmp(ptChave, tabTermos->tab[i]->port ) == 0 ) {
                 iguais++;
		             strcpy(tabTermos->tab[i]->engl,enValor);
                 fim = 1;
                 break;
              }
            i++;
            if (i >= tabTermos->tamanho) i = 0; // reiniciar - percurso circular
          }
          /* Chave não encontrada, inserir em posição estendida (i) */
          if (i < tabTermos->tamanho && fim == 0){
            novoT = criarNovoTermo(ptChave, enValor);
            tabTermos->tab[i] = novoT;
            tabTermos->qtde++;
            //printf("\nNovo termo: %s %s", novoT->port, novoT->engl);
          }
          else if (fim == 0) /* a chave já foi encontrada e substituída */
                 printf("\nChave encont/substituida em pos estendida (%d)",i);
		      
      }
	}
}


/* Buscar um par chave/valor (termo pt/en) em uma tabela hash. */
char *buscarTermoTh(TabelaHs *tabTermos, char *chv ) {
	int bin = 0,i;
	Termo *par;

	bin = ht_hash(tabTermos, chv);
  //printf("\nPosição na tabela: %d",bin);
	
  /* Alcança a posição bin para buscar o valor da chave. */
	par = tabTermos->tab[bin];


	if(par == NULL)
      return NULL;
  else{
     i = bin;
     while(par!=NULL){
        if (strcmp(tabTermos->tab[i]->port, chv) == 0)
           return tabTermos->tab[i]->engl;
        i++;
        if (i >= tabTermos->tamanho) i = 0; 
        par = tabTermos->tab[i];
     }
  }
  return NULL;
}


void percursoTh(TabelaHs *tabTermos){
   int i,tam;
   Termo *t;

   tam = tabTermos->tamanho;
   for (i=0;i<tam;i++){
     t = tabTermos->tab[i];
     printf("%d:",i);
     if (t != NULL){
       printf("(%s, %s) ",t->port,t->engl);
     }
     printf("\n");
   }
}


void liberaTh(TabelaHs *tabTermos){
   int i,tam;
   Termo *t;

   tam = tabTermos->tamanho;
   for (i=0;i<tam;i++){
     t = tabTermos->tab[i];
     if (t != NULL){
        free(t);
     }
   }
   free(tabTermos);
}