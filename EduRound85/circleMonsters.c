#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

unsigned long long dieMonsters(unsigned long long**, int);
int cmpfun(const void*, const void*);

int main(void){
	int T, n;
	unsigned long long **m;
	int k, i;
	
	scanf("%d", &T);
	
	for(k=0; k<T; k++){
		scanf("%d", &n);
		
		m = (unsigned long long**)malloc(n*sizeof(unsigned long long*));
		for(i=0; i<n; i++){
			m[i] = (unsigned long long*)malloc(2*sizeof(unsigned long long));
			
			scanf("%llu", &m[i][0]);
			scanf("%llu", &m[i][1]);
		}
		
		printf("%llu\n", dieMonsters(m, n));
		
		for(i=0; i<n; i++)
			free(m[i]);
		free(m);
	}
	
	return 0;
}

unsigned long long dieMonsters(unsigned long long **m, int n){
	unsigned long long min, bullets;
	unsigned long long **orderM;
	long long int liveRemaning;
	int i, j, k;
	
	orderM = (unsigned long long**)malloc(n*sizeof(unsigned long long*));
	for(i=0; i<n; i++){
		orderM[i] = (unsigned long long*)malloc(3*sizeof(unsigned long long));
		
		orderM[i][0] = m[i][0];
		orderM[i][1] = m[i][1];
		orderM[i][2] = i;
	}
	
	qsort(orderM, n, sizeof(unsigned long long*), cmpfun);
	
	min = 1.e19;
	for(k=0; k<n; k++){
		i = orderM[k][2];
		bullets = 0;
		j = 0;
		liveRemaning = m[i][0];
		while(j != n){
			bullets += liveRemaning;
			if(bullets>=min){
				break;
			}
			do{
				liveRemaning = m[(i+j+1)%n][0] - m[(i+j)%n][1];
				j++;
			}while(liveRemaning <= 0 && j != n);
		}
		
		if(bullets < min)
			min = bullets;
	}
	
	return min;
}

int cmpfun(const void *a, const void *b){
	if((*(unsigned long long**)a)[0] < (*(unsigned long long**)b)[0] && (*(unsigned long long**)a)[1] > (*(unsigned long long**)b)[1]){
		return -1;
	}else{
		return 1;
	}
	return 0;
}
