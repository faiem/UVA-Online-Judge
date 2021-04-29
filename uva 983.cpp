#include<stdio.h>
#define MAX 1001

int mat[MAX][MAX];


int main(){

    unsigned long long int total_sum;
    long int N,M,C=0,I,J,sum;

    while(scanf("%ld %ld",&N,&M)==2){

        for(I=1;I<=N;I++){
            for(J=1;J<=N;J++){
                scanf("%d",&mat[I][J]);
                mat[I][J]+=mat[I][J-1];
            }
        }
        for(I=1;I<=N;I++){
            for(J=1;J<=N;J++)
                mat[I][J]+=mat[I-1][J];
        }

        if(C>0)
            printf("\n");
        total_sum=0;
        for(I=M;I<=N;I++){
            sum=0;
            for(J=M;J<=N;J++){
               sum=mat[I][J]-(mat[I-M][J]+mat[I][J-M]-mat[I-M][J-M]);
               printf("%ld\n",sum);
               total_sum+=sum;
            }

        }
        printf("%llu\n",total_sum);

    C++;
    }




return 0;
}
