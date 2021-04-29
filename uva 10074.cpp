#include<stdio.h>
#define MAX 111
int mat[MAX][MAX];

int max(int a,int b){
    if(a>b)
        return a;
return b;
}

int solve(int R,int C){
    int I,J,K,sum,res;
    for(I=0;I<R;I++){
        for(J=0;J<C;J++){
            scanf("%d",&mat[I+1][J+1]);
            if(mat[I+1][J+1]==1)
                mat[I+1][J+1]=-100;
            else
                mat[I+1][J+1]=1;
            mat[I+1][J+1]+=mat[I][J+1];
        }
    }
    res=mat[1][1];
    for(I=0;I<R;I++){
        for(J=I+1;J<=R;J++){
            sum=0;
            for(K=1;K<=C;K++){
                sum+=mat[J][K]-mat[I][K];
            if(sum<0)
                sum=0;
            res=max(res,sum);
            }

        }
    }

return res;
}

int main(){


    int R,C,I;

    while(scanf("%d %d",&R,&C) && R){
        printf("%d\n",solve(R,C));
    }

return 0;
}
