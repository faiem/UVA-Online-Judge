#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define MAX 10010


vector< pair<int,int> > B;
int tall[MAX],res;


void clear(){
    B.clear();
    res=0;
    for(int I=0;I<MAX;I++)
        tall[I]=-1;
}

int finding_max_tall(int node){

    if(tall[node]!=-1)
        return tall[node];
    int maxi=0;
    for(int I=node+1;I<B.size();I++){
        if(B[node].first<=B[I].first&&B[node].second<=B[I].second)
            maxi=max(maxi,finding_max_tall(I));
    }

return tall[node]=maxi+1;
}


int main(){

    //freopen("in.txt","r",stdin);
    int in,l,m;
    while(cin>>in && in){
        clear();
        for(int I=0;I<in;I++){
            cin>>l>>m;
            B.push_back(make_pair(l,m));
        }
        sort(B.begin(),B.end());
        for(int I=0;I<in;I++)
            res=max(res,finding_max_tall(I));
    cout<<res<<endl;
    }
    cout<<"*"<<endl;

return 0;
}
