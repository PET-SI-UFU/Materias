
struct grafo {
    int NumVertices;
    int NumArestas;
    int **Mat;
};

typedef struct grafo TipoGrafo;

TipoGrafo* CriarGrafo(int NVertices);
int inserirAresta(TipoGrafo *G, int v1, int v2);
int retirarAresta(TipoGrafo *Grafo, int v1, int v2);
void exibirGrafo(TipoGrafo *G);
void exibirMatriz(TipoGrafo *G);
TipoGrafo* liberarGrafo(TipoGrafo* G);
int verificaAresta(TipoGrafo *Grafo, int v1, int v2);

int adjacencias(TipoGrafo *Grafo, int v);