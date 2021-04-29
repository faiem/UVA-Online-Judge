#include<cstdio>
#include<iostream>
#include<string>
#include<vector>
#include<stack>
using namespace std;

unsigned long convert10(string s,int base){
    unsigned long mod=0;
    for(int I=0;I<s.size();I++)
        mod=mod*base+(s[I]-48);
return mod;
}

stack<char> convert10toAny(unsigned long num,int base){

    stack<char> st;
    if(num==0)
        st.push(0+48);
    while(num){
        st.push((num%base)+48);
        num/=base;
    }
return st;
}

int main(){
unsigned long m;
int base;
string s,t;
char ch;
    while(cin>>base && base){
         cin>>s>>t;
         long mod=0;
         stack<char> st;
         m=convert10(t,base);
         for(int I=0;I<s.size();I++){
            mod=(mod*base+(s[I]-48))%m;
         }
        st=convert10toAny(mod,base);
        while(st.size()){
            cout<<st.top();
        st.pop();
        }
        cout<<endl;
    }

return 0;
}

