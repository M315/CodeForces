#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(void){
	int t, T;
	int i, j, n, *v, *a, *b;
	bool possible;

	scanf("%d", &T);

	for(t = 0; t < T; t++){
		scanf("%d", &n);

		v = (int*)malloc(n * sizeof(int));
		for(i = 0; i < n; i++)
			scanf("%d", &v[i]);

		possible = true;

		a = (int*)malloc(n * sizeof(int));
		b = (int*)malloc(n * sizeof(int));

		a[0] = v[0];
		b[0] = 0;

		for(i = 1; i < n; i++){
			if(a[i-1] < v[i] - b[i-1]){
				a[i] = a[i-1];
			}else{
				a[i] = v[i] - b[i-1];
			}

			if(a[i] < 0)
				a[i] = 0;

			b[i] = v[i] - a[i];
		}

		for(i = 1; i < n; i++){
			if(b[i] < b[i-1]){
				possible = false;
				break;
			}
		}

		if(possible){
			printf("YES\n", t + 1);
		}else{
			printf("NO\n", t + 1);
		}

		free(v);
		free(a);
		free(b);
	}

	return 0;
}
