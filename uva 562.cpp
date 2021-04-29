#include<stdio.h>
#define MAX 111

int dp[111][26000],coin[MAX],max_value;

int max(int x,int y){
    if(x>y)
        return x;
return y;
}

int knapsack(int I,int W,int capacity){

    int profit1,profit2;

    if(dp[I][W]!=-1)
        return dp[I][W];
    if(W+coin[I]<=capacity)
        profit1=coin[I]+knapsack(I+1,W+coin[I],capacity);
    else
        profit1=0;
    profit2=knapsack(I+1,W,capacity);
    //printf("%d %d\n",profit1,profit2);
    dp[I][W]=max(profit1,profit2);
return dp[I][W];
}

void clear(int N){
    int I,J;
    for(I=0;I<N;I++)
        for(J=0;J<26000;J++)
            dp[I][J]=-1;
    for(I=0;I<26000;I++)
        dp[N][I]=0;
}
int main(){

        /*
        freopen("in.txt","r",stdin);
        */
        int I,J,sum,N,test;
        scanf("%d",&test);
        while(test--){
        sum=0;
        max_value=0;
        scanf("%d",&N);
        clear(N);
        for(I=0;I<N;I++){
            scanf("%d",&coin[I]);
            sum+=coin[I];
        }

        max_value=knapsack(0,0,sum/2);
        /*
        for(I=0;I<N;I++){
            for(J=0;J<N;J++)
                printf("%d ",dp[I][J]);
        printf("\n");
        }
        */
        printf("%d\n",(sum-max_value)-max_value);
    }

return 0;
}
