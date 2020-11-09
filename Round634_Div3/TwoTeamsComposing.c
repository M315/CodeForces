#include <stdio.h>
#include <stdlib.h>

#define MIN(a,b) (((a)<(b)) ? (a): (b))
#define MAX(a,b) (((a)>(b)) ? (a): (b))

int cmpfun(const void *a, const void *b){
	return (*(int*)a - *(int*)b);
}

int main(void){
	int t, n, k, i;
	int *s, count, max, num_ds;
	
	scanf("%d", &t);
	
	for(k=0; k<t; k++){
		scanf("%d", &n);
		
		if(n>0){
			s = (int*)malloc(n*sizeof(int));
			
			for(i=0; i<n; i++)
				scanf("%d", &s[i]);
			
			qsort(s, n, sizeof(int), cmpfun);
			
			max = 1;
			num_ds = 0;
			for(i=0; i<n; i++){
				num_ds++;
				
				count = 1;
				while(i<n-1 && s[i+1] == s[i]){
					i++;
					count++;
				}
				
				if(count > max)
					max = count;
			}
			
			free(s);
			
			printf("%d\n", MAX(MIN(num_ds-1, max), MIN(num_ds, max-1)));
		}else{
			printf("%d\n", 0);
		}
	}
	
	return 0;
}
