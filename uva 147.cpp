#include<stdio.h>
#include<string.h>

unsigned long long dp[12][30001];

int coin[12]={5,10,20,50,100,200,500,1000,2000,5000,10000};
int make_money;



unsigned long long coin_change(int I,int amount){

    if(I>10 || amount<0){
        return 0;
    }

    if(amount==0)
        return 1;

    if(dp[I][amount]!=-1)
        return dp[I][amount];

return dp[I][amount]=coin_change(I,amount-coin[I])+coin_change(I+1,amount);
}


int main(){

    //freopen("in.txt","r",stdin);
    int part1,part2;
    memset(dp,-1,sizeof(dp));
    while(scanf("%d.%d",&part1,&part2)==2){
        if(part1==0 && part2==0)
            break;
    make_money=part1*100+part2;
    printf("%3d.%.2d%17llu\n",part1,part2,coin_change(0,make_money));
    }



return 0;
}
