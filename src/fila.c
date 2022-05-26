#include "fila.h"

void FFVazia(Fila *f){
	f->P = NULL;
	f->U = NULL;
}

void Enfileira(Fila *f, Item d){
	Block *novo = (Block*)malloc(sizeof(Block));
	novo->data = d;
	novo->prox = NULL;
	
	if (f->P == NULL) {
		f->P = novo;
	}
	else {
		f->U->prox = novo;
	}
	f->U = novo;
}

void Desenfileira(Fila *f, Item *d){
	Block *aux;

	if(f->P == NULL){
		printf("FILA VAZIA!\n");
		d->x = -1;
		d->y = -1;
		return;
	}
	
	*d = f->P->data;
	aux = f->P;
	f->P = f->P->prox;
	free(aux);
	if(f->P == NULL)
		f->U = NULL;
}

void Imprime(Fila *f){
	Block *aux;

	aux = f->P;
	while(aux != NULL){
		printf("(%d,%d)\n", aux->data.x, aux->data.y);
		aux = aux->prox;
	}
}

void OrdenaBubble(Fila *f){
	bool mudou = false;
	Block *aux1, *aux2 =NULL;
	Item tmp;

	do{
		mudou = false;
		aux1 = f->P;
		while(aux1->prox != aux2){
			if(aux1->data.calculo > aux1->prox->data.calculo){
				tmp = aux1->data;
				aux1->data = aux1->prox->data;
				aux1->prox->data= tmp;
				mudou = true;
			}
			aux1 = aux1->prox;
		}
		aux2=aux1;
	}while(mudou);
}