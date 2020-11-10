#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(void){
	int t, T;
	int a, b, m, cost, connection_cost;
	bool exploding;

	scanf("%d", &T);

	for(t = 0; t < T; t++){
		scanf("%d%d\n", &a, &b);

		cost = 0;
		exploding = false;
		connection_cost = 0;
		
		m = getchar() - 48;
		while(m >= 0){
			if(m == 1){
				if(!exploding){
					cost += a;
					exploding = true;
				}else{
					if(connection_cost){
						if(connection_cost < a){
							cost += connection_cost;
						}else{
							cost += a;
						}

						connection_cost = 0;
					}
				}
			}else{
				if(exploding)
					connection_cost += b;
			}

			m = getchar() - 48;
		}

		printf("%d\n", cost);
	}

	return 0;
}
