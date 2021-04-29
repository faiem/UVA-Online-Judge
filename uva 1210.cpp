#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;

#define MAX 10001

bool prime[MAX];
int represent[MAX];
vector<int> primeStore;

void clear(){

    for(int I=0;I<MAX;I++){
        prime[I]=1;
        represent[I]=0;
    }
}

void sieve(){
    clear();
    prime[1]=0;
    prime[2]=1;
    primeStore.push_back(2);
    represent[2]++;
    for(int I=4;I<MAX;I+=2)
        prime[I]=0;
    for(int I=3;I*I<MAX;I+=2){
        if(prime[I]){
           for(int J=2*I;J<MAX;J+=I)
                prime[J]=0;
        }
    }

    for(int I=3;I<MAX;I+=2){
        if(prime[I]){
            primeStore.push_back(I);
            represent[I]++;
        }
    }
}




int main(){
    int sum=0,num;
    sieve();

    for(int I=0;I<25;I++)
        cout<<primeStore[I]<<endl;
    for(int I=0;I<primeStore.size()-1;I++){
        sum=primeStore[I];
        for(int J=I+1;J<primeStore.size();J++){
            if(sum+primeStore[J]<MAX){
            sum+=primeStore[J];
            represent[sum]++;
            }
        }
    }


    while(cin>>num && num){
        cout<<represent[num]<<endl;
    }
return 0;
}
