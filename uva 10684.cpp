#include<stdio.h>
#define MAX 10001

long long seq[MAX],interval_sum[MAX];

long long max(long long a,long long b){
    if(a>b)
        return a;
return b;
}

long long solve(int N){
    int I;
    long long res=0;
    for(I=0;I<N;I++)
        scanf("%lld",&seq[I]);
    interval_sum[0]=seq[0];
    res=max(res,interval_sum[0]);
    for(I=1;I<N;I++){
        if(interval_sum[I-1]<0){
            interval_sum[I]=seq[I];
        continue;
        }
    interval_sum[I]=(interval_sum[I-1]+seq[I]);
    res=max(res,interval_sum[I]);
    }
return res;
}

int main(){

    int N;
    long long res;
    while(scanf("%d",&N) && N){
        res=solve(N);
        if(res==0)
            printf("Losing streak.\n");
        else
            printf("The maximum winning streak is %lld.\n",res);
    }

return 0;
}

