#include <stdio.h>
#include <stdlib.h>

int cmpfun (const void * a, const void * b){
   return ( *(int*)a - *(int*)b );
}

int main(void){
	int t, T, n, *A, i, count, min1, min2;

	scanf("%d", &T);

	for(t = 0; t < T; t++){
		scanf("%d", &n);
		
		A = (int*)malloc(n * sizeof(int));

		for(i = 0; i < n; i++)
			scanf("%d", &A[i]);

		qsort(A, n, sizeof(int), cmpfun);

		count = 0;

		if(A[0] != 0){
			min2 = 0;
			count++;
		}

		if(A[1] != 0){
			min1 = 0;
			count++;
		}

		for(i = 1; i < n-1 && count < 2; i++){
			if(A[i] != A[i+1] && A[i] != A[i-1]){
				if(count < 1){
					min1 = A[i];
					count++;
				
					if(A[i+1] != A[i] + 1){
						min2 = A[i] + 1;
						count++;
					}
				}
			}
		}

		if(count < 2)
			min2 = A[n-1] + 1;

		if(count < 1)
			min1 = A[n-1] + 1;

		printf("%d\n", min1 + min2);
		
		free(A);
	}

	return 0;
}
