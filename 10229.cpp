#include<iostream>
#include<cstdio>
#include<math.h>
using namespace std;
unsigned long Div_Con_Fib(long n){

    unsigned long i,h,j,k,t;
    i=1;h=1;
    j=0;k=0;

    while(n>0){
        if(n%2==1){
        t=j*h;
        j=i*h+j*k+t;
        i=i*k+t;
        }

    t=h*h;
    h=2*k*h+t;
    k=k*k+t;
    n=(unsigned long)n/2;
    }
return j;
}

int main(){
long pow[21];
pow[0]=1;
for(int I=1;I<21;I++){
    pow[I]=pow[I-1]*2;
    }
long in,po;
while(cin>>in>>po){
cout<<Div_Con_Fib(in)%pow[po]<<endl;
}

return 0;
}
