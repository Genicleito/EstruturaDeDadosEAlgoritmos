/*
 * PilhaSimplesGenicleito.c
 *
 * Copyright 2014 Genicleito <genicleito@genicleito-Infoway-a7520>
 *
 */ 
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#define N 20

_Bool verificar(char exp[]){
	int i;
	char aux[N];
	for(i=strlen(exp); i != 0; i--){
		switch(exp[i]){
			case ')':{
				if(exp[i-1] != '(')
					return false;
				break;
			}
			case ']':{
				if(exp[i-1] != '[')
					return false;
				break;
			}
			case '}':{
				if(exp[i-1] != '{')
					return false;
				break;
			}
		}
	}
	return true;
	
}

int main(){
	char exp[N];
	scanf("%s", exp);
	if(verificar(&exp))
		printf("\nCorreta!");
	else
		printf("\nErrada!");
	return 0;
}
