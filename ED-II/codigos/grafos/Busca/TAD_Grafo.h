/*
   O grafo é uma estrutura com número de vértices,
   número de ligações(arcos) e a estrutura vértice.
*/
struct grafo
{
    int NumVert;
    int NumArco;
    struct noVert *vertices;
};
typedef struct grafo *Grafo;

/*
   Cada vértice tem um número que o identifica
   o ponteiro para o pŕoximo e outra para as
   conexões que ele possui
*/
struct noVert
{
    int vert;
    struct noVert *prox;
    struct noAdj *ladj;
};

/*
   Cada conexão está ligada a um vértice
   e indica a próxima conexão que está ligada
   a esse mesmo vértice.
*/
struct noAdj
{
    int vert;
    struct noAdj *prox;
};

struct visitaTempo
{
    int vert;
    int tempoDescoberta;
    int tempoFinalizacao;
};

Grafo criarGrafo(int nVert);
void inserirArco(Grafo G, int v1, int v2);
void inserirNovoVertice(Grafo G, int nv);
int grauVertice(Grafo G, int v);
void imprimirListaAdj(Grafo G);
void liberarListaAdj(Grafo G);
void imprimirListaAdjRec(struct noVert *nv);

void BuscaEmLargura(Grafo G, int v);
void BuscaEmProfundidade(Grafo G, int v);
void PercursoProfundidadeTempo(Grafo G, int v);
