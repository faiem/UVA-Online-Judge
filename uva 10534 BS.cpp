#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
#define MAX 10010
#define inf 2147483647

int seq[MAX],check[MAX],L[MAX],LIS_seq;

void LIS(int N){

    int I,J,high,low,mid,LIS_length=0;
    check[0]=-inf;
    L[0]=inf;
    for(I=1;I<=N;I++){
        check[I]=inf;
        L[I]=0;
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
        L[I]=low;
        if(LIS_length<low)
            LIS_length=low;
    }

}

int main(){

//    freopen("in.txt","r",stdin);
    int N,res;
    while(cin>>N){
        res=0;
        for(int I=1;I<=N;I++){
            cin>>seq[I];
        }
        LIS(N);
        vector<int> L1(L+1,L+1+N);
        reverse(seq+1,seq+1+N);
        LIS(N);
        reverse(L+1,L+1+N);
        vector<int> L2(L+1,L+1+N);
        for(int I=0;I<N;I++)
            res=max(res,min(L1[I],L2[I]));
    cout<<(2*res)-1<<endl;
    }
return 0;
}

