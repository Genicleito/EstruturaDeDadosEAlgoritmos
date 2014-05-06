/*
 * ListaDinamicaGenicleito.c
 * 
 * Copyright 2014 Genicleito <genicleito@genicleito-Infoway-a7420>
 * 
 */
#include <stdio.h>
#include <stdbool.h>

typedef struct NoListaInt{
	int chave;
	struct NoListaInt *ant, *prox;
}NoListaInt, *ListaInt;

void inicializa(ListaInt *l){
	*l = NULL;
}

_Bool consulta(ListaInt *l, int x){
	NoListaInt *p;
	for(p = *l; (p != NULL) && (p->chave != x); p = p->prox);
	if (!(p))
		return false;
	return true;
}

_Bool insere(ListaInt *l, int x){
	NoListaInt *p;
	if(consulta(l, x))
		return true;
	if(!(p = (NoListaInt *) malloc (sizeof(NoListaInt))))
		return false;
	p->chave = x;
	p->ant = NULL;
	p->prox = *l;
	if(*l)
		(*l)->ant = p;
	*l = p;
	return true;
}

_Bool retira(ListaInt *l, int x){
	if(!(consulta(l, x)))
		return false;
	NoListaInt *p;
	for(p = *l; (p->chave != x); p=p->prox);
	if((!(p->prox) && (!(p->ant)))){
		free(p);
		*l = NULL;
		return true;
	}
	else if(!(p->ant)){
		*l = p->prox;
		p->prox->ant = p->ant;		//p->ant é NULL.
		free(p);
		return true;
	}
	p->ant->prox = p->prox;
	if(!(p->prox))
		p->prox->ant = p->ant;
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
