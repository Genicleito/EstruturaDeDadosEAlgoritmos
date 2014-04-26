/*
 * ListaDinamicaGenicleito.c
 * 
 * Copyright 2014 Genicleito <genicleito@genicleito-Infoway-a7420>
 * 
 */
#include <stdio.h>
#include <stdbool.h>

typedef struct ElemListaInt{
	int chave;
	struct ElemListaInt *prox;
}NoLista;

typedef NoLista* ListaInt;


void inicializa(ListaInt *l){
	*l = NULL;
}

_Bool consulta(ListaInt *l, int x){
	NoLista *p;
	for(p = *l; (p != NULL) && (p->chave != x); p = p->prox);
	if (p == NULL)
		return false;
	return true;
}

_Bool insere(ListaInt *l, int x){
	NoLista *p;
	if (consulta(l, x))
		return true;
	if (p = (NoLista *)malloc(sizeof(NoLista))){
		p->chave = x;
		p->prox = *l;
		*l = p;
	}
	return p;
}

_Bool retira(ListaInt *l, int x){
	NoLista *p, *a = NULL;	
	if((!(l)) || (!(consulta(l, x))))
		return false;
	p = *l;	
	while(p->chave != x){
		a = p;
		p = p->prox;
	}
	if(!(a)){
		*l = p->prox;
		free(p);
		return true;
	}
	a->prox = p->prox;
	free(p);
	return true;
}

int main(int argc, char **argv){
	ListaInt y;
	int OP = 0;
	while(OP < 5){
		printf("\t\t-- Lista Encadeada - By Genicleito Goncalves--\n\n");
		printf("Menu:\n1. Inicializar Lista;");
		printf("\n2. Consultar na Lista;");
		printf("\n3. Inserir na Lista;");
		printf("\n4. Retirar da Lista.");
		printf("\n\nOpcao Desejada: ");
		scanf("%d", &OP);

			if (OP == 1) {
				inicializa(&y);
			}

			else if(OP == 2) {
				int num;
				printf("\nNumero para consultar na lista: ");
				scanf("%d", &num);
				if(consulta(&y, num)){
					printf("%d esta na lista.\n\n", num);
				}else
					printf("%d nao esta na lista.\n\n", num);
			}
			else if(OP == 3){
				int x;
				printf("\nNumero para inserir na lista: ");
				scanf("%d", &x);
				if(insere(&y, x)){
					printf("\nInsercao realizada com sucesso!\n");
				}else
					printf("A lista ja esta cheia ou o numero ja esta na lista!\n");
			}
			else if(OP == 4) {
				int x;
				printf("\nNumero para retirar da lista: ");
				scanf("%d", &x);
				if(retira(&y, x))
					printf("\nNumero retirado da lista com sucesso!\n");
				else
					printf("\nO numero nao esta na lista!\n");
			}
	}

	return 0;
}
