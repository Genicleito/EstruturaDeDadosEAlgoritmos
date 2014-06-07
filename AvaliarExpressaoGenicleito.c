/*
 * AvaliarExpressao.c
 *
 * Copyright 2014 Genicleito <genicleito@genicleito-Infoway-a7520>
 *
 */ 
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#define N 20

_Bool verificar(char exp[]){
	int i, j=0;
	char aux[N], auxDesem, topo;		//Atribuir n (NULL) a auxDesem para utiliza-lo no switch.

	for(i=0, aux[0] = "N"; aux[0] != '\0'; i++){
		if((exp[i] == ')') || (exp[i] == ']') || (exp[i] == '}')){
			auxDesem = exp[i];		//Desempilha
			
			if(auxDesem == ')'){
				if(topo == '('){		//Compara com o Topo
					j--;
					auxDesem = exp[i+1];
					topo = aux[j-1];
					aux[j] = '\0';
				}else
					return false;
			}
			if(auxDesem == ']'){
				if(topo == '['){		//Compara com o Topo
					j--;
					auxDesem = exp[i+1];
					aux[j] = '\0';
					topo = aux[j-1];
				}else
					return false;
			}
			if(auxDesem == '}'){
				if(topo == '{'){		//Compara com o Topo
					if(j > 1)
					j--;
					auxDesem = exp[i+1];
					aux[j] = '\0';
					topo = aux[j-1];
				}else
					return false;
			}
		}else if((exp[i] == '(') || (exp[i] == '[') || (exp[i] == '{')){
			aux[i] = exp[i];		//Empilha
			j++;					//Contador
			topo = aux[i];			//Guarda o Topo
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
