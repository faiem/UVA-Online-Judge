#include<stdio.h>
#include<math.h>

void light(double v){

    double a,b,c;

        a=sqrt(v);
        b=(long) a ;
        if(a==b)
            printf("yes\n");
        else
            printf("no\n");
    }


int main(){

    double a;
    while(scanf("%lf",&a) && a!=0){
        light(a);
    }


return 0;
}
