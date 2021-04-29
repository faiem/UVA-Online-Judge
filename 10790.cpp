#include<stdio.h>

int main(){
    int T=1;
    unsigned long long a,b;
    while(scanf("%llu %llu",&a,&b) && a)
        printf("Case %d: %llu\n",T++,(((a-1)*a)/2)*(((b-1)*b)/2));
return 0;
}
