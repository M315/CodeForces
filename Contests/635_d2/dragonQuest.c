#include <stdio.h>
#include <stdlib.h>

int main(void){
	int t, k;
	int x, n, m;
	
	scanf("%d", &t);
	
	for(k=0; k<t; k++){
		scanf("%d", &x);
		scanf("%d", &n);
		scanf("%d", &m);
		
		while(x > 20 && n > 0){
			x = x/2 + 10;
			n--;
		}
		
		while(x > 0 && m > 0){
			x -= 10;
			m--;
		}
		
		if(x > 0){
			printf("NO\n");
		}else{
			printf("YES\n");
		}
	}
	
	return 0;
}
