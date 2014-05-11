/*
 * FilaDinamicaGenicleito.c
 * 
 * Copyright 2014 Genicleito <genicleito@genicleito-Infoway-a7520>
 * 
 */
#include <stdio.h>
#include <stdbool.h>

typedef struct NoFilaInt{
	int chave;
	struct NoFilaInt *prox;
}NoFilaInt;

typedef struct{
	NoFilaInt *prim, *ult;
}FilaInt;

void inicializa(FilaInt *f){
	f->prim = NULL;
}

_Bool enfileira(FilaInt *f, int x){
	NoFilaInt *p;
	if(!(p = (NoFilaInt *) malloc (sizeof(NoFilaInt))))
		return false;
	p->chave = x;
	p->prox = NULL;
	if(f->prim)
		f->ult->prox = p;
	else
		f->prim = p;
	f->ult = p;
	return true;
}

_Bool desenfileira(FilaInt *f, int *x){
	NoFilaInt *p;
	if(!(p = f->prim))
		return false;
	f->prim = p->prox;
	*x = p->chave;
	free(p);
	return true;
}

int main(){
	FilaInt f;
	inicializa(&f);
	
	int x, OP=1;

	while((OP >= 1) && (OP <= 3)){
		printf("\t\t-- Fila Dinamicamente Encadeada - By Genicleito Goncalves--\n\n");
		printf("Menu:\n1. Inicializar Fila;");
		printf("\n2. Enfileirar;");
		printf("\n3. Desenfileirar.");
		printf("\n\nOpcao Desejada: ");
		scanf("%d", &OP);

			if (OP == 1) {
				inicializa(&f);
			}
			else if(OP == 2){
				printf("\nNumero para inserir na lista: ");
				scanf("%d", &x);
				if(enfileira(&f, x)){
					printf("\nEnfileirado %d com sucesso!\n", x);
				}else
					printf("\nNao foi possivel enfileirar o numero %d.\n", x);
			}
			else if(OP == 3){
				printf("\nNumero para desenfileirar da Fila: ");
				scanf("%d", &x);
				if(desenfileira(&f, &x))
					printf("\nO valor %d foi desenfileirado!\n", x);
				else
					printf("\nA fila estava vazia!\n");
			}
	}
	
	return 0;	
}
