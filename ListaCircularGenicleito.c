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
}NoListaInt;

typedef NoListaInt* ListaInt;

void inicializa(ListaInt *l){
	*l = NULL;
}

_Bool consulta(ListaInt *l, int x){
	NoListaInt *p;			//l é do tipo ListaInt e p é do tipo NoLista int, embora seja a mesma estrutura, o compilador mostra um Warning!
	p = l;					//Quando usar p = *l ou p = l	?
	
	if(*l != NULL){
		do
			p=p->prox;
		while((p->chave != x) && (p != l));
	}
	if(p->chave == x)
		return true;
	else
		return false;
}



_Bool insere(ListaInt *l, int x){
	NoListaInt *p;
	
	if(consulta(*l, x))
		return true;
	if(p = (NoListaInt *) malloc(sizeof(NoListaInt))){
		if(l){
			p->chave = x;
			p->prox = (*l)->prox;
			(*l)->prox = p;
		}else{
			*l = p;
			p->prox = p;
		}
		return true;
	}
	return false;
}

_Bool retira(ListaInt *l, int x){
	
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
		else{
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
