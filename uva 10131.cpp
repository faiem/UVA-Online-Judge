#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

struct elephant{
    int weight,IQ,number;
};

vector<elephant> E;
int dir[1001],dp[1001];

bool comp(elephant x,elephant y){

    if(x.weight==y.weight)
        return x.IQ>y.IQ;

    if(x.weight<y.weight)
        return 1;

return 0;
}

int findind_biggest(int N){

    if(dp[N]!=-1)
        return dp[N];
    int maxi=0;
    for(int I=N+1;I<E.size();I++){
        if(E[N].weight<E[I].weight && E[N].IQ>E[I].IQ){
            if(maxi<findind_biggest(I)){
                maxi=findind_biggest(I);
                dir[N]=I;
            }
        }
    }
return dp[N]=maxi+1;
}

void solution(int start){
    while(dir[start]!=-1)
    {
        printf("%d\n",E[start].number);
        start=dir[start];
    }
    printf("%d\n",E[start].number);
}

int main(){

    //freopen("in.txt","r",stdin);

    int w,iq,c=1,res=0,start=0;
    for(int I=0;I<1001;I++)
        dp[I]=dir[I]=-1;
    while(cin>>w){
        cin>>iq;
    E.push_back((elephant){w,iq,c});
    c++;
    }

    sort(E.begin(),E.end(),comp);

    for(int I=0;I<E.size();I++){
        if(res<findind_biggest(I)){
            res=findind_biggest(I);
            start=I;
        }
    }
    cout<<res<<endl;
    solution(start);
return 0;
}
