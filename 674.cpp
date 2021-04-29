#include<stdio.h>
#include<string.h>
#define Max 10001


int main(){
int coin[5]={50,25,10,5,1},money,I,J,K;
long way[Max];

while(scanf("%d",&money)==1){
    memset(way,0,sizeof(way));
    way[0]=1;
    for(I=0;I<5;I++){
        K=coin[I];
        for(J=K;J<=money;J++)
            way[J]+=way[J-K];
    }
    printf("%ld\n",way[money]);
}


return 0;
}
