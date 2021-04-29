#include<stdio.h>
#define MAX 30

int s1[MAX],s2[MAX],matrix_value[MAX][MAX],I,J;

int max(int x,int y){
    if(x>y)
        return x;
return y;
}


int LCS(int N){

    for(I=0;I<=N;I++){
        matrix_value[0][I]=0;
        matrix_value[I][0]=0;
    }


    for(I=1;I<=N;I++){
        for(J=1;J<=N;J++){
            if(s1[I]==s2[J])
                matrix_value[I][J]=matrix_value[I-1][J-1]+1;
            else
                matrix_value[I][J]=max(matrix_value[I-1][J],matrix_value[I][J-1]);
        }
    }

return matrix_value[N][N];
}

int main(){

    int N,in;
    scanf("%d",&N);
    for(I=1;I<=N;I++){
        scanf("%d",&in);
        s1[in]=I;
    }

    while(scanf("%d",&in)==1){

        s2[in]=1;

        for(I=2;I<=N;I++){
            scanf("%d",&in);
            s2[in]=I;
        }
        printf("%d\n",LCS(N));

    }


return 0;
}

