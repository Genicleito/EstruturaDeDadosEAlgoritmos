/*
 * UsoDeParenteses.c
 *
 * Copyright 2014 Genicleito <genicleito@genicleito-Infoway-a7520>
 *
 */
 #include <stdio.h>
 #include <stdbool.h>
 #include <string.h>
 #define MAX 20

int validar( char s[]){
	char *p, aux[MAX]; 
	int t; 
	int n, i;
  
	n = strlen(s);
	p = malloc( n * sizeof (char));
	t = 0;
	for (i = 0; s[i] != '\0'; ++i){
		switch (s[i]) {
			case ')': if (t != 0 && p[t-1] == '(') 
                      --t;
                   else return 0;
                   break;
			case ']': if (t != 0 && p[t-1] == '[') 
                      --t;
                   else return 0;
                   break;
			case '}': if (t != 0 && p[t-1] == '{') 
                      --t;
                   else return 0;
                   break;
			default:  p[t++] = s[i];
      }
   }
   return 1;
}

int main(){
	char p[MAX];
	
	printf("Digite uma sequencia de parenteses, chaves ou colchetes[Max. 20]:\n");
 	scanf("%s", p);
 	
 	
 	if((validar(&p)) != 0){
 		printf("\nBem formada!");
 	}else{
 		printf("\nMal formada!");
 	}
	
	return 0;
}
