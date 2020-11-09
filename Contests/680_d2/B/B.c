#include <stdio.h>
#include <stdlib.h>

int main(void){
	int t, T;
	int a, b, c, d;

	scanf("%d", &T);

	for(t = 0; t < T; t++){
		scanf("%d%d%d%d", &a, &b, &c, &d);
		
		if(a + b >= c + d)
			printf("%d\n", a + b);
		else
			printf("%d\n", c + d);
	}

	return 0;
}
