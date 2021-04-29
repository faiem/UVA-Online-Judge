
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

            for(int I=0;I<size;I++)
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

    int name,relation;
    char ch;
    //freopen("in.txt","r",stdin);
    while(cin>>name>>relation && name>0){
    getchar();
    map<string,int> M;
    string s;
    Union_Find U;
    U.Make_set(name);

    for(int I=0;I<name;I++){
        cin>>s;
        M[s]=I;
    }
    getchar();
    while(relation--){
    char arr[35];
        int I=0;
        while((ch=getchar())!=' '){
            arr[I]=ch;
        I++;
        }
        arr[I]='\0';
        s=arr;
        int x= M.find(s)->second;

        I=0;
        while((ch=getchar())!='\n'){
            arr[I]=ch;
        I++;
        }
        arr[I]='\0';
        s=arr;
        int y=M.find(s)->second;
    U.Union(x,y);
    }
    int min=1;
    for(int I=0;I<name;I++)
        if(U.set[I]<min)
            min=U.set[I];
    cout<<min*-1<<endl;
    }
return 0;
}

