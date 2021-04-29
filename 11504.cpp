#include<cstdio>
#include<iostream>
#include<set>
#include<stack>
#include<queue>
#include<vector>
#include<algorithm>
#define N 100010
using namespace std;


vector<int> v[N],rv[N];

class Dominos{

bool flag[N],knock[N];
int group[N];
stack<int> S;
public:
void clear(int node){
    node+=1;
    for(int I=0;I<node;I++){
        flag[I]=true;
        group[I]=0;
        knock[I]=false;
        v[I].clear();
        rv[I].clear();
        }
    }

void DFS(int node){
    flag[node]=false;
    for(int I=0;I<v[node].size();I++)
        if(flag[ v[node][I] ])
            DFS( v[node][I] );
S.push(node); //TopSort korsi
}

void revDFS(int node,int group_number){
    flag[node]=true;
    group[node]=group_number;
    for(int I=0;I<rv[node].size();I++)
        if(!flag[rv[node][I]])
            revDFS(rv[node][I],group_number);
}

int findingStrongComponents(int node){
    node+=1;
    int in=0;
    for(int I=1;I<node;I++)
        if(flag[I])
            DFS(I);

    while(!S.empty()){

       if(!flag[S.top()]){
            revDFS(S.top(),++in);
            //in++;
            }
        S.pop();
        }
//cout<<endl;
    return in;
    }

int input(int node,int edge)
{
    clear(node);

     int n1,n2,count=0;

    for(int I=0;I<edge;I++){
        cin>>n1>>n2;
        v[n1].push_back(n2);
        rv[n2].push_back(n1);

        }
        //print(node);
    int components=findingStrongComponents(node);
    //cout<<components;
    node+=1;
    for(int I=1;I<node;I++){
        for(int J=0;J<v[I].size();J++){
            if(group[I]!=group[ v[I][J] ])
                knock[ group[ v[I][J] ] ]=true;
        }
    }

    for(int I=1;I<=components;I++)
        if(!knock[I])
            count++;
    return count;
    }



/*
void print(int node){
 //v print
    cout<<"\nOriginal Matrix: \n";
    node+=1;
    for(int I=1;I<node;I++){
        cout<<"\n"<<I<<": ";
        for(int J=0;J<v[I].size();J++)
            cout<<" "<<v[I][J];
        }

    //node+=1;
    cout<<"\nReverse Matrix:\n";
    for(int I=1;I<node;I++){
        cout<<"\n"<<I<<": ";
        for(int J=0;J<rv[I].size();J++)
            cout<<" "<<rv[I][J];
        }

    cout<<"\nSet Print\n";
    for(int I=1;I<node;I++){
        cout<<"\n"<<I<<": ";
        for(it=inCheck[I].begin();it!=inCheck[I].end();it++)
            cout<<" "<<*it;
        }

cout<<"\n";
}
*/
};

int main(){
    int test,node,edge;
   //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    cin>>test;
    while(test--){
    cin>>node>>edge;
    Dominos D;
    cout<<D.input(node,edge)<<endl;
    }

return 0;
}
