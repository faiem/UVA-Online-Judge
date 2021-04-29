#include<stdio.h>

int main(){
    int N=0,I=0,J=0;
    while(scanf("%d",&N)==1){

    if(N<4)
        printf("Impossible\n");

    else if(N%6==2){
        for(I=2;I<=N;I+=2)
            printf("%d ",I);
        printf("3 1 ");
        for(I=7;I<N;I+=2)
            printf("%d ",I);
        printf("5\n");
        }
    else if(N%6==3){
        for(I=4;I<=N;I+=2)
            printf("%d ",I);
        printf("2 ");
        for(I=5;I<=N;I+=2)
            printf("%d ",I);
        printf("1 3\n");
        }
    else{
        for(I=2;I<=N;I+=2)
            printf("%d ",I);
        if(N&1){
        for(I=1;I<N;I+=2)
            printf("%d ",I);
        printf("%d\n",N);
            }
        else{
            for(I=1;I<N-1;I+=2)
                printf("%d ",I);
            printf("%d\n",N-1);
            }
        }
    }

    return 0;
    }