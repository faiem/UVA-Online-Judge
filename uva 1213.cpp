#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int prime[190],num;
unsigned int dp[1122][188][15];

void prime_generate(int limit){

    limit+=1;
    bool p[1200];
    memset(p,1,sizeof(p));
    p[0]=p[1]=0;
    for(int I=4;I<limit;I+=2)
        p[I]=0;
    for(int I=3;I*I<limit;I+=2){
        if(p[I]){
            for(int J=I*I;J<limit;J+=I)
                p[J]=0;
        }
    }
    prime[0]=2;

    for(int c=1,I=3;I<limit;I+=2)
        if(p[I]){
            prime[c]=I;
        c++;
        }
}



unsigned int knap(int sum,int I,int K){

    if(K==0){
        if(sum==0)
            return 1;
    return 0;
    }

    if(I>186 || sum<0)
        return 0;

    if(dp[sum][I][K]!=-1)
            return dp[sum][I][K];

return dp[sum][I][K] = knap(sum-prime[I],I+1,K-1)+knap(sum,I+1,K);
}




int main(){

    //freopen("in.txt","r",stdin);
    int k;
    memset(dp,-1,sizeof(dp));
    prime_generate(1120);
    /*
    for(int I=1120;I>0;I--){
        for(int J=1;J<15;J++)
            out[I][J]=knap(I,0,J);
    }
    */
    while(cin>>num>>k && num){
        cout<<knap(num,0,k)<<endl;
    }


return 0;
}
