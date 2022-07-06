
#ifndef FILA_PRE_ED
#define FILA_PRE_ED

#define FALSO -4
#define NAO_ENCONTRADO -3
#define MEMORIA_INSUFICIENTE -2
#define PONTEIRO_INVALIDO -1
#define SUCESSO 1

typedef struct
{
    char aluno[30];
    float notaP1;
    float Notap2;
    float Notap3;
}Dado;

typedef struct FILA Fila;

struct FILA* Cria_Fila (void);

int Enfilera (Dado dado, struct FILA *Fila);

void Clear_Fila(struct FILA *Fila);

void destrutor (struct FILA *Fila);

void exibir_Fila (struct FILA *fila);

int BuscaPrimeiro(struct FILA *fila, Dado *dado);

int TamanhoFila (struct FILA *Fila);

int FilaVazia(struct FILA *fila);

#endif