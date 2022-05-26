#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

typedef struct Pos Pos;
typedef struct Bloco Bloco;
typedef struct Pilha Pilha;

struct Pos{
	int x;
	int y;
};

struct Bloco{
	Pos dado;
	Bloco *ant;
};

struct Pilha{
	Bloco *F;
	Bloco *T;
};

void FPVazia(Pilha *P);

void PUSH(Pilha *P, Pos D);

Pos POP(Pilha *P);

void Imprimir(Pilha *P);