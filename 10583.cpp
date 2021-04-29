
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<cmath>
#include<math.h>
#include<cstring>
#include<string>

using namespace std;

class Union_Find{

    private:

    public:
         vector<int> set;

        void Make_set(int size){

            for(int I=0;I<=size;I++)
                set.push_back(-1);
        }

        int Find(int x){

            if(set[x]<0)
                return x;
        return Find(set[x]);
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

        void Union(int x,int y){
            x=Find(x);
            y=Find(y);
            if(x!=y)
            Create_Union(x,y);
        }
    void print(){

        for(int I=0;I<set.size();I++)
            printf("%2d ",I);
        cout<<"\n";
        for(int I=0;I<set.size();I++)
            printf("%2d ",set[I]);
    cout<<"\n-------\n";
    }
};


int main(){

    int m,n,x,y,I,J=1,count;
    while(cin>>n>>m && n>0){
        count=0;
        Union_Find U;
        U.Make_set(n);
        while(m--){
            cin>>x>>y;
            U.Union(x,y);
        }
    for(I=1;I<=n;I++)
        if(U.set[I]<0)
            count++;
    printf("Case %d: %d\n",J,count);
    J++;
    }



return 0;
}

