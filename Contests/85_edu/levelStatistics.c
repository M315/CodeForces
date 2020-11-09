#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(void){
	int T, n, p, c, p0, c0;
	int k, i;
	bool possible;
	
	scanf("%d", &T);
	
	for(k=0; k<T; k++){
		scanf("%d", &n);
		
		possible = true;
		p0 = 0;
		c0 = 0;
		
		for(i=0; i<n; i++){
			scanf("%d", &p);
			scanf("%d", &c);
			
			if(possible){
				if(p0 > p)
					possible = false;
				
				if(c0 > c)
					possible = false;
				
				if(c-c0 > p-p0)
					possible = false;
			}
			
			p0 = p;
			c0 = c;
		}
		
		if(possible){
			printf("YES\n");
		}else{
			printf("NO\n");
		}
	}
	
	return 0;
}
