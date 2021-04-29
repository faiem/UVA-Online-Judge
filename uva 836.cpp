#include<stdio.h>
#define MAX 26

int mat0[MAX][MAX];

int max(int a,int b){
    if(a>b)
        return a;
return b;
}

int solve(int N){
    int I,J,K,sum1,res1;
    for(I=0;I<N;I++){
        for(J=0;J<N;J++){
            mat0[I+1][J+1]+=mat0[I][J+1];
        }
    }
    res1=mat0[1][1];
    for(I=0;I<N;I++){
        for(J=I+1;J<=N;J++){
            sum1=0;
            for(K=1;K<=N;K++){
                sum1+=mat0[J][K]-mat0[I][K];
            if(sum1<0)
                sum1=0;
            res1=max(res1,sum1);
            }

        }
    }
return res1;
}


int main(){


    char ch;
    int test,C=0,I,J,K,value;
    scanf("%d",&test);
    getchar();

    while(test--){
        getchar();
        I=0;
        while((ch=getchar())!='\n'){
            value=(ch-48);
            mat0[1][I+1]=(value*(26))-25;
        I++;
        }

        for(J=2;J<=I;J++){
            for(K=1;K<=I;K++){
            ch=getchar();
            value=(ch-48);
            mat0[J][K]=(value*(26))-25;
            }
        getchar();
        }

    if(C>0)
        printf("\n");

        printf("%d\n",solve(I));
    C++;
    }



return 0;
}
