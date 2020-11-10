#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int cmpfun(const void *a, const void *b){
	int *A = *(int**)a;
	int *B = *(int**)b;

	if(A[0] < B[0])
		return -1;

	if(A[0] > B[0])
		return 1;

	return A[1] - B[1];
}

int main(void){
	int t, T;
	int i, n, **list;
	long long sum;

	scanf("%d", &T);

	for(t = 0; t < T; t++){
		scanf("%d", &n);

		list = (int**)malloc(n * sizeof(int*));

		for(i = 0; i < n; i++){
			list[i] = (int*)malloc(2 * sizeof(int));
			scanf("%d", &list[i][0]);
		}

		for(i = 0; i < n; i++)
			scanf("%d", &list[i][1]);

		qsort(list, n, sizeof(int**), cmpfun);

		sum = 0;
		for(i = n - 1; i >= 0; i--){
			if(sum + list[i][1] < list[i][0]){
				sum += list[i][1];
			}else{
				break;
			}
		}

		if(i < 0){
			printf("%lld\n", sum);
		}else{
			if(sum < list[i][0]){
				printf("%d\n", list[i][0]);
			}else{
				printf("%lld\n", sum);
			}
		}

		for(i = 0; i < n; i++)
			free(list[i]);
		free(list);
	}

	return 0;
}
