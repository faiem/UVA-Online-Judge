#include<cstdio>
#include<iostream>
#include<string>
#include<sstream>
using namespace std;

int dp[25][200],coin[25],max_value;

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
return dp[I][W]=max(profit1,profit2);
}

void clear(int N){
    int I,J;
    for(I=0;I<21;I++)
        for(J=0;J<200;J++)
            dp[I][J]=-1;
    for(I=0;I<200;I++)
        dp[N][I]=0;
}
int main(){


        //freopen("in.txt","r",stdin);

        int test,sum,I,num;
        cin>>test;
        getchar();
        while(test--){
        sum=0;
        string s;
        getline(cin,s);
        stringstream line(s);
        I=0;
        while(line>>num){
            coin[I]=num;
            sum+=num;
        I++;
        }
        clear(I);
        max_value=knapsack(0,0,sum/2);
        if(sum==max_value*2)
        printf("YES\n");
        else
        printf("NO\n");
        }

return 0;
}

