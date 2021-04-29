#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Treasure{
    int depth,gold_quantity,cost;
};

Treasure T[35];
int dp[31][1010],dir[31][1010],cap,c;

int max(int a,int b){
    if(a>b)
        return a;
return b;
}

void clear(int N){

    for(int I=0;I<=N;I++){
        T[I].depth=0; T[I].gold_quantity=0; T[I].cost=0;
        for(int J=0;J<1010;J++)
            dir[I][J]=dp[I][J]=-1;
    }
    //for return 0 for all pos in dp[N][0,1,2,,,,N];
    for(int I=0;I<1010;I++)
        dp[N][I]=0;
}



int max_gold_found(int I,int w,int gold){

    int profit1,profit2;

    if(dp[I][w]!=-1)
        return dp[I][w];

    if(w+T[I].cost<=cap){
        profit1=T[I].gold_quantity+max_gold_found(I+1,w+T[I].cost,gold+T[I].gold_quantity);
    }
    else
        profit1=0;

    profit2=max_gold_found(I+1,w,gold);
    dir[I][w]=(profit1>profit2);

return dp[I][w]=max(profit1,profit2);
}


int count(int I,int w){

    if(dir[I][w]==-1)
        return c;
    if(dir[I][w]==1){
        c++;
        count(I+1,w+T[I].cost);
    }
    else{
        count(I+1,w);
    }
}


void print(int I,int w){

    if(dir[I][w]==-1)
        return;
    if(dir[I][w]==1){
        printf("%d %d\n",T[I].depth,T[I].gold_quantity);
        print(I+1,w+T[I].cost);
    }
    else{
        print(I+1,w);
    }

}



int main(){

    //freopen("in.txt","r",stdin);
    int t,w,N;
    bool C=0;
    while(cin>>t>>w){
        c=0;
        cap=t;
        cin>>N;
        clear(N);
        for(int I=0;I<N;I++){
            cin>>T[I].depth>>T[I].gold_quantity;
            T[I].cost=3 * w * T[I].depth;
        }
    if(C)
        printf("\n");
    cout<<max_gold_found(0,0,0)<<endl;
    cout<<count(0,0)<<endl;
    print(0,0);
    C=1;
    }


return 0;
}
