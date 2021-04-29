#include<stdio.h>
#include<math.h>

int main(){
    int T;
    double n;
    scanf("%d",&T);
    while(T--){
        scanf("%lf",&n);
        printf("%lld\n",(long long)((sqrt(1+(4*2*n))-1)/2));
    }

return 0;
}
