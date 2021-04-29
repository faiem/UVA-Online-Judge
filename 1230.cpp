#include<stdio.h>

long sqr(long x){
return x*x;
}

long BigMod(long a,long p,long mod){

    if(p==0)
        return 1;
    else if(!(p&1))
        return sqr(BigMod(a,p/2,mod))%mod;
    else
        return ((a%mod)*BigMod(a,p-1,mod))%mod;

}

int main(){

long T,x,y,mod;
scanf("%ld",&T);
    while(T--){

    scanf("%ld %ld %ld",&x,&y,&mod);
    printf("%ld\n",BigMod(x,y,mod));
    }
scanf("%ld",&T);



return 0;
}
