#include<cstdio>
#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
#include<map>
using namespace std;

class Finding_Bridge{
map<pair<int,int>,bool> backage;
map<pair<int,int>,bool>::iterator it;
vector<pair<int,int> > bridge,nobridge;
vector<int> adjList[1001];
int dfsnumber,dfn[1001],low[1001],root[1001];
bool visit[1001],bvis[1001];
pair<int,int> p;
public:

void input(int node,int edge){
int a,b;
    clear(node);
    for(int I=0;I<edge;I++){
    cin>>a>>b;
    adjList[a].push_back(b);
    adjList[b].push_back(a);
    }

    for(int I=1;I<=node;I++){
        if(!visit[I]){
        dfsnumber=0;
        DFS(I,-1);
        find_bridge(I);
        }

    }

    for(int I=0;I<bridge.size();I++){
        cout<<bridge[I].first<<" "<<bridge[I].second<<endl;
        cout<<bridge[I].second<<" "<<bridge[I].first<<endl;
    }
    //cout<<"---\n";
    for(int I=0;I<nobridge.size();I++){
        cout<<nobridge[I].first<<" "<<nobridge[I].second<<endl;
    }
    //cout<<"---\n";
    for(it=backage.begin();it!=backage.end();it++)
        cout<<(*it).first.first<<" "<<(*it).first.second<<endl;
    //print_all(node);
}

void find_bridge(int node){

    bvis[node]=true;
    for(int I=0;I<adjList[node].size();I++){
        if(!bvis[adjList[node][I]]){
            //cout<<node<<"--"<<adjList[node][I]<<endl;
            if(dfn[adjList[node][I]]<=low[adjList[node][I]])
                bridge.push_back(make_pair(node,adjList[node][I]));
            else
                nobridge.push_back(make_pair(node,adjList[node][I]));
        find_bridge(adjList[node][I]);
        }
        else if( (root[node]!=adjList[node][I]) && (dfn[node]>dfn[adjList[node][I]])){
            //cout<<node<<"->"<<adjList[node][I]<<endl;
            p.first=node;
            p.second=adjList[node][I];
            backage[p]=1;
        }
    }
}

void clear(int node){

    for(int I=0;I<=node;I++){
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

    for(int I=1;I<node;I++)
        cout<<I<<" "<<dfn[I]<<" "<<low[I]<<endl;
}


};


int main(){

int node,edge,t=1;

//freopen("in.txt","r",stdin);
//freopen("out.txt","w",stdout);

while(cin>>node>>edge && node){
    cout<<t<<endl<<endl;
    Finding_Bridge B;
    B.input(node,edge);
    cout<<"#"<<endl;
    t++;
    }




return 0;
}
