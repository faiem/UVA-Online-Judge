#include<cstdio>
#include<iostream>
#include<queue>
#include<vector>
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

    int node,edge,a,b,cost;
    //freopen("in.txt","r",stdin);
    while(cin>>node>>edge && node>0){
        priority_queue<kruskal> PQ;
        priority_queue<int, vector<int>, greater<int> > highCost;
        Union_Find U;
        U.Make_set(node);
        while(edge--){
            cin>>a>>b>>cost;
            PQ.push(kruskal(a,b,cost));
            }
        while(!PQ.empty()){
            a=PQ.top().X();
            b=PQ.top().Y();
            if(!U.Union(a,b))
                highCost.push(PQ.top().Cost());
        PQ.pop();
        }
        if(highCost.empty())
            cout<<"forest"<<endl;
        else{
            cout<<highCost.top();
            highCost.pop();
            while(!highCost.empty()){
                cout<<" "<<highCost.top();
            highCost.pop();
            }
        cout<<endl;
        }
    }



return 0;
}


