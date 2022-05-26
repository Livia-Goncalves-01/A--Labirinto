#include "fila.h"
#include "pilha.h"
#define ARQ_MAXTAM 30

typedef struct Cell Cell;
typedef struct Labirinto Labirinto;

struct Cell {
    char value;
    bool added;
    bool left;
    bool right;
    bool bottom;
};

struct Labirinto {
    Cell **map;
    int linha;
    int coluna;
};

void Inicializar(Labirinto *lab, int l, int c);

void Finalizar(Labirinto *lab);

void ImprimirLab(Labirinto *lab);

int BFS(Labirinto *lab, Fila *f, int n);

bool checkLast(Labirinto *lab, Fila *f);

bool LerArquivo(Labirinto *lab);

void Manhattan(Labirinto *lab, Item *tmp);

void Euclidiana(Labirinto *lab, Item *tmp);

int EscolhaA();

void Opcao(int n, Labirinto *lab, Item *tmp);

int DFS(Labirinto *lab, Pilha *p);

void FazDFS();

void FazA();

void FazBFS();