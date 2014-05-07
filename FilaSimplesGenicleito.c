/*
 * FilaSimplesGenicleito.c
 *
 * Copyright 2014 Genicleito <genicleito@genicleito-Infoway-a7520>
 *
 */
 
#define MTAMFILA 10
#include <stdio.h>
#include <stdbool.h>

typedef struct {
	int chave[MTAMFILA];
	int prim, nelems;
}FilaInt;

void inicializa(FilaInt *f){
	f->nelems = f->prim = 0;
	printf("\n\n");
}

_Bool enfileira(FilaInt *f, int x){
	if(f->nelems == MTAMFILA)
		return false;
	f->chave[(f->prim + f->nelems) % MTAMFILA] = x;
	(f->nelems)++;
	return true;
}

_Bool desenfileira(FilaInt *f, int *x){
	if(f->nelems == 0)
		return false;
	*x = f->chave[f->prim];
	f->prim = (f->prim)++ % MTAMFILA;
	(f->nelems)--;
	return true;
}

int main(){
	FilaInt y;
	int OP=0, x;

	while(OP < 4){
		printf("\t\t-- Lista Encadeada - By Genicleito Goncalves--\n\n");
		printf("Menu:\n1. Inicializar Fila;");
		printf("\n2. Enfileirar na Fila;");
		printf("\n3. Desenfileirar da Fila.");
		printf("\n\nOpcao Desejada: ");
		scanf("%d", &OP);

		if (OP == 1) {
			inicializa(&y);
		}
		else if(OP == 2){
			printf("\nNumero para enfileirar na lista: ");
			scanf("%d", &x);
			if(enfileira(&y, x)){
				printf("\nConseguiu enfileirar!\n");
			}else
				printf("A fila ja esta cheia!");
		}
		else if(OP == 3) {
			if(desenfileira(&y, &x))
				printf("\n%d foi desenfileirado com sucesso!\n", x);
			else
				printf("\nA fila esta vazia!\n", x);
		}
	}
	return 0;
}
