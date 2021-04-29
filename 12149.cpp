#include<cstdio>
#include<iostream>
using namespace std;

int main(){
long long in,sum;
while(cin>>in&&in!=0){
sum=0;
for(int I=1;I<=in;I++)
    sum+=I*I;
cout<<sum<<endl;
}

return 0;
}
