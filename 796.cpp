#include<cstdio>
#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;

class Finding_Bridge{

vector<pair<int,int> > bridge;
vector<int> adjList[1000];
int dfsnumber,dfn[1000],low[1000],root[1000];
bool visit[1000],bvis[1000];

public:

void input(int node){
int a,n,b;
    clear(node);
    for(int I=0;I<node;I++){
        scanf("%d",&a);
    while(getchar()!='(');
        scanf("%d)",&n);
    for(int J=0;J<n;J++){
        scanf("%d",&b);
        adjList[a].push_back(b);
        adjList[b].push_back(a);
        }
    }

    for(int I=0;I<node;I++){
        if(!visit[I]){
        dfsnumber=0;
        DFS(I,-1);
        find_bridge(I);
        }

    }

    cout<<bridge.size()<<" critical links"<<endl;
    sort(bridge.begin(),bridge.end());
    for(int I=0;I<bridge.size();I++){
        cout<<bridge[I].first<<" - "<<bridge[I].second<<endl;
    }
    cout<<endl;
    //print_all(node);
}

void find_bridge(int node){

    bvis[node]=true;
    for(int I=0;I<adjList[node].size();I++)
        if(!bvis[adjList[node][I]]){

            if(dfn[adjList[node][I]]<=low[adjList[node][I]]){
                if(node<adjList[node][I])
                bridge.push_back(make_pair(node,adjList[node][I]));
                else
                bridge.push_back(make_pair(adjList[node][I],node));

            }
        find_bridge(adjList[node][I]);
        }
}

void clear(int node){

    for(int I=0;I<node;I++){
        dfn[I]=low[I]=0;
        root[I]=-1;
        visit[I]=false;
        bvis[I]=false;
    }

}

int min(int a,int b){
    if(a>b)
        return b;
return a;
}


void DFS(int node,int r){

    dfn[node]= ++dfsnumber;
    low[node]=dfn[node];
    root[node]=r;
    visit[node]=true;
    for(int I=0;I<adjList[node].size();I++)
        if(!visit[adjList[node][I]])
            DFS(adjList[node][I],node);
    for(int I=0;I<adjList[node].size();I++)
            if(root[node]!=adjList[node][I])
                low[node]=min(low[node],low[adjList[node][I]]);
}

void print_all(int node){

    for(int I=0;I<node;I++)
        cout<<I<<" "<<dfn[I]<<" "<<low[I]<<endl;
}


};


int main(){

int node;

//freopen("in.txt","r",stdin);
//freopen("out.txt","w",stdout);

while(cin>>node){
    if(node==0)
        cout<<"0 critical links"<<endl<<endl;
    else{
    Finding_Bridge B;
    B.input(node);
    }


}

return 0;
}
