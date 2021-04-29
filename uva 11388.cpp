#include<stdio.h>

int main(){

    int T;
    unsigned long G,L;

    scanf("%d",&T);

    while(T--){

        scanf("%ld %ld",&G,&L);
        if(L%G==0)
            printf("%ld %ld\n",G,L);
        else
            printf("-1\n");
    }



return 0;
}
