#include<stdio.h>
#define MAX 2001

int LIS[MAX],LDS[MAX],arr[MAX],limit;

int max(int a,int b){
    if(a>b)
        return a;
return b;
}


void clear(){
    int I;
    for(I=0;I<MAX;I++){
        LDS[I]=-1;
        LIS[I]=-1;
        arr[I]=0;
    }
}

int decrease(int N){

    if(LDS[N]!=-1)
        return LDS[N];
    int I,maxi=0;
    for(I=N+1;I<limit;I++)
        if(arr[N]>arr[I])
            maxi=max(maxi,decrease(I));
return LDS[N]=maxi+1;
}

int increase(int N){

    if(LIS[N]!=-1)
        return LIS[N];
    int I,maxi=0;
    for(I=N+1;I<limit;I++)
        if(arr[N]<arr[I])
            maxi=max(maxi,increase(I));
return LIS[N]=maxi+1;
}


int main(){

int test,N,res,I;
    scanf("%d",&test);
    while(test--){
        clear();
        scanf("%d",&N);
        limit=N;
        res=0;
        for(I=0;I<N;I++)
            scanf("%d",&arr[I]);
        for(I=0;I<N;I++)
            res=max(res,(increase(I)+decrease(I)-1));
        printf("%d\n",res);
    }

return 0;
}


