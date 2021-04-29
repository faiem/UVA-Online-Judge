#include<stdio.h>
#define MAX 101
int mat[MAX][MAX];

int max(int a,int b){
    if(a>b)
        return a;
return b;
}

int solve(int N){
    int I,J,K,sum,res;
    for(I=0;I<N;I++){
        for(J=0;J<N;J++){
            scanf("%d",&mat[I+1][J+1]);
            mat[I+1][J+1]+=mat[I][J+1];
        }
    }
    res=mat[1][1];
    for(I=0;I<N;I++){
        for(J=I+1;J<=N;J++){
            sum=0;
            for(K=1;K<=N;K++){
                if(sum>=0)
                sum+=mat[J][K]-mat[I][K];
                else
                sum=mat[J][K]-mat[I][K];
            res=max(res,sum);
            }

        }
    }
return res;
}

int main(){


    int N,I;
    for(I=0;I<101;I++){
        mat[0][I]=0;
        mat[I][0]=0;
    }

    while(scanf("%d",&N)==1){
        printf("%d\n",solve(N));
    }

return 0;
}
