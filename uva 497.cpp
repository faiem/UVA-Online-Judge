#include<iostream>
#include<cstdio>
#include<vector>
#include<stack>
#include<cstring>
#include<cstdlib>
using namespace std;
#define inf 2147483647

vector<int> seq,check,L;

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
    max=1;
    for(int I=2;I<=N;I++)
        if(L[I]>L[max])
            max=I;
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
    //freopen("out.txt","w",stdout);

    int N,Test;
    bool bline=0;
    char str[50];

    scanf("%d",&Test);
    getchar();
    getchar();
    while(Test--){
        N=1;
        seq.push_back(inf);
        while(gets(str) && strlen(str)){
            seq.push_back( (int)atoi(str) );
        N++;
        }
        if(bline) printf("\n");
        printf("Max hits: %d\n",LIS(N));
        LIS_sequence_print(N);
    bline=1;
    seq.clear();
    check.clear();
    L.clear();
    }


return 0;
}

