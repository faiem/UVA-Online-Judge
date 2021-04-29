#include<stdio.h>

int gcd(int m, int n) {
    if (n)
        return gcd(n, m % n);
    return m;
    }


int main(){

   int N,I,J,total;
   while(scanf("%d",&N)&&N){
        total=0;
        for(I=1;I<N;I++)
            for(J=I+1;J<=N;J++)
                total+=gcd(I,J);
   printf("%d\n",total);
   }

return 0;
}
