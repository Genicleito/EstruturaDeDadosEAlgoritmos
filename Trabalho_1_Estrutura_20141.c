/*
*
*	Trabalho 1 - 2014.1 - MATA40 - Algoritmos e Estruturas de Dados I
*	Genicleito Goncalves
*
* 	Todas as funcoes nao retornam nada a main. Tudo eh feito e mostrado (se necessario) na propria funcao.
* 	Caso alguma entrada incoerente, como codigo de remocao que ainda nao foi cadastrado, o programa retorna para a main.
* 	No caso da funcao de insercao, caso o codigo digitado seja igual a um ja cadastrado, a funcao pula para o proximo...
* 	...cadastro a ser realizado, se houver.
* 
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define N 11

typedef struct Registro{
	int codigo;
	char dp[4];
	float salario;
	struct Registro *apont;
	char nome[20];
}Registro, *ListaFun;

typedef struct AuxOrdenar{
	char nome[20];
}Ordenar;

void inicializa(ListaFun *l){
	int i;
	for(i = 0; i< N; i++)
		l[i] = NULL;		//Inicializar todos os elementos da lista!
}

void insercao(ListaFun *l){
	int num, i;
	Registro *p, *a, *ax = NULL;
	scanf("%d", &num);
	
	for(i = 0; i < num; i++){
		p = (Registro *) malloc (sizeof(Registro));
		scanf("\n\r%[^\n]", p->nome);
		scanf("%d", &p->codigo);	
		for(a = l[p->codigo % N]; ((a) && (a->codigo != p->codigo)) && (a->codigo < p->codigo); ax = a, a = a->apont);
		if((!(a)) || (a->codigo > p->codigo)){		//Se o codigo for diferente.
			scanf("%s", p->dp);
			scanf("%f", &p->salario);
			if(ax){				
				p->apont = ax->apont;
				ax->apont = p;
			}else{
				p->apont = l[p->codigo % N];
				l[p->codigo % N] = p;
			}
		}
	}	
}

void remocao(ListaFun *l){
	Registro *p, *a = NULL;
	int num;
	scanf("%d", &num);
	if(l[num % N]){
		for(p = l[num % N]; (p) && (p->codigo != num); a = p, p = p->apont);
		if(p){			//Se achar o elemento com o codigo correspondente na lista
			if((p == l[num % N])){			//Se for o primeiro elemento
				l[num % N] = p->apont;
				free(p);
			}
			else{
				a->apont = p->apont;
				free(p);
			}
		}
	}
}

void consultaFun(ListaFun *l){
	int num;
	scanf("%d", &num);
	Registro *p;
	for(p = l[num % N]; (p) && (p->codigo != num); p=p->apont);
	if(p){
		printf("%s\n", p->nome);
		printf("%d\n", p->codigo);
		if(strstr(p->dp, "adm"))
			printf("administrativo\n");
		else if(strstr(p->dp, "ped"))
			printf("pesquisa-e-desenvolvimento\n");
		else if(strstr(p->dp, "prod"))
			printf("producao\n");
		printf("%.2f\n", p->salario);
	}
}

void ListarFun(ListaFun *l){
	int num;
	scanf("%d", &num);
	if(l[num]){
		Registro *p = l[num];
		while(p){
			printf("%d\n", p->codigo);
			p = p->apont;
		}
	}
}

void ordenarCrescente(Ordenar *nomes, int qtd){
	int i,j;
	
	char* temp = (char*) malloc(50*sizeof(char));

	for(i = 1; i < qtd; i++)
		for (j = 0; j < qtd -1 ; j++)
			if(strcmp(nomes[j].nome,nomes[j+1].nome) >= 0){
				strcpy(temp,nomes[j].nome);
				strcpy(nomes[j].nome,nomes[j+1].nome);
				strcpy(nomes[j+1].nome,temp);
			}
	
	free(temp);
    
	for(i = 0; i < qtd; ++i)
		printf("%s\n",nomes[i].nome);
}

void ordenarDecrescente(Ordenar *nomes, int qtd){
	int i,j;
   
	char* temp = (char*) malloc(50*sizeof(char)); 
	
	for(i = 1; i < qtd; i++) 
		for (j = 0; j < qtd -1 ; j++)
			if(strcmp(nomes[j].nome,nomes[j+1].nome) <= 0){   
				strcpy(temp,nomes[j].nome);
				strcpy(nomes[j].nome,nomes[j+1].nome);
				strcpy(nomes[j+1].nome,temp);                               
			}
      
	free(temp);   
    
	for(i = 0; i < qtd; ++i)
		printf("%s\n",nomes[i].nome);
}

void ordenar(ListaFun *l){
	char opcao;	
	int i=0, j, cont;
	Registro *a;
	
	scanf(" %c", &opcao);
	
	for(j = 0; (l[j] == NULL) && (j< N); j++);
	if(j == N)			//Se nao tiver elementos nas listas de cada indice do vetor
		return;

		for(j = 0, a = l[j]; (!(a)); j++, a = l[j]);
		i = j;
		cont = 0;
		a = l[i];
		while(i < N){
			while(a){
				cont++;
				a = a->apont;
			}
			i++;
			a = l[i];
		}
	Ordenar pM[cont];
	
	for(j = 0, a = l[j]; (!(a)); j++, a = l[j]);
		i = j;
	a = l[i];
	j = 0;
	while((i < N)){
		while(a){
			strcpy(pM[j].nome, a->nome);
			a = a->apont;
			j++;
		}
		i++;
		a = l[i];
	}
	if(opcao == 'c')
		ordenarCrescente(pM, cont);
	else if(opcao == 'd')
		ordenarDecrescente(pM, cont);
}

int main(){
	ListaFun Lista[N];
	char op;
	
	inicializa(Lista);		//Colocar os apontadores de cada elemento da lista simples como NULL
	
	scanf(" %c", &op);
	while(op != 'e'){
		switch(op){
			
			case 'i':{
				insercao(Lista);
				break;
			}
			
			case 'r':{
				remocao(Lista);
				break;
			}
			
			case 'c':{
				consultaFun(Lista);
				break;
			}
			
			case 'l':{
				ListarFun(Lista);
				break;
			}
			
			case 'o':{
				ordenar(Lista);
				break;
			}
		}
		scanf("%c", &op);
	}
	return 0;
}
