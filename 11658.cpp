
#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

int share[110],dp[110][10002],min_value;


void clear(int N){

    for(int I=0;I<N;I++)
        for(int J=0;J<10001;J++)
            dp[I][J]=-1;
    for(int I=0;I<10001;I++)
        dp[N][I]=0;
}

int max_50percent_found(int I,int w){

    int profit1,profit2;

    if(dp[I][w]!=-1)
        return dp[I][w];
    if(w+share[I]<5001)
        profit1=share[I]+max_50percent_found(I+1,w+share[I]);
    else{
        profit1=0;
        min_value=min(min_value,w+share[I]);
    }

    if(w>5000)
        min_value=min(min_value,w);

    profit2=max_50percent_found(I+1,w);

return dp[I][w]=max(profit1,profit2);
}

int main(){

    //freopen("in.txt","r",stdin);
    //double in;
    int n,x,my_share,max_find,i_part,f_part;
    while(cin>>n>>x && n){
        for(int I=0;I<n;I++){
            //cin>>in;
            scanf("%d.%d",&i_part,&f_part);
            share[I]=i_part*100+f_part;

        }
        my_share=share[x-1];
        share[x-1]=0;
        min_value=10000;

        if(my_share>5000){
            printf("100.00\n");
            continue;
        }

        clear(n);
        max_50percent_found(0,my_share);
        double res;
        res=(((double)my_share/100.0)*100.0)/((double)min_value/100.0);
        printf("%.2lf\n",round(100.0*res)/100.0);
    }

return 0;
}
