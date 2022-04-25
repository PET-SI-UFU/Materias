#include <stdio.h>
#include <stdlib.h>
#include "arv_rn.h"

void rotacaoEsq(struct rnNo **raiz, struct rnNo *x) {
struct rnNo *y;
   y = x->dir;
   x->dir = y->esq;
   if (y->esq != NULL) 
      y->esq->pai = x;
   y->pai = x->pai;
   if (x->pai == NULL) {
      *raiz = y;
   } 
   else {
      if (x == x->pai->esq) 
        x->pai->esq = y;
      else 
        x->pai->dir = y;
   }
  y->esq = x;
  x->pai = y;
}


void rotacaoDir(struct rnNo **raiz, struct rnNo *x) {
  struct rnNo *y;
   y = x->esq;
   x->esq = y->dir;
   if (y->dir != NULL) 
       y->dir->pai = x;
   y->pai = x->pai;
   if (x->pai == NULL) {
      *raiz = y;
   } 
   else {
      if (x == x->pai->esq) 
        x->pai->esq = y;
      else 
        x->pai->dir = y;
   }
  y->dir = x;
  x->pai = y;
}


void reparaInsercao(struct rnNo **raiz, struct rnNo *novo){
   
   if (*raiz == novo) (*raiz)->cor = 'p'; //Conserta quebra da regra 2

   while (novo->pai != NULL && novo->pai->cor == 'v') {
         
         if (novo->pai->pai != NULL && novo->pai == novo->pai->pai->esq) { 
            // o pai é o nó da esquerda
            struct rnNo *tio;
            tio = novo->pai->pai->dir;
            if (tio != NULL && tio->cor == 'v') { // Caso 1 - tio é vermelho
                   novo->pai->cor = 'p'; 
                   tio->cor = 'p'; 
                   novo->pai->pai->cor = 'v'; 
                   novo = novo->pai->pai; 
            } 
            else { // Casos 2 e 3 - tio é preto
                  if (novo == novo->pai->dir) { // novo nó está à direita
                     novo = novo->pai; 
                     rotacaoEsq(raiz, novo); 
                  }
                  novo->pai->cor = 'p';         // novo nó está à esquerda 
                  novo->pai->pai->cor = 'v';
                  rotacaoDir(raiz, novo->pai->pai); 
            }
         }
         else {
             if (novo->pai->pai != NULL && novo->pai == novo->pai->pai->dir) {
                // o pai é o nó da direita
                struct rnNo *tio = novo->pai->pai->esq;
                if (tio != NULL && tio->cor == 'v') { // Caso 1 - tio é vermelho
                    novo->pai->cor = 'p'; 
                    tio->cor = 'p'; 
                    novo->pai->pai->cor = 'v'; 
                    novo = novo->pai->pai; 
                } 
                else {  // Casos 2 e 3 - tio é preto
                    if (novo == novo->pai->esq) { // novo nó está à esquerda 
                       novo = novo->pai; 
                       rotacaoDir(raiz, novo); 
                    }
                    novo->pai->cor = 'p';        // novo nó está à direita 
                    novo->pai->pai->cor = 'v';
                    rotacaoEsq(raiz, novo->pai->pai);  
                }
             } // fim if
         } // fim else
    } // fim while
    (*raiz)->cor = 'p'; //Conserta possível quebra da regra 2  
}



struct rnNo *inserir(int val, struct rnNo *raiz) {
  struct rnNo *novaRaiz = raiz;
  struct rnNo *pai = NULL;
  struct rnNo *atual = raiz;
  struct rnNo *novo;
  novo = (struct rnNo *) malloc (sizeof (struct rnNo));
  novo->info = val;
  //busca a posicao na árvore
  while (atual != NULL) {
    pai = atual;
    atual = (novo->info < atual->info) ? atual->esq :atual->dir;
  }
  novo->pai = pai;
  if (pai == NULL) novaRaiz = novo;
  else 
    if (novo->info < pai->info) pai->esq = novo;
    else pai->dir = novo;
  novo->esq = NULL;
  novo->dir = NULL;
  novo->cor = 'v';
  reparaInsercao(&novaRaiz, novo);
  return novaRaiz;
}



void percursoEmOrdem(struct rnNo * raiz){

  struct rnNo * temp = raiz;
  if (temp != NULL) {
    percursoEmOrdem(temp->esq);
    printf(" %d–%c ", temp->info, temp->cor);
    percursoEmOrdem(temp->dir);
  }
  return;
}


void percursoPosOrdem(struct rnNo * raiz) {

  struct rnNo * temp = raiz;
  if (temp != NULL)  {
    percursoPosOrdem(temp->esq);
    percursoPosOrdem(temp->dir);
    printf(" %d–%c ", temp->info, temp->cor);
  }
  return;
}


void atravessar(struct rnNo * raiz){

  if (raiz != NULL){
    printf("Raiz: %d–%c", raiz->info, raiz->cor);
    printf("\nPercurso em Ordem:\n");
    percursoEmOrdem(raiz);
    printf("\nPercurso pos-Ordem\n");
    percursoPosOrdem(raiz);
  }
}


int buscar(int val, struct rnNo *raiz){

  struct rnNo *temp = raiz;
  while (temp != NULL) {
    if (val > temp->info) 
        temp = temp->dir; 
    else 
       if (val < temp->info)
           temp = temp->esq;
       else 
           return 1;
  }
  return 0;
}


struct rnNo *buscarRec (int valor, struct rnNo  *raiz) {
   if (!raiz || raiz->info == valor)
       return raiz;
   return (valor > raiz->info) ? buscarRec(valor, raiz->dir) : buscarRec(valor, raiz->esq);
}


struct rnNo *min(struct rnNo *x){

  while (x->esq)  
     x = x->esq;
  return x;
}


struct rnNo *sucessor(struct rnNo *x){

  struct rnNo * y;
  if (x->dir) {
    return min(x->dir);
  }
  y = x->pai;
  while (y && x == y->dir) {
    x = y;
    y = y->pai;
  }
  return y;
}

int nosVermelhos(struct rnNo* x) {
    int cont = 0;
    if (x == NULL) {
        return 0;
    }
    cont += nosVermelhos(x->esq);
    cont += nosVermelhos(x->dir);

    if(x->cor == 'v'){
        cont++;
    }
    return cont;
}