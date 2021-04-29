#include<iostream>
#include<cstdio>
#include<vector>
#include<stack>
using namespace std;

class Come{

vector<int> Mat[2010],rMat[2010];
bool flag[2010];
stack<int> s,SCC;

public:

void clear(int node){
    node+=1;
    for(int I=0;I<node;I++)
        flag[I]=true;
    }

void DFS(int node){
flag[node]=false;
    for(int I=0;I<Mat[node].size();I++)
        if(flag[ Mat[node][I] ])
            DFS(Mat[node][I]);
s.push(node);
}

void revDFS(int node){
flag[node]=true;
    for(int I=0;I<rMat[node].size();I++)
        if(!flag[ rMat[node][I] ])
            revDFS(rMat[node][I]);
SCC.push(node);
}

bool finding(int node){
    node+=1;
    for(int I=1;I<node;I++)
        if(flag[I])
            DFS(I);

    revDFS(s.top());
    //cout<<"-->"<<SCC.size()<<endl;
    if(SCC.size()==(node-1))
         return true;
    return false;
    }
bool input(int node,int edge){
    int s,d,way;
    clear(node);
    for(int I=0;I<edge;I++){
        cin>>s>>d>>way;
        if(way==1){
            Mat[s].push_back(d);
            rMat[d].push_back(s);
        }
        else{
            Mat[s].push_back(d);
            Mat[d].push_back(s);
            rMat[s].push_back(d);
            rMat[d].push_back(s);
        }

        }
    return finding(node);
    }

};



int main(){

    int node,edge;
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    while(scanf("%d %d",&node,&edge)==2&&node!=0){
        Come go;
        cout<<go.input(node,edge)<<endl;
        }
    return 0;
    }