#include <stdio.h>
#include <stdlib.h>

int main(void){
	int t, T;
	int n, i;

	scanf("%d", &T);

	for(t = 0; t < T; t++){
		scanf("%d", &n);

		for(i = 0; i < n; i++)
			printf("1 ");
		printf("\n");
	}

	return 0;
}
