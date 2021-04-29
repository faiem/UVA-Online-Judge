#include<cstdio>
#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
#include<map>
#include<string>
#include<set>
using namespace std;

class Articulation{

map<string,int> m,alpha;
map<string,int>::iterator it;
map<int,string> camera;
vector<int> adjList[101],childList[101],artpoint;
int dfn[101],low[101],root[101],child[101],dfsnumber;
bool visit[101];
public:


void input(int node,int test){
int a,b,n,different=0;
string s,t;
for(int I=0;I<node;I++){
    cin>>s;
    m[s]=++different;
    camera[different]=s;
}
cin>>n;
for(int I=0;I<n;I++){
    cin>>s>>t;
    adjList[m.find(s)->second].push_back(m.find(t)->second);
    adjList[m.find(t)->second].push_back(m.find(s)->second);
}
    clear(node);
    for(int I=1;I<=node;I++){
        if(!visit[I]){
        dfsnumber=0;
        DFS(I,-1);
        }
    }
    Find_Articulation(node);
    cout<<"City map #"<<test<<": "<<artpoint.size()<<" camera(s) found"<<endl;
    for(int I=0;I<artpoint.size();I++){
        s=camera.find(artpoint[I])->second;
        alpha[s]=I;
    }
for ( it=alpha.begin() ; it != alpha.end(); it++ )
    cout<<(*it).first<<endl;
//        cout<<camera.find(artpoint[I])->second<<endl;
    //print_art();



}



void clear(int node){

    for(int I=0;I<=node;I++){

        dfn[I]=0;
        low[I]=0;
        root[I]=-1;
        child[I]=0;
        visit[I]=false;
    }
}

int min(int a,int b){
    if(a<b)
        return a;
return b;
}

void DFS(int node,int r){

    dfn[node]=++dfsnumber;
    low[node]=dfn[node];
    root[node]=r;
    visit[node]=true;
    for(int I=0;I<adjList[node].size();I++)
        if(!visit[adjList[node][I]]){
            child[node]++;
            childList[node].push_back(adjList[node][I]);
            DFS(adjList[node][I],node);
        }

    for(int I=0;I<adjList[node].size();I++){
        if(adjList[node][I]!=root[node])
            low[node]=min(low[node],low[adjList[node][I]]);
    }

}

void Find_Articulation(int node){

    for(int I=1;I<=node;I++){
        if(root[I]==-1){
            if(child[I]>=2)
                artpoint.push_back(I);
           }
        else{
            if(child[I]>=1){
                for(int J=0;J<childList[I].size();J++)
                        if(dfn[I]<=low[childList[I][J]]){
                            artpoint.push_back(I);
                            break;
                        }
            }
        }
    }
}

void print_art(){

    for(int I=0;I<artpoint.size();I++)
        cout<<artpoint[I]<<" ";

cout<<endl;
}

};

int main(){
//freopen("in.txt","r",stdin);
int node,test=1;
while(scanf("%d",&node)&&node){
    if(test>1)
        cout<<endl;
    Articulation point;
    point.input(node,test);
    test++;
}


return 0;
}
