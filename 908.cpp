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
    //freopen("out.txt","w",stdout);


    long cost1,cost2;
    int computer,a,b,c,nwln=1,k,M;
    while(cin>>computer){
    cost1=0;cost2=0;
    if(nwln>1)
        cout<<endl;

    for(int I=0;I<computer-1;I++){
        cin>>a>>b>>c;
        cost1+=c;
    }
    cout<<cost1<<endl;
    priority_queue<kruskal> PQ;
    cin>>k;
    for(int I=0;I<k;I++){
        cin>>a>>b>>c;
        PQ.push( kruskal(a,b,c) );
        }
    cin>>M;
    for(int I=0;I<M;I++){
        cin>>a>>b>>c;
        PQ.push( kruskal(a,b,c) );
        }
    Union_Find U;
    U.Make_set(computer);
    while(!PQ.empty()){
    a=PQ.top().X();
    b=PQ.top().Y();
    if(U.Union(a,b))
       cost2+=PQ.top().Cost();
    PQ.pop();
    }
    cout<<cost2<<endl;
    nwln++;
    }


return 0;
}

