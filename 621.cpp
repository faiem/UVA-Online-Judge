#include<cstdio>
#include<string>
#include<iostream>
using namespace std;

int main(){

int test;
    cin>>test;
    string s;
    while(test--){

    cin>>s;
    if(s=="78")
        cout<<"+"<<endl;
    else if((s[s.size()-1]=='5') && (s[s.size()-2]=='3'))
        cout<<"-"<<endl;
    else if(s[0]=='9' && s[s.size()-1]=='4')
        cout<<"*"<<endl;
    else if(s[0]=='1' && s[1]=='9' && s[2]=='0')
        cout<<"?"<<endl;

    }


return 0;
}
