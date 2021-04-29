#include<iostream>
#include<cstdio>
#include<vector>
#include<stack>

using namespace std;
#define MAX 33000
#define inf 1000000

int seq[MAX],check[MAX];

int LIS(int N){

    int I,J,high,low,mid,LIS_length=0;
    check[0]=-inf;
    //L[0]=inf;
    for(I=1;I<=N;I++){
        check[I]=inf;
        //L[I]=0;
    }

    for(int I=1;I<=N;I++){
        low=0;
        high=LIS_length;

        while(low<=high){
            mid=(low+high)/2;
            if(check[mid]<seq[I])
                low=mid+1;
            else
                high=mid-1;
        }
        check[low]=seq[I];
      //  L[I]=low;
        if(LIS_length<low)
            LIS_length=low;
    }

return LIS_length;
}


int main(){

int in,in2,I,C=1;
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    while(cin>>in){
        if(in==-1)
            continue;
        stack<int> s;
        s.push(in);
        while(cin>>in2 && in2!=-1){
            s.push(in2);
        }
        I=1;
        while(s.size()){
           seq[I]=s.top();
        s.pop();
        I++;
        }
    if(C>1)
        printf("\n");
    printf("Test #%d:\n  maximum possible interceptions: %d\n",C,LIS(I-1));
    C++;
    }



return 0;
}

