#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;

long long check(long long Oddnumber){

    long long x,y,a=0,b=0;
    x=Oddnumber+1;
    y=Oddnumber-1;

    if(Oddnumber==3)
        return Oddnumber-1;
    if(y==0)
        return 0;

    while(x%2==0&&x!=0){
        x/=2;
        a++;
    }

    while(y%2==0&&y!=0){
        y/=2;
        b++;
    }
    if((a-b)>0)
        return Oddnumber+1;
    else
        return Oddnumber-1;
}

int main(){

long long number,step=0;;
        while(cin>>number){
            step=0;
            while(number>0){
                if(number%2==0)
                    number/=2;
                else
                   number=check(number);
            step++;
            }
        cout<<step<<endl;
        }

return 0;
}
