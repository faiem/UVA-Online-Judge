#include<iostream>
#include<cstdio>
#include<map>
#include<vector>
using namespace std;

unsigned long factorial(int num){

unsigned long fact=1;
for(int I=num;I>1;I--)
    fact*=I;
return fact;
}

int main(){
char ch;
int test;
unsigned long num;
cin>>test;
getchar();
    for(int I=1;I<=test;I++){
        map<char,int> M;
        map<char,int>::iterator it;

        int count=0;
        while((ch=getchar())!='\n'){
        M[ch]++;
        count++;
        }
    num=factorial(count);
    for(it=M.begin();it!=M.end();it++){
        num=num/factorial((*it).second);
        }
    cout<<"Data set "<<I<<": "<<num<<endl;
    }
return 0;
}
