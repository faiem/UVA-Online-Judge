#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;

#define inf 2147483647

int taka[10001];

int main(){


    //freopen("in.txt","r",stdin);

    int test,make_money,coin[101],number_of_coin;


    cin>>test;
    while(test--){

        cin>>make_money>>number_of_coin;

        for(int I=0;I<10001;I++)
            taka[I]=inf;

        taka[0]=0;

        for(int I=0;I<number_of_coin;I++){
            cin>>coin[I];
           for(int J=10000-coin[I];J>=0;J--)
                if(taka[J]!=inf && J+coin[I]<=10000)
                    taka[J+coin[I]]=min(taka[J+coin[I]],taka[J]+1);

        }

        for(int I=make_money;I<=10000;I++)
            if(taka[I]!=inf){
                cout<<I<<" "<<taka[I]<<endl;
            break;
            }
    }




return 0;
}
