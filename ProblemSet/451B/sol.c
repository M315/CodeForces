#include <stdio.h>
#include <stdlib.h>

int cmpfun(const void *a, const void *b){
	return *(int*)a - *(int*)b;
}

int main(void){
	int n, *arr, *sorted_arr, i, x = -1, y = -1;
	
	scanf("%d", &n);
	
	arr = (int*)malloc(n * sizeof(int));
	sorted_arr = (int*)malloc(n * sizeof(int));
	for(i = 0; i < n; i++){
		scanf("%d", &arr[i]);
		sorted_arr[i] = arr[i];
	}

	qsort(sorted_arr, n, sizeof(int), cmpfun);

	for(i = 0; i < n; i++){
		if(sorted_arr[i] != arr[i]){
			x = i;
			break;
		}
	}
	
	for(i = x + 1; i < n - 1; i++){
		if(sorted_arr[i] == arr[i] && arr[i+1] == sorted_arr[i+1]){
			y = i;
			break;
		}
	}
	
	if(x == -1){
		printf("yes\n");
		printf("1 1\n");
		
		free(arr);
		free(sorted_arr);

		return 0;
	}
	
	if(y == -1){
		if(arr[i] == sorted_arr[i]){
			y = n - 1;
		}else{
			y = n;
		}
	}

	for(i = 0; i < y - x; i++){
		if(arr[i+x] != sorted_arr[y-1-i]){
			printf("no\n");

			free(arr);
			free(sorted_arr);

			return 0;
		}
	}

	printf("yes\n");
	printf("%d %d\n", x + 1, y);
	
	
	free(arr);
	free(sorted_arr);

	return 0;
}
