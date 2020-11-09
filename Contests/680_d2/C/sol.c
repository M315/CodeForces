#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int* garbellErastotenes(int N){
        int *I, *p;
        int i, j, n;

        I = (int*)calloc(N+1,sizeof(int));
                if(I == NULL){printf("Err: No Mem\n"); return NULL;}

        for(i=2; i<=N; i++)
                I[i] = i;

        i = 0;

        while(I[i]*I[i]<=N){
                if(I[i]!=0){
                        for(j=2; j<N; j++){
                                if(j*I[i]>N){
                                        break;
                                }else{
                                        I[j*I[i]] = 0;
                                }
                        }
                }
                i++;
        }

        p = (int*)malloc(sizeof(int));
                if(p == NULL){printf("Err: No Mem\n"); return NULL;}

        n = 1;
        p[0] = n-1;

        for(i=0; i<=N; i++){
                if(I[i] != 0){
                        n++;
                        p = (int*)realloc(p, n*sizeof(int));
                                if(p == NULL){printf("Err: No Mem\n"); return NULL;}

                        p[n-1] = I[i];
                        /*save the number of primes that we get in the initial position*/
                        p[0] = n-1;
                }
        }

        free(I);
	
        return p;
}

int main(void){
	int t, T;
	long long int p, x;
	long long int Q, q;
	long long int *prime_q, n, i;
	int *primes = garbellErastotenes(100000);
	
	scanf("%d", &T);
	
	for(t = 0; t < T; t++){
		scanf("%lld%lld", &p, &Q);
		
		n = 0;
		prime_q = (long long int*)malloc(64 * sizeof(long long int));
		
		i = 1;
		q = Q;
		while(i < primes[0] && q != 1){
			if(q % primes[i] == 0){
				prime_q[n] = primes[i];
				n++;
				q /= primes[i];
			}else{
				i++;
			}
		}
		
		if(n == 0){
			prime_q[0] = Q;
			n++;
		}
		
		x = p;
		i = 0;
		while(x % Q == 0 && i < n){
			x = p / prime_q[i];
			i++;
		}
		x = x / prime_q[0];
		
		if(x % Q == 0)
			printf("1\n");
		else
			printf("%lld\n", x);
		
		printf("%lld\n\n", n);
		for(i = 0; i < n; i++)
			printf("%lld\n", prime_q[i]);

		free(prime_q);
	}

	free(primes);

	return 0;
}
