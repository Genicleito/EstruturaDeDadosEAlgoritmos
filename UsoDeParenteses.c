/*
 * UsoDeParenteses.c
 *
 * Copyright 2014 Genicleito <genicleito@genicleito-Infoway-a7520>
 *
 */
 #include <stdio.h>
 #include <stdbool.h>
 #define MAX 20
 
 typedef struct{
 	char sequencia[MAX];
 	int nelems;
 }Sequencia;

void empilha(Sequencia *y, int x){
	y->sequencia[y->nelems] = x;
	(y->nelems)++;
}

_Bool desempilha(Sequencia *y, int *x){	
	if (y->nelems == 0)
		return false;
	*x = y->sequencia[y->nelems -1];
	(y->nelems)--;
	return true;
}

_Bool validar(Sequencia *y){
	Sequencia ax;
	int topo=0, aux=0;
	ax.nelems = 0;
	
	do{
 		if((((y->sequencia[y->nelems -1]) != '(') && ((y->sequencia[y->nelems -1]) != '[') && ((y->sequencia[y->nelems -1]) != '{')) && (desempilha(y, &topo)))
	 		empilha(&ax, topo);
	 	else
	 		return false;
 	}while(((y->sequencia[y->nelems -1]) == '(') && ((y->sequencia[y->nelems -1]) == '[') && ((y->sequencia[y->nelems -1]) == '{'));
}
 
 int main(){
 	int i=0;
 	Sequencia y;
 	y.nelems = 0;
 	
 	printf("Digite uma sequencia de parenteses, chaves ou colchetes[Max. 20]:\n");
 	scanf("%s", &y.sequencia);
 	
 	while(y.sequencia[i] != '\0')
 		i++;
 	y.nelems = i--;
 	
 	validar(&y);
 	
 	return 0;
 }
