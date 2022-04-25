#include "No.h"

typedef struct Fila
{
    TipoNo *inicio, *fim;
    int tamanho;
} TipoFila;

void IniciaFila(TipoFila *fila);
int Vazia(TipoFila *fila);
void Enfileira(int x, TipoFila *fila);
int Desenfileira(TipoFila *fila);
