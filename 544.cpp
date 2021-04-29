#include<iostream>
#include<cstdio>
#include<map>
#include<string>
#include<cstring>
#include<queue>
#include<set>
#include<stack>
using namespace std;

class cargo{

    int nodeNumber,weight;

public:

    cargo(int w,int nn){
        weight=w;
        nodeNumber=nn;
    }


    int Weight()const{
    return weight;
    }

    int Node()const{
    return nodeNumber;
    }

};

bool operator<(const cargo &c1,const cargo &c2){

        if(c1.Weight() < c2.Weight())
            return true;
return false;
}


int main(){
    bool flag[201];
    int node,edge,L=1;
    //freopen("in.txt","r",stdin);
    while(cin>>node>>edge && node>0){

    string s,d;
    map<string,int> M;
    int nodeNumber=0,x,y,weight;
    vector<cargo> city[node+1];
    priority_queue<cargo> PQ;

    for(int I=0;I<=node;I++)
            flag[I]=false;

        while(edge--){

        cin>>s>>d>>weight;
        if(!M[s]){
            M[s]=++nodeNumber;
            x=nodeNumber;
            }
        else
            x=M.find(s)->second;


        if(!M[d]){
            M[d]=++nodeNumber;
            y=nodeNumber;
            }
        else
            y=M.find(d)->second;

        city[x].push_back(cargo(weight,y));
        city[y].push_back(cargo(weight,x));
        }

        cin>>s>>d;
        x=M.find(s)->second;
        y=M.find(d)->second;
        int minCost=100000;
        PQ.push(cargo(100000,x));

        while(!PQ.empty()){
        x=PQ.top().Node();
        flag[x]=true;
        if(minCost>PQ.top().Weight())
            minCost=PQ.top().Weight();
        if(x==y)
            break;
        PQ.pop();

            for(int I=0;I<city[x].size();I++)
                if( !flag[ city[x][I].Node() ] )
                    PQ.push( cargo( city[x][I].Weight(),city[x][I].Node() )  );

        }
        if(minCost==100000)
            minCost=0;
        cout<<"Scenario #"<<L<<endl<<minCost<<" tons"<<endl<<endl;
    L++;
    }




return 0;
}
