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

        Union_Find(int size){
        Make_set(size);
        }
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
    int node,edge,maxlength,x,y,length,visit_city;

    while(cin>>node>>edge && node){
        maxlength=0;
        visit_city=0;
        priority_queue<kruskal> PQ;
        Union_Find U(node);
        for(int I=0;I<edge;I++){
        cin>>x>>y>>length;
        PQ.push(kruskal(x,y,length));
        }
        while(!PQ.empty()){

            if(U.Union(PQ.top().X(),PQ.top().Y())){
                if(maxlength<PQ.top().Cost())
                    maxlength=PQ.top().Cost();
            visit_city++;
            }
        PQ.pop();
        }
    if(visit_city==node-1)
        cout<<maxlength<<endl;
    else
        cout<<"IMPOSSIBLE"<<endl;
    }


return 0;
}
