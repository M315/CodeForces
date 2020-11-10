#include <stdio.h>
#include <stdlib.h>

int main(void){
	int t, n, a, b;
	int k, i;
	char *s;
	
	scanf("%d", &t);
	
	for(k=0; k<t; k++){
		scanf("%d", &n);
		scanf("%d", &a);
		scanf("%d", &b);
		
		s = (char*)malloc(n*sizeof(char));
		
		i = 0;
		while(i<b){
			s[i] = (char)(i+97);
			i++;
		}
		
		while(i<n){
			s[i] = s[i-b];
			i++;
		}
		
		printf("%s\n", s);
		
		free(s);
	}
	
	return 0;
}
