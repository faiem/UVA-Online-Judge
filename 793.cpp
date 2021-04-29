
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


   //freopen("in.txt","r",stdin);
   int test,computer,S,US,x,y;
   char ch;
   cin>>test;

   for(int K=1;K<=test;K++){
   S=0;US=0;
   Union_Find U;
   cin>>computer;
   getchar();
   U.Make_set(computer);
   while(1){

   ch=getchar();

   if(ch=='\n'||ch==EOF)
    break;

   else if(ch=='c'){
        cin>>x>>y;
        getchar();
        U.Union(x,y);
        }
   else if(ch=='q'){
        cin>>x>>y;
        getchar();
        if(U.Find(x)==U.Find(y))
            S++;
        else
            US++;
        }

   }
   cout<<S<<","<<US<<endl;
   if(K<test)
    cout<<endl;
   }


return 0;
}
