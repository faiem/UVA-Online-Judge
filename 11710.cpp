#include<cstdio>
#include<iostream>
#include<queue>
#include<vector>
#include<map>
#include<string>
using namespace std;

class kruskal{

    int x,y,cost;

public:

    kruskal(int a,int b,int meter){
        x=a;
        y=b;
        cost=meter;
    }

    int X()const{
    return x;
    }

    int Y()const{
    return y;
    }

    int Cost()const{
    return cost;
    }

};

bool operator<(const kruskal &n1,const kruskal &n2){

    if( n1.Cost()>=n2.Cost() )
        return true;
    return false;
    }

class Union_Find{

    private:
        vector<int> set;

    public:

        void Make_set(int size){

            for(int I=0;I<=size;I++)
                set.push_back(-1);
        }

        int Find(int x){

            if(set[x]<0)
                return x;
        return set[x]=Find(set[x]);
        }

        void Create_Union(int x,int y){

            if(set[x]>=set[y]){
                set[y]+=set[x];
                set[x]=y;
            }
            else{
                set[x]+=set[y];
                set[y]=x;
            }

        }

        bool Union(int x,int y){
            x=Find(x);
            y=Find(y);
            if(x!=y){
            Create_Union(x,y);
            return 1;
            }
        return 0;
        }
    void print(){

        for(int I=0;I<set.size();I++)
            printf("%2d ",I);
        cout<<"\n";
        for(int I=0;I<set.size();I++)
            printf("%2d ",set[I]);
    cout<<"\n";//-------\n";
    }
};

int main(){
//freopen("in.txt","r",stdin);
long total_cost;
int num,node,edge,station,cost;
while(cin>>node>>edge && node>0){
    total_cost=0;
    num=0;
    station=0;
    string s,t;
    map<string,int> M;
    Union_Find U;
    U.Make_set(node);
    priority_queue<kruskal> PQ;
    for(int I=0;I<node;I++){
    cin>>s;
    M[s]=++num;
    }

    for(int I=0;I<edge;I++){
        cin>>s>>t>>cost;
        PQ.push(kruskal(M.find(s)->second,M.find(t)->second,cost));
    }

    cin>>s;

    while(!PQ.empty()){
        if(U.Union( PQ.top().X(),PQ.top().Y() ) ){
            station++;
            total_cost+=PQ.top().Cost();
            }
        PQ.pop();
        }

       if(station==node-1)
            cout<<total_cost<<endl;
        else
            cout<<"Impossible"<<endl;
    }


return 0;
}

