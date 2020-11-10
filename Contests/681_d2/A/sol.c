#include <stdio.h>
#include <stdlib.h>

int main(void){
	int t, T;
	int n, *nums, len, i, j;

	scanf("%d", &T);

	for(t = 0; t < T; t++){
		scanf("%d", &n);

		nums = (int*)malloc(n * sizeof(int));
		len = 0;

		for(i = 4*n - 2; i >= 2; i -= 2){
			for(j = 0; j < len; j++)
				if(nums[j] % i == 0)
					break;

			if(j == len){
				nums[len] = i;
				len++;
			}

			if(len == n)
				break;
		}

		for(j = 0; j < len; j++)
			printf("%d ", nums[j]);
		printf("\n");

		free(nums);
	}

	return 0;
}
