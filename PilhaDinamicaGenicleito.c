#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct NoPilhaInt{
	int chave;
	struct NoPilhaInt *prox;
}NoPilhaInt, *Topo;

void inicializa(Topo *y){
	*y = NULL;
}

_Bool empilha(Topo *y, int x){
	NoPilhaInt *p;
	if(p = (NoPilhaInt *) malloc (sizeof(NoPilhaInt))){
		p->chave = x;
		p->prox = *y;
		*y = p;
	}
	return p;
}

_Bool desempilha(Topo *y, int *x){
	NoPilhaInt *p;
	if(!(p = *y))
		return false;
	*x = p->chave;
	*y = p->prox;
	free(p);
	return true;
}

int main(){
	Topo f;
	inicializa(&f);
	
	int x, OP=1;

	while((OP >= 1) && (OP <= 3)){
		printf("\t\t-- Pilha Dinamicamente Encadeada - By Genicleito Goncalves--\n\n");
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
