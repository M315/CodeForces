#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(void){
    int T, t;
    long long int a, b, x, y, n, min1, min2;
    
    scanf("%d", &T);
    
    for(t = 0; t < T; t++){
        scanf("%lld%lld%lld%lld%lld", &a, &b, &x, &y, &n);
        
        if(a - n < x){
            if(b - (n - (a -x)) < y){
                min1 = x*y;
            }else{
                min1 = x*(b - (n- (a -x)));
            }
            
        }else{
            min1 = (a - n)*b;
        }
        
        if(b - n < y){
            if(a - (n - (b -y)) < x){
                min2 = x*y;
            }else{
                min2 = y*(a - (n- (b -y)));
            }
            
        }else{
            min2 = a*(b - n);
        }
        
        if(min1 < min2){
            printf("%lld\n", min1);
        }else{
            printf("%lld\n", min2);
        }
    }
    
    return 0;
}
