#include<stdio.h>
#include<math.h>

int main(){

    long num,a,b,j,s_a,s_b,i;
    while(scanf("%ld",&num)==1 && num){
        i=0;b=0;a=1;s_a=0;s_b=0;
        while(num>0){
        j=num%2;
            if(j && a){
                s_a+=j*pow(2,i);
            a=0;b=1;
            }
            else if(j && b){
                s_b+=j*pow(2,i);
            b=0;a=1;
            }
        num/=2;
        i++;
        }
    printf("%ld %ld\n",s_a,s_b);
    }


return 0;
}
