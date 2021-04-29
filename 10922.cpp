#include<cstdio>
#include<iostream>
#include<string>
using namespace std;

int main(){
    int sum,t,dgree;
    string s;
    //freopen("in.txt","r",stdin);

    while(cin>>s){
        if(s=="0")
            break;
        sum=0;dgree=1;
        for(int I=0;I<s.size();I++)
            sum+=s[I]-'0';

        if(sum%9==0){

            while(sum>=10){
            t=0;
                while(sum>0){
                    t+=sum%10;
                    sum=sum/10;
                    }
            sum=t;
            dgree++;
            }
        cout<<s<<" is a multiple of 9 and has 9-degree "<<dgree<<"."<<endl;
        }
        else
        cout<<s<<" is not a multiple of 9."<<endl;
    }


return 0;
}
