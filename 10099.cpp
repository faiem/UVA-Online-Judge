
#include<cstdio>
#include<iostream>
#include<queue>
#include<vector>
#include<cmath>
using namespace std;

#define INF 2147483647

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
        return false;
    return true;
    }

class Union_Find{

    private:
        vector<int> set;

    public:

        Union_Find(int size){
        Make_set(size);
        }
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
    int node,edge,min,touriest,x,y,length,visit_city,L=0;

    while(cin>>node>>edge && node){
        min=INF;
        visit_city=0;
        priority_queue<kruskal> PQ;
        Union_Find U(node);
        vector<int> adj[node+1];
        int bus_capacity[node+1][node+1];
        bool flag[node+1];
        int path[node+1];
        for(int I=1;I<node+1;I++){
            flag[I]=0;
            path[I]=0;
            }
        for(int I=0;I<edge;I++){
        cin>>x>>y>>length;
        PQ.push(kruskal(x,y,length));
        }
        cin>>x>>y>>touriest;
        while(!PQ.empty()){

            if(U.Union(PQ.top().X(),PQ.top().Y())){
                adj[PQ.top().X()].push_back(PQ.top().Y());
                adj[PQ.top().Y()].push_back(PQ.top().X());
                bus_capacity[PQ.top().X()][PQ.top().Y()]=bus_capacity[PQ.top().Y()][PQ.top().X()]=PQ.top().Cost();
                }
        PQ.pop();
        }

    queue< pair<int,int> > Q;
    Q.push(make_pair(x,-1));

    while(!Q.empty()){
    x=Q.front().first;
    flag[x]=1;
    path[x]=Q.front().second;
    for(int I=0;I<adj[x].size();I++)
        if(!flag[adj[x][I]])
            Q.push(make_pair(adj[x][I],x));
    Q.pop();
    }
    int man_cap;
    while(path[y]!=-1){
        man_cap=bus_capacity[y][path[y]];
        if(min>man_cap)
            min=man_cap;
        y=path[y];
        }
    min-=1;
    printf("Scenario #%d\nMinimum Number of Trips = %d\n\n",++L,(int)ceil((double)touriest/double(min)));

}


return 0;
}
