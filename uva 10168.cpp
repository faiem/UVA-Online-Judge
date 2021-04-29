#include<cstdio>
#include<iostream>
using namespace std;

#define MAX 10000001

bool prime[MAX];

void clear(){

    for(int I=0;I<MAX;I++){
        prime[I]=1;
     }
}

void sieve(){
    clear();
    prime[1]=0;
    prime[2]=1;
    for(int I=4;I<MAX;I+=2)
        prime[I]=0;
    for(int I=3;I*I<MAX;I+=2){
        if(prime[I]){
           for(int J=2*I;J<MAX;J+=I)
                prime[J]=0;
        }
    }

 }

void goldbachConjecture(int num){

    if(num==4){
        printf("2 2\n");
    return;
    }
    bool flag=true;
    int i=3;
    while(i<=num-i && flag){
        if(prime[i] && prime[num-i]){
            printf("%d %d\n",i,num-i);
            flag=false;
        }
    i+=2;
    }

}

int main(){

    int num;
    sieve();
    while(cin>>num){
        if(num<8)
            printf("Impossible.\n");
        else{

            if(num%2){
                printf("2 3 ");
                goldbachConjecture(num-5);
            }
            else{
                printf("2 2 ");
                goldbachConjecture(num-4);
            }

        }
    }

return 0;
}
