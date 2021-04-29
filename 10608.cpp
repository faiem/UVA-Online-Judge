
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
        vector<int> set;

    public:

        void Make_set(int size){
            set.push_back(1000000);
            for(int I=1;I<=size;I++)
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
    int Largest_Group_Member_Number(){

            sort(set.begin(),set.end());
        return set[0]*(-1);
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

    int x,y,size,pair,test;
    cin>>test;
    while(test--){
    cin>>size>>pair;
        Union_Find U;
        U.Make_set(size);
        //U.print();
        while(pair--){
            cin>>x>>y;
            U.Union(x,y);
            //U.print();
        }
    cout<<U.Largest_Group_Member_Number()<<endl;
        }


return 0;
}
