#include<cstdio>
#include<map>
#include<iostream>
using namespace std;
#define limit 100

    long long cataline[limit+1];
    map<long long,int> M;

    void number_generate(){
        int I;
        cataline[0]=1;
        for(I=1;I<20;I++){
            cataline[I]=((2*(2*(I-1) + 1)*cataline[I-1])/(I+1));
            /*
            cout<<I<<" "<<cataline[I]<<endl;
            if(cataline[I]>4294967295){
                break;
            }
        cout<<I<<" "<<cataline[I]<<endl;
            */
        M[cataline[I]]=I;
        }


    }


int main(){

     long long n;
     number_generate();
     while(scanf("%lld",&n)!=EOF){
             cout<<M[n]<<endl;
             }
return 0;
}

