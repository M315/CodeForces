#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void){
	int n, i, j, *a, sum = 0;
	int mod = 998244353;
	
	scanf("%d", &n);
	
	a = (int*)malloc(2 * n * sizeof(int));
	for(i = 0; i < 2 * n; i++)
		scanf("%d", &a[i]);
	
	for(i = 0; i < 2 * n; i++){
		for(j = i + 1; j < 2 * n; j++){
			sum += fabs(a[i] - a[j]);
			sum %= mod;
			sum += fabs(a[j] - a[i]);
			sum = ((sum % mod) + mod) % mod;
		}
	}
	
	printf("%d\n", sum);
	
	return 0;
}
