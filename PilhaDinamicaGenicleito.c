/*
 * PilhaSimplesGenicleito.c
 *
 * Copyright 2014 Genicleito <genicleito@genicleito-Infoway-a7520>
 *
 */
 
 //OBS: AINDA EM CRIAÇÃO
 
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#define N 20

char Posfixa[N];

_Bool priori(char aux, char t){
	if(((aux == '*') || (aux == '/')) && ((t == '+') || (t == '-')))
		return true;
	else
		return false;
}

void ConverteInfixaParaPosfixa(char *p[]){
	char t;
	char aux[N];
	int i, cont, j=0;
	for(i=0; p[i] != '\0'; i++, cont++);
	i=0;
	while(i < cont){
		t = p[i];
		if((t != '(') && (t != '[') && (t != '{') && (t != ')') && (t != ']') && (t != '}'))
			Posfixa[i] = t;
		else if((t == '+') || (t == '-') || (t == '/') || (t == '*')){
			if( (i > 1) && ((aux[i-1] == '+') || (aux[i-1] == '-') || (aux[i-1] == '/') || (aux[i-1] == '*'))){
				if(!(priori(aux[i], t))){
					aux[i] = t;
					j++;
				}
				else{
					Posfixa[i] = aux[i];
					aux[i] = t;
					j++;
				}
			}else
				aux[i] = t;
		}else if(t == '('){
			aux[i] = t;
			j++;	
		}
		if (i+2 == cont){
			int k=i+1;
			for(; j != 0; j--)
				if(aux[j-1] != '(')
					Posfixa[k] = aux[j-1];
		}		
	i++;
	}
	Posfixa[i] = '\0';
}

int main(){
	int i=0;
	printf("Digite uma expressao Infixa:\n");
	scanf("%s", Posfixa);
	ConverteInfixaParaPosfixa(&Posfixa);
	printf("%s", Posfixa);
	
	return 0;
}
