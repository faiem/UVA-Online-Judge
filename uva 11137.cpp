#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
#define total_coin 21

unsigned long long dp[22][10002];


int coin[22];
int make_money;


unsigned long long coin_change(int I,int amount){

    if(I>(total_coin-1) || amount<0){ //coin index 0 to 20 = 21.
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
    memset(dp,-1,sizeof(dp));

    for(int I=1;I<22;I++)
        coin[I-1]=I*I*I;

    int make_money;
    while(cin>>make_money){
        cout<<coin_change(0,make_money)<<endl;

    }





return 0;
}

