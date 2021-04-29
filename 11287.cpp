#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;

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

bool is_prime(long n){

    if(!(n&1)||(n==1))
        return 0;
    for(int I=3;I*I<=n;I+=2)
        if(n%I==0)
            return 0;
return 1;
}
int main(){
    //freopen("in.txt","r",stdin);
    long p,a;

    while(cin>>p>>a && p){

        if( !is_prime(p) && (BigMod(a,p,p)==a) )
            printf("yes\n");
        else
            printf("no\n");

    }


return 0;
}
