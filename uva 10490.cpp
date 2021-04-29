#include<cstdio>
#include<iostream>
using namespace std;

bool prime_check(unsigned long num){
    int I;
    if(num==2)
        return true;
    if(num%2){
        for(I=3;I*I<num+1;I+=2){
            if(num%I==0)
                return false;
        }
    return true;
    }

return false;
}

/**return 2^p**/
unsigned long power(unsigned long p){

    unsigned long result=1;
    for(int I=0;I<p;I++)
        result*=2;
return result;
}

int main(){

    bool prime,perfect_condition;
    long long num;
    while(cin>>num && num){
        prime=prime_check(num);
        perfect_condition=prime_check(power(num)-1);
        if(prime){
            if(perfect_condition)
                cout<<"Perfect: "<<power(num-1)*(power(num)-1)<<"!\n";
            else
                cout<<"Given number is prime. But, NO perfect number is available.\n";
        }
        else
                cout<<"Given number is NOT prime! NO perfect number is available.\n";
    }

return 0;
}
