#include <stdio.h>
#include <stdlib.h>

int main(void){
	int t, k;
	long long int a, b, c, d;
	
	scanf("%d", &t);
	
	for(k=0; k<t; k++){
		scanf("%lld", &a);
		scanf("%lld", &b);
		scanf("%lld", &c);
		scanf("%lld", &d);
		
		/*Using the triangular inequlity, we just need to make sure that:
		 * z + y > x (ez cause: y + z >= y + y >= x + x > x) 
		 * z + x > y (ez cause: z + x >= y + x > y)
		 * x + y > z, if y = c and z = c the previous inequalities still
		 * holds and now x + y = x + z > z #
		*/
		printf("%lld %lld %lld\n", b, c, c);
	}
	
	return 0;
}
