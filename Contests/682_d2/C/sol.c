#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(void){
	int t, T;
	int i, j, n, m, **a;
	bool **used;

	scanf("%d", &T);

	for(t = 0; t < T; t++){
		scanf("%d%d", &n, &m);

		a = (int**)malloc(n * sizeof(int*));
		used = (bool**)calloc(n, sizeof(bool*));

		for(i = 0; i < n; i++){
			a[i] = (int*)malloc(m * sizeof(int));
			used[i] = (bool*)calloc(m, sizeof(bool));

			for(j = 0; j < m; j++)
				scanf("%d", &a[i][j]);
		}

		for(j = 1; j < m; j++)
			if(a[0][j] == a[0][j-1]){
				a[0][j]++;
				used[0][j] = true;
			}

		for(i = 1; i < n; i++){
			if(a[i][0] == a[i-1][0]){
				a[i][0]++;
				used[i][0] = true;
			}

			for(j = 1; j < m; j++)
				if(a[i][j] == a[i-1][j] || a[i][j] == a[i][j-1]){
					a[i][j]++;
					used[i][j] = true;
				}
		}

		i = n - 1;
		for(j = m - 2; j >= 0; j--)
			if(a[i][j] == a[i][j+1] && !used[i][j]){
				a[i][j]++;
			}

		for(i = n - 2; i >= 0; i--){
			j = m - 1;
			if(a[i][j] == a[i+1][j] && !used[i][j]){
				a[i][j]++;
			}

			for(j = m - 2; j >= 0; j--)
				if((a[i][j] == a[i+1][j] || a[i][j] == a[i][j+1]) && !used[i][j]){
					a[i][j]++;
				}
		}

		for(i = 0; i < n; i++){
			for(j = 0; j < m; j++)
				printf("%d ", a[i][j]);
			printf("\n");
		}

		for(i = 0; i < n; i++)
			free(a[i]);
		free(a);
	}

	return 0;
}
