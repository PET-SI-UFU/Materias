
// Representação de um nó da arvore
struct arv
{
    int info;        // Informação
    struct arv *esq; // Ponteiros para as sub árvores
    struct arv *dir;
};

typedef struct arv Arv;

// Cria uma árvore vazia
Arv *arv_criavazia(void);

/*Cria uma árvore com a informação do nó raiz c,
 com subárvore esquerda 'e' e subárvore direita 'd'*/
Arv *arv_cria(int c, Arv *e, Arv *d);

// Libera o espaço de memória ocupado pela árvore a
Arv *arv_libera(Arv *a);

// Retorna true se a árvore estiver vazia e false caso contrário
int arv_vazia(Arv *a);

// Indica a ocorrência (1) ou não (0) do inteiro c
int arv_pertence(Arv *a, int c);

// Imprime as informações dos nós da árvore
void arv_imprime_pre(Arv *a);
void arv_imprime_pos(Arv *a);
void arv_imprime_em(Arv *a);

int altura(Arv *a);

int isBaS(Arv *a);