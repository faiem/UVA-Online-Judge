#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int tall_max(int N){

    pair<int,int> block[N];
    int hight,maxi,I,J,tall[N],l,m;
    for(I=0;I<N;I++){
        cin>>l>>m;
    block[I]=make_pair(l,m);
    tall[I]=0;
    }
    sort(block,block+N);

    tall[0]=1;
    hight=tall[0];

    for(I=1;I<N;I++){
        maxi=0;
        for(J=I-1;J>=0;J--){
            if(block[I].first>=block[J].first && block[I].second>=block[J].second)
                maxi=max(maxi,tall[J]);
            tall[I]=maxi+1;
            hight=max(hight,maxi+1);
        }
    }
return hight;
}


int main(){

    //freopen("in.txt","r",stdin);
    int in;
    while(scanf("%d",&in) && in){
        printf("%d\n",tall_max(in));
    }
    printf("*\n");
return 0;
}

