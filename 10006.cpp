#include<cstdio>
#include<iostream>
#include<vector>
#include<set>
using namespace std;
#define Max 65001

vector<int> prime;
bool flag[Max];
bool chermical[Max];
int numOfFactor;

void primeGen(int limit){

    for(int I=1;I<=limit;I++)
        flag[I]=1;

    flag[1]=0;

    for(int I=4;I<=limit;I+=2)
        flag[I]=0;

    for(int I=3;I*I<=limit;I+=2){
        if(flag[I])
            for(int J=2*I;J<=limit;J+=I)
                flag[J]=0;
    }

    for(int I=1;I<=limit;I++)
        if(flag[I])
            prime.push_back(I);
}


set< int > primeFactor(int num){

    int I=0;
    set<int> factor;
    while(num>=(prime[I]*prime[I])){

        if(num%prime[I]==0){
            numOfFactor++;
            num/=prime[I];
            factor.insert(prime[I]);
        }
        else
            I++;
    }
    if(num!=1){
        numOfFactor++;
        factor.insert(num);
    }

return factor;
}

int main(){


    primeGen(65000);

    for(int I=1;I<Max;I++)
        chermical[I]=0;

    for(int I=3;I<Max;I+=2){

        if(!flag[I]){
            numOfFactor=0;
            set<int> a;
            set<int>::iterator it;

            bool c=1;
            a=primeFactor(I);
            if(numOfFactor==a.size()){

                for(it=a.begin();it!=a.end();it++)
                    if((I-1)%(*it-1)!=0){
                        c=0;
                    break;
                    }

                if(c)
                    chermical[I]=1;
            }
        }
    }
    int n=0;

    while( scanf("%d",&n) && n){

        if(chermical[n])
            printf("The number %d is a Carmichael number.\n",n);
        else
            printf("%d is normal.\n",n);

    }
 return 0;
}
