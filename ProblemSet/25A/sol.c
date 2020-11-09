#include <stdio.h>
#include <stdlib.h>

int main(void){
	int n, *nums, num, changes = 0, last_change, i;
	
	scanf("%d", &n);
	
	nums = (int*)malloc(n * sizeof(int));
	for(i = 0; i < n; i++)
		scanf("%d", &nums[i]);

	for(i = 1; i < n && changes < 2; i++){
		if(nums[i] % 2 != nums[i-1] % 2){
			changes++;
			last_change = i;
		}
	}
	
	if(changes == 1 && last_change == n - 1)
		last_change = n;
	
	printf("%d\n", last_change);

	free(nums);

	return 0;
}
