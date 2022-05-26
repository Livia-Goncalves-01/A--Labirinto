#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

typedef struct Item Item;
typedef struct Block Block;
typedef struct Fila Fila;

struct Item{
	int x;
	int y;
	double calculo;
};

struct Block{
	Item data;
	Block *prox;
};

struct Fila{
	Block *P;
	Block *U;
};

void FFVazia(Fila *f);
void Enfileira(Fila *f, Item d);
void Desenfileira(Fila *f, Item *d);
void Imprime(Fila *f);
void OrdenaBubble(Fila *f);