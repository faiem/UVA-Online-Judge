#include<stdio.h>

int main(){

    int I,J,test,n,sales[1001],sum;
    scanf("%d",&test);
    while(test--){
        sum=0;
        scanf("%d",&n);
        for(I=0;I<n;I++){
            scanf("%d",&sales[I]);
            for(J=0;J<I;J++)
              sum+=(sales[J]<=sales[I]);
        }
    printf("%d\n",sum);
    }

return 0;
}
