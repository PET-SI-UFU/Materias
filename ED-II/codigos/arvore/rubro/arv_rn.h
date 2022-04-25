struct rnNo{
  int info;
  char cor;
  struct rnNo *esq, *dir, *pai;
};

struct rnNo *inserir(int val, struct rnNo *raiz);
int buscar(int val, struct rnNo *raiz);
struct rnNo *buscarRec (int valor, struct rnNo  *raiz);
struct rnNo *remover(int  var, struct rnNo *raiz);
void atravessar(struct rnNo * raiz);

int nosVermelhos(struct rnNo* x);