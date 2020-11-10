#include <stdio.h>
#include <stdlib.h>

int main(void){
	int a, b, aux, k, i;
	
	scanf("%d", &k);
	
	for(i = 0; i < k; i++){
		
		scanf("%d%d", &a, &b);
		
		if(a < b){
			aux = a;
			a = b;
			b = aux;
		}

		if((a - b) % 10 == 0){
			printf("%d\n", (a-b)/10);
		}else{
			printf("%d\n", (a-b)/10 + 1);
		}
	}

	return 0;
}
