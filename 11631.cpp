#include<cstdio>
#include<iostream>
#include<queue>
#include<vector>
using namespace std;

class road{

    int x,y,cost;

public:

    road(int a,int b,int meter){
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

bool operator<(const road &r1,const road &r2){

    if( r1.Cost()>=r2.Cost() )
        return true;
    return false;
    }

class Union_Find{

    private:
        vector<int> set;

    public:

        void Make_set(int size){

            for(int I=0;I<size;I++)
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
    int x,y,cost,node,edge;
    long minCost=0,totalcost=0;

    while(cin>>node>>edge && node>0){
        minCost=0;totalcost=0;
        priority_queue<road> PQ;
        Union_Find U;

        while(edge--){
        cin>>x>>y>>cost;
        PQ.push(road(x,y,cost));
        }
        U.Make_set(node);
        while(!PQ.empty()){
        x=PQ.top().X();
        y=PQ.top().Y();
        totalcost+=PQ.top().Cost();
        if(U.Union(x,y))
            minCost+=PQ.top().Cost();
        PQ.pop();
        }
        cout<<totalcost-minCost<<endl;
    }
return 0;
}

