#include "Fila.h"
#include <stdio.h>
#include <string.h>

int main (void)
{
    Dado dados[4];

    strcpy(dados[0].aluno, "Maycon");
    dados[0].notaP1 = 63;
    dados[0].Notap2 = 75;
    dados[0].Notap3 = 85;

    strcpy(dados[1].aluno, "Cleison");
    dados[1].notaP1 = 45;
    dados[1].Notap2 = 75;
    dados[1].Notap3 = 100;

    strcpy(dados[2].aluno, "Josue");
    dados[2].notaP1 = 83;
    dados[2].Notap2 = 75;
    dados[2].Notap3 = 81;

    strcpy(dados[3].aluno, "Pedro");
    dados[3].notaP1 = 63;
    dados[3].Notap2 = 85;
    dados[3].Notap3 = 85;

    Fila *fila = Cria_Fila();

    if(fila == NULL){
        printf("Erro na criação");
        return 0;
    } 


    for(int i = 0; i < 4; i++)
    {
        Enfilera(dados[i], fila);
    }

    exibir_Fila(fila);
    destrutor(fila);

    return 0;
}