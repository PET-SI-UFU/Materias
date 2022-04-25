

struct termo{
  char port[30];
  char engl[30];
  struct termo *prox;
};

typedef struct termo Termo;

struct tabelaHs {
	int tamanho;
	Termo **tab;	
};

typedef struct tabelaHs TabelaHs;

TabelaHs *criar (int tam);
void inserirTermoTh(TabelaHs *tabTermos, char *ptChave, char *enValor);
char *buscarTermoTh(TabelaHs *hashtable, char *key);
void percursoTh(TabelaHs *tabTermos);