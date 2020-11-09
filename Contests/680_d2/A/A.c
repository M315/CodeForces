#include <stdio.h>
#include <stdlib.h>

int main(void){
	int t, T, n, x;
	int i, *a, *b;
	
	scanf("%d", &T);

	for(t = 0; t < T; t++){
		scanf("%d%d", &n, &x);
		
		a = (int*)malloc(n * sizeof(int));
		b = (int*)malloc(n * sizeof(int));
		
		for(i = 0; i < n; i++)
			scanf("%d", &a[i]); 
		for(i = 0; i < n; i++)
			scanf("%d", &b[i]); 
		
		for(i = 0; i < n; i++)
			if(a[i] + b[n-1-i] > x){
				printf("No\n");
				break;
			}
		
		if(i == n)
			printf("Yes\n");
		
		free(a);
		free(b);
	}

	return 0;
}
