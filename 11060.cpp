#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<stack>
#include<queue>
using namespace std;

class beverage{
    int indgree[100];
    stack<string> sta;
    vector<int> adjList[100];
    map<string,int> drinks;
    vector<string> numToString;
    bool visit[100];
    string s,t;
public:

    void clear(int node){
        for(int I=0;I<node;I++){
            visit[I]=false;
            indgree[I]=0;
        }
    }


    void input(int node,int test){
        clear(node);
        for(int I=0;I<node;I++){
            cin>>s;
            numToString.push_back(s);
            drinks[s]=I;
        }
        int edge,a,b;
        cin>>edge;
        for(int I=0;I<edge;I++){
            cin>>s>>t;
            a=drinks.find(s)->second;
            b=drinks.find(t)->second;
            adjList[a].push_back(b);
            indgree[b]++;
            }
        cout<<"Case #"<<test<<": Dilbert should drink beverages in this order:";

        for(int I=0;I<node;I++){
        priority_queue< pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > pq;
        for(int I=0;I<node;I++){
            if(!visit[I])
                pq.push(make_pair(indgree[I],I));
            }
        a=pq.top().second;
        cout<<" "<<numToString[a];
        visit[a]=true;
        for(int I=0;I<adjList[a].size();I++)
            indgree[adjList[a][I]]--;
        }
        cout<<"."<<endl;

    }



};


int main(){
//freopen("in.txt","r",stdin);
int t=1,node;
while(cin>>node){
beverage B;
B.input(node,t);
t++;
cout<<endl;
}

return 0;
}
