/*
 * ListasCircularesGenicleito.c
 *
 * Copyright 2014 Genicleito <genicleito@genicleito-Infoway-a7520>
 *
 */

#include <stdio.h>
#include <stdbool.h>

typedef struct NoListaInt{
	int chave;
	struct NoListaInt *prox;
}NoListaInt, *ListaInt;

void inicializa(ListaInt *l){
	*l = NULL;
}

_Bool consulta(ListaInt *l, int x){
	if (!(*l))
		return false;
	ListaInt p;

	for(p = *l; (p->chave != x) && (p->prox != *l); p=p->prox);
		if(p->chave == x)
			return true;
	return false;
}

_Bool insere(ListaInt *l, int x){
	ListaInt p;
	if (consulta(l,x))
		return true;
	if (!(p = (ListaInt *) malloc (sizeof(ListaInt))))
		return false;
	p->chave = x;
	if (!(*l)){
		*l = p;
		p->prox = p;
	}
	else{
		p->prox = (*l)->prox;
		(*l)->prox = p;
	}
	return true;
}

_Bool retira(ListaInt *l, int x){		//ERRO: Apos remover um numero, o programa afirma que os outros foram removidos.
	ListaInt p, a;
	
	if (!(consulta(l,x)))
		return false;
	if(*l == (*l)->prox){
		free(*l);
		*l = NULL;
		return true;
	}
	for(p = *l; p->chave != x; a = p, p=p->prox);
	a->prox = p->prox;
	free(p);
	return true;
}

int main(){
	ListaInt y;
	int OP = 1, x;

	while((OP < 5) && (OP > 0)){
		printf("\t\t-- Lista Circular - By Genicleito Goncalves--\n\n");
		printf("Menu:\n1. Inicializar Lista;");
		printf("\n2. Consultar na Lista;");
		printf("\n3. Inserir na Lista;");
		printf("\n4. Retirar da Lista.");
		printf("\n\nOpcao Desejada: ");
		scanf("%d", &OP);

		if(OP == 1)
			inicializa(&y);
		else if(OP == 2){
			printf("\nNumero para consultar da Lista: ");
			scanf("%d", &x);
			if(consulta(&y, x))
				printf("\nO numero %d esta na Lista!\n\n", x);
			else
				printf("\nO numero %d nao esta na Lista!\n\n", x);
		}
		else if(OP == 3){
			printf("\nNumero para inserir da Lista: ");
			scanf("%d", &x);
			if (insere(&y, x))
				printf("\nO numero %d foi inserido com sucesso!\n\n", x);
			else
				printf("\nO numero %d nao foi inserido, pode nao haver memoria suficiente!\n\n");
		}
		else if (OP == 4){
			printf("\nNumero para remover da Lista: ");
			scanf("%d", &x);
			if(retira(&y, x))
				printf("\nO numero %d foi removido com sucesso!\n\n", x);
			else
				printf("\nO numero %d nao foi removido! Pode nao estar na lista ou ela pode estar vazia!\n\n");
		}
	}

	return 0;
}
