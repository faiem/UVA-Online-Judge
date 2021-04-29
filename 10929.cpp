#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main(){
string s;
int even,odd;

//freopen("in.txt","r",stdin);
//freopen("out.txt","w",stdout);


while(cin>>s && s!="0"){
    even=0;odd=0;
    for(int I=0;I<s.size();I+=2){
        even+=(s[I]-48);
        }

    for(int I=1;I<s.size();I+=2){
        odd+=(s[I]-48);
        }
    if((odd-even)%11==0){
        cout<<s<<" is a multiple of 11."<<endl;
    }
    else
        cout<<s<<" is not a multiple of 11."<<endl;

}



return 0;
}
