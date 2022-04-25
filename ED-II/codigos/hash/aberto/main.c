/* Armazenar uma lista de 1000 pares de termos (português,inglês) numa tabela hash */

#include <stdio.h>
#include <stdlib.h>
#include "hash.h"

int main(void) {
  TabelaHs *ht;
  int i=0, t = 1513, op;
  char chv[30], vlr[30], *res;
  FILE *ft;

  // Criar tabela hash
  ht = criar(t);

  // Inserir pares de termos (pt/en) de um arquivo texto
  ft = fopen("port-ingl.txt", "r");

  while((fscanf(ft,"%s %s",chv,vlr) != EOF)){
       inserirTermoTh(ht, chv, vlr);
       i++;
  }
  printf("\n%d termos foram lidos no arquivo!",i);
  printf("\n%d entradas foram inseridas na tabela hash",ht->qtde);
  printf("\n%d colisões ocorreram",getColisao());
  printf("\n%d entradas identicas foram substituidas",getIguais());

  fclose(ft);
  
  // Buscar um termo na tabela hash
  printf("\nBuscar termo: ");
  scanf("%s",chv);
  res = buscarTermoTh(ht,chv);
  if (res!=NULL)
      printf("Traducao: %s -> %s",chv,res);
  else printf("Termo não encontrado!");
  

  printf("\n\nDeseja ver a Tabela Completa (0/1)? ");
  scanf("%d",&op);
  if (op == 1)  percursoTh(ht);

  liberaTh(ht);
  return 0;
}