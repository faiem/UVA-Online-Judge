#include<stdio.h>
#include<string.h>
#define Max 30001


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
    if(way[money]==1)
    printf("There is only 1 way to produce %d cents change.\n",money);
    else
    printf("There are %ld ways to produce %d cents change.\n",way[money],money);
}


return 0;
}
