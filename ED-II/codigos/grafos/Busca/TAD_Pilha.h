#include "No.h"

typedef struct Pilha
{
    TipoNo *topo;
    int tamanho;
} TipoPilha;

void IniciaPilha(TipoPilha *pilha);
int VaziaPilha(TipoPilha *pilha);
void Empilha(int x, TipoPilha *pilha);
int Desempilha(TipoPilha *pilha);
int Topo(TipoPilha *pilha);