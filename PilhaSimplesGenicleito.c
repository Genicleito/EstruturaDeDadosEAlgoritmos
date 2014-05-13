/*
 * PilhaSimplesGenicleito.c
 *
 * Copyright 2014 Genicleito <genicleito@genicleito-Infoway-a7520>
 *
 */

#include <stdio.h>
#include <stdbool.h>
#define MTAMPILHA 10

typedef struct NoPilhaInt{
	int chave[MTAMPILHA];
	int nelems;
}PilhaInt;

void inicializa(PilhaInt *y){
	y->nelems = 0;
}

_Bool empilha(PilhaInt *y, int x){
	if(y->nelems == MTAMPILHA)
		return false;
	y->chave[y->nelems] = x;
	(y->nelems)++;
	return true;
}

_Bool desempilha(PilhaInt *y, int *x){
	if(y->nelems == 0)
		return false;
	*x = y->chave[y->nelems - 1];
	(y->nelems)--;
}

int main(){
	PilhaInt f;
	inicializa(&f);
	
	int x, OP=1;

	while((OP >= 1) && (OP <= 3)){
		printf("\t\t-- Pilha Simples Com Vetor - By Genicleito Goncalves--\n\n");
		printf("\n1. Empilhar;");
		printf("\n2. Desempilhar.");
		printf("\n\nOpcao Desejada: ");
		scanf("%d", &OP);
			if(OP == 1){
				printf("\nNumero para empilhar: ");
				scanf("%d", &x);
				if(empilha(&f, x)){
					printf("\nEmpilhado %d com sucesso!\n", x);
				}else
					printf("\nNao foi possivel empilhar o numero %d.\n", x);
			}
			else if(OP == 2){
				if(desempilha(&f, &x))
					printf("\nO valor %d foi desempilhado!\n", x);
				else
					printf("\nA Pilha esta vazia!\n");
			}
	}
	return 0;	
}
