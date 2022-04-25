

struct termo{
  char port[30];
  char engl[30];
};

typedef struct termo Termo;

struct tabelaHs {
	int tamanho;
  int qtde;
	Termo **tab;	// ponteiro para vetor de ponteiros
};

typedef struct tabelaHs TabelaHs;

TabelaHs *criar (int tam);
void inserirTermoTh(TabelaHs *tabTermos, char *ptChave, char *enValor);
char *buscarTermoTh(TabelaHs *hashtable, char *key);
void percursoTh(TabelaHs *tabTermos);
void liberaTh(TabelaHs *tabTermos);
int getColisao();
int getIguais();