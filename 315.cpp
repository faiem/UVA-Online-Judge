#include<cstdio>
#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;

class Articulation{

vector<int> adjList[101],childList[101],artpoint;
int dfn[101],low[101],root[101],child[101],dfsnumber;
bool visit[101];
public:


void input(int node){
int a,b;
char str[1000];
while( gets(str) && strcmp(str,"0") ){

    char *p;
    p=strtok(str," ");
    a= atoi (p);

    p=strtok(NULL," ");
    while(p!=NULL){
    b=atoi(p);
    adjList[a].push_back(b);
    adjList[b].push_back(a);
    p=strtok(NULL," ");
    }
}

if(node==1)
    cout<<artpoint.size()<<endl;
else{
    clear(node);
    for(int I=1;I<=node;I++){
        if(!visit[I]){
        dfsnumber=0;
        DFS(I,-1);
        }
    }
    Find_Articulation(node);
    cout<<artpoint.size()<<endl;
    //print_art();
}


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
int node;
while(scanf("%d",&node)&&node){
    getchar();
    Articulation point;
    point.input(node);
}


return 0;
}
