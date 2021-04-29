#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
#define MAX 100

struct block{
    int x,y,z;
};

vector<block> B;
int max_store[MAX];

bool comp(block a,block b){
return(a.x > b.x);
}

void clear(){
    for(int I=0;I<MAX;I++)
        max_store[I]=-1;
B.clear();
}

bool decn(int a,int b){
return a>b;
}

int max(int a,int b){

    if(a>b)
        return a;
return b;
}

int finding_max(int I){

    if(max_store[I]!=-1)
        return max_store[I];

    for(int J=I+1;J<B.size();J++){
        if((B[I].x>B[J].x && B[I].y>B[J].y )||( B[I].y>B[J].x && B[I].x>B[J].y ) ){
               max_store[I]=max(max_store[I],finding_max(J)+B[I].z);
        }
    }
    if(max_store[I]!=-1)
        return max_store[I];
return max_store[I]=B[I].z;
}

int main(){
 //freopen("in.txt","r",stdin);
 int N,C=1,arr[3];
 while(cin>>N && N){
    clear();
    while(N--){

        for(int I=0;I<3;I++)
            scanf("%d",&arr[I]);
        sort(arr,arr+3,decn);
        B.push_back((block){arr[0],arr[1],arr[2]});
        B.push_back((block){arr[0],arr[2],arr[1]});
        B.push_back((block){arr[1],arr[2],arr[0]});
        }
    sort(B.begin(),B.end(),comp);

    for(int I=0;I<B.size();I++){
        finding_max(I);
    }
    int hight=0;
    for(int I=0;I<B.size();I++){
        if(hight<max_store[I])
            hight=max_store[I];
    }
    printf("Case %d: maximum height = %d\n",C,hight);
 C++;
 }



return 0;
}
