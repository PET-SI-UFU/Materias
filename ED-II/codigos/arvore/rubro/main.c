#include <stdio.h>
#include <stdlib.h>
#include "arv_rn.h"


int main(){
  struct rnNo *raiz = NULL, *no;

  int opcao, val, res, var,c;


  while (1)  {

    printf("\nMenu Arvore Rubro-Negra\n1:Insere  \n2:Remove  \n3:Busca  \n4:Percorre  \n5:Encerra\n-->Opcao: ");

    scanf("%d", &opcao);

    switch (opcao) {

    case 1:
      printf("Valor (numero) a ser adicionado : ");
      scanf("%d", &val);
      raiz = inserir(val, raiz);
      break;

    case 2:
      printf("Valor (numero) a ser removido : ");
      scanf("%d", &var);
    //  remover(var, raiz);
      break;

    case 3:
      printf("\nValor a ser buscado: ");
      scanf("%d", &val);
      res = buscar(val, raiz);
      if (res==1) printf("Elemento encontrado!");
      else printf("Elemento nao encontrado!");
      no = buscarRec(val,raiz);
      if (no != NULL) printf(" (%d-%c)",no->info,no->cor);
      break;

    case 4:
      atravessar(raiz);
      c = nosVermelhos(raiz);
      printf("\nNós vermelhos atravessados: %d",c);
      break;

    case 5:
      return 1;

    default:
      printf("\nOpcao Invalida\n");
    }



  }
  return 0;
}