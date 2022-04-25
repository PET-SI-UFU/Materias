struct Retorna
{
    int a;
    int b;
    int valido;
};
typedef struct Retorna Retorna;

Retorna achaSoma(Arv *A, int V);
int *achaSomaX(Arv *arv, int V);
void achaSomaL(Arv *a, int soma);
int achaSomaP(Arv *a, int v, int *valA, int *valB);

int achaSomaK(Arv *a, int V);