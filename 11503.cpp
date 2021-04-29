
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


    public:
        vector<int> set;

        void Make_set(int size){

            for(int I=0;I<=2*size;I++)
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

   int test,pair,I,node,x,y;
   char ch1[30],ch;
   //freopen("in.txt","r",stdin);
   //freopen("out.txt","w",stdout);

   cin>>test;
   while(test--){

 map< string,int > M;
   map< string,int >::iterator it;

   string s;
   Union_Find U;
   node=0;

   cin>>pair;
   getchar();
   U.Make_set(pair);

   while(pair--){
    I=0;
    while((ch=getchar())!=' '){
        ch1[I]=ch;
        I++;
        }
    ch1[I]='\0';
    s=ch1;
    //cout<<s<<"->";
    if(!M[s]){
        M[s]=++node;
        x=node;
        }
    else{
        x=M.find(s)->second;
        }
    //cout<<"size:"<<s.size()<<"->";
    //cout<<x<<" ";
    /////////////////////////////
    I=0;
    while((ch=getchar())!='\n'){
        ch1[I]=ch;
        I++;
        }
    ch1[I]='\0';
    s=ch1;

    //cout<<s<<"->";
    if(!M[s]){
        M[s]=++node;
        y=node;
        }
    else{
        y=M.find(s)->second;
        }
    //cout<<"size:"<<s.size()<<"->";
    //cout<<y<<endl;
    U.Union(x,y);
    if(x<=y)
      cout<<U.set[U.Find(x)]*-1<<endl;
    else
      cout<<U.set[U.Find(y)]*-1<<endl;
   //getchar();
   }

   }




return 0;
}

