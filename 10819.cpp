#include<iostream>
#include<cstdio>
#include<algorithm>
 using namespace std;

 int dp[102][10201],money[102],fav[102],total_money;

 void clear(int N){

    for(int I=0;I<N;I++)
        for(int J=0;J<10201;J++)
            dp[I][J]=-1;
    for(int I=0;I<10201;I++)
        dp[N][I]=0;
 }



 int love_13dots(int I,int expense){

    int profit1=0,profit2;

    if(dp[I][expense]!=-1)
        return dp[I][expense];

    if(expense+money[I]<=total_money){
        profit1=fav[I]+love_13dots(I+1,expense+money[I]);
    }

    else if(expense+money[I]>2000 && expense+money[I]<=total_money+200){
        profit1=fav[I]+love_13dots(I+1,expense+money[I]);
    }

    profit2=love_13dots(I+1,expense);

 return dp[I][expense]=max(profit1,profit2);
 }

 int main(){

    //freopen("in.txt","r",stdin);
    int item;
    while(cin>>total_money>>item){

        clear(item);
        for(int I=0;I<item;I++)
            cin>>money[I]>>fav[I];

        cout<<love_13dots(0,0)<<endl;
    }


 return 0;
 }
