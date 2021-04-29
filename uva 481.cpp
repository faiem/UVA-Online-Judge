#include<iostream>
#include<cstdio>
#include<vector>
#include<stack>
using namespace std;
#define inf 2147483647

vector<int> seq,check,L;
/**
1.seq contains input numbers.
2.check always create accending order and apply binary search in here
3.L store the  index values like [2,1,3,....]
**/

int LIS(int N){

    int I,J,high,low,mid,LIS_length=0;
    check.push_back(-inf);
    L.push_back(inf);
    for(I=1;I<=N;I++){
    check.push_back(inf);
    L.push_back(0);
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

return LIS_length;
}

void LIS_sequence_print(int N){
    int I,max;
    stack<int> s;
    max=N;
    for(int I=N-1;I>=1;I--)
        if(L[I]>L[max])
            max=I;
/*
    for(int I=1;I<=N;I++)
        cout<<seq[I]<<" ";
    cout<<endl;
    for(int I=1;I<=N;I++)
        cout<<L[I]<<" ";
    cout<<endl;
*/
    s.push(seq[max]);
    for(int I=max;I>1;I--){
        if(seq[max]>seq[I-1] && L[I-1]==L[max]-1){
            s.push(seq[I-1]);
        max=I-1;
        }
    }

    while(!s.empty()){
        cout<<s.top()<<endl;
    s.pop();
    }

}


int main(){

    //freopen("in.txt","r",stdin);
    int N=1,in,Test;

        seq.push_back(inf);
        while(cin>>in)
        {
        seq.push_back(in);
        N++;
        }
        cout<<LIS(N)<<endl;
        cout<<"-"<<endl;
        LIS_sequence_print(N);

return 0;
}

