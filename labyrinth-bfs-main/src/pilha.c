#include "pilha.h"

void FPVazia(Pilha *P) {
	P->T = (Bloco*)malloc(sizeof(Bloco));
	P->T->ant = NULL;
	P->F = P->T;
}

void PUSH(Pilha *P, Pos D) {
	Bloco *aux = (Bloco*)malloc(sizeof(Bloco));;
	aux->dado = D;
	aux->ant = P->T;
	P->T = aux;
};

Pos POP(Pilha *P) {
	Bloco *tmp;
	Pos aux;
	
	if (P->T == P->F) {
		printf("Vazia!");
		aux.x = -1;
		aux.y = -1;
	} else {
		tmp = P->T; 
		aux = P->T->dado;
		P->T = P->T->ant;
		free(tmp);
	}

	return aux;
};

void Imprimir(Pilha *P) {
	Bloco *aux;
	aux = P->T;
	while(aux->ant != NULL){
		printf("(%d,%d)\n", aux->dado.x, aux->dado.y);
		aux = aux->ant;
	}
}