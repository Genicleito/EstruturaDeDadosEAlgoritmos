/*
 * ConverteInfixaParaPosfixa.c
 *
 * Copyright 2014 Genicleito <genicleito@genicleito-Infoway-a7520>
 *
 */
 
 //OBS: AINDA EM CRIAÇÃO
 
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#define N 20

typedef struct NoPilhaInt{
	char chave[N];
	int nelems;
}PilhaInt;

void empilha(PilhaInt *y, char x){
	y->chave[y->nelems] = x;
	(y->nelems)++;
}

void desempilha(PilhaInt *y, char *x){
	*x = y->chave[y->nelems - 1];
	(y->nelems)--;
}

_Bool priori(char aux, char t){
	if(((aux == '*') || (aux == '/')) && ((t == '+') || (t == '-')))
		return true;
	else
		return false;
}

void ConverteInfixaParaPosfixa(PilhaInt *p, char *Posfixa[]){
	char t;
	char aux[N];
	int i=0, cont=0;
	int j = p->nelems;
	while(i < p->nelems){
		t = p->chave[i];
		if((t != '(') && (t != '[') && (t != '{') && (t != ')') && (t != ']') && (t != '}'))
			Posfixa[i] = t;
		else if((t == '+') || (t == '-') || (t == '/') || (t == '*')){
			if(((aux[cont] == '+') || (aux[cont] == '-') || (aux[cont] == '/') || (aux[cont] == '*'))){
				if(!(priori(aux[cont], t))){
					desempilha(p, aux[cont]);
					cont++;
				}else{
					empilha(Posfixa[i], aux[cont]);
					cont++;
					desempilha(p, aux[cont]);
				}
			}else{
				desempilha(p, aux[cont]);
				cont++;
			}
		}else if(t == '('){
			desempilha(p, aux[cont]);
			cont++;
		}else{
			for(; cont != 0; cont--){
				if(aux[cont] != '(')
					empilha(Posfixa[i], aux[cont]);
			}
		}		
	i++;
	}
}

int main(){
	PilhaInt y;
	char Posfixa[N];
	int i=0;
	printf("Digite uma expressao Infixa:\n");
	scanf("%s", y.chave);
	printf("\n%s", Posfixa);
	while(y.chave[i] != '\0'){
		y.nelems++;
		i++;
	}
	ConverteInfixaParaPosfixa(&y, Posfixa);
	
	return 0;
}
