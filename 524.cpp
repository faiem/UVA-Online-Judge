#include<cstdio>
#include<iostream>
#include<vector>
#include<deque>
using namespace std;
bool prime[32],flag[17];
vector<int> adjList[17],even,odd;
deque<int> DQ,PQ;

void clear(){

    for(int I=0;I<17;I++){
        adjList[I].clear();
        flag[I]=0;
    }
    even.clear();
    odd.clear();
    DQ.clear();
    PQ.clear();
}

void primeGen(){

    for(int I=0;I<32;I++)
        prime[I]=0;

    prime[2]=1;
    prime[3]=1;
    prime[5]=1;
    prime[7]=1;
    prime[11]=1;
    prime[13]=1;
    prime[17]=1;
    prime[19]=1;
    prime[23]=1;
    prime[29]=1;
    prime[31]=1;
}


void adjListMake(int n){

    for(int I=2;I<=n;I+=2)
        even.push_back(I);
    for(int I=3;I<=n;I+=2)
        odd.push_back(I);

    for(int I=1;I<=n;I++){

        if(I&1){
            for(int J=0;J<even.size();J++)
                if(prime[I+even[J]])
                    adjList[I].push_back(even[J]);
        }

         else{
            for(int J=0;J<odd.size();J++)
                if(prime[I+odd[J]])
                    adjList[I].push_back(odd[J]);
        }

    }

}


void printMatrix(int n){

    for(int I=1;I<=n;I++){
    cout<<I<<"->";
        for(int J=0;J<adjList[I].size();J++)
            cout<<adjList[I][J]<<" ";
    cout<<endl;
    }

}

void RingFind(int num,int size){

    flag[num]=true;
    DQ.push_back(num);
    for(int I=0;I<adjList[num].size();I++){
        if(!flag[adjList[num][I]])
            RingFind(adjList[num][I],size);
    }
    if(DQ.size()==size){
        if(prime[DQ.back()+1]){
        PQ=DQ;
            printf("%d",PQ.front());
            PQ.pop_front();
            while(!PQ.empty()){
                printf(" %d",PQ.front());
                PQ.pop_front();
            }
        printf("\n");
        }
    }

    DQ.pop_back();
    flag[num]=false;
}


int main(){
    int T,C=1;
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    primeGen();
    while(scanf("%d",&T)==1){
    if(C>1)
    printf("\n");
    printf("Case %d:\n",C++);
    if(T>2&&prime[T]){}
    else{
    clear();
    adjListMake(T);
    RingFind(1,T);
    }
    }


return 0;
}
