/*
 * FilaDinamicaGenicleito.c
 * 
 * Copyright 2014 Genicleito <genicleito@genicleito-Infoway-a7520>
 * 
 */
#define MTAMLISTA 10
#include <stdio.h>
#include <stdbool.h>

typedef struct{
	int chaves[MTAMLISTA];
	int nelems;
}ListaInt;

void Inicializa(ListaInt *l){
	l->nelems = 0;
	printf("\n\n");
}

_Bool consulta(ListaInt *l, int x){
	int i;
	for(i=0; (i<l->nelems) && (l->chaves[i] != x); i++);
	if(i == l->nelems)
		return false;
	return true;
}

_Bool insere(ListaInt *l, int x){
	if (consulta(l, x))
		return true;
	if(l->nelems == MTAMLISTA)
		return false;
	l->chaves[l->nelems] = x;
	(l->nelems)++;
	return true;
}

_Bool retira(ListaInt *l, int x){
	int i=0;
	for(i=0; (i<l->nelems) && (l->chaves[i] != x);i++);
	if (consulta(l, x) == false)
		return false;
	l->chaves[i] = l->chaves[l->nelems - 1];
	l->nelems = l->nelems - 1;
	return true;
	
}

int main(){
	ListaInt y;
	int OP=0, x;

	while(OP < 5){
		printf("\t\t-- Lista Encadeada - By Genicleito Goncalves--\n\n");
		printf("Menu:\n1. Inicializar Lista;");
		printf("\n2. Consultar na Lista;");
		printf("\n3. Inserir na Lista;");
		printf("\n4. Retirar da Lista.");
		printf("\n\nOpcao Desejada: ");
		scanf("%d", &OP);

			if (OP == 1) {
				Inicializa(&y);
			}
			else if(OP == 2) {
				printf("\nNumero para consultar na lista: ");
				scanf("%d", &x);
				if(consulta(&y, x)){
					printf("%d esta na lista.\n\n", x);
				}else
					printf("%d nao esta na lista.\n\n", x);
			}
			else if(OP == 3){
				printf("\nNumero para inserir na lista: ");
				scanf("%d", &x);
				if(insere(&y, x)){
					printf("\nInsercao realizada com sucesso!\n");
				}else
					printf("A lista ja esta cheia ou o numero ja esta na lista!");
			}
			else if(OP == 4) {
				printf("\nNumero para retirar da lista: ");
				scanf("%d", &x);
				if(retira(&y, x))
					printf("\n%d foi retirado da lista com sucesso!\n", x);
				else
					printf("\n%d nao esta na lista!\n", x);
			}
	}
	return 0;
}
