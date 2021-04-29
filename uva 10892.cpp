#include<cstdio>
#include<iostream>
#include<set>
using namespace std;


long gcd(long m, long n) {

   if (n)
    return gcd(n, m % n);

return m;
}


set<int> finding_divisor(int Number){

    set<int> s;
    for(int I=1;I*I<=Number;I++){
        if(!(Number%I)){
            s.insert(I);
            s.insert(Number/I);
        }

    }

return s;
}
/*
int lcm(int a,int b){

return (a*b)/gcd(a,b);
}
*/
int main(){

    int in;

    while(cin>>in && in){
    set<int> divisor;
    set<int>::iterator it1,it2,b,e;
    divisor=finding_divisor(in);
    e=divisor.end();
    e--;
    int count=1;
    for(it1=divisor.begin();it1!=e;it1++){
        for(it2=it1,it2++;it2!=divisor.end();it2++){
            if(gcd(*it1,*it2)==1){
                count++;
            }


        }
    }

    cout<<in<<" "<<count<<endl;
    }

return 0;
}

