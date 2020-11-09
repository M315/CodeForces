#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int maxPeople(int*, int, int);
int cmpfun(const void*, const void*);

int main(void){
	int T, n, x, *a;
	int k, j;
	
	scanf("%d", &T);
	
	for(k=0; k<T; k++){
		scanf("%d", &n);
		scanf("%d", &x);
		
		a = (int*)malloc(n*sizeof(int));
		for(j=0; j<n; j++)
			scanf("%d", &a[j]);
		
		printf("%d\n", maxPeople(a, n, x));
		
		free(a);
	}
	
	return 0;
}

int maxPeople(int *a, int n, int x){
	int i;
	unsigned long long sum = 0;
	
	qsort(a, n, sizeof(int), cmpfun);
	
	for(i=0; i<n; i++){
		sum += a[i];
		if((double)sum/(double)(i+1) < (double)x)
			return i;
	}
	
	return i;
}

int cmpfun(const void *a, const void *b){
	return (*(int*)b - *(int*)a);
}
