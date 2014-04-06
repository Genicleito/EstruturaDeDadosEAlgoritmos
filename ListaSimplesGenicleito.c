//Desenvolvido por Genicleito Gonçalves
#define MTAMLISTA 10
#include <stdio.h>
#include <stdbool.h>

typedef struct{
	int chaves[MTAMLISTA];
	int nelems;
}ListaInt;

void Inicializa(ListaInt *l){
	l->nelems = 0;
}

_Bool consulta(ListaInt l, int x){
	if(l.nelems == 0){
		printf("Sem elementos na lista!\n");
		return false;
	}
	else{
		int i=0;
		for(i=0; i<MTAMLISTA; i++){
			if(x == l.chaves[i])
				return true;
		}
		return false;
	}
	
}

_Bool insere(ListaInt *l, int x){
	int i=0;
	for(i=0; (i<l->nelems) && (l->chaves[i] != x);i++);
	if((i == l->nelems) && (l->nelems == MTAMLISTA))
		return false;
	else{
		l->chaves[i] = x;	
		l->nelems = l->nelems + 1;
		printf("\n%d\n%d\n%d", l->chaves[0], l->chaves[1], l->chaves[2]);
	}
}

_Bool retira(ListaInt *l, int x){
	
	return true;
}

int main(){
	ListaInt y;
	int OP=0;	
	
	while(OP < 4){
		printf("\t\t-- Lista Encadeada - By Genicleito Goncalves--\n\n");
		printf("Menu:\n1. Inicializar Lista;");
		printf("\n2. Consultar na Lista;");
		printf("\n3. Inserir na Lista;");
		printf("\n4. Retirar da Lista.");
		printf("\n\nOpcao Desejada:");
		scanf("%d", &OP);

			if (OP == 1) {
				Inicializa(&y); 
				//break;
			}
			
			else if(OP == 2) {
				int num;
				printf("\nNumero para consultar na lista: ");
				scanf("%d", &num);
				if(consulta(y, num)){
					printf("%d esta na lista.", num);
				}else
					printf("%d nao esta na lista.", num);;
				//break;
			}
		
			
			else if(OP == 3){
				int x;
				printf("\nNumero para inserir na lista: ");
				scanf("%d", &x);
				insere(&y, x);
				//break;
			}
			else if(OP == 4) {
				int x;
				printf("\nNumero para retirar da lista: ");
				scanf("%d", &x);
				retira(&y, x);
				//break;
			}
	}
	
	
	return 0;
}
