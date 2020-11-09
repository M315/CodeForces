#include <stdio.h>

int main(void){
	int t, n;
	int k, i;
	
	scanf("%d", &t);
	
	for(k=0; k<t; k++){
		scanf("%d", &n);
		if(n%2 == 0){
			printf("%d\n", n/2-1);
		}else{
			printf("%d\n", n/2);
		}
	}
	
	return 0;
}
