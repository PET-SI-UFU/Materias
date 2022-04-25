/* Armazenar uma lista de 1000 pares de termos (português,inglês) numa tabela hash */

#include <stdio.h>
#include <stdlib.h>
#include "hash.h"

int main(void) {
  TabelaHs *ht;
  int i=0, t = 1029, op;
  char chv[30], vlr[30], *res;
  FILE *ft;

  // Criar tabela hash
  ht = criar(t);
  
  // Inserir pares de termos (pt/en) de um arquivo texto
  ft = fopen("port-ingl.txt", "r");

  while((fscanf(ft,"%s  %s",chv,vlr) != EOF)){
       inserirTermoTh(ht, chv, vlr);
       i++;
  }
  printf("\n%d tentativas de inserção na tabela hash!",i);
  fclose(ft);
  
  inserirTermoTh(ht, "casa", "house");
  // Buscar um termo na tabela hash
  printf("\n\nBuscar termo: ");
  scanf("%s",chv);
  res = buscarTermoTh(ht,chv);
  if (res!=NULL)
      printf("\n\nTraducao: %s -> %s",chv,res);
  else printf("\nTermo não encontrado!");
  

  printf("\n\nDeseja ver a Tabela Completa (0/1)? ");
  scanf("%d",&op);
  if (op == 1)  percursoTh(ht);
  return 0;
}